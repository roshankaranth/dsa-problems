#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum crime{ARSON = 10, ASSAULT = 5, BURGLARY = 5, CRIMINAL_MISCHIEF = 5, GRAND_LARCENY = 10, GRAND_THEFT_AUTO = 10, HOMICIDE = 20, BREAKING_AND_ENTERING = 5, ROBBERY = 10}Crime;

const static struct {
    Crime crime;
    const char *str;
} conversion[] = {
    {ARSON,"ARSON"},
    {ASSAULT, "ASSAULT"},
    {BURGLARY, "BURGLARY"},
    {CRIMINAL_MISCHIEF, "CRIMINAL MISCHIEF"},
    {GRAND_LARCENY, "GRAND LARCENY"},
    {GRAND_THEFT_AUTO, "GRAND THEFT AUTO"},
    {HOMICIDE, "HOMICIDE"},
    {BREAKING_AND_ENTERING, "BREAKING_AND_ENTERING"},
    {ROBBERY,"ROBBERY"}
};

typedef struct crime_data{
    char crime[50];
    int year;
}crimeData;

typedef struct criminal{
    char name[100];
    int age;
    int ID;
    double criminality;
    crimeData crimes[50];
    int crimeCount;

}Criminal;

Criminal itoe(char* name, int age, int ID){
    Criminal cr;

    strcpy(cr.name, name);
    cr.ID = ID;
    cr.age = age;
    cr.crimeCount = 0;
    return cr;
}

void displayData(Criminal data[], int size){

    for(int i = 0 ; i < size ; i++){
        printf("%s %d %d %d %.2f \n", data[i].name, data[i].age, data[i].ID,data[i].crimeCount ,data[i].criminality);
    }
}

Crime convertStrtoEnum(char* crime){
    for(int i = 0; i < sizeof(conversion)/sizeof(conversion[0]); i++){
        if(!strcmp(crime, conversion[i].str)) return conversion[i].crime;
    }

}

void recordCrime(char* crime, int year, int ID, Criminal data[]){
    int currentYear = 2023;
    int criminalIndex = ID-100000;

    double multiplier = 1;
    int birth_year = currentYear - data[criminalIndex].age;
    int crime_age = year - birth_year;

    if(crime_age < 18) multiplier = 0.5;

    Crime cr = convertStrtoEnum(crime);
    data[criminalIndex].criminality += cr*multiplier;

    crimeData cd;
    strcpy(cd.crime, crime);
    cd.year = year;
    data[criminalIndex].crimes[data[criminalIndex].crimeCount] = cd;
    data[criminalIndex].crimeCount++;

}

void merge(Criminal data[], int lo, int mid, int hi){

    for(int i = mid+1 ; i <= hi; i++){
        Criminal cr = data[i];
        int j = i-1;
        while(j>=lo){
            if(data[j].criminality < cr.criminality){
                data[j+1] = data[j];
            }else break;
            j--;

        }

        data[j+1] = cr;
    }
}

void mergeSort(Criminal data[], int hi, int lo){
    if(hi==lo) return;

    int mid = (hi+lo)/2;
    mergeSort(data,mid,lo);
    mergeSort(data,hi,mid+1);
    merge(data,lo,mid,hi);
}

int main(int argc, char* argv[]){
    
    FILE* fptr = fopen(argv[1],"r");
    if(fptr == NULL){
        printf("Error opening file!");
        return 0;
    }

    char line[100];
    fgets(line,100,fptr);
    int size = atoi(line);

    Criminal* data = (Criminal*)malloc(sizeof(Criminal)*size);

    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        char* name = token;
        token = strtok(NULL,",");
        int age = atoi(token);
        token = strtok(NULL,",");
        int ID = atoi(token);

        data[ID-100000] = itoe(name, age, ID);
       
    }

    fclose(fptr);

    fptr = fopen(argv[2],"r");
    if(fptr == NULL){
        printf("Error opening file!");
        return 0;
    }

    fgets(line,100,fptr);
    while(fgets(line,100,fptr)){
        char* token = strtok(line,",");
        char* crime = token;
        token = strtok(NULL,",");
        int year = atoi(token);
        token = strtok(NULL,",");
        int ID = atoi(token);

        recordCrime(crime, year, ID, data);
    }

    mergeSort(data, size-1, 0);

    displayData(data, size);

}
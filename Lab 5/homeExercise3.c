#include<stdio.h>
#include<sys/time.h>
#include<string.h>
#include<stdlib.h>

#define MAX_STRING_LENGTH 100

int comparator(char* s1, char* s2){
    while(*s1 != '\0' && *s1 != '\0'){
        if(*s1 - '0' == *s2 - '0'){
            s1 += 1;
            s2 += 1;
        }else break;
    }

    if((*s1 - '0' > *s2 - '0') || (*s2 == '\0' && *s1 != '\0')) return 1;
    else return 0;
}

void sortString1(char arr[][MAX_STRING_LENGTH], int size){

    for(int i = 1; i < size ; i++){
        char s[MAX_STRING_LENGTH];
        strcpy(s,arr[i]);
        int j = i-1;
        while(j>=0){
            if(comparator(arr[j],s)){
                strcpy(arr[j+1], arr[j]);
            }else break;
            
            j--;
        }

        strcpy(arr[j+1],s);
    }
}

void sortString2(char* arr[], int size){

    for(int i = 1; i < size ; i++){
        char* s;
        s = arr[i];
        int j = i-1;
        while(j>=0){
            if(comparator(arr[j],s)){
                arr[j+1] = arr[j];
            }else break;

            j--;
        }

        arr[j+1] = s;
    }
}

void main(){

    char* fruits[] = {"Apple", "India", "New York", "Pizza",
    "Banana", "China", "London", "Sushi",
    "Mango", "Japan", "Paris", "Tacos",
    "Orange", "USA", "Tokyo", "Burger",
    "Grapes", "Brazil", "Sydney", "Pasta",
    "Pineapple", "Australia", "Beijing", "Rice",
    "Watermelon", "Russia", "Mumbai", "Curry",
    "Strawberry", "Germany", "Delhi", "Noodles",
    "Cherry", "France", "Shanghai", "Sandwich",
    "Blueberry", "Italy", "Bangkok", "Salad",
    "Raspberry", "Spain", "Kolkata", "Soup",
    "Blackberry", "Canada", "Chennai", "Fries",
    "Avocado", "Mexico", "Hyderabad", "Bread",
    "Peach", "South Africa", "Ahmedabad", "Eggs",
    "Pear", "North Korea", "Pune", "Cereal",
    "Apricot", "South Korea", "Jaipur", "Milk",
    "Plum", "United Kingdom", "Kanpur", "Cheese",
    "Papaya", "Argentina", "Lucknow", "Butter",
    "Guava", "Chile", "Nagpur", "Honey",
    "Kiwi", "Peru", "Coimbatore", "Sugar",
    "Pomegranate", "Colombia", "Visakhapatnam", "Coffee",
    "Acai", "Venezuela", "Surat", "Tea",
    "Cranberry", "Ecuador", "Thane", "Juice",
    "Gooseberry", "Bolivia", "Gurgaon", "Water",
    "Pine", "Uruguay", "Noida", "Soda",
    "Fig", "Paraguay", "Faridabad", "Cake",
    "Date", "Guyana", "Ghaziabad", "Pastry",
    "Prune", "Suriname", "Ranchi", "Ice Cream",
    "Raisin", "French Guiana", "Bhopal", "Chocolate",
    "Grapefruit", "Fiji", "Indore", "Candy",
    "Lemon", "Tonga", "Patna", "Cookie",
    "Lime", "Samoa", "Agra", "Muffin",
    "Tangerine", "Vanuatu", "Varanasi", "Biscuit",
    "Kumquat", "Solomon Islands", "Allahabad", "Pudding",
    "Loquat", "New Caledonia", "Amritsar", "Yogurt",
    "Persimmon", "Papua New Guinea", "Jalandhar", "Buttermilk",
    "Pummelo", "Palau", "Ludhiana", "Smoothie",
    "Quince", "Marshall Islands", "Meerut", "Shake",
    "Soursop", "Micronesia", "Nasik", "Fruit Salad",
    "Tamarillo", "Nauru", "Vadodara", "Fruit Juice",
    "Physalis", "Tuvalu", "Rajkot", "Energy Drink",
    "Passion Fruit", "Kiribati", "Jamnagar", "Sports Drink",
    "Durian", "Tonga", "Bhavnagar", "Soda Water",
    "Rambutan", "Samoa", "Moradabad", "Mineral Water",
    "Lychee", "Vanuatu", "Gwalior", "Flavored Water",
    "Longan", "Solomon Islands", "Jabalpur", "Sparkling Water",
    "Mangosteen", "New Caledonia", "Raipur", "Iced Tea",
    "Starfruit", "Papua New Guinea", "Kota", "Hot Chocolate",
    "Dragon Fruit", "Palau", "Udaipur", "Espresso",
    "Pitaya", "Marshall Islands", "Ajmer", "Cappuccino",
    "Jackfruit", "Micronesia", "Jodhpur", "Latte",
    "Breadfruit", "Nauru", "Bikaner", "Mocha",
    "Sapodilla", "Tuvalu", "Alwar", "Frappuccino",
    "Soursop", "Kiribati", "Sikar", "Macchiato",
    "Tamarind", "Tonga", "Jhunjhunu", "Americano",
    "Guarana", "Samoa", "Chittorgarh", "Breve",
    "Cupuacu", "Vanuatu", "Bhilwara", "Cold Brew",
    "Acerola", "Solomon Islands", "Rajsamand", "Turkish Coffee",
    "Acai Berry", "New Caledonia", "Dungarpur", "Iced Coffee",
    "Goji Berry", "Papua New Guinea", "Banswara", "Coffee Cake",
    "Pomegranate", "Palau", "Churu", "Cinnamon Roll",
    "Amla", "Marshall Islands", "Jaisalmer", "Donut",
    "Mangosteen", "Micronesia", "Barmer", "Croissant",
    "Physalis", "Nauru", "Jalore", "Bagel",
    "Passion Fruit", "Tuvalu", "Sirohi", "Muffin Top",
    "Durian", "Kiribati", "Pali", "Scone",
    "Rambutan", "Tonga", "Sikar", "Biscotti",
    "Lychee", "Samoa", "Jhunjhunu", "Cannoli",
    "Longan", "Vanuatu", "Chittorgarh", "Tiramisu",
    "Mangosteen", "Solomon Islands", "Bhilwara", "Cheesecake",
    "Starfruit", "New Caledonia", "Rajsamand", "Brownies",
    "Dragon Fruit", "Papua New Guinea", "Dungarpur", "Cookies",
    "Pitaya", "Palau", "Banswara", "Cupcakes",
    "Jackfruit", "Marshall Islands", "Churu", "Fruit Tarts",
    "Breadfruit", "Micronesia", "Jaisalmer", "Cream Puffs",
    "Sapodilla", "Nauru", "Barmer", "Eclairs",
    "Soursop", "Tuvalu", "Jalore", "Fruit Pies",
    "Tamarind", "Kiribati", "Sirohi", "Tartlets",
    "Guarana", "Tonga", "Pali", "Macarons",
    "Cupuacu", "Samoa", "Sikar", "Madeleines",
    "Acerola", "Vanuatu", "Jhunjhunu", "Fruit Cakes",
    "Acai Berry", "Solomon Islands", "Chittorgarh", "Gingerbread",
    "Goji Berry", "New Caledonia", "Bhilwara", "Pound Cake",
    "Pomegranate", "Papua New Guinea", "Rajsamand", "Angel Food Cake",
    "Amla", "Palau", "Dungarpur", "Sponge Cake",
    "Mangosteen", "Marshall Islands", "Banswara", "Fruit Salad",
    "Physalis", "Micronesia", "Churu", "Fruit Smoothie",
    "Passion Fruit", "Nauru", "Jaisalmer", "Yogurt Parfait",
    "Durian", "Tuvalu", "Barmer", "Granola",
    "Rambutan", "Kiribati", "Jalore", "Energy Bars",
    "Lychee", "Tonga", "Sirohi", "Trail Mix",
    "Longan", "Samoa", "Pali", "Dried Fruits",
    "Mangosteen", "Vanuatu", "Sikar", "Nuts",
    "Starfruit", "Solomon Islands", "Jhunjhunu", "Seeds",
    "Dragon Fruit", "New Caledonia", "Chittorgarh", "Honey",
    "Pitaya", "Papua New Guinea", "Bhilwara", "Maple Syrup",
    "Jackfruit", "Palau", "Rajsamand", "Agave Nectar",
    "Breadfruit", "Marshall Islands", "Dungarpur", "Stevia",
    "Sapodilla", "Micronesia", "Banswara", "Sugar",
    "Soursop", "Nauru", "Churu", "Salt",
    "Tamarind", "Tuvalu", "Jaisalmer", "Spices",
    "Guarana", "Kiribati", "Barmer", "Herbs",
    "Cupuacu", "Tonga", "Jalore", "Tea Leaves",
    "Acerola", "Samoa", "Sirohi", "Coffee Beans",
    "Acai Berry", "Vanuatu", "Pali", "Cocoa Beans",
    "Goji Berry", "Solomon Islands", "Sikar", "Vanilla Beans",
    "Pomegranate", "New Caledonia", "Jhunjhunu", "Almonds",
    "Amla", "Papua New Guinea", "Chittorgarh", "Walnuts",
    "Mangosteen", "Palau", "Bhilwara", "Pecans",
    "Physalis", "Marshall Islands", "Rajsamand", "Hazelnuts",
    "Passion Fruit", "Micronesia", "Dungarpur", "Pistachios",
    "Durian", "Nauru", "Banswara", "Cashews",
    "Rambutan", "Tuvalu", "Churu", "Macadamia Nuts",
    "Lychee", "Kiribati", "Jaisalmer", "Brazil Nuts",
    "Longan", "Tonga", "Barmer", "Peanuts",
    "Mangosteen", "Samoa", "Jalore", "Sunflower Seeds",
    "Starfruit", "Vanuatu", "Sirohi", "Pumpkin Seeds",
    "Dragon Fruit", "Solomon Islands", "Pali", "Chia Seeds",
    "Pitaya", "New Caledonia", "Sikar", "Flaxseeds",
    "Jackfruit", "Papua New Guinea", "Jhunjhunu", "Hemp Seeds",
    "Breadfruit", "Palau", "Chittorgarh", "Sesame Seeds",
    "Sapodilla", "Marshall Islands", "Bhilwara", "Poppy Seeds",
    "Soursop", "Micronesia", "Rajsamand"};

    int size = 400;
    
    char arr1[size][MAX_STRING_LENGTH];
    char* arr2[size];

    for(int i = 0 ; i < size ; i++){
        strcpy(arr1[i], fruits[i]);
        
        arr2[i] = malloc(strlen(fruits[i]) + 1);
        strcpy(arr2[i], fruits[i]);
    }

    struct timeval t1,t2;
    double time_taken = 0;
    
    gettimeofday(&t1,NULL);
    sortString1(arr1, size);
    gettimeofday(&t2,NULL);
    //printf("\n");
    // for(int i = 0 ; i < 100 ; i++){
    //     printf("%s\n",arr1[i]);
    // }

    time_taken = (t2.tv_sec - t1.tv_sec)*1e6;
    time_taken += (t2.tv_usec-t1.tv_usec)*1e-6;

    printf("2D matrix approach took %f seconds to execute!\n", time_taken);

    gettimeofday(&t1,NULL);
    sortString2(arr2, size);
    gettimeofday(&t2,NULL);
    // printf("\n");
    // for(int i = 0 ; i < 100 ; i++){
    //     printf("%s\n",arr2[i]);
    // }

    time_taken = (t2.tv_sec - t1.tv_sec)*1e6;
    time_taken += (t2.tv_usec-t1.tv_usec)*1e-6;

    printf("1D matrix approach took %f seconds to execute!\n", time_taken);


    
}
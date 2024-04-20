#include <stdio.h>

int main() 
{
    int apartment, entrance, floor;
    
    printf("Enter the apartment number: ");
    scanf("%d", &apartment);
    
    entrance = (apartment - 1) / 36 + 1;
    floor = ((apartment - 1) % 36) / 4 + 1;
    
    printf("Entrance number: %d\n", entrance);
    printf("Floor number: %d\n", floor);
    
    return 0;
}

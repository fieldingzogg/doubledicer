#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>


typedef struct {
    uint64_t x; ///s
    uint64_t y; ///e
    uint64_t z; ///m
    uint64_t a; /// full 
}SEM;


//returns -1 if not exception....  exceptions ---  subnormal = 0. nan = 1. 0 = 2. inf = 3. 
int isexcept( int e, uint64_t m){
    
    if(e == 0 ){
        
        if(m != 0){
            return 0;
        }   
        return 2;
    }
  
    if (e == 2047){
        
        if(m != 0){
            return 1;
        }
        
        return 3; 
    }
    else
    
    return -1;   
}

double reconstructdoub(SEM a){
    
    int exponent = (int)a.y - 1023;
    int numbertype = isexcept(a.y, a.z);
    
    
    if (a.x ){
    
        if(numbertype < 0){
        
            double norm = (double)a.z/(pow(2,52)) + 1.0;
            
            double multiplyer = (pow(2, exponent)) ;
            
            double regdouble = (norm) * multiplyer * -1.0;
            
            printf(" this is a regular double, of value %.17f \n", regdouble);
            
            return regdouble;
        }
    
        if(numbertype == 0){
        
            double subm = (double)a.z/(pow(2,52) + 1.0);
        
            double subnorm = ((subm) * (pow(2, exponent))) * -1.0;
            
            printf(" this is a subnomral double, of value %e \n", subnorm);
        
            return subnorm; 
        }   
    
         if(numbertype == 1){
           
           printf("we have a NaN ! \n");
            return 0;
        }
    
        if(numbertype == 2) {
            
            printf("we have a - 0.0 \n");
           return -0.0;
        }
    
        if(numbertype ==3){
            
            printf("we have a - inf \n");
            
            return 0;
        }
        return 0;    
    }
    
    else {
        
         if(numbertype < 0){
        
            double norm = (double)a.z/(pow(2,52)) + 1.0;
        
            double regdouble = (norm) * (pow(2,exponent));
        
            printf("this is a regular double, of value %.17f  \n", regdouble);
            
            return regdouble;
        }
    
        if(numbertype == 0){
        
            double subm = (double)a.z/(pow(2,52) + 1.0);
        
            double subnorm = (subm) * (pow(2,-1022));
        
            printf("this is a subnomral double, of value %e \n", subnorm);
            
            return subnorm;
        }   
    
         if(numbertype == 1){
             
            printf("we have a NaN ! \n");
           
            return 0;
        }
    
        if(numbertype == 2) {
            
            printf("we have a + 0.0 \n");
            
            return 0.0;
        }
    
        if(numbertype ==3){
            
            printf("we have a + inf \n");
            
            return 0;
        }
        return -25;
    }
    return -25;   
}
void binaryprint(uint64_t bits){
    
    for(int i = 0; i < 64; i++){
       
       int a = bits>> (63-i) & 1; 
      
      
        printf("%d",a);
    }
    
    printf("\n \n");
}

uint64_t copydoubletoint(double source){
    uint64_t depositbox = 0;
    
    memcpy(&depositbox, &source, sizeof(source));
    
    return depositbox; 
}


SEM parsebits(double number){
    
    uint64_t ourbits = copydoubletoint(number);
    
    SEM d1;
    d1.a = ourbits; 
    d1.x = ourbits >> 63;
    d1.y = ourbits >> 52 & 0x7ff;
    d1.z = ourbits & 0xfffffffffffff;
    
    return d1;
}


void printbits(SEM b){

    binaryprint(b.a);
    
    printf("\nS = %" PRIu64 "\n", b.x);
    printf("E = %" PRIu64 "\n", b.y);
    printf("M = %" PRIu64 "\n", b.z);
   
}
    
void displaybehave(double figure){
    
    printf("\nCURRENT FIGURE = %.17f \n", figure);
    printf("Here are the bits stored in IEEE 754 format s-e-m  \n\n");
    SEM a = parsebits(figure);
    printbits(a);
    reconstructdoub(a);
    printf("_________________________________________________________________\n");
}

int main()
{
    double input1 = 0;
    double input2 = 0;
    
    printf("welcome to the Double Dicer Demo \n");
    
    printf("Enter Numerator : ");
    scanf("%lf", &input1);
    printf("Enter Denomninator : ");
    scanf("%lf", &input2);
    
    
    double INP = input1/input2;
    
   
    
    displaybehave(INP);
    
return 0;

}

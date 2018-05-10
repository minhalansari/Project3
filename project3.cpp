#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<cmath>
using std::sqrt;
#include<string>
using std::to_string; using std::string;
long divisor_sum(long number){ //calculates divisor sum of number
    long result = 0; //init result to 0
    long i; 
    for(i = 1; i <= sqrt(number);i++){ //for loop to interate through every number less than or equal to the square root of number checking
        if(number%i ==0){ //check if it is a divisor of number
            result +=i; //add to result
            if (i != number/i ){ //get acutal number
                result += number/i; //add to result
            } 
            
        }
    }
    return result; //return the result
}
long gcd(long first,long second){ //function to get the greatest common divisor of two numbers
    long small; 
    long result;
    if (first>second){ //if and else to check which number is smaller
        small = second;
        }
    else{
        small = first;
    }
    for(int n =1;n<=small;++n){ //for loop to interate through numbers smaller  than or equal to n
        if(first%n ==0 and second%n==0){ //checks if its a divisor of both numbers
            result = n;
        }
    }
    return result; //returns the largest
}
bool is_solitary(long argument){ //checks if the gcd of number and its divisor_sum is one
    long dsum = divisor_sum(argument);
    if(gcd(argument,dsum)==1){
        return true;
    }
    else{
        return false;
    }
}
string abIndex_friend(long ab_numerator, long ab_denominator, long f_pair){
  return to_string(ab_numerator) + "/" + to_string(ab_denominator) +
    ":" + to_string(f_pair);
}
string friendly_check(long integer, long limit){ //function to check if two numbers are friendly
    long gcdabun;
    long reducednumerator2;
    long reduceddenom2;
    long gcdabun2;
    gcdabun = gcd(divisor_sum(integer),integer); //get the gcd of the abundancancy index
    long reducednumerator;
    long reduceddenom;
    reducednumerator = divisor_sum(integer)/gcdabun; //divide the numerator by the gcd to reduce
    reduceddenom = integer/gcdabun; //divide the denomenator by the gcd to reduce
    for(long i=0; i<limit ;++i){ //for loop to look for friendly numbers
        gcdabun2 = gcd(divisor_sum(i),i);
        reducednumerator2 = divisor_sum(i)/gcdabun2;
        reduceddenom2 = i/gcdabun2; //reduce num and denom in same way
        if(reducednumerator2 == reducednumerator and reduceddenom2 ==  reduceddenom and i != integer){ //if statement to return and break if its a friendly number
            return abIndex_friend(reducednumerator, reduceddenom, i);
            break;
        }
    }
    if(reducednumerator2 != reducednumerator or reduceddenom2 != reduceddenom){ //if statement to return -1 if no friendly number
            return abIndex_friend(reducednumerator, reduceddenom, -1);
        }    
}
int main (){
  cout << boolalpha;   // print true or false for bools
  int test;
  cin >> test;
  switch (test) {
  case 1 : {   // divisor sum test
    long input;
    cin >> input;
    cout << divisor_sum(input) << endl;
    break;
  } // of case 1
  case 2:{    // gcd test
    long first, second;
    cin >> first >> second;
    cout << gcd(first, second) << endl;
    break;
  } // of case 2
  case 3: {    // is_solitary test
    long input;
    cin >> input;
    cout << is_solitary(input) << endl;
    break;
  } // of case 3
  case 4: {
     //friend check. Make sure the return value is the
     //result of calling abIndex_friend, a string!
     long input;
     long limit;
     cin >> input >> limit;
     cout << friendly_check(input, limit) << endl;
     break;
  } //of case 4
  } // of switch
} // of main

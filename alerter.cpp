#include <iostream>
#include <assert.h>
#include <string.h>

#define MAX_THRESHOLD 151

int alertFailureCount = 0;
std::string environment;

int networkAlertStub(float celcius) {
    int returnValue;
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    if (environment == "prd"){
        if(celcius > MAX_THRESHOLD){
            std::cout << "Maximum threshold for production is " << MAX_THRESHOLD << " celcius."<< std::endl;
            returnValue=500;
        }
        else{
            returnValue=200;
        }
    }
    else{
        // Return 200 for ok
        // Return 500 for not-ok
        // stub always succeeds and returns 200
        returnValue=200;
    }
    return returnValue;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
        assert (alertFailureCount > 0);
    }
}

int main(int argc, char* argv[]) {

    if(argc == 2){
        std::string env(argv[1]);
        assert (env == "test" || env == "prd");
        environment = env; 
    }
    else{
        std::cout << "Please run me by passing env test or prd only." << std::endl;
        return -1; 
    }

    alertInCelcius(400.5);
    alertInCelcius(303.6);

    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";

    return 0;
}

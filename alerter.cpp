#include "alerter.h"

int gloabl::alertFailureCount = 0;

int TestAlerter::networkAlertStub(float celcius) {
    std::cout << "TEST ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

int ProductionAlerter::networkAlertStub(float celcius) {
    std::cout << "PRD ALERT: Temperature is " << celcius << " celcius.\n";

    if(MAX_THRESHOLD > celcius) {
        return 200;
    }
    else {
        return 500;
    }
}

float Alerter::convertFarenheitToCelcius(const float farenheit) {
    return (farenheit - 32) * 5 / 9;
}

void Alerter::addFailure() {
    gloabl::alertFailureCount += 1;
}

void Alerter::validateFailureCount() {
    assert (gloabl::alertFailureCount > 0);
}

void Alerter::alertInCelcius(float farenheit) {
    float celcius = convertFarenheitToCelcius(farenheit);

    int returnCode = networkAlertStub(celcius);

    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        addFailure();
        validateFailureCount();
    }
}

int main() {
    //Run alerter in test environement
    Alerter *alerterObj = new TestAlerter();

    //Run alerter in production environement 
    //Alerter *alerterObj = new ProductionAlerter();
 
    alerterObj->alertInCelcius(400.5);
    alerterObj->alertInCelcius(303.6);
    alerterObj->alertInCelcius(303.8);

    std::cout << gloabl::alertFailureCount << " alerts failed.\n";
    std::cout << "All is well.\n";
    return 0;
}

#include<bits/stdc++.h>

#define MAX_THRESHOLD 151
namespace gloabl {
    extern int alertFailureCount;
};

class Alerter{

    public:
    float convertFarenheitToCelcius(const float farenheit);
    void alertInCelcius(float farenheit);
    void validateFailureCount();
    void addFailure();

    virtual int networkAlertStub(float celcius) = 0;
};

class TestAlerter : public Alerter {

    public:
    virtual int networkAlertStub(float celcius);
};

class ProductionAlerter : public Alerter {
    public: 
    virtual int networkAlertStub(float celcius);
};

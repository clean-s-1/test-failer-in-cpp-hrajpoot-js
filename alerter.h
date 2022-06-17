#include<bits/stdc++.h>

#define MAX_THRESHOLD 151
namespace gloabl {
    extern int alertFailureCount;
};

class Alerter{

    public:
    float convertFarenheitToCelcius(const float farenheit);
    void alertInCelcius(const float farenheit);
    void validateFailureCount();
    void addFailure();

    virtual int networkAlertStub(const float celcius) = 0;
};

class TestAlerter : public Alerter {

    public:
    int networkAlertStub(const float celcius) override;
};

class ProductionAlerter : public Alerter {
    public: 
    int networkAlertStub(const float celcius) override;
};

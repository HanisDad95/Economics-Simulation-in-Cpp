#include <iostream>
#include <vector>


enum class ConsumerPersonalities{
    HEDONIST,
    RATIONALIST,
    SAVER,
    HAND_TO_MOUTH
};

struct Consumer{
    ConsumerPersonalities cons_per;
    double wealth;
    double age;
    double c1;
    double c2;

    void decideConsumptionC1(){

    };

    void decideConsumptionC2(){

    };
    double subjectiveDiscFactor() {
        double disc_factor;
        switch (cons_per)
        {
        case ConsumerPersonalities::HEDONIST:
            disc_factor = 0.2;
            break;
        case ConsumerPersonalities::RATIONALIST:
            disc_factor = 0.8;
            break;
        case ConsumerPersonalities::SAVER:
            disc_factor = 0.95;
            break;
        case ConsumerPersonalities::HAND_TO_MOUTH:
        disc_factor = 0.0;
        break;
        
        default:
            break;
        };
        return disc_factor;
    };

};







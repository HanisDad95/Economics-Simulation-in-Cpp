// Consumer.hpp

enum class ConsumerPersonalities{HEDONIST,
    RATIONALIST,
    SAVER,
    HAND_TO_MOUTH};

struct Consumer{
    ConsumerPersonalities cons_per;
    double wealth, age, c1, c2;

    void decideConsumptionC1(){};
    void decideConsumptionC2(){};
    double subjectiveDiscFactor(){};
};


#include <iostream>
#include <vector>
#include <random>

struct producer
{
    double stock, labor_level, i_d_investment;

    producer() : stock(0.0),labor_level(0.0), i_d_investment(0.0) {};
    producer(double s, double ll, double idi): stock(s), labor_level(ll), i_d_investment(idi/50) {};
};

struct consumer
{
    int preference;
    double consumption_propension;
    
    consumer() : preference(0), consumption_propension(0.0) {};
    consumer(int p, double c) : preference(p), consumption_propension(c/10) {};
};

int main(){

    std::default_random_engine generator;
    std::uniform_real_distribution<double> investment_dist(0.1,50.0);
    std::uniform_real_distribution<double> consump_prop_dist(0.1,10.0);
    std::uniform_int_distribution<int> pref_dist(1, 5);

    int pop_size = 500000;
    int economy_size = 20;

    std::vector<consumer> consumers;
    consumers.reserve(pop_size);

    for (int i = 0; i < pop_size; i++){
        consumers.push_back(consumer(pref_dist(generator),consump_prop_dist(generator)));
    };
    
    double biggest_prop_c, prop_c_sum;

    if (consumers.size() > 0){
        biggest_prop_c = 0;
        prop_c_sum = 0;
        for (const consumer& person : consumers){
            prop_c_sum += person.consumption_propension;

            if (person.consumption_propension > biggest_prop_c){
                biggest_prop_c = person.consumption_propension;
            };
        };
        
        std::cout << "The market size is : " << consumers.size() << "\n";
        std::cout << "The biggest propensity consumption is : " << biggest_prop_c << "\n";
        std::cout << "The mean propensity consumption is : " << prop_c_sum/consumers.size() << "\n";   
    };

    return 0;
};

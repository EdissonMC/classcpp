
#include <iostream>
#include <map>



/*D EFINICION DE LA ABSTRACCION MEDIANTE UNA CLASE */

class FMRadio
{
public:
    FMRadio();
    FMRadio(double freq, int vol);

    double getFrequency();
    void setFrequency(double newFreq);

    int getVolume();
    void setVolume(int newVolume);

    void setPreset(int index, double freq);
    bool presetExits(int index);    
    double getPreset(int index);


private:
    
    void checkFrequeny(double freq);
    void checkPreset(int index);
    void FMRadio::initialize(double freq, int vol);
    
    double frequency;
    int volume;
    double presets[6];


};

//  Private function for help 
void FMRadio::initialize(double freq, int vol) {
    for(size_t i = 0; i < 6; ++i)
        presets[i] = 0.0; 
    frequency = 87.5; 
    volume = 5;
}


/* CONSTRUCTOR 1*/ 
FMRadio::FMRadio (){
    initialize(87.5, 5);
   
}


/* CONSTRUCTOR 2*/ 
FMRadio::FMRadio (double freq,  int vol){
     initialize(freq , vol);
}



double FMRadio::getFrequency() {
    return frequency;
}

void FMRadio::setFrequency(double newFreq) {
    checkFrequeny(newFreq);
    frequency = newFreq;
}

int FMRadio::getVolume(){
    return volume;
}

void FMRadio::setVolume (int newVol) {
    assert(newVol >=0 && newVol <=10);
    volume =  newVol;
}

void FMRadio::setPreset (int index, double freq) {

    checkPreset(index);
    checkFrequeny(freq);
    presets[index-1] = freq;
}


bool FMRadio::presetExits(int index) {
    checkPreset(index);
    return presets[index - 1] == 0.0; // -1 maps [1, 6] to [0, 5]
}


double FMRadio::getPreset (int index) {
    assert(presetExits(index) );
    return presets[index];
}


void FMRadio::checkFrequeny(double freq) {
    assert(freq>87.5 && freq<= 108.8);
}

void FMRadio::checkPreset(int index) {
    assert(index>=1 && index <= 6);
}


int main(){

    // way 1
    FMRadio myRadio;

    // way 2
    //FMRadio myRadio(88.5,  5);


     std::cout <<"la frecuencia : " << myRadio.getFrequency()<<std::endl;
    if (myRadio.presetExits(1)){
        std::cout <<"Preset 1: " << myRadio.getPreset(1) << std::endl;

    }else{
        std::cout << "Preset 1 no programmed " <<std::endl;
    }
    
}
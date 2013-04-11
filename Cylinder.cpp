#include "Cylinder.h"



 void Cylinder::Vibrate(){

    ///move the cylinder back and forth
    this->m_engine.SetPosition(this->m_engine.GetPosition()+30.0);
    this->m_engine.SetPosition(this->m_engine.GetPosition()-60.0);
    std::cout<<"\nI have got rid off the remaining material from the cylinder\n";
 }

 void Cylinder::GetMaterial(double weight){

    if (weight > this->GetMaxWeight()){
        std::cout<<"\nToo much to load!\n";
        std::cin>>weight;
    }


    ///Make the engine move
    double a = m_engine.Engine::GetAnVelocity();
    m_engine.SetPosition(a*3);
    md_weight=weight;


    std::cout<<"\nI have loaded "<<weight<<" of matherial\n";

 }

 void Cylinder::Unload(double weight){

        Cylinder::Empty();
        Vibrate();
        std::cout<<"\nI have unloaded the material\n";

    }

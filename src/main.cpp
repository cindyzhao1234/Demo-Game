#include "Engine.h"

int main(){
    Engine e;
    e.init(1280, 750, "engine demo");
    e.run();
    e.shutdown(); //only calls after run returns
}
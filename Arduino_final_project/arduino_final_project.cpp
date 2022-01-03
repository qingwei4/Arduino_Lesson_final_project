#include <MatrixMini.h>

void setup(){
    Mini.begin();
    Mini.RC3.set(0);
}

bool work = 0;
bool first = 0;
bool prev = 0;

void loop(){
    int val = Mini.BTN1.get();
    if(val && val != prev){
        first = !first;
    }
    if(first)work = 1;
    else work = 0;
    if(work){
        for(int i = 90 ; i <= 180 ; i++){
            Mini.RC3.set(i);
            delay(10);
        }
        delay(500);
        for(int i = 180 ; i >= 90 ; i--){
            Mini.RC3.set(i);
            delay(10);
        }
        delay(500);
    }
    else Mini.RC3.set(90);

    prev = val;
}

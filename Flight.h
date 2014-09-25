#ifndef _Flight_h
#define _Flight_h

int acc = 0;
int old_acc = 0;

void flight(){
    if(acc != old_acc){
        // Update motor speed if needed
        setMotor(0, acc);
        // Update las value of acc
        old_acc = acc;
    }
}

#endif

#ifndef _Stability_h
#define _Stability_h

// Pitch
double pitch = 0;
double pKp = 7, pKi = 0, pKd = 1.1,
      pOut = 0, pSet = 0;
PID* pController = new PID(&pitch, &pOut, &pSet, pKp, pKi, pKd, REVERSE);


// Stability initialization or Setup
void stabilitySetup(){
	pController->SetOutputLimits(-1000, 1000);
	pController->SetMode(AUTOMATIC);
}

// Stability Loop
void stability(){
    pController->Compute();
}

// Set PID values
void setPID(){
    pController->SetTunings(pKp, pKi, pKd);
}

#endif

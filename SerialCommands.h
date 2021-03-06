#ifndef _SerialCommands_h
#define _SerialCommands_h

// how much serial data we expect before a newline
#define MAX_INPUT 50

// Serial Comands functions
void command_motors(int i, int value){
  if(value > MOTOR_LOW && value < MOTOR_HIGH){
    motors[i].write(value);
    Serial.print("Set motor ");
    Serial.print(i);
    Serial.print(" to ");
    Serial.println(value);
  }else{
    Serial.println("Value out of range for motors");
  }
}

// Really basic parser for commands
void select_command(String command, String value){
  if(command == "motors0"){
    command_motors(0, value.toInt());
  }else if(command == "motors1"){
    command_motors(1, value.toInt());
  }else{
    Serial.println("Command not found");
  }
}

// here to process incoming serial data after a terminator received
void process_data (const char * data){
  String in = String(data);
  String command, value;
  int token = in.indexOf(':');

  if(token >= 0){
    command = in.substring(0,token);
    value = in.substring(token+1);
    select_command(command, value);
  }
}  // end of process_data
  
void processIncomingByte (const byte inByte){
  static char input_line[MAX_INPUT];
  static unsigned int input_pos = 0;

  switch (inByte){

    case ';':   // end of textx
      input_line [input_pos] = 0;  // terminating null byte
      
      // terminator reached! process input_line here ...
      process_data (input_line);
      
      // reset buffer for next time
      input_pos = 0;  
      break;

    case '\n':   // discard newline
      break;
    case '\r':   // discard carriage return
      break;

    default:
      // keep adding if not full ... allow for terminating null byte
      if (input_pos < (MAX_INPUT - 1))
        input_line [input_pos++] = inByte;
      break;

    }  // end of switch
   
  } // end of processIncomingByte  

void readSerialCommands(){
  // if serial data available, process it
  if (Serial.available () > 0)
    processIncomingByte (Serial.read());
    
  // do other stuff here like testing digital input (button presses) ...
}  // end of loop

#endif

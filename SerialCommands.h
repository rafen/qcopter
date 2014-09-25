#ifndef _SerialCommands_h
#define _SerialCommands_h

// how much serial data we expect before a newline
#define MAX_INPUT 50

#define COMMANDS_DEBUG_LEVEL 1


// Really basic parser for commands
void select_command(String command, String value){
  #if COMMANDS_DEBUG_LEVEL >= 1
      Serial.print(command);
      Serial.print(":");
      Serial.println(value);
  #endif

  if(command == "stop"){
    }else if(command == "acc"){
        acc = value.toInt();
    }else if(command == "p"){
        Kp = value.toInt();
    }else if(command == "i"){
        Ki = value.toInt();
    }else if(command == "d"){
        Kd = value.toInt();
    }else{
        #if COMMANDS_DEBUG_LEVEL >= 1
            Serial.println("Command not found");
        #endif
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
    }else{
        command = in;
        value = "";
    }
    select_command(command, value);
}

void processIncomingByte (const byte inByte){
    static char input_line[MAX_INPUT];
    static unsigned int input_pos = 0;

    switch (inByte){

        case ';':     // end of textx
            input_line [input_pos] = 0;    // terminating null byte

            // terminator reached! process input_line here ...
            process_data (input_line);

            // reset buffer for next time
            input_pos = 0;
            break;

        case '\n':     // discard newline
            break;
        case '\r':     // discard carriage return
            break;

        default:
            // keep adding if not full ... allow for terminating null byte
            if (input_pos < (MAX_INPUT - 1))
                input_line [input_pos++] = inByte;
            break;
    }
}

void readSerialCommands(){
    // if serial data available, process it
    if (Serial.available () > 0){
        processIncomingByte (Serial.read());
    }
}

#endif

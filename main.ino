/* Program Note
1.デフォルトでSDAとSCLをHIGHにする
2.通信したい指示が来たらSDAをLOWにする。
3.送信したい場合は送るデータ列を分解する？もしくは送信時にFIFOの先端を抜き出す
3.SCLがLOWかどうか調べる、LOWだったら
*/



//analogWrite only work on 3,5,6,9,11  on Atmega328P
uint8_t SCL_PIN = 3;
uint8_t SDA_PIN = 4;
//detect SCL clock. must connect to SCL pin.
uint8_t SCL_DETECT_PIN = 5;

bool clock_flag = false;

//for check pin clock that is high or low
bool previous_state = false;
bool now_state = false;

//PortD 0 to 7
//PortB 8 to 13
//PortC other analog pin

void setup(){
    //pinMode(SCL_PIN,OUTPUT);
    pinMode(SDA_PIN,OUTPUT);
    pinMode(SCL_DETECT_PIN,INPUT)
    //waiting start
    analogWrite(SCL_PIN,255);
}

void loop(){

}

void start_transfer(){
  analogWrite(SCL_PIN,128);
}

void end_transfer(){
  analogWrite(SCL_PIN,255);
}

//send i2c data without port register
void send_data(char data){
  int data_length = length of data;
  deigitalWrite(SDA_PIN,LOW);
  start_transfer();
  for(int length_count=0; length_count<data_length; length_cont++;)
  {
    for(uint8_t )
      //change bit statas
      while(clock_flag==false){
        check_clock_change();
      }
      if(data_bit==0){
        digitalWrite(SDA_PIN,LOW);
      }
      else{
        digitalWrite(SCL_PIN,HIGH);
      }
    }

}

//receive i2c data without port register
void receive_data(){
  end_transfer();
  digitalWrite(SDA_PIN,HIGH);

}

void check_clock_change(){
  //high is true, low is false
  now_state = digitalRead(SCL_DETECT_PIN);
  if(previous_state==now_state){
    clock_flag = false;
  }
  else{
    clock_flag = true;
  }
}

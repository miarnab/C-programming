#include<LiquidCrystal.h>             //including the lcd library
#include<SoftwareSerial.h>            //including the Software serial library to  define a 2nd rx and tx pin 					for gps

LiquidCrystal lcd(2,3,4,5,6,7);       //assigning the pin on arduino for lcd (rs,en,db4,db5,db6,db7) 					respectively

SoftwareSerial gps(8,9);              // RX, TX for gps. But only rx is required as gps isn't transmitting 					anything

				

int led=10;                           	// vaiable for led;assigning pin no. 10 for led

					

String gpsString="";                 	 	// variables for gps ; String to identify and store the $GPGGA line in the NMEA 					data;
const char *test="$GPGGA";                 	 //this will identify the $GPGGA string that contains the latitude and longitude
String latitude="NO RANGE      ";     	//initially latitude will contain no range
String longitude="NO RANGE     ";     	//same
String Time="NOT AVAILABLE";         	 //same
int temp=0,i;                        	//temp will be used as a variable to activate the msg sending 					process of arduino on command;i used for loop
boolean gps_status=0;                 		//will tell if the gps has got satellite feed

void setup() 
{
  lcd.begin(16,2);                  	//begining the 16x2 lcd
  Serial.begin(9600);             	  //beginning the serial port where gsm is connected and giving the 				baud rate
  gps.begin(9600);                  //beginning the gps serial port(pin 8,9) through where gps will tx and rx 				data
  pinMode(led,OUTPUT);              //setting pin no. 10 as output
  
  lcd.print("::INITIALISING::");   		 //printing on lcd
  lcd.setCursor(0,1);
  lcd.print("::::::::::::::::");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("VEHICLE TRACKING");
  lcd.setCursor(0,1);
  lcd.print(":::::SYSTEM::::::");
  delay(2000);
  gsm_init();                    			 //calling the gsm_init fxn.Now jump to line number:130
  lcd.clear();
  Serial.println("AT+CNMI=2,2,0,0,0");    		//tell the gsm module that we are expecting to 							receive a text message through this command
  lcd.print("GPS INITIALISING");          	//printing
  lcd.setCursor(0,1);
  lcd.print("GPS FINDING FIX ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("  PLEASE WAIT   ");
  delay(1000);
  get_gps();                          		//calling the get_gps fxn. now jump to line no:202
  delay(2000);
  lcd.clear();
  lcd.print(":SATTELITE FEED:");
  lcd.setCursor(0,1);
  lcd.print("::::::FOUND:::::");
  delay(1500);
  lcd.clear();
  lcd.print("**SYSTEM READY**");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("*ENTER  COMMAND*");
  lcd.setCursor(0,1);
  lcd.print("***************");
  digitalWrite(led,HIGH);
  delay(1000);
  temp=0;       
}

void loop()
{
  serialEvent();
  if(temp)
  {
    get_gps();
    tracking();
  }
}

void serialEvent()
{
  while(Serial.available())
  {
    if(Serial.find((char*)"Track Vehicle"))
    {
      temp=1;
      break;
    }
    else
    temp=0;
  }
}


void gpsEvent()			//defining gpsEvent function
{
  gpsString="";                 		//empty the string that will contain the gpgga sentence
  while(1)
  {
   while (gps.available()>0)            //this loop will work only when gps data is available
   {                                      								 
    char location = (char)gps.read();         //typecasting the integer data available on gps port(pin 8,9) 					to char type and storing in location
     gpsString+= location;            //gps.read()gives on char at a tym.,so location will contain one 					char..now append the location on gpsString 1by1
     i++;
     if (i < 7)                      
     {
      if(gpsString[i-1] != test[i-1])         //checking for $GPGGA sentence
      {
        i=0;
        gpsString="";
      }
     }
    if(location=='\r')
    {
     if(i>65)
     {
       gps_status=1;
       break;
     }
     else
     {
       i=0;
     }
    }
  }
   if(gps_status)
    break;
  }
}

					
void gsm_init()                                       	//defining the gsm_init fxn
{
  lcd.clear();
  lcd.print("**FINDING**GSM**");
  lcd.setCursor(0,1);
  lcd.print("****************");
  boolean flag=1;                   		  //setting a trigger
  while(flag)                        		 //till the trigger is on
  {
    Serial.println("AT");           		//checking for AT commands.This will tell that the gsm is 					ready for action
    while(Serial.available()>0)     		//this condition makes sure that it will wait for the reply 					from the gsm
    {
      if(Serial.find((char*)"OK"))        	 //if gsm sends ok in reply to AT send before then turn of the 						trigger in next line
      flag=0;
    }
    
    delay(1000);
  }

  lcd.clear();                      			//start printing on the lcd that gsm is ready
  lcd.print(" ***GSM READY***");
  lcd.setCursor(0,1);
  lcd.print("****************");
  lcd.setCursor(0,0);
  delay(1000);

  					
  lcd.clear();				//disabling echo
  lcd.print("DISABLING ECHO");
  int echo=1;                    			 //setting trigger for echo
  while(echo)                         		//till the trigger is on
  {
    Serial.println("ATE0");          		 //commanding the gsm to turn of echo
    while(Serial.available())     		  //till serial port gets a reply from the gsm
    {
      if(Serial.find((char*)"OK"))           	//if gsm sends ok in response to echo off command through 						serial port then turn of the trigger
      echo=0;
    }
    delay(1000);
  }

  lcd.clear();
  lcd.print("**ECHO DISABLED**");         //print echo is disabled
  lcd.setCursor(0,1);
  lcd.print("****************");
  lcd.setCursor(0,0);
  delay(1000);
  lcd.clear();

 						 //finding network
  
  lcd.print("FINDING NETWORK");
  boolean net=1;                              		//trigger for network
  while(net)                                  			//while trigger is on
  {
    Serial.println("AT+CPIN?");              	 	//ask for status of network to gsm
    while(Serial.available()>0)               		//if reply is available
    {
      if(Serial.find((char*) "+CPIN: READY"))         	//if gsm sends reply that network is ready turn of 							trigger
      net=0;                                          
    }
    delay(1000);
  }
  lcd.clear();
  lcd.print(":NETWORK  FOUND:");                	//print network found
  lcd.setCursor(0,1);
  lcd.print("::::::::::::::::");
  lcd.setCursor(0,0);
  delay(1000);
  lcd.clear();                                  			//now go back to line no:38
}

						

void get_gps()  			//defining the get_gps function
{
   gps_status=0;                        //initiate status of the gps.gps_Status stores whether there is sattelite 				connection or not.1=yes,0=no.
   int x=0;                             	//take a loop counter
   while(gps_status==0)                 //till there is no sattelite connection,ie, it is not getting data this loop will work
   {
    gpsEvent();                        	 //call the gpsEvent fxn..jump to line 92
    int lenth=i;                        	//storing length of the gpsString  
    Time="";                            	//flushing
    latitude="";                       	 //same
    longitude="";
    int comma=0;
    while(x<lenth)
    {
      if(gpsString[x]==',')
      comma++;
      if(comma==1)          			//extract tym
      Time+=gpsString[x+1];
      else if(comma==2)        		//extract latitude from string
      latitude+=gpsString[x+1];     
      else if(comma==4)        		//extract longitude from string
      longitude+=gpsString[x+1];
      x++;
    }

    int l1=Time.length();     
    Time[l1-1]=' ';
    l1=latitude.length();
    latitude[l1-1]=' ';
    l1=longitude.length();
    longitude[l1-1]=' ';

    
    
    lcd.clear();
    lcd.print(" TIME(-5:30 IST):  ");
    lcd.setCursor(0,1);
    lcd.print("   ");
    lcd.print(Time);
    lcd.print("   ");
    delay(1000);
    lcd.clear();
    
    lcd.print("   LATITUDE:");
    lcd.setCursor(0,1);
    lcd.print("   ");
    lcd.print(latitude);
    lcd.print("   ");
    delay(1500);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("   LONGITUDE:");
    lcd.setCursor(0,1);
    lcd.print("   ");
    lcd.print(longitude);
    lcd.print("   ");
    i=0;x=0;
    lenth=0;
    delay(2000);
    
   }
}

void init_sms()
{
  Serial.println("AT+CMGF=1");          			//command to set gsm in sms sending mode
  delay(400);
  Serial.println("AT+CMGS=\"+919062116777\"");  	 // use your 10 digit cell no. here
  delay(400);
}

void send_data(String message)
{
  Serial.println(message);
  delay(200);
}

void send_sms()
{
  Serial.write(26);  		 //26 is the ASCII CODE for ctrl+z which is used to send a sms; this 				particular line will send the text to the registered number.
}

void lcd_status()
{
  lcd.clear();
  lcd.print("**Message Sent**");
  lcd.setCursor(0,1);
  lcd.print("****************");
  delay(2000);
  lcd.clear();
  lcd.print("*ENTER**COMMAND*");
  lcd.setCursor(0,1);
  lcd.print("****************");
  return;
}

void tracking()
{
    init_sms();
    send_data("VEHICLE TRACKING REQUEST ALERT:");
    send_data("Current Location of the vehicle is:");
    Serial.print("LATITUDE:");
    send_data(latitude);  
    Serial.print("LONGITUDE:");
    send_data(longitude);
    send_data("Please recover me quickly.......");
    send_sms();
    delay(2000);
    lcd_status();
}

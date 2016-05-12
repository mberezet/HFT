/*
 * Userspace program that communicates with the led_vga device driver
 * primarily through ioctls
 *
 * Stephen A. Edwards
 * Columbia University
 */

#include <stdio.h>
#include "vga_led.h"
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <dirent.h>
#include "usbkeyboard.h"
#include <pthread.h>

struct libusb_device_handle *openkeyboard(uint8_t *endpoint_address);
void *keyboard_thread_f(void *);



int vga_led_fd;

int transmitFlag=0;
int continueTransmitFlag=0;
int breakFlag=0;

#define currencyNumber 5

double getRate(char * tempLine);
void getSouDes(char *filename, int * tSou, int *tDes);

char * currency[currencyNumber]={"USD","EUR","CAD","GBP","NZD"};
int message[VGA_LED_DIGITS] = {0};


/* Read and print the segment values */
void print_segment_info() {
  vga_led_arg_t vla;
  int i;

  for (i = 0 ; i < VGA_LED_DIGITS ; i++) {
    vla.digit = i;
    if (ioctl(vga_led_fd, VGA_LED_READ_DIGIT, &vla)) {
      perror("ioctl(VGA_LED_READ_DIGIT) failed");
      return;
    }
    printf("%02x ", vla.segments);
    //printf("%d ", vla.segments);
  }
  printf("\n");
}

/* Write the contents of the array to the display */
void write_segments(int segs[VGA_LED_DIGITS])
{
  vga_led_arg_t vla;
  int i;
  for (i = 0 ; i < VGA_LED_DIGITS ; i++) {
    vla.digit = i;
    vla.segments = segs[i];
    if (ioctl(vga_led_fd, VGA_LED_WRITE_DIGIT, &vla)) {
      perror("ioctl(VGA_LED_WRITE_DIGIT) failed");
      return;
    }
  }

}

void new_write_segments(int segs, int i)
{
    vga_led_arg_t vla;
    
    vla.digit = i;
    vla.segments = segs;
    if (ioctl(vga_led_fd, VGA_LED_WRITE_DIGIT, &vla)) {
        perror("ioctl(VGA_LED_WRITE_DIGIT) failed");
        return;
    }
}


//
int main()
{
    
    
    
    char dir[] = "original_data/";
    FILE *fp_name;
    char CSV_file_name[100][20];
    int fileNumber=0;
    
    system("cd original_data/\nls *.csv > CSV_file_name.txt");
    fp_name=fopen("original_data/CSV_file_name.txt","r");
    while(1){
        if ( fgets(CSV_file_name[fileNumber],20,fp_name)==NULL) break;
        CSV_file_name[fileNumber][strlen(CSV_file_name[fileNumber])-1]='\0';
        printf("%s\n",CSV_file_name[fileNumber]);
        fileNumber++;
    }
    fclose(fp_name);
    
    
    FILE *fp[100];
    int sou[100]={0};
    int des[100]={0};

    int source_number;
    
    int n;
    int tempSou,tempDes;
    char fileNameTemp[50]={'\0'};
    for(n=0;n<fileNumber;n++){
        strcpy(fileNameTemp,dir);
        strcat(fileNameTemp,CSV_file_name[n]);
        fp[n]=fopen(fileNameTemp, "rb");
        printf("path: %s\n",fileNameTemp);
        getSouDes(CSV_file_name[n],&(sou[n]),&(des[n]));
	
        printf("sou: %d  des: %d\n",sou[n],des[n]);
/*	
if(n==0){
	   source_number=sou[n];
	   printf("source_number: %d\n",source_number);
	}
*/
    }
    




  vga_led_arg_t vla;
  int i;
  static const char filename[] = "/dev/vga_led";

//  static int message[VGA_LED_DIGITS] = {0};

  

  printf("VGA LED Userspace program started\n");

  if ( (vga_led_fd = open(filename, O_RDWR)) == -1) {
    fprintf(stderr, "could not open %s\n", filename);
    return -1;
  }

  printf("initial state: ");
  print_segment_info();

  write_segments(message);

  printf("current state: ");
  print_segment_info();

  pthread_t keyboard_thread;
  pthread_create(&keyboard_thread, NULL, keyboard_thread_f, NULL);
    
  int rate[currencyNumber][currencyNumber]={0};
 /*
  int fake_rate[currencyNumber][currencyNumber]={{0,100,0,0,0,0,0},
						 {0,0,200,0,0,-1200,100},
						 {0,0,0,200,0,0,0},
						 {0,0,0,0,100,0,0},
						 {0,0,-1300,0,0,0,0},
						 {0,0,0,0,0,0,100},
						 {0,100,0,0,0,0,0}};

 */
  int total_running_time=1;
  int running_times=0;
  int ii=1;
  int jj=1;
  while(breakFlag!=1){
      if(continueTransmitFlag==1||transmitFlag==1){
          if(transmitFlag==1){
              transmitFlag=0;
          }
          char tempLine[200]={'\0'};
          double tempData;
          int logData;
          for(n=0;n<fileNumber;n++){
              fscanf(fp[n],"%s",tempLine);
              tempData=getRate(tempLine);
              logData=(int)(-log10(tempData)*1000000);
              rate[sou[n]][des[n]]=logData;
              //printf("sou: %d, des: %d, rate: %d\n",sou[n],des[n],rate[sou[n]][des[n]]);
              rate[des[n]][sou[n]]=-logData;
              //printf("sou: %d, des: %d, rate: %d\n",des[n],sou[n],rate[des[n]][sou[n]]);
          }
          
          int row,col;
          for(row=0;row<currencyNumber;row++){
              for (col=0;col<currencyNumber;col++){
		  if(rate[row][col]!=0&&col!=0){
	                  message[0]=(row<<7)+col;
	                  printf("%x :",message[0]);
	                  message[1]=rate[row][col];
			  //message[1] = fake_rate[row][col];
	                  printf("%d \n",message[1]);
			  new_write_segments(message[0],0);
	                  new_write_segments(message[1],1);
			  usleep(100000);
		  }
		  /*
                  message[0]=row;
                  message[1]=col;
		  if(col%2!=0) message[3]=37;
		  else 
		  {message[3]=ii;
		  ii++;
			}
		  if(ii==7) ii=1;
		  
                  //message[3]=row*5+col+ii;
			
                  new_write_segments(message[0],0);
                  new_write_segments(message[1],1);
                  new_write_segments(message[3],3);
                  
                  if(message[2]!=0){
                      message[2]=0;
                  }
                   
		  */

              }
              //printf("\n");
          }
          
          //usleep(1000000);
      }
  }
    
    /* Terminate the keyboard thread */
    pthread_cancel(keyboard_thread);
    
    /* Wait for the keyboard thread to finish */
    pthread_join(keyboard_thread, NULL);
      
    for(n=0;n<fileNumber;n++){
        fclose(fp[n]);
    }
    
  printf("current state: ");
  print_segment_info();

	printf("\n");
	printf("\n");

  printf("VGA LED Userspace program terminating\n");

  return 0;
}

void getSouDes(char *filename, int * tSou, int *tDes){
    char temp[4]={'\0'};
    int i,j;
    for(i=0;i<3;i++){
        temp[i]=filename[i];
    }
    
    for(j=0;j<currencyNumber;j++){
        if(strcmp(temp,currency[j])==0){
            *tSou =j;
            break;
        }
    }
    if(j==currencyNumber){
        printf("getSou error!\n");
    }
    for(i=4;i<7;i++){
        temp[i-4]=filename[i];
    }
    
    for(j=0;j<currencyNumber;j++){
        if(strcmp(temp,currency[j])==0){
            *tDes =j;
            break;
        }
    }
    if(j==currencyNumber){
        printf("getDes error!\n");
    }
}


double getRate(char * tempLine){
    double rate;
    int j,commaNumber=0,k=0;
    char tempNumber[20]={'\0'};
    for(j=0;j<strlen(tempLine);j++){
        if(tempLine[j]==','){
            commaNumber++;
            continue;
        }
        if(commaNumber==5){
            tempNumber[k]=tempLine[j];
            k++;
        }
        if(commaNumber==6){
            break;
        }
    }
    
    rate=atof(tempNumber);
    
    return rate;
}

void *keyboard_thread_f(void *ignored)
{
    struct libusb_device_handle *keyboard;
    uint8_t endpoint_address;

    struct usb_keyboard_packet packet;
    int transferred;
    char keystate[12];

    /* Open the keyboard */
    if ( (keyboard = openkeyboard(&endpoint_address)) == NULL ) {
        fprintf(stderr, "Did not find a keyboard\n");
        exit(1);
    }

    for (;;) {
        libusb_interrupt_transfer(keyboard, endpoint_address,
                                  (unsigned char *) &packet, sizeof(packet),
                                  &transferred, 0);
        if (transferred == sizeof(packet)) {
            sprintf(keystate, "%02x %02x %02x", packet.modifiers, packet.keycode[0],
                    packet.keycode[1]);
                    printf("%s\n", keystate);
            
            switch (packet.keycode[0]) {
                case 0x2C:  //space
                    transmitFlag=1;
                    break;
                case 0x1E:  //1
                    continueTransmitFlag=1;
                    break;
                case 0x1F:  //2
                    continueTransmitFlag=0;
                    break;
                case 0x20:  //3
                    breakFlag=1;
                    break;
        	case 0x28:  //enter
		    message[2]=3;
            new_write_segments(message[2],2);
		    break;
                case 0x51:  //dowm arrow
		    message[2]=2;
            new_write_segments(message[2],2);
		    break;
                case 0x52:  //up arrow
                    message[2]=1;
                    new_write_segments(message[2],2);
		    break;
		case 0x29:  //ESC
		    message[2]=4;
            new_write_segments(message[2],2);
		    break;
		case 0x00:  // release
   		    message[2]=0;
            new_write_segments(message[2],2);
			break;
                default:
                    break;
            }

            

             
        
        }
    }

    
    return NULL;
}


struct libusb_device_handle *openkeyboard(uint8_t *endpoint_address) {
    libusb_device **devs;
    struct libusb_device_handle *keyboard = NULL;
    struct libusb_device_descriptor desc;
    ssize_t num_devs, d;
    uint8_t i, k;
    
    /* Start the library */
    if ( libusb_init(NULL) < 0 ) {
        fprintf(stderr, "Error: libusb_init failed\n");
        exit(1);
    }
    
    /* Enumerate all the attached USB devices */
    if ( (num_devs = libusb_get_device_list(NULL, &devs)) < 0 ) {
        fprintf(stderr, "Error: libusb_get_device_list failed\n");
        exit(1);
    }
    
    /* Look at each device, remembering the first HID device that speaks
     the keyboard protocol */
    
    for (d = 0 ; d < num_devs ; d++) {
        libusb_device *dev = devs[d];
        if ( libusb_get_device_descriptor(dev, &desc) < 0 ) {
            fprintf(stderr, "Error: libusb_get_device_descriptor failed\n");
            exit(1);
        }
        
        if (desc.bDeviceClass == LIBUSB_CLASS_PER_INTERFACE) {
            struct libusb_config_descriptor *config;
            libusb_get_config_descriptor(dev, 0, &config);
            for (i = 0 ; i < config->bNumInterfaces ; i++)
                for ( k = 0 ; k < config->interface[i].num_altsetting ; k++ ) {
                    const struct libusb_interface_descriptor *inter =
                    config->interface[i].altsetting + k ;
                    if ( inter->bInterfaceClass == LIBUSB_CLASS_HID &&
                        inter->bInterfaceProtocol == USB_HID_KEYBOARD_PROTOCOL) {
                        int r;
                        if ((r = libusb_open(dev, &keyboard)) != 0) {
                            fprintf(stderr, "Error: libusb_open failed: %d\n", r);
                            exit(1);
                        }
                        if (libusb_kernel_driver_active(keyboard,i))
                            libusb_detach_kernel_driver(keyboard, i);
                        //libusb_set_auto_detach_kernel_driver(keyboard, i);
                        if ((r = libusb_claim_interface(keyboard, i)) != 0) {
                            fprintf(stderr, "Error: libusb_claim_interface failed: %d\n", r);
                            exit(1);
                        }
                        *endpoint_address = inter->endpoint[0].bEndpointAddress;
                        goto found;
                    }
                }
        }
    }
    
found:
    libusb_free_device_list(devs, 1);
    
    return keyboard;
}



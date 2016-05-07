import sys, os, time #system
import fcntl, termios, ctypes #ioctl
import csv, linecache #CSV
import math

DECIMAL_PLACES = 1000000
DRIVER_FILE = "/dev/forex_driver"

currencies = {}

edges = [(0, 1, 1),
         (1, 2, 2),
         (2, 3, 2),
         (3, 4, 1),
         (4, 2, -13),
         (1, 5, -9),
         (5, 6, 1),
         (6, 1, 1)]

class driver_arg_t(ctypes.Structure):
    _fields_ = [
        ('w', ctypes.c_int),
        ('src', ctypes.c_uint),
        ('dst', ctypes.c_uint),
    ]

def main(path):
    driver_fd = open(DRIVER_FILE)
    hash_i = 0
    row = 0
    driver_args = driver_arg_t()
    while 1:
        #for fn in os.listdir(path):
               #print "READING: " + fn
            #try:
                #Take in input
                '''
                pair = fn.split('_')[2]
                if(not pair[:3] in currencies):
                    currencies[pair[:3]] = hash_i
                    hash_i += 1

                if(not pair[3:6] in currencies): 
                    currencies[pair[3:6]] = hash_i
                    hash_i +=  1

                src = currencies[pair[:3]]
                dst = currencies[pair[3:6]]
                line = linecache.getline(path+"/"+fn, row)
                tick = csv.reader(line.splitlines())
                tick_arr = next(tick)
                #Do some maths
                rate = float(tick_arr[len(tick_arr) - 2]) #For testing -1, but in reality -2
                op_rate =  -1*math.log(rate, 10) * DECIMAL_PLACES
                round_int = int(op_rate)
                '''
                #Data Struct
                driver_args.src = edges[row][0]#src
                driver_args.dst = edges[row][1]#dst
                driver_args.w = edges[row][2]#round_int
                #print "Writing..."
                #print "Row: " + str(row)
                #print "Src: " + str(driver_args.src)
                #print "Dst: " + str(driver_args.dst)
                #print "W: " + str(driver_args.w)
                fcntl.ioctl(driver_fd, 0, driver_args) #check for ref or not
                #driver_args.src = dst
                #driver_args.dst = src
                #driver_args.w = -1*round_int
                #fcntl.ioctl(driver_fd, 0, driver_args) #check for ref or not
                time.sleep(0.01) #Wait 1000 ms
            #except:
            #    print "Error"

                row = row + 1
                print "Row:" + str(row)
                if(row == 8):
                    print "ALL DONE" 
                    return

if __name__ == "__main__":
    if (len(sys.argv) == 2):
        main(sys.argv[1])

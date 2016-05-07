import sys, os, time #system
import fcntl, termios, ctypes #ioctl
import csv, linecache #CSV

DECIMAL_PLACES = 1000
DRIVER_FILE = "/dev/forex_driver"

currencies = {}

edges = [(0, 1, 4),
         (1, 2, 3),
         (2, 3, 4),
         (3, 4, -7),
         (4, 1, -9)]

class driver_arg_t(ctypes.Structure):
    _fields_ = [
        ('w', ctypes.c_int),
        ('src', ctypes.c_uint),
        ('dst', ctypes.c_uint),
    ]

def main(path):
    driver_fd = open(DRIVER_FILE)
    hash_i = 0
    row = 1
    driver_args = driver_arg_t()
    while 1:
        for fn in os.listdir(path):
            #try:
                print "Taking in some data"
                #Take in input
                pair = fn.split('_')[2]
                if(!currencies[pair[:3]]) currencies[pair[:3]] = hash_i
                if(!currencies[pair[3:6]]) currencies[pair[3:6]] = hash_i + 1
                hash_i = hash_i + 2
                src = currencies[pair[:3]]
                dst = currencies[pair[3:6]]
                line = linecache.getline(path+"/"+fn, row)
                tick = csv.reader(line.splitlines())
                tick_arr = next(tick)
                #Do some maths
                rate = float(tick_arr[len(tick_arr) - 1]) #For testing -1, but in reality -2
                op_rate = rate * DECIMAL_PLACES#-1 * math.log(rate, 2) * DECIMAL_PLACES
                round_int = int(op_rate)
                #Data Struct
                driver_args.src = src
                driver_args.dst = dst
                driver_args.w = round_int
                print "Writing..."
                print "Src: " + str(driver_args.src)
                print "Dst: " + str(driver_args.dst)
                print "W: " + str(driver_args.w)
                fcntl.ioctl(driver_fd, 0, driver_args) #check for ref or not
                time.sleep(1) #Wait 1000 ms
            #except:
            #    print "Error"

        row = row + 1
        if(row == 300): return

if __name__ == "__main__":
    if (len(sys.argv) == 2):
        main(sys.argv[1])

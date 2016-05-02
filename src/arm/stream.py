import sys, os, time #system
import fcntl, termios, ctypes #ioctl
import csv, linecache #CSV

DECIMAL_PLACES = 10
DRIVER_FILE = "/dev/forex_driver"

currencies = {"EUR" : 0,
              "AUD" : 1,
              "CHF" : 2}

class driver_arg_t(ctypes.Structure):
    _fields_ = [
        ('w', ctypes.c_int),
        ('src', ctypes.c_uint),
        ('dst', ctypes.c_uint),
    ]

def main(path):
    driver_fd = open(DRIVER_FILE)
    row = 1
    driver_args = driver_arg_t()
    while 1:
        for fn in os.listdir(path):
            try:
                print "Taking in some data"
                #Take in input
                pair = fn.split('_')[2]
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
                driver_args.w = round_int
                driver_args.src = src
                driver_args.dst = dst
                print "Going to write now"
                fcntl.ioctl(driver_fd, 0, driver_args) #check for ref or not
                time.sleep(1) #Wait 1000 ms
            finally:
                if (row < 20) : print "All Done..."
                else : print "ERROR!"
                return

            row = row + 1
            if(row > 0): return

if __name__ == "__main__":
    if (len(sys.argv) == 2):
        main(sys.argv[1])

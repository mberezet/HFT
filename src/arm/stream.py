import sys, os, time #system
import fcntl, termios, ctypes #ioctl
import csv #CSV

DECIMAL_PLACES = 10
DRIVER_FILE = "/dev/forex_driver"

currencies = {"USD" : 1,
              "EUR" : 2,
              "AUD" : 3,
              "JPY" : 4,
              "GBP" : 5,
              "CHF" : 6}

class operation_arg(ctypes.Structure):
    _fields_ = [
        ('w', ctypes.c_int),
        ('src', ctypes.c_uint),
        ('dst', ctypes.c_uint),
    ]

def main(path):
    driver_fd = open(DRIVER_FILE, 'rw')
    row = 0;
    driver_args = operation_args()
    while 1:
        for fn in os.listdir(path):
            if os.path.isfile(fn):
                try:
                    pair = fn.split('_')[2];
                    src = currencies[pair[:3]]
                    dst = currencies[pair[3:6]]
                    line = linecache.getline(path+fn, row)
                    tick = csv.reader(line)
                    rate = float(tick[len(tick) - 1])
                    op_rate = -1 * math.log(rate, 2) * DECIMAL_PLACES
                    round_int = int(op_rate)
                    driver_args.w = round_int
                    driver_args.src = src
                    driver_args.dst = dst
                    fnctl.ioct(driver_fd, termios.TIOCGPGRP, driver_args)
                    time.usleep(0.1); #Wait 100 ms
                finally:
                    print "All Done..."
                    break

            row += 1




if __name__ == "__main__":
    if (len(sys.argv) == 2):
        main(sys.argv[1])

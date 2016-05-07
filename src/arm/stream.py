import sys, os, time #system
import fcntl, termios, ctypes #ioctl
import csv, linecache #CSV

DECIMAL_PLACES = 1000
DRIVER_FILE = "/dev/forex_driver"

currencies = {"AED" : 1,
            "AFN" : 2,
            "ALL" : 3,
            "AMD" : 4,
            "ANG" : 5,
            "AOA" : 6,
            "ARS" : 7,
            "AUD" : 8,
            "AWG" : 9,
            "AZN" : 10,
            "BAM" : 11,
            "BBD" : 12,
            "BDT" : 13,
            "BGN" : 14,
            "BHD" : 15,
            "BIF" : 16,
            "BMD" : 17,
            "BND" : 18,
            "BOB" : 19,
            "BRL" : 20,
            "BSD" : 21,
            "BTN" : 22,
            "BWP" : 23,
            "BYR" : 24,
            "BZD" : 25,
            "CAD" : 26,
            "CDF" : 27,
            "CHF" : 28,
            "CLP" : 29,
            "CNY" : 30,
            "COP" : 31,
            "CRC" : 32,
            "CUC" : 33,
            "CUP" : 34,
            "CVE" : 35,
            "CZK" : 36,
            "DJF" : 37,
            "DKK" : 38,
            "DOP" : 39,
            "DZD" : 40,
            "EGP" : 41,
            "ERN" : 42,
            "ETB" : 43,
            "EUR" : 44,
            "FJD" : 45,
            "FKP" : 46,
            "GBP" : 47,
            "GEL" : 48,
            "GGP" : 49,
            "GHS" : 50,
            "GIP" : 51,
            "GMD" : 52,
            "GNF" : 53,
            "GTQ" : 54,
            "GYD" : 55,
            "HKD" : 56,
            "HNL" : 57,
            "HRK" : 58,
            "HTG" : 59,
            "HUF" : 60,
            "IDR" : 61,
            "ILS" : 62,
            "IMP" : 63,
            "INR" : 64,
            "IQD" : 65,
            "IRR" : 66,
            "ISK" : 67,
            "JEP" : 68,
            "JMD" : 69,
            "JOD" : 70,
            "JPY" : 71,
            "KES" : 72,
            "KGS" : 73,
            "KHR" : 74,
            "KMF" : 75,
            "KPW" : 76,
            "KRW" : 77,
            "KWD" : 78,
            "KYD" : 79,
            "KZT" : 80,
            "LAK" : 81,
            "LBP" : 82,
            "LKR" : 83,
            "LRD" : 84,
            "LSL" : 85,
            "LYD" : 86,
            "MAD" : 87,
            "MDL" : 88,
            "MGA" : 89,
            "MKD" : 90,
            "MMK" : 91,
            "MNT" : 92,
            "MOP" : 93,
            "MRO" : 94,
            "MUR" : 95,
            "MVR" : 96,
            "MWK" : 97,
            "MXN" : 98,
            "MYR" : 99,
            "MZN" : 100,
            "NAD" : 101,
            "NGN" : 102,
            "NIO" : 103,
            "NOK" : 104,
            "NPR" : 105,
            "NZD" : 106,
            "OMR" : 107,
            "PAB" : 108,
            "PEN" : 109,
            "PGK" : 110,
            "PHP" : 111,
            "PKR" : 112,
            "PLN" : 113,
            "PYG" : 114,
            "QAR" : 115,
            "RON" : 116,
            "RSD" : 117,
            "RUB" : 118,
            "RWF" : 119,
            "SAR" : 120,
            "SBD" : 121,
            "SCR" : 122,
            "SDG" : 123,
            "SEK" : 124,
            "SGD" : 125,
            "SHP" : 126,
            "SLL" : 127,
            "SOS" : 128,
            "SPL*" : 129,
            "SRD" : 130,
            "STD" : 131,
            "SVC" : 132,
            "SYP" : 133,
            "SZL" : 134,
            "THB" : 135,
            "TJS" : 136,
            "TMT" : 137,
            "TND" : 138,
            "TOP" : 139,
            "TRY" : 140,
            "TTD" : 141,
            "TVD" : 142,
            "TWD" : 143,
            "TZS" : 144,
            "UAH" : 145,
            "UGX" : 146,
            "USD" : 147,
            "UYU" : 148,
            "UZS" : 149,
            "VEF" : 150,
            "VND" : 151,
            "VUV" : 152,
            "WST" : 153,
            "XAF" : 154,
            "XCD" : 155,
            "XDR" : 156,
            "XOF" : 157,
            "XPF" : 158,
            "YER" : 159,
            "ZAR" : 160,
            "ZMW" : 161,
            "ZWD" : 162}

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
    row = 1
    driver_args = driver_arg_t()
    while 1:
        for fn in os.listdir(path):
            #try:
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

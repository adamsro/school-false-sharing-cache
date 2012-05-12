import os
#import system

def main():
	for i in range(0, 64,2):
		os.system("g++ -g -DNUMT=4 -DNUM=%d -o main main.cpp -fopenmp -lm" % (i))
		os.system("./main")
		#os.system("./main >& out4t.out")

if __name__ == "__main__":
    main()

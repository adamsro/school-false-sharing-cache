import os

def main():
	for i in range(1, 64,2):
		os.system("g++ -g -DNUMT=1 -DNUM=%d -o main main.cpp -fopenmp -lm" % (i))
		os.system("./main >> out1t.out")
	for i in range(1, 64,2):
		os.system("g++ -g -DNUMT=2 -DNUM=%d -o main main.cpp -fopenmp -lm" % (i))
		os.system("./main >> out2t.out")
	for i in range(1, 64,2):
		os.system("g++ -g -DNUMT=4 -DNUM=%d -o main main.cpp -fopenmp -lm" % (i))
		os.system("./main >> out4t.out")
	for i in range(1, 64,2):
		os.system("g++ -g -DNUMT=8 -DNUM=%d -o main main.cpp -fopenmp -lm" % (i))
		os.system("./main >> out8t.out")

if __name__ == "__main__":
    main()

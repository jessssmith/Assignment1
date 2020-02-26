#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;


int main(int argc, char** argv) {

//loop for entire program
int end = 1;
while(end != 0) {

  // variable to dictate opening to append or to output
  int outOrApp = 1;

    //check for command line input
    string cLine;
    if (argc == 1) {
      cerr << "Please enter a file name as an argument into the command line" << endl;
      exit(1);
    }
    else {
      //read text from command line argument
      cLine = argv[1];
    }

      //program will start here if user wants to process a second file
      int processFile = 1;
      while(processFile != 0) {
        //first calculations done
          float sum_length = 0.0;
          float mean = 0.0;
          float variance = 0.0;
          float standard_deviation = 0.0;

        //second calculations done
          float probA = 0.0;
          float probC = 0.0;
          float probT = 0.0;
          float probG = 0.0;

        //third calculations done
          float probAA = 0.0;
          float probCC = 0.0;
          float probTT = 0.0;
          float probGG = 0.0;
          float probAC = 0.0;
          float probAT = 0.0;
          float probAG = 0.0;
          float probCA = 0.0;
          float probCT = 0.0;
          float probCG = 0.0;
          float probTA = 0.0;
          float probTC = 0.0;
          float probTG = 0.0;
          float probGA = 0.0;
          float probGC = 0.0;
          float probGT = 0.0;

      //open the file
      ifstream inFile;
      inFile.open(cLine,ios::in);
      //check for error in opening file
      if (inFile.fail()) {
        cerr << "File was not opened properly" << endl;
        exit(1);
      }

        //check how many strings are in the file
        string all_strings = "";
        float count = 0.0;
        string items;
        while (!inFile.eof()) {
          inFile >> items;
          sum_length += items.length();
          all_strings.append(items + " ");
          count++;
        }

        //close File
        inFile.close();
        //calulating the mean
        mean = sum_length/count;

        //find the difference between mean and and each value
        float lenCount = 0.0;
        float sum_difference = 0.0;
        string check;
        for(int i = 0; i < all_strings.length(); ++i) {
          check = all_strings[i];
          //if check is a blank space then we have hit the end of a dna sequence
          if(check != " ") {
            lenCount++;
          }
          //if we hit the end of a sequence we need to reset the difference and then calculate the new one
          if(check == " ") {
            float difference = 0.0;

            difference = mean - lenCount;
            //square the difference between mean and standard deviation
            difference = pow(difference, 2);
            //summing all the difference squared
            sum_difference += difference;

            //reset the count for the length of each dna sequence
            lenCount = 0.0;
          }
            //finding the variance
            variance = sum_difference/count;
            //finding standard deviation
            standard_deviation = sqrt(variance);
        }


        //calculate the probability of each nucleotide
        //variables to keep track of how many times each nucleotide occurs
        float countA = 0.0;
        float countC = 0.0;
        float countT = 0.0;
        float countG = 0.0;

        //checking each char to see how many times each one occurs
        float total_Nucleotides = 0.0;
        for(char& c : all_strings) {
          char n = tolower(c);
          switch (n) {
            case 'a':
              countA++;
              total_Nucleotides++;
              break;
            case 'c':
              countC++;
              total_Nucleotides++;
              break;
            case 't':
              countT++;
              total_Nucleotides++;
              break;
            case 'g':
              countG++;
              total_Nucleotides++;;
              break;
            default:
              //should only happen if there is a letter that should not be in a dna sequence or we hit a space between dna sequences
              break;
          }
          //calculating all probabilities for each nucleotide
          probA = countA/total_Nucleotides;
          probC = countC/total_Nucleotides;
          probT = countT/total_Nucleotides;
          probG = countG/total_Nucleotides;
        }

        //relative probabiliity of each nucleotide bigram
        //variables to keep track of how many times each bigram occurs
        float countAA = 0.0;
        float countCC = 0.0;
        float countTT = 0.0;
        float countGG = 0.0;
        float countAC = 0.0;
        float countAT = 0.0;
        float countAG = 0.0;
        float countCA = 0.0;
        float countCT = 0.0;
        float countCG = 0.0;
        float countGA = 0.0;
        float countGC = 0.0;
        float countGT = 0.0;
        float countTA = 0.0;
        float countTC = 0.0;
        float countTG = 0.0;

        string firstChar;
        string bigram = "";
        float total_bigrams = 0.0;
        for(int i = 0; i <= all_strings.length(); ++i) {
          firstChar = all_strings[i];
          //make sure char is not a space
          if(firstChar != " ") {
            bigram.append(firstChar);
            if(bigram.length()%2 == 0) {
              if(bigram == "AA") {
                countAA++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "CC") {
                countCC++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "TT") {
                countTT++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "GG") {
                countGG++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "AC") {
                countAC++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "AT") {
                countAT++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "AG") {
                countAG++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "CA") {
                countCA++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "CT") {
                countCT++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "CG") {
                countCG++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "TA") {
                countTA++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "TC") {
                countTC++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "TG") {
                countTG++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "GA") {
                countGA++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "GC") {
                countGC++;
                total_bigrams++;
                bigram = "";
              }
              else if(bigram == "GT") {
                countGT++;
                total_bigrams++;
                bigram = "";
              }
              else {
                //Should only happen if there is no such bigram, an error in nucleotides in the file
                cout << bigram << " is not a recognizable bigram" << endl;
                bigram = "";
              }
            }
          }
        }

        //calculate the probabilities of each bigram
        probAA = countAA / total_bigrams;
        probCC = countCC / total_bigrams;
        probTT = countTT / total_bigrams;
        probGG = countGG / total_bigrams;
        probAC = countAC / total_bigrams;
        probAT = countAT / total_bigrams;
        probAG = countAG / total_bigrams;
        probCA = countCA / total_bigrams;
        probCT = countCT / total_bigrams;
        probCG = countCG / total_bigrams;
        probTA = countTA / total_bigrams;
        probTC = countTC / total_bigrams;
        probTG = countTG / total_bigrams;
        probGA = countGA / total_bigrams;
        probGC = countGC / total_bigrams;
        probGT = countGT / total_bigrams;


        //writing to File
        ofstream outFile;
        if(outOrApp == 1) {
          //open the file to be written to
          outFile.open("JesseSmith.out");
          outFile << "Jesse Smith\n" << "2327584\n" << "CPSC 350 Assignment 1\n" << endl;
        }
        else {
          //open the file to be appended to
          outFile.open("JesseSmith.out",std::ios_base::app);
        }

        outFile << "The sum of the length of the DNA sequences is: " << sum_length << endl;
        outFile << "The mean is: " << mean << endl;
        outFile << "The standard deviation is: " << standard_deviation << endl;
        outFile << "The variance is: " << variance << endl;
        outFile << "\n" << "The probabilities for each nucleotide is as follows:" << endl;
        outFile << "A " << probA << endl;
        outFile << "C " << probC << endl;
        outFile << "T " << probT << endl;
        outFile << "G " << probC << endl;
        outFile << "\n" << "The probabilities for each bigram is as follows:" << endl;
        outFile << "AA " << probAA << endl;
        outFile << "CC " << probCC << endl;
        outFile << "GG " << probGG << endl;
        outFile << "TT " << probTT << endl;
        outFile << "AC " << probAC << endl;
        outFile << "AT " << probAT << endl;
        outFile << "AG " << probAG << endl;
        outFile << "CA " << probCA << endl;
        outFile << "CT " << probCT << endl;
        outFile << "CG " << probCG << endl;
        outFile << "TA " << probTA << endl;
        outFile << "TC " << probTC << endl;
        outFile << "TG " << probTG << endl;
        outFile << "GA " << probGA << endl;
        outFile << "GC " << probGC << endl;
        outFile << "GT " << probGT << endl;


        //gaussian distribution
        string randStrings = "";

        for(int i = 0; i < 1000; ++i) {
          float a = (float)rand() / RAND_MAX;
          float b = (float)rand() / RAND_MAX;

          //using first equation
          //C is a standard Gaussian
          float C = sqrt(-2*log(a)) * cos(2*M_PI*b);

          //convert C, a standard Gaussian to a normal random variable
          int D = standard_deviation*C + mean;
          //make sure D is not negative
          if(D < 0)
            D *= -1;

          //Here D is is the length of the string being generated
          //once that length is hit there will be a space and the next string of D length will be generated
          for(int i = 0; i < D; ++i) {
            //create rand under 100
            float randvar = (float)rand() / RAND_MAX;

            if(randvar < probA)
              randStrings += "A";
            else if(randvar < (probA + probC))
              randStrings += "C";
            else if(randvar < (probA + probC + probT))
              randStrings += "T";
            else
              randStrings += "G";
          }
          randStrings += " ";
        }

        outFile << "\n1000 randomly generated strings with the same mean and variance as calculated above:" << endl;
        outFile << randStrings << "\n" << endl;

        outFile.close();

      //checking if user wants to quit or run process another file
      string nextFile;
      char yn;
      cout << "Would you like to process another file? (Y/N)" << endl;
      cin >> yn;
      char yn1 = tolower(yn);
      if(yn1 == 'y') {
        cout << "Please enter the name of the file: " << endl;
        cin >> nextFile;
        cLine = nextFile;
        //set = 0 so that out file is opened to append and not write over what is already there
        outOrApp = 0;
      }
      else if(yn1 == 'n') {
        //close file and exit program
        outFile.close();
        exit(1);
      }
      else
        cout << "Input was not valid" << endl;
    }
  }
}

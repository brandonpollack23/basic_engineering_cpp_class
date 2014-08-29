//Brandon Pollack
//2375 4365
//Period 5
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <algorithm>
#define MAX_RECORDS 10
#define RUNS_PER_REC 4
#define VAL_PER_RUN 5
#define EMPTY 0
#define START_STR "Data file"
#define END_STR "END OF DATA"
using namespace std;

class record
{
 public:
  record();
  void setFileN(int nFileNum);
  void setRecN(int nRecordNum);
  void setNumR(int nNumRuns);
  void setVal(int nVal,int run,int pos);
  int getFileN();
  int getRecN();
  int getNumR();
  int getMaxVal();
  int getMinVal();
  double getAvgVal();
  void print();
 private:
  int fileNum;
  int recordNum;
  int numRuns;
  int values[RUNS_PER_REC][VAL_PER_RUN];
};

int p_filenum(string& input);
int p_recordnum(string& input);
void p_run(string& input, vector<int>& sample, int& numVals);

int main()
{
	vector<record> records;
	vector<int> sample;
	string test,input;
	int filenum, recordnum;
	int numVals = 0;
	int numRuns = 0;
	int min, max = 0;
	double avg;

	/*move the "file" into the string input*/
	getline(cin,test);

	while(test.compare(END_STR))
	{/*copy strings until the valid ending of the file*/
		input = input+test;
		getline(cin,test);
	}


	filenum = p_filenum(input);

	while(input.length() != 0)
	{
		numRuns = 0;
		sample.clear();
		numVals = 0;
		records.push_back(record());

		recordnum = p_recordnum(input);

		while(!input.empty() && input.find("Record") != 0) //while we are still not at the end of a record
		{
			numRuns++;
			p_run(input,sample, numVals);
			if(!input.empty() && input.at(0) != 'R') input.erase(0,1);
		}

		records.back().setRecN(recordnum);
		records.back().setFileN(filenum);
		records.back().setNumR(numRuns);

		//loop to set all vals
		for(int i = 0; i < RUNS_PER_REC; i++)
		{
			for(int j = 0; j < VAL_PER_RUN; j++)
			{
				records.back().setVal(sample[(VAL_PER_RUN*i)+j],i,j);
			}
		}
	}

	for(int i = 0; i < records.size(); i++)
	{
		records[i].print();
		cout << endl;
	}

	for(int i = 0; i < records.size(); i++)
	{
		max = std::max(max, records.at(i).getMaxVal());
	}

	min = records.at(0).getMinVal();
	for(int i = 1; i < records.size(); i++)
	{
		min = std::min(min,records.at(i).getMinVal());
	}

	avg = records.at(0).getAvgVal();
	for(int i = 1; i < records.size(); i++)
	{
		avg = ((avg + records.at(i).getAvgVal())/2);
	}

	cout << "File number:" << filenum << " max:" << max << " min:" << min << " avg:" << setprecision(10) << avg << endl;
	//system("pause");
}

int p_filenum(string& input)
{
	string sanswer;
	sanswer = input.substr(input.find('#')+1,input.find(':')-1);
	input.erase(0,input.find("Record"));
	return atoi(sanswer.c_str());
}

int p_recordnum(string& input)
{
	string sanswer;
	sanswer = input.substr(input.find('#')+1,input.find(':')-1-input.find('#'));
	input.erase(0,input.find('*')+1);
	return atoi(sanswer.c_str());
}

void p_run(string& input, vector<int>& sample, int& numVals)
{
	while(!input.empty() && input.at(0) != '*' && input.at(0) != 'R')
	{
		numVals++;
		sample.push_back(atoi(input.substr(0,input.find(';')).c_str()));
		input.erase(0,input.find(';')+1);
	}
}

record::record()
{
	fileNum = 0;
	recordNum = 0;
	numRuns = 0;
}

void record::setFileN(int nFileNum)
{
	fileNum = nFileNum;
}

void record::setRecN(int nRecordNum)
{
	recordNum = nRecordNum;
}

void record::setNumR(int nNumRuns)
{
	numRuns = nNumRuns;
}

void record::setVal(int nVal,int run,int pos)
{
	values[run][pos] = nVal;
}

int record::getFileN()
{
	return fileNum;
}

int record::getRecN()
{
	return recordNum;
}

int record::getNumR()
{
	return numRuns;
}

int record::getMaxVal()
{
	int max = 0;
	for(int i = 0; i < RUNS_PER_REC; i++)
	{
		for(int j = 0; j < VAL_PER_RUN; j++)
		{
			if(values[i][j] > max) max = values[i][j];
		}
	}
	return max;
}

int record::getMinVal()
{
	int min = values[0][0];
	for(int i = 0; i < RUNS_PER_REC; i++)
	{
		for(int j = 0; j < VAL_PER_RUN; j++)
		{
			if(values[i][j] < min) min = values[i][j];
		}
	}
	return min;
}

double record::getAvgVal()
{
	double sum = 0;
	for(int i = 0; i < RUNS_PER_REC; i++)
	{
		for(int j = 0; j < VAL_PER_RUN; j++)
		{
			sum += values[i][j];
		}
	}

	return sum/((double)(VAL_PER_RUN*RUNS_PER_REC));
}

void record::print()
{
	cout << "File num:" << fileNum << " Rec num:" << recordNum << " Num Runs:" << numRuns << endl;
	for(int i = 0; i < RUNS_PER_REC; i++)
	{
		cout << "Run #" << i+1 << " is:";
		for(int j = 0; j < VAL_PER_RUN; j++)
		{
			cout << values[i][j] << ' ';
		}
		cout << endl;
	}

	//cout << "File number:" << fileNum << " max:" << getMaxVal() << " min:" << getMinVal() << " avg:" << setprecision(10) << getAvgVal() << endl;
}
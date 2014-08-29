#Brandon Pollack
#2375 4365
#Period 5

RUNS_PER_REC = 4
VALS_PER_RUN = 4

class record:


  def __init__(self):
	self.fileNum = 0
	self.recordNum = 0
	self.numRuns = 0
	self.values = []
	for i in range(0,RUNS_PER_REC):
		self.values.append([])

  def getMaxVal(self):
	max = 0
	for i in range(0,RUNS_PER_REC):
		for j in range(0,VALS_PER_RUN):		
			if(self.values[i][j] > max):
				max = self.values[i][j]	
	return max
	
  def getMinVal(self):
	min = self.values[0][0]
	for i in range(0,RUNS_PER_REC):	
		for j in range(0,VALS_PER_RUN):
			if(self.values[i][j] < min):
				min = self.values[i][j]
	return min
    
  def getAvgVal(self):
  	sum = 0.0
	for i in range(0,RUNS_PER_REC):
		for j in range(0,VALS_PER_RUN):
			sum += self.values[i][j]
	return sum/(VALS_PER_RUN*RUNS_PER_REC);
  
  def rprint(self):
	output = "File num: {0} Rec num: {1} Num Runs: {2}\n".format(self.fileNum,self.recordNum,self.numRuns)
	for i in range(0,RUNS_PER_REC):	
		output += "Run # %d is:" %(i+1)
		for j in range(0,VALS_PER_RUN):
			output += "%4d " %(self.values[i][j])
		output += '\n'
	print output

records = []
sample = []
test = ""
input = ""
filenum = 0
recordnum = 0
numVals = 0
numRuns = 0
min = 100000000
max = 0
avg = 0

infile = open("data.txt","rt")
input = infile.readlines()
infile.close()

input = ''.join(input)

#filenum = p_filenum(input)

filenum = int(input[(input.find('#')+1):(input.find(':'))])
input = input[input.find("Record"):]

while len(input) != 0 and input != "END OF DATA":
	numRuns = 0
	numVals = 0
	records.append(record())
	sample = []

	#recordnum = p_recordnum(input)
	recordnum = int(input[(input.find('#')+1) : (input.find(':'))])
	input = input[input.find('*')+1:]

	while input != "END OF DATA" and input.find("Record") != 0: #while we are still not at the end of a record
		numRuns += 1
		
		#p_run(input,sample)		
		while input != "" and input[0] != '*' and input[0] != 'R' and input[0] != '\n':
			sample.append(int(input[:input.find(';')]))
			input = input[(input.find(';')+1):]
		
		input = input[2:]
	

	records[-1].recordNum = recordnum
	records[-1].fileNum = filenum
	records[-1].numRuns = numRuns
	
	#print len(records[-1].values)

	for i in range(0,RUNS_PER_REC):
		for j in range(0,VALS_PER_RUN):
			records[-1].values[i].append(sample[(VALS_PER_RUN*i)+j])
			
	print records[-1].values

for i in range(0,len(records)):
	records[i].rprint()

for i in range(0,len(records)):
	if max < records[i].getMaxVal():
		max = records[i].getMaxVal()


min = records[0].getMinVal();
for i in range(1,len(records)):
	if min > records[i].getMinVal():
		min = records[i].getMinVal()

avg = records[0].getAvgVal()
for i in range(1,len(records)):
	avg = ((avg + records[i].getAvgVal())/2)

output = "File number: %d max: %d min: %d avg: %10f" %(filenum,max,min,avg)

output = output.rstrip('0')
if output[-1] == '.':
	output = output[:-1]
	
print output

#raw_input()

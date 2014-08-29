#create variables for loop, total and count
loop = total = count = 0

#Increment loop by 1 until it reaches 50 (inclusive)
#Add loop to total in each iteration if it is an even number and increment count if loop is added
#Use a while loop
#*** 1. Fill in this line of code ***
while loop <= 50:
 if loop%2 == 0: #if even
#*** 2. Fill in this line of code *** #Hint: update total
	total += loop
  count = count + 1
#*** 3. Fill in this line of code ***
 loop = loop + 1

#print the current total and average
print "Total after increment is:",total
print "Average is:",total/count

#Decrement loop by 1 until it reaches 16 (inclusive)
#Subtract 1/2 of loop value from total in each iteration if it is an odd number and
#Subtract 1/4 of loop value if it is even
#Use a while loop
while loop > 15:
 if loop%2 != 0:
#*** 4. Fill in this line of code ***
     total -= loop/4
 else:
     total -= loop/2
#*** 5. Fill in this line of code ***
 loop = loop - 1

#print the current total
print "Total after decrement is:",total

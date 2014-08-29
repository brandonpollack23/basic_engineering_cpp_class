#create array of numbers
array = [0,1,2,3,4,5,6,7,8,9,10]

#find the smallest and largest numbers using for
smallest = largest = array[0]
#*** 1. Fill in this line of code ***
for x in array:
 if x < smallest:
#*** 2. Fill in this line of code *** #Hint: update smallest
  smallest  = x
#*** 3. Fill in this line of code *** #Hint: check for largest update condition
 if x > largest:
  largest = x

#print out the smallest and largest
print "The largest is:",largest,"The smallest is:",smallest

#find the average of the numbers using for
total = count = 0
#*** 4. Fill in this line of code ***
for y in array:
 total = total + y
 count = count + 1

#print out the average of the numbers
print "Average of number is:",total/count

#print out the even numbers using for
print "The even numbers are:"
#*** 5. Fill in this line of code ***
for num in array:
 if num%2==0:
  print num,
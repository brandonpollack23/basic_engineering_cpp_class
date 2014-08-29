#create three integers
first = 10
second = 20
third = 30

#print out the numbers
print "The numbers are:", first, second, third

#print out the largest using if
if first > second and first > third:
 print first, "is the largest number"
if second > first and second > third:
  print second, "is the largest number"
if third > first and third > second:
  print third, "is the largest number"

#print out any number that is smaller than the average using if
average = (first + second + third)/3
if first < average:
 print first, "is less than the average of", average
if second < average:
 print second, "is less than the average of", average
if third < average:
 print third, "is less than the average of", average

#print out if the average is greater than 30 or not using if-else
if average > 30:
 print "Average is greater than 30"
else:
 print "Average is not greater than 30"
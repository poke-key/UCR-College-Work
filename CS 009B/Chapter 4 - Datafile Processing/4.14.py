fileHandle = open("Global_Temperature_Data_File.txt", "r") # open file 
lines = fileHandle.readlines() # read all lines into variable 
fileHandle.close() # close the file since we are done reading 
numReadings = len(lines) # number of temperature readings = number of lines in the file

# next, loop through each line in the file and split line by separator
avgOceanTemp = 0
avgLandTemp = 0 
for line in lines: 
     year, landTemp, oceanTemp = line.split("\t")
     # TODO  - convert landTemp and oceanTemp to floats and compute averages
     avgOceanTemp += float(oceanTemp)
     avgLandTemp += float(landTemp)
# TODO  - write code to compute average of land temp and ocean temp and print results
avgOceanTemp /= numReadings
avgLandTemp /= numReadings
print ("Average land temperature anomaly: ", avgLandTemp )
print ("Average ocean temperature anomaly: ", avgOceanTemp )

landVariance = 0
oceanVariance = 0
for line in lines: 
     year, landTemp, oceanTemp = line.split("\t")
     # TODO  - write code to compute average of variance 
     landVariance += ((float(landTemp) - avgLandTemp)**2)
     oceanVariance += ((float(oceanTemp) - avgOceanTemp)**2)
landVariance /= (numReadings - 1)
oceanVariance /= (numReadings - 1)
# TODO - print the variance of land temp and ocean temp 
print ("Land temperature anomaly variance: ", landVariance) 
print ("Ocean temperature anomaly variance: ", oceanVariance) 
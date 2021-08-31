# readFileName = "expected_output_distance.txt"
# writeFileName = "expected_output_distance_formatted.txt"
readFileName = "expected_output_trig.txt"
writeFileName = "expected_output_trig_formatted.txt"
with open(readFileName, "r") as readFile:	
	with open(writeFileName, "w") as writeFile:
		for line in readFile.readlines():
			writeFile.write(f",{line.rstrip()}")

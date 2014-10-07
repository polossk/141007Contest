def setInputPath( i )
	s1 = "test"
	s2 = i.to_s
	s3 = ".in"
	s1 + s2 + s3
end

def setOutputPath( i )
	s1 = "test"
	s2 = i.to_s
	s3 = ".out"
	s1 + s2 + s3
end

def setCommand( inputPath, outputPath, exePath )
	s1 = exePath.to_s
	s2 = " < " + inputPath.to_s
	s3 = " > " + outputPath.to_s
	s1 + s2 + s3
end

1.times { |i|
	cur = Time.now
	system setCommand(setInputPath(i), setOutputPath(i), "guide")
	fin= Time.now
	run = fin - cur;
	File.open("record.txt", "a") { |f|
		f << "case #{i}: #{run}\n"
	}
}
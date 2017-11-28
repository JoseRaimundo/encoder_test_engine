HEVC ENCODER AUTOMATED TEST
===================


This work has the objective is help researchers and developers in the test steps of HEVC encoder development process.
----------


How use this tool??
--------------------

In the directory "codec_test_tool", usu the *make* command for generate the executable program.
		
		$make

Run the binary program using the *./bin* and the parameters of the test.

	./bin/CodecTest -mod 1 -thr 2 -f 300 -fr 30 -eva encoderEva -ref encoderRef -vin 1 video.yuv -vout videosout/ -cfg 1 config.cfg -outl filelog/
	 
Command     | Description
-------- | ---
-thr    | Number of thread (encoder instances running simultaneously) !Check the number of processor cores!
-eva     | Encoder to be evaluated
-ref     | Reference encoder
-vin     | Number of videos followed by the Input video(s)
-outv     | Output video path
-outl     | Output log file path
-cfg     | Number of configurations followed by the configuration(s)
-f     | Total frames used in test
-fr     | Frame rate
-wdt     | Video resolution width
-hgt     | Video resolution height
-bdepth     | Bit depth per color component
-subsamp     | Chroma subsampling
-qp     | Quantization parameters



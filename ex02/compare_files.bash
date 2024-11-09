#!/bin/bash
./tests > tmp.log

awk -F '[ ]' -v NOF=$(awk 'END{print NR}' tmp.log) '{print $2}' tmp.log > my_tmp_log.log
awk -F '[ ]' -v NOF=$(awk 'END{print NR}' 19920104_091532.log) '{print $2}' 19920104_091532.log > tmp_log_1.log
awk -F '[ ]' -v NOF=$(awk 'END{print NR}' 19920104_091532.log) 'NOF-7>NR{print $2}' 19920104_091532.log > tmp_log_2.log ; tail -n 8 19920104_091532.log | tac | awk -F '[ ]' '{print $2}' >> tmp_log_2.log

output1=$(diff my_tmp_log.log tmp_log_1.log)
output2=$(diff my_tmp_log.log tmp_log_2.log)

if [[ -z $output1 || -z $output2 ]]; then
	echo 'OK'
elif [[ -z $output1 ]]; then
	echo $output1
else
	echo $output2
fi

rm tmp.log my_tmp_log.log tmp_log_1.log tmp_log_2.log

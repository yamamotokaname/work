#! /bin/bash

#example : ./execute.sh lar 5000 25000 5000

exefile=$1
writtenfile="${exefile}.tsv"
plotfile="${exefile}.plot"
make ${exefile}

keyfile=$2
if [ $# -ne 5 ]; then
	targetfile=$3
else
	start=$3
	end=$4
	step=$5
	targetfile=`eval echo {${start}..${end}..${step}}`
fi

#初期化
> ${writtenfile}
for textfile in ${targetfile}; do
	file=`printf "%06d" ${textfile}`.txt
	./${exefile} keyfile/${keyfile}.txt keyfile/${file} >> ${writtenfile}
done

#初期化
> ${plotfile}
echo "plot '${writtenfile}' using 1:2 title 'ヒット数', '${writtenfile}' using 1:3 title '成功探索数', '${writtenfile}' using 1:4 title '不成功探索数', '${writtenfile}' using 1:5 title '総探索数'" >> ${plotfile}
echo "pause -1" >> ${plotfile}

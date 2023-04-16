#! /bin/bash

#example ： ./make.sh lar

exe=${1}
texfile=${exe}.tex
display=c\|c\|c\|c\|c

> ${texfile}
echo \\documentclass{jsarticle} >> ${texfile}
echo \\begin{document} >> ${texfile}
echo \\begin{table} >> ${texfile}
echo \\begin{tabular}{${display}} >> ${texfile}
echo `sed -e 's/\\t/\&/g' -e 's/$/\\\\\\\\/g' ${exe}.tsv`  >> ${texfile}
echo \\end{tabular} >> ${texfile}
echo \\end{table} >> ${texfile}
echo \\end{document} >> ${texfile}

platex ${texfile}
platex ${texfile}
dvipdfmx ${exe}.dvi
evince ${exe}.pdf
rm *.aux *.dvi *.log

#/bin/bash
for VARIABLE in {1 .. 14}
do
	qpdf --decrypt "Tema ${VARIABLE}.pdf" "ha/Tema ${VARIABLE}.pdf"
done

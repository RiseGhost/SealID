#!/bin/bash
"" > data
echo "File clean!"
for i in {0..55000}
do
	progress=$((i * 100 / 55000))
    echo -ne "\rProgress: $progress%  -  $i/55000"
	./teste.out >> data
done
echo "\nAcabou!!!"
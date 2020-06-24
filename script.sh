RED="\e[1;31m"; #'\033[0;31m';
NC="\e[0m";  #'\033[0m';

# top -o cpu > tmp &
top -b -o -%CPU > tmp &

while [[ true ]]; do
	sleep 1;
	# sed -n 13,17p tmp | while read line; do
	tail -5 tmp | while read line; do
		S=($line);
		# outp="${S[0]}\t\t${S[2]}\t\t${S[1]}";
		outp="${S[0]}  ${S[8]}  ${S[11]}";
		
		a=`echo "${S[8]} > 10" | bc -l`;

		if [[ $a == "1" ]]; then
			echo "${RED}${outp}${NC}";
		else
			echo "${outp}";
		fi;
	done;

	> tmp;
done
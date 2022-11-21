TARGET_FILE		=client
TARGET_TBC_FILE	=${TARGET_FILE}.tbc
TARGET_C_FILE	=${TARGET_FILE}.c




client: 
	gcc -I${TMAXDIR} -L${TB_HOME}/client/lib -ltbertl -L${TMAXDIR}/lib -lcli ${TARGET_C_FILE} -o ${TARGET_FILE}

TARGET_FILE		=create
TARGET_TBC_FILE	=${TARGET_FILE}.tbc
TARGET_C_FILE	=${TARGET_FILE}.c

create: 
	gcc -I${TMAXDIR} -L${TB_HOME}/client/lib -ltbertl -L${TMAXDIR}/lib -lcli ${TARGET_C_FILE} -o ${TARGET_FILE}

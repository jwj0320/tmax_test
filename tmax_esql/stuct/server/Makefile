TARGET_FILE		=server
TARGET_TBC_FILE	=${TARGET_FILE}.tbc
TARGET_C_FILE	=${TARGET_FILE}.c


SERVER_FILE		=tabsvr
SVCTAB_FILE		=${SERVER_FILE}_svctab.c



server: 
	tbpc ${TARGET_TBC_FILE} INCLUDE=${TMAXDIR}
	gcc -I${TB_HOME}/client/include -I${TMAXDIR} -L${TB_HOME}/client/lib -ltbertl -L${TMAXDIR}/lib -lsvr -lnodb ${TMAXDIR}/lib64/sdl.o  ${TARGET_C_FILE} ${TMAXDIR}/svct/${SVCTAB_FILE} -o ${SERVER_FILE}
	cp ${SERVER_FILE} ${TMAXDIR}/appbin/

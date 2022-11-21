# TARGET_FILE		=server
# TARGET_TBC_FILE	=${TARGET_FILE}.tbc
# TARGET_C_FILE	=${TARGET_FILE}.c

SERVER_FILE		=odbcsvr
SVCTAB_FILE		=${SERVER_FILE}_svctab.c



# server: 
# 	gcc -I${TB_HOME}/client/include -I${TMAXDIR} -L${TB_HOME}/client/lib -ltbertl -L${TMAXDIR}/lib -lsvr -lnodb ${TMAXDIR}/lib64/sdl.o  ${TARGET_C_FILE} ${TMAXDIR}/svct/${SVCTAB_FILE} -lodbc -o ${SERVER_FILE}
# 	cp ${SERVER_FILE} ${TMAXDIR}/appbin/

TARGET_FILE		=server2
TARGET_TBC_FILE	=${TARGET_FILE}.tbc
TARGET_C_FILE	=${TARGET_FILE}.c


server2:
	gcc -I${TB_HOME}/client/include -I${TMAXDIR} -L${TB_HOME}/client/lib -ltbodbc -ltbertl -L${TMAXDIR}/lib -lsvr -lnodb ${TMAXDIR}/lib64/sdl.o  ${TARGET_C_FILE} ${TMAXDIR}/svct/${SVCTAB_FILE} -o ${SERVER_FILE}
	cp ${SERVER_FILE} ${TMAXDIR}/appbin/

server3:
	gcc -I${TB_HOME}/client/include -I${TMAXDIR} -L${TMAXDIR}/lib -lsvr -lnodb -L${TB_HOME}/client/lib -ltbodbc -ltbertl ${TMAXDIR}/lib64/sdl.o  ${TARGET_C_FILE} ${TMAXDIR}/svct/${SVCTAB_FILE} -o ${SERVER_FILE}
	cp ${SERVER_FILE} ${TMAXDIR}/appbin/

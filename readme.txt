##환경설정

sample3.m을 {TMAXDIR}/config 에 넣고
1. cfl -i sample3.m
2. gst

#ESQL

##SDL
1. cd {tmax_esql/sdl}
2. sdlc -c -i mem.s
3. export SDLFILE={mem.sdl path}
--------------------------------------
4. cd {tmax_esql/struct/server}
5. make (프리컴파일, 컴파일, 서버로 복사)
--------------------------------------
6. cd {tmax_esql/struct/client}
7. make create (create table 수행, struct 사용 X)
8. make client (insert 수행)
--------------------------------------
./create 테이블 생성 정상 수행
./client 에서 발생
2860042.020512:(E) SVR3128 invalid sdl subtype (mem) : check sdl.o [CSC5726]

##FDL
1. cd {tmax_esql/fdl}
2. fdlc -c -i mem.f
3. export FDLFILE={mem.fdl path}
--------------------------------------
4. cd {tmax_esql/fb/server}
5. make server(프리컴파일, 컴파일, 서버로 복사)
--------------------------------------
6. cd {tmax_esql/fb/client}
7. make client (insert 수행)
--------------------------------------
./client_f (정상 수행)

#ODBC
1. cd {odbc/server}
2. make server3 (컴파일, 서버로 복사)
--------------------------------------
###client only
3. cd {odbc/}
4. gcc test4.c -lodbc
5. ./a.out (정상 수행)
###server, client
6. cd {odbc/client}
7. make client
8. ./client (정상 수행)

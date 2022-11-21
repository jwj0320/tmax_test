###############################################################
#                                                             #
#         Sample Configuration File for Tmax System           #
#         =========================================           #
#                                                             #
#     Copyright(c) 2004 TmaxSoft Inc. All rights reserved     #
#                                                             #
###############################################################


*DOMAIN
tmax1           SHMKEY = 79990, MINCLH = 1, MAXCLH = 3,
                TPORTNO = 8888, BLOCKTIME = 30,
		MAXCPC = 150


*NODE
tmaxwj        TMAXDIR = "/root/shared/OF71/OHOME/tmax",
                APPDIR  = "/root/shared/OF71/OHOME/tmax/appbin",
                PATHDIR = "/root/shared/OF71/OHOME/tmax/path",
                TLOGDIR = "/root/shared/OF71/OHOME/tmax/log/tlog",
                ULOGDIR = "/root/shared/OF71/OHOME/tmax/log/ulog",
                SLOGDIR = "/root/shared/OF71/OHOME/tmax/log/slog",
#               SQKEY = 78550, SQSIZE = 8192, SQMAX = 1024, SQKEYMAX = 64, SQTIMEOUT = 30
		TPORTNO=8573

*SVRGROUP
svg1            NODENAME = "tmaxwj"

### tms for Oracle ###
#svg2           NODENAME = "tmaxwj", DBNAME = ORACLE,
#               OPENINFO = "Oracle_XA+Acc=P/scott/tiger+SesTm=60+DbgFl=7+LogDir=/root/shared/OF71/OHOME/tmax/log/xalog",
#               TMSNAME  = tms_ora

### tms for Informix ###
#svg3           NODENAME = "tmaxwj", DBNAME = INFORMIX,
#               OPENINFO = "stores7",
#               CLOSEINFO = "",
#               TMSNAME  = tms_info

### tms for Tibero ###
#svg4           NODENAME = "tmaxwj", DBNAME = TIBERO,
#               OPENINFO = "TIBERO_XA:user=tibero,pwd=tmax,sestm=60,db=tibero",
#               TMSNAME  = tms_tbr

### hms for Tibero ###
#hms01          NODENAME = "tmaxwj", SVGTYPE = "HMS", HMSNAME = hms_tbr,
#               HMSINDEX = 1, HMSMAXTHR = 2, HMSMAXDBTHR = 4, RESTART=N,
#               OPENINFO = "TIBERO_XA:user=tibero,pwd=tmax,sestm=60"

### hms for Oracle ###
#hms01          NODENAME = "tmaxwj", SVGTYPE = "HMS", HMSNAME = hms_ora,
#               HMSINDEX = 1, HMSMAXTHR = 2, HMSMAXDBTHR = 4, RESTART=N,
#               OPENINFO = "Oracle_XA+Acc=P/scott/tiger+SesTm=60+Threads=true"

### MultipleRM STMAX for Oracle ###
#svg_s1		NODENAME = tmaxwj,
#		DBNAME = ORACLE,
#		OPENINFO="Oracle_Xa+Acc=P/scott/tiger+SesTm=60+DbgFl=7+LogDir=/root/shared/OF71/OHOME/tmax/log/xalog",
#		TMSNAME = tms_ora,
#		SVGTYPE = STMAX

### MultipleRM STMAX for Tibero ###
#svg_s2		NODENAME = tmaxwj,
#		DBNAME = TIBERO,
#		OPENINFO="TIBERO_XA:user=tibero,pwd=tmax,db=tibero,Loose_Coupling=false,sestm=60",
#		TMSNAME = tms_tbr,
#		SVGTYPE = STMAX

### MultipleRM MTMAX ###
#svgm1		NODENAME = tmaxwj,
#		SVGLIST = "svg_s1,svg_s2",
#		SVGTYPE = MTMAX

### Multithread/Multicontext ###
#svgmt		NODENAME = tmaxwj

### for RQ ###
#rqsvg          NODENAME = "tmaxwj", SVGTYPE = RQMGR, CPC = 4

#*RQ
#rq1            SVGNAME = rqsvg, BOOT = WARM, FILEPATH = "/root/shared/OF71/OHOME/tmax/appbin/rq1.dat"

#*HMS
#queue01        SVGNAME = hms01, BOOT = "WARM", TYPE = "QUEUE"


*SERVER
#svr1           SVGNAME = svg1, MIN = 1
#svr2            SVGNAME = svg1
tabsvr          SVGNAME = svg1
odbcsvr         SVGNAME = svg1

#svr3           SVGNAME = svg1
#svr_ucs        SVGNAME = svg1, SVRTYPE = UCS
#svr_conv       SVGNAME = svg1, CONV = YES
#svr_rq         SVGNAME = svg1
#svr_sq         SVGNAME = svg1
#svr_hms        SVGNAME = svg1

### servers for Oracle sample program###
#fdltest        SVGNAME = svg2
#sdltest        SVGNAME = svg2

### server for Tibero sample program ###
#tbrtest        SVGNAME = svg4

### server for MultipleRM Oracle&Tibero sample program ###
#mrmtest       SVGNAME = svgm1, MIN=5, MAX=5, MAXRSTART=-1

### Multithread/Multicontext ###
#msvr            SVGNAME = svgmt, SVRTYPE = "STD_MT", CPC = 10, MINTHR = 5, MAXTHR = 10

*SERVICE
# SDLTOUPPER     SVRNAME = svr1
# SDLTOLOWER     SVRNAME = svr1
# TOUPPER         SVRNAME = svr2
# TOLOWER         SVRNAME = svr2
#FDLTOUPPER     SVRNAME = svr3
#FDLTOLOWER     SVRNAME = svr3
#LOGIN          SVRNAME = svr_ucs
#TOUPPER_CONV   SVRNAME = svr_conv
#TPENQ          SVRNAME = svr_rq
#TPDEQ          SVRNAME = svr_rq
#GET_SQ         SVRNAME = svr_sq
#HMS            SVRNAME = svr_hms

CREATETABLE     SVRNAME = tabsvr
ADDMEMBER       SVRNAME = tabsvr

SELECTFROMTABLE SVRNAME = odbcsvr


### services for fdltest ###
#FDLINS         SVRNAME = fdltest
#FDLSEL         SVRNAME = fdltest
#FDLUPT         SVRNAME = fdltest
#FDLDEL         SVRNAME = fdltest

### services for sdltest ###
#SDLINS         SVRNAME = sdltest, AUTOTRAN = Y
#SDLSEL         SVRNAME = sdltest, AUTOTRAN = Y
#SDLUPT         SVRNAME = sdltest, AUTOTRAN = Y
#SDLDEL         SVRNAME = sdltest, AUTOTRAN = Y

### services for tbrtest ###
#TBRINS         SVRNAME = tbrtest
#TBRSEL         SVRNAME = tbrtest
#TBRUPT         SVRNAME = tbrtest
#TBRDEL         SVRNAME = tbrtest

### services for mrmtest ###
#MRMINS		SVRNAME = mrmtest, SVCTIME=5
#MRMSEL		SVRNAME = mrmtest, SVCTIME=5
#MRMUPT		SVRNAME = mrmtest, SVCTIME=5
#MRMDEL		SVRNAME = mrmtest, SVCTIME=5

### services for Multithread/Multicontext ###
#MSERVICE	SVRNAME = msvr
#MTOUPPER	SVRNAME = msvr
#MTOLOWER	SVRNAME = msvr


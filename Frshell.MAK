ORIGIN		= Symantec C++
ORIGIN_VER	= Version 7.22
VERSION		= DEBUG

!IFDEF SUB_DEBUG
DEBUG		= $(SUB_DEBUG)
NDEBUG		= !$(SUB_DEBUG)
!ELSE
DEBUG		= 1
NDEBUG		= 0
!ENDIF

PROJ		= Frshell
APPTYPE		= WIN32 EXE
PROJTYPE	= EXE

CC		= SC
CPP		= SPP
JAVAC		= sj
MAKE		= SMAKE
RC		= RCC
HC		= HC31
ASM		= SC
DISASM		= OBJ2ASM
LNK		= LINK
DLLS		= 

HEADERS		= stdafx.h ..\..\..\..\..\SC\include\win32\WINVER.H ..\..\..\..\..\SC\include\winver.h  \
		..\..\..\..\..\SC\include\win32\scdefs.h ..\..\..\..\..\SC\mfc\include\32-bit\afxres.h ..\..\..\..\..\SC\mfc\include\afxres.h mdiappvw.h  \
		mdiapdoc.h ..\..\..\..\..\SC\include\math.h mainfrm.h resource.h  \
		MDIAPP.h ..\..\..\..\..\SC\include\win32\poppack.h ..\..\..\..\..\SC\include\win32\pshpack2.h ..\..\..\..\..\SC\include\win32\pshpack4.h  \
		..\..\..\..\..\SC\mfc\include\afxwin.h ..\..\..\..\..\SC\mfc\include\32-bit\afxwin.h ..\..\..\..\..\SC\mfc\include\afx.h ..\..\..\..\..\SC\mfc\include\32-bit\afx.h  \
		..\..\..\..\..\SC\mfc\include\afxver_.h ..\..\..\..\..\SC\mfc\include\32-bit\afxver_.h ..\..\..\..\..\SC\mfc\include\afxv_w32.h ..\..\..\..\..\SC\mfc\include\32-bit\afxv_w32.h  \
		..\..\..\..\..\SC\include\windows.h ..\..\..\..\..\SC\include\win32\WINDOWS.H ..\..\..\..\..\SC\include\excpt.h ..\..\..\..\..\SC\include\stdarg.h  \
		..\..\..\..\..\SC\include\windef.h ..\..\..\..\..\SC\include\win32\WINDEF.H ..\..\..\..\..\SC\include\winnt.h ..\..\..\..\..\SC\include\win32\WINNT.H  \
		..\..\..\..\..\SC\include\ctype.h ..\..\..\..\..\SC\include\pshpack4.h ..\..\..\..\..\SC\include\poppack.h ..\..\..\..\..\SC\include\string.h  \
		..\..\..\..\..\SC\include\winbase.h ..\..\..\..\..\SC\include\win32\WINBASE.H ..\..\..\..\..\SC\include\winerror.h ..\..\..\..\..\SC\include\win32\WINERROR.H  \
		..\..\..\..\..\SC\include\wingdi.h ..\..\..\..\..\SC\include\win32\WINGDI.H ..\..\..\..\..\SC\include\pshpack1.h ..\..\..\..\..\SC\include\win32\pshpack1.h  \
		..\..\..\..\..\SC\include\pshpack2.h ..\..\..\..\..\SC\include\winuser.h ..\..\..\..\..\SC\include\win32\WINUSER.H ..\..\..\..\..\SC\include\winnls.h  \
		..\..\..\..\..\SC\include\win32\WINNLS.H ..\..\..\..\..\SC\include\wincon.h ..\..\..\..\..\SC\include\win32\WINCON.H ..\..\..\..\..\SC\include\winreg.h  \
		..\..\..\..\..\SC\include\win32\WINREG.H ..\..\..\..\..\SC\include\winnetwk.h ..\..\..\..\..\SC\include\win32\WINNETWK.H ..\..\..\..\..\SC\include\winsvc.h  \
		..\..\..\..\..\SC\include\win32\WINSVC.H ..\..\..\..\..\SC\include\mcx.h ..\..\..\..\..\SC\include\win32\MCX.H ..\..\..\..\..\SC\include\imm.h  \
		..\..\..\..\..\SC\include\win32\IMM.H ..\..\..\..\..\SC\include\commctrl.h ..\..\..\..\..\SC\include\win32\COMMCTRL.H ..\..\..\..\..\SC\include\prsht.h  \
		..\..\..\..\..\SC\include\win32\PRSHT.H ..\..\..\..\..\SC\include\tchar.h ..\..\..\..\..\SC\include\mbstring.h ..\..\..\..\..\SC\include\mbctype.h  \
		..\..\..\..\..\SC\include\stdio.h ..\..\..\..\..\SC\include\stdlib.h ..\..\..\..\..\SC\include\time.h ..\..\..\..\..\SC\include\limits.h  \
		..\..\..\..\..\SC\include\stddef.h ..\..\..\..\..\SC\include\crtdbg.h ..\..\..\..\..\SC\mfc\include\afxcoll.h ..\..\..\..\..\SC\mfc\include\32-bit\afxcoll.h  \
		..\..\..\..\..\SC\mfc\include\afxstat_.h ..\..\..\..\..\SC\mfc\include\32-bit\afxstat_.h ..\..\..\..\..\SC\mfc\include\afxtls_.h ..\..\..\..\..\SC\mfc\include\32-bit\afxtls_.h  \
		..\..\..\..\..\SC\include\shellapi.h ..\..\..\..\..\SC\include\win32\shellapi.h ..\..\..\..\..\SC\mfc\include\afxmsg_.h ..\..\..\..\..\SC\mfc\include\32-bit\afxmsg_.h  \
		..\..\..\..\..\SC\mfc\include\afxdd_.h ..\..\..\..\..\SC\mfc\include\32-bit\afxdd_.h ..\..\..\..\..\SC\mfc\include\afxext.h ..\..\..\..\..\SC\mfc\include\32-bit\afxext.h  \
		..\..\..\..\..\SC\mfc\include\afxdlgs.h ..\..\..\..\..\SC\mfc\include\32-bit\afxdlgs.h ..\..\..\..\..\SC\include\commdlg.h ..\..\..\..\..\SC\include\win32\COMMDLG.H  \
		..\..\..\..\..\SC\include\richedit.h ..\..\..\..\..\SC\include\win32\RICHEDIT.H ..\..\..\..\..\SC\include\win32\VER.H ..\..\..\..\..\SC\include\ver.h  \
		..\..\..\..\..\SC\mfc\include\32-bit\winres.h 

DEFFILE		= Frshell.def

!IF $(DEBUG)
OUTPUTDIR	= .
CREATEOUTPUTDIR	=
TARGETDIR	= .
CREATETARGETDIR	=

SYMROOT		= 
SYMS		= 
LIBS		= KERNEL32.LIB GDI32.LIB USER32.LIB 

CFLAGS		=  -Ae -mn -C -WA -S -3 -a8 -c -gf 
LFLAGS		=  /CO /NOI /DE /NOPACKF /XN /NT /ENTRY:WinMainCRTStartup /BAS:4194304 /A:512 /RC   :MDIAPP.RES
DEFINES		= -D_DEBUG=1 -D_X86_=1 -D_MT=1 -D_MBCS=1
!ELSE
OUTPUTDIR	= .
CREATEOUTPUTDIR	=
TARGETDIR	= .
CREATETARGETDIR	=

SYMROOT		= 
SYMS		= 
LIBS		= KERNEL32.LIB GDI32.LIB USER32.LIB 

CFLAGS		=  -Ae -mn -o+time -WA -3 -a8 -c 
LFLAGS		=  /NOI /DE /E /PACKF /XN /NT /ENTRY:WinMainCRTStartup /BAS:4194304 /A:512 /RC   :MDIAPP.RES
DEFINES		= -D_X86_=1 -D_MT=1 -D_MBCS=1
!ENDIF

HFLAGS		= $(CFLAGS) 
MFLAGS		= MASTERPROJ=$(PROJ) 
LIBFLAGS	=  /C 
RESFLAGS	=  -32 
DEBUGGERFLAGS	=  
AFLAGS		= $(CFLAGS) 
HELPFLAGS	= 

MODEL		= N

PAR		= PROJS BATS OBJS

RCDEFINES	= 

INCLUDES	= 

INCLUDEDOBJS	= 

OBJS		= MAINFRM.OBJ mdiapdoc.OBJ MDIAPP.OBJ  \
		mdiappvw.OBJ 

RCFILES		=  MDIAPP.RES 

RESFILES	= 

HELPFILES	= 

BATS		= 

.SUFFIXES: .C .CP .CPP .CXX .CC .H .HPP .HXX .COM .EXE .DLL .LIB .RTF .DLG .ASM .RES .RC .OBJ 

.C.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.c

.CPP.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.cpp

.CXX.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.cxx

.CC.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.cc

.CP.OBJ:
	$(CC) $(CFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.cp

.H.SYM:
	$(CC) $(HFLAGS) $(DEFINES) $(INCLUDES) -HF -o$(*B).sym $*.h

.HPP.SYM:
	$(CC) $(HFLAGS) $(DEFINES) $(INCLUDES) -HF -o$(*B).sym $*.hpp

.HXX.SYM:
	$(CC) $(HFLAGS) $(DEFINES) $(INCLUDES) -HF -o$(*B).sym $*.hxx

.C.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES)   $*.c   -o$*.lst

.CPP.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES) $*.cpp -o$*.lst

.CXX.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES) $*.cxx -o$*.lst

.CP.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES)  $*.cp  -o$*.lst

.CC.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES)  $*.cc  -o$*.lst

.ASM.EXP:
	$(CPP) $(CFLAGS) $(DEFINES) $(INCLUDES) $*.asm -o$*.lst

.OBJ.COD:
	$(DISASM) $*.OBJ -c

!IF $(DEBUG)
.OBJ.EXE:
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
MAINFRM.OBJ+
mdiapdoc.OBJ+
MDIAPP.OBJ+
mdiappvw.OBJ
$$SCW$$.EXE
NUL
KERNEL32.LIB GDI32.LIB USER32.LIB 
Frshell.def;
<<
!ELSE
.OBJ.EXE:
		$(LNK) $(LFLAGS) @$(PROJ).LNK<<
MAINFRM.OBJ+
mdiapdoc.OBJ+
MDIAPP.OBJ+
mdiappvw.OBJ
$$SCW$$.EXE
NUL
KERNEL32.LIB GDI32.LIB USER32.LIB 
Frshell.def;
<<
!ENDIF

.RTF.HLP:
	$(HC) $(HELPFLAGS) $*.HPJ

.ASM.OBJ:
	$(ASM) $(AFLAGS) $(DEFINES) $(INCLUDES) -o$*.obj $*.asm

.RC.RES: 
	$(RC) $(RCDEFINES) $(RESFLAGS) $(INCLUDES) $*.rc -o$*.res

.DLG.RES:
	echo ^#include "windows.h" >$$$*.rc
	echo ^IF EXIST "$*.h" >>$$$*.rc
	echo ^#include "$*.h" >>$$$*.rc
	echo ^#include "$*.dlg" >>$$$*.rc
	$(RC) $(RCDEFINES) $(RESFLAGS) $(INCLUDES) $$$*.rc
	-del $*.res
	-ren $$$*.res $*.res



all:	noteout createdir $(PRECOMPILE) $(SYMS) $(OBJS) $(INCLUDEDOBJS) $(POSTCOMPILE) $(TARGETDIR)\$(PROJ).$(PROJTYPE) $(POSTLINK) _done


all2:	createdir $(PRECOMPILE) $(SYMS) $(OBJS) $(INCLUDEDOBJS) $(POSTCOMPILE) $(TARGETDIR)\$(PROJ).$(PROJTYPE) $(POSTLINK) _done

noteout:
	REM Output to $(OUTPUTDIR)

createdir:
	$(CREATEOUTPUTDIR)
	$(CREATETARGETDIR)
	
$(TARGETDIR)\$(PROJ).$(PROJTYPE): $(OBJS) $(INCLUDEDOBJS) $(RCFILES) $(RESFILES) $(HELPFILES) $(DEFFILE)
			-del $(TARGETDIR)\$(PROJ).$(PROJTYPE)
!IF $(DEBUG)
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
MAINFRM.OBJ+
mdiapdoc.OBJ+
MDIAPP.OBJ+
mdiappvw.OBJ
$$SCW$$.EXE
NUL
KERNEL32.LIB GDI32.LIB USER32.LIB 
Frshell.def;
<<
!ELSE
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
MAINFRM.OBJ+
mdiapdoc.OBJ+
MDIAPP.OBJ+
mdiappvw.OBJ
$$SCW$$.EXE
NUL
KERNEL32.LIB GDI32.LIB USER32.LIB 
Frshell.def;
<<
!ENDIF

			-ren $(TARGETDIR)\$$SCW$$.$(PROJTYPE) $(PROJ).$(PROJTYPE)
			-echo $(TARGETDIR)\$(PROJ).$(PROJTYPE) built

_done:
		REM  Project is up to date

buildall:	clean	all


clean:
		-del $(TARGETDIR)\$$SCW$$.$(PROJTYPE)
		-del $(PROJ).CLE
		-del $(OUTPUTDIR)\SCPH.SYM
		-del Frshell.dpd
		-del $(OBJS)
		-del MDIAPP.RES

cleanres:
		-del MDIAPP.RES

res:		cleanres $(RCFILES) all


link:
!IF $(DEBUG)
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
MAINFRM.OBJ+
mdiapdoc.OBJ+
MDIAPP.OBJ+
mdiappvw.OBJ
$$SCW$$.EXE
NUL
KERNEL32.LIB GDI32.LIB USER32.LIB 
Frshell.def;
<<
!ELSE
		$(LNK) $(LFLAGS) @<<$(PROJ).LNK
MAINFRM.OBJ+
mdiapdoc.OBJ+
MDIAPP.OBJ+
mdiappvw.OBJ
$$SCW$$.EXE
NUL
KERNEL32.LIB GDI32.LIB USER32.LIB 
Frshell.def;
<<
!ENDIF

		-del $(TARGETDIR)\$(PROJ).$(PROJTYPE)
		-ren $(TARGETDIR)\$$SCW$$.$(PROJTYPE) $(PROJ).$(PROJTYPE)




!IF EXIST (Frshell.dpd)
!INCLUDE Frshell.dpd
!ENDIF



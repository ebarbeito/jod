#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include nbmakefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/level.o \
	${OBJECTDIR}/src/menustate.o \
	${OBJECTDIR}/src/pausestate.o \
	${OBJECTDIR}/src/item.o \
	${OBJECTDIR}/src/playstate.o \
	${OBJECTDIR}/src/player.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/timer.o \
	${OBJECTDIR}/src/gameengine.o \
	${OBJECTDIR}/src/sprite.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lgosu
CXXFLAGS=-lgosu

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-Debug.mk dist/Debug/GNU-Linux-x86/jod

dist/Debug/GNU-Linux-x86/jod: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/GNU-Linux-x86
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/jod ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/level.o: nbproject/Makefile-${CND_CONF}.mk src/level.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/level.o src/level.cc

${OBJECTDIR}/src/menustate.o: nbproject/Makefile-${CND_CONF}.mk src/menustate.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/menustate.o src/menustate.cc

${OBJECTDIR}/src/pausestate.o: nbproject/Makefile-${CND_CONF}.mk src/pausestate.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/pausestate.o src/pausestate.cc

${OBJECTDIR}/src/item.o: nbproject/Makefile-${CND_CONF}.mk src/item.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/item.o src/item.cc

${OBJECTDIR}/src/playstate.o: nbproject/Makefile-${CND_CONF}.mk src/playstate.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/playstate.o src/playstate.cc

${OBJECTDIR}/src/player.o: nbproject/Makefile-${CND_CONF}.mk src/player.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/player.o src/player.cc

${OBJECTDIR}/src/main.o: nbproject/Makefile-${CND_CONF}.mk src/main.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cc

${OBJECTDIR}/src/timer.o: nbproject/Makefile-${CND_CONF}.mk src/timer.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/timer.o src/timer.cc

${OBJECTDIR}/src/gameengine.o: nbproject/Makefile-${CND_CONF}.mk src/gameengine.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/gameengine.o src/gameengine.cc

${OBJECTDIR}/src/sprite.o: nbproject/Makefile-${CND_CONF}.mk src/sprite.cc 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Iinclude -I/usr/include/Gosu -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/sprite.o src/sprite.cc

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/GNU-Linux-x86/jod

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

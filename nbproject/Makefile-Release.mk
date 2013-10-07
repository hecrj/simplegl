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
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/1743844973/RotationTool.o \
	${OBJECTDIR}/states/BackgroundSelector.o \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/Viewport.o \
	${OBJECTDIR}/Window.o \
	${OBJECTDIR}/Vertex.o \
	${OBJECTDIR}/Engine.o \
	${OBJECTDIR}/Color.o \
	${OBJECTDIR}/_ext/278205734/Cone.o \
	${OBJECTDIR}/objects/Triangle.o \
	${OBJECTDIR}/Object.o \
	${OBJECTDIR}/states/TriangleSelector.o \
	${OBJECTDIR}/_ext/278205734/Sphere.o \
	${OBJECTDIR}/objects/Teapot.o \
	${OBJECTDIR}/_ext/1743844973/MoveTool.o \
	${OBJECTDIR}/StateMachine.o \
	${OBJECTDIR}/_ext/1784398881/Tool.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsimplegl.${CND_DLIB_EXT}

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsimplegl.${CND_DLIB_EXT}: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -dynamiclib -install_name libsimplegl.${CND_DLIB_EXT} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsimplegl.${CND_DLIB_EXT} -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1743844973/RotationTool.o: /Users/hector0193/Proyectos/idi/Bloc2/simplegl/tools/RotationTool.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1743844973
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1743844973/RotationTool.o /Users/hector0193/Proyectos/idi/Bloc2/simplegl/tools/RotationTool.cpp

${OBJECTDIR}/states/BackgroundSelector.o: states/BackgroundSelector.cpp 
	${MKDIR} -p ${OBJECTDIR}/states
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/states/BackgroundSelector.o states/BackgroundSelector.cpp

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/Viewport.o: Viewport.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Viewport.o Viewport.cpp

${OBJECTDIR}/Window.o: Window.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Window.o Window.cpp

${OBJECTDIR}/Vertex.o: Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Vertex.o Vertex.cpp

${OBJECTDIR}/Engine.o: Engine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Engine.o Engine.cpp

${OBJECTDIR}/Color.o: Color.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Color.o Color.cpp

${OBJECTDIR}/_ext/278205734/Cone.o: /Users/hector0193/Proyectos/idi/Bloc2/simplegl/objects/Cone.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/278205734
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/278205734/Cone.o /Users/hector0193/Proyectos/idi/Bloc2/simplegl/objects/Cone.cpp

${OBJECTDIR}/objects/Triangle.o: objects/Triangle.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Triangle.o objects/Triangle.cpp

${OBJECTDIR}/Object.o: Object.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Object.o Object.cpp

${OBJECTDIR}/states/TriangleSelector.o: states/TriangleSelector.cpp 
	${MKDIR} -p ${OBJECTDIR}/states
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/states/TriangleSelector.o states/TriangleSelector.cpp

${OBJECTDIR}/_ext/278205734/Sphere.o: /Users/hector0193/Proyectos/idi/Bloc2/simplegl/objects/Sphere.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/278205734
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/278205734/Sphere.o /Users/hector0193/Proyectos/idi/Bloc2/simplegl/objects/Sphere.cpp

${OBJECTDIR}/objects/Teapot.o: objects/Teapot.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Teapot.o objects/Teapot.cpp

${OBJECTDIR}/_ext/1743844973/MoveTool.o: /Users/hector0193/Proyectos/idi/Bloc2/simplegl/tools/MoveTool.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1743844973
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1743844973/MoveTool.o /Users/hector0193/Proyectos/idi/Bloc2/simplegl/tools/MoveTool.cpp

${OBJECTDIR}/StateMachine.o: StateMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/StateMachine.o StateMachine.cpp

${OBJECTDIR}/_ext/1784398881/Tool.o: /Users/hector0193/Proyectos/idi/Bloc2/simplegl/Tool.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1784398881
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1784398881/Tool.o /Users/hector0193/Proyectos/idi/Bloc2/simplegl/Tool.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsimplegl.${CND_DLIB_EXT}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

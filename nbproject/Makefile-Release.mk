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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/State.o \
	${OBJECTDIR}/states/BackgroundSelector.o \
	${OBJECTDIR}/tools/MoveTool.o \
	${OBJECTDIR}/objects/Sphere.o \
	${OBJECTDIR}/objects/Snowman.o \
	${OBJECTDIR}/Tool.o \
	${OBJECTDIR}/Viewport.o \
	${OBJECTDIR}/Window.o \
	${OBJECTDIR}/Vertex.o \
	${OBJECTDIR}/Engine.o \
	${OBJECTDIR}/tools/RotationTool.o \
	${OBJECTDIR}/Color.o \
	${OBJECTDIR}/objects/Triangle.o \
	${OBJECTDIR}/Object.o \
	${OBJECTDIR}/states/TriangleSelector.o \
	${OBJECTDIR}/objects/Teapot.o \
	${OBJECTDIR}/objects/Cone.o \
	${OBJECTDIR}/StateMachine.o \
	${OBJECTDIR}/objects/Plane.o


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
	${LINK.cc} -shared -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libsimplegl.${CND_DLIB_EXT} -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/State.o: State.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/State.o State.cpp

${OBJECTDIR}/states/BackgroundSelector.o: states/BackgroundSelector.cpp 
	${MKDIR} -p ${OBJECTDIR}/states
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/states/BackgroundSelector.o states/BackgroundSelector.cpp

${OBJECTDIR}/tools/MoveTool.o: tools/MoveTool.cpp 
	${MKDIR} -p ${OBJECTDIR}/tools
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/tools/MoveTool.o tools/MoveTool.cpp

${OBJECTDIR}/objects/Sphere.o: objects/Sphere.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Sphere.o objects/Sphere.cpp

${OBJECTDIR}/objects/Snowman.o: objects/Snowman.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Snowman.o objects/Snowman.cpp

${OBJECTDIR}/Tool.o: Tool.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Tool.o Tool.cpp

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

${OBJECTDIR}/tools/RotationTool.o: tools/RotationTool.cpp 
	${MKDIR} -p ${OBJECTDIR}/tools
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/tools/RotationTool.o tools/RotationTool.cpp

${OBJECTDIR}/Color.o: Color.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Color.o Color.cpp

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

${OBJECTDIR}/objects/Teapot.o: objects/Teapot.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Teapot.o objects/Teapot.cpp

${OBJECTDIR}/objects/Cone.o: objects/Cone.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Cone.o objects/Cone.cpp

${OBJECTDIR}/StateMachine.o: StateMachine.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/StateMachine.o StateMachine.cpp

${OBJECTDIR}/objects/Plane.o: objects/Plane.cpp 
	${MKDIR} -p ${OBJECTDIR}/objects
	${RM} $@.d
	$(COMPILE.cc) -O2 -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/objects/Plane.o objects/Plane.cpp

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

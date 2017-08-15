################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
..\src/delay/delay.c 

C_DEPS += \
./src/delay/delay.d 

OBJS += \
./src/delay/delay.obj 


# Each subdirectory must supply rules for building sources it contributes
src/delay/%.obj: ../src/delay/%.c
	@echo 'Scanning and building file: $<'
	@echo 'Invoking: Scanner and Compiler'
	ccrx  -MM -MP -output=dep="$(@:%.obj=%.d)" -MT="$(@:%.obj=%.obj)" -MT="$(@:%.obj=%.d)" -lang=c   -include="C:\PROGRA~2\Renesas\RX\2_4_1/include","D:\Documents\Texas Instruments\workspace_v7\RX_PROJECT_Y_2_0\src"  -debug -nomessage -isa=rxv2 -fpu -alias=noansi -nologo  -define=__RX   "$<"
	ccrx -lang=c -output=obj="$(@:%.d=%.obj)"  -include="C:\PROGRA~2\Renesas\RX\2_4_1/include","D:\Documents\Texas Instruments\workspace_v7\RX_PROJECT_Y_2_0\src"  -debug -nomessage -isa=rxv2 -fpu -alias=noansi -nologo  -define=__RX   "$<"
	@echo 'Finished scanning and building: $<'
	@echo.


################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App.c \
../App_FunctionsandDefine.c \
../DIO_Prog.c \
../Keypad_program.c \
../LCD_Prog.c 

OBJS += \
./App.o \
./App_FunctionsandDefine.o \
./DIO_Prog.o \
./Keypad_program.o \
./LCD_Prog.o 

C_DEPS += \
./App.d \
./App_FunctionsandDefine.d \
./DIO_Prog.d \
./Keypad_program.d \
./LCD_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



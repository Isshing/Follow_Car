################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
CODE/Back_Wheel.obj: ../CODE/Back_Wheel.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/Beep.obj: ../CODE/Beep.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/Light.obj: ../CODE/Light.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/NRF24L01.obj: ../CODE/NRF24L01.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/Oled.obj: ../CODE/Oled.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/PM_Control.obj: ../CODE/PM_Control.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/QMath.obj: ../CODE/QMath.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/TOF.obj: ../CODE/TOF.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/WIRELESS.obj: ../CODE/WIRELESS.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/%.obj: ../CODE/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/all_init.obj: ../CODE/all_init.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/button.obj: ../CODE/button.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/delay.obj: ../CODE/delay.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/distance.obj: ../CODE/distance.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/encoder.obj: ../CODE/encoder.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/gy86.obj: ../CODE/gy86.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/gyroscope.obj: ../CODE/gyroscope.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/key.obj: ../CODE/key.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/main.obj: ../CODE/main.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/pwm.obj: ../CODE/pwm.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/timer.obj: ../CODE/timer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

CODE/uart.obj: ../CODE/uart.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/bin/cl430" -vmspx --data_model=restricted -O3 --use_hw_mpy=F5 --include_path="E:/Ti/ccs/ccs_base/msp430/include" --include_path="E:/Ti/workspace2/TJ" --include_path="E:/Ti/workspace2/TJ/driverlib/MSP430F5xx_6xx" --include_path="E:/Ti/ccs/tools/compiler/ti-cgt-msp430_21.6.1.LTS/include" --advice:power="all" --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --fp_reassoc=on --preproc_with_compile --preproc_dependency="CODE/$(basename $(<F)).d_raw" --obj_directory="CODE" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



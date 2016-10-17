################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
UARTmodule.obj: ../UARTmodule.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --temp_directory="D:/CodeComposerProj/CardReader001/out" --asm_directory="D:/CodeComposerProj/CardReader001/out" --list_directory="D:/CodeComposerProj/CardReader001/out" --preproc_with_compile --preproc_dependency="D:/CodeComposerProj/CardReader001/out/UARTmodule.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

init.obj: ../init.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --temp_directory="D:/CodeComposerProj/CardReader001/out" --asm_directory="D:/CodeComposerProj/CardReader001/out" --list_directory="D:/CodeComposerProj/CardReader001/out" --preproc_with_compile --preproc_dependency="D:/CodeComposerProj/CardReader001/out/init.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

initClock.obj: ../initClock.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --temp_directory="D:/CodeComposerProj/CardReader001/out" --asm_directory="D:/CodeComposerProj/CardReader001/out" --list_directory="D:/CodeComposerProj/CardReader001/out" --preproc_with_compile --preproc_dependency="D:/CodeComposerProj/CardReader001/out/initClock.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

initGpio.obj: ../initGpio.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --temp_directory="D:/CodeComposerProj/CardReader001/out" --asm_directory="D:/CodeComposerProj/CardReader001/out" --list_directory="D:/CodeComposerProj/CardReader001/out" --preproc_with_compile --preproc_dependency="D:/CodeComposerProj/CardReader001/out/initGpio.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --temp_directory="D:/CodeComposerProj/CardReader001/out" --asm_directory="D:/CodeComposerProj/CardReader001/out" --list_directory="D:/CodeComposerProj/CardReader001/out" --preproc_with_compile --preproc_dependency="D:/CodeComposerProj/CardReader001/out/main.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

timer.obj: ../timer.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/ccsv6/ccs_base/msp430/include" --include_path="D:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --temp_directory="D:/CodeComposerProj/CardReader001/out" --asm_directory="D:/CodeComposerProj/CardReader001/out" --list_directory="D:/CodeComposerProj/CardReader001/out" --preproc_with_compile --preproc_dependency="D:/CodeComposerProj/CardReader001/out/timer.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



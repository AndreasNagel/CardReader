################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
D:/Programmeerimine/Code\ Composer\ WS/CardReader/out/package_ti.mcu.msp430.driverlib.product.obj: ../msp430_driverlib_2_80_00_01/packages/ti/mcu/msp430/driverlib/product/package/package_ti.mcu.msp430.driverlib.product.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="C:/ti/ccsv6/ccs_base/msp430/include" --include_path="C:/ti/ccsv6/tools/compiler/msp430_15.12.3.LTS/include" --advice:power=all -g --define=__MSP430F5529__ --diag_warning=225 --display_error_number --diag_wrap=off --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --printf_support=minimal --temp_directory="D:/Programmeerimine/Code Composer WS/CardReader/out" --obj_directory="D:/Programmeerimine/Code Composer WS/CardReader/out" --list_directory="D:/Programmeerimine/Code Composer WS/CardReader/out" --asm_directory="D:/Programmeerimine/Code Composer WS/CardReader/out" --preproc_with_compile --preproc_dependency="D:/Programmeerimine/Code Composer WS/CardReader/out/msp430_driverlib_2_80_00_01/packages/ti/mcu/msp430/driverlib/product/package/package_ti.mcu.msp430.driverlib.product.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '



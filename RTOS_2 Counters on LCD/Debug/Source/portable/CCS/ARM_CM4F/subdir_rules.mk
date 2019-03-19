################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Source/portable/CCS/ARM_CM4F/port.obj: ../Source/portable/CCS/ARM_CM4F/port.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-052/workspace_v8/RTOS_Challenge2" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/AVE-LAP-052/workspace_v8/RTOS_Challenge2/Source" --include_path="C:/Users/AVE-LAP-052/workspace_v8/RTOS_Challenge2/Source/include" --include_path="C:/Users/AVE-LAP-052/workspace_v8/RTOS_Challenge2/Source/portable/CCS/ARM_CM4F" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Source/portable/CCS/ARM_CM4F/port.d_raw" --obj_directory="Source/portable/CCS/ARM_CM4F" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

Source/portable/CCS/ARM_CM4F/portasm.obj: ../Source/portable/CCS/ARM_CM4F/portasm.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/AVE-LAP-052/workspace_v8/RTOS_Challenge2" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/Users/AVE-LAP-052/workspace_v8/RTOS_Challenge2/Source" --include_path="C:/Users/AVE-LAP-052/workspace_v8/RTOS_Challenge2/Source/include" --include_path="C:/Users/AVE-LAP-052/workspace_v8/RTOS_Challenge2/Source/portable/CCS/ARM_CM4F" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.1.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Source/portable/CCS/ARM_CM4F/portasm.d_raw" --obj_directory="Source/portable/CCS/ARM_CM4F" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '



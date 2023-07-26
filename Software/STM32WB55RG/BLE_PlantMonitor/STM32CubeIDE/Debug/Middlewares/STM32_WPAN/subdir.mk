################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/STM32_WPAN/ble_gap_aci.c \
../Middlewares/STM32_WPAN/ble_gatt_aci.c \
../Middlewares/STM32_WPAN/ble_hal_aci.c \
../Middlewares/STM32_WPAN/ble_hci_le.c \
../Middlewares/STM32_WPAN/ble_l2cap_aci.c \
../Middlewares/STM32_WPAN/dbg_trace.c \
../Middlewares/STM32_WPAN/dis.c \
../Middlewares/STM32_WPAN/hci_tl.c \
../Middlewares/STM32_WPAN/hci_tl_if.c \
../Middlewares/STM32_WPAN/hrs.c \
../Middlewares/STM32_WPAN/hss.c \
../Middlewares/STM32_WPAN/osal.c \
../Middlewares/STM32_WPAN/otp.c \
../Middlewares/STM32_WPAN/shci.c \
../Middlewares/STM32_WPAN/shci_tl.c \
../Middlewares/STM32_WPAN/shci_tl_if.c \
../Middlewares/STM32_WPAN/stm_list.c \
../Middlewares/STM32_WPAN/stm_queue.c \
../Middlewares/STM32_WPAN/svc_ctl.c \
../Middlewares/STM32_WPAN/tl_mbox.c 

OBJS += \
./Middlewares/STM32_WPAN/ble_gap_aci.o \
./Middlewares/STM32_WPAN/ble_gatt_aci.o \
./Middlewares/STM32_WPAN/ble_hal_aci.o \
./Middlewares/STM32_WPAN/ble_hci_le.o \
./Middlewares/STM32_WPAN/ble_l2cap_aci.o \
./Middlewares/STM32_WPAN/dbg_trace.o \
./Middlewares/STM32_WPAN/dis.o \
./Middlewares/STM32_WPAN/hci_tl.o \
./Middlewares/STM32_WPAN/hci_tl_if.o \
./Middlewares/STM32_WPAN/hrs.o \
./Middlewares/STM32_WPAN/hss.o \
./Middlewares/STM32_WPAN/osal.o \
./Middlewares/STM32_WPAN/otp.o \
./Middlewares/STM32_WPAN/shci.o \
./Middlewares/STM32_WPAN/shci_tl.o \
./Middlewares/STM32_WPAN/shci_tl_if.o \
./Middlewares/STM32_WPAN/stm_list.o \
./Middlewares/STM32_WPAN/stm_queue.o \
./Middlewares/STM32_WPAN/svc_ctl.o \
./Middlewares/STM32_WPAN/tl_mbox.o 

C_DEPS += \
./Middlewares/STM32_WPAN/ble_gap_aci.d \
./Middlewares/STM32_WPAN/ble_gatt_aci.d \
./Middlewares/STM32_WPAN/ble_hal_aci.d \
./Middlewares/STM32_WPAN/ble_hci_le.d \
./Middlewares/STM32_WPAN/ble_l2cap_aci.d \
./Middlewares/STM32_WPAN/dbg_trace.d \
./Middlewares/STM32_WPAN/dis.d \
./Middlewares/STM32_WPAN/hci_tl.d \
./Middlewares/STM32_WPAN/hci_tl_if.d \
./Middlewares/STM32_WPAN/hrs.d \
./Middlewares/STM32_WPAN/hss.d \
./Middlewares/STM32_WPAN/osal.d \
./Middlewares/STM32_WPAN/otp.d \
./Middlewares/STM32_WPAN/shci.d \
./Middlewares/STM32_WPAN/shci_tl.d \
./Middlewares/STM32_WPAN/shci_tl_if.d \
./Middlewares/STM32_WPAN/stm_list.d \
./Middlewares/STM32_WPAN/stm_queue.d \
./Middlewares/STM32_WPAN/svc_ctl.d \
./Middlewares/STM32_WPAN/tl_mbox.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/STM32_WPAN/%.o Middlewares/STM32_WPAN/%.su Middlewares/STM32_WPAN/%.cyclo: ../Middlewares/STM32_WPAN/%.c Middlewares/STM32_WPAN/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_NUCLEO -DDEBUG -DSTM32WB55xx -c -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Middlewares/ST/STM32_WPAN/ble" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32CubeIDE/Middlewares/STM32_WPAN/Inc" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Core/Inc" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Middlewares/ST/STM32_WPAN/ble/svc/Inc" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/svc/Src" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/BSP/P-NUCLEO-WB55.Nucleo" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Middlewares/ST/STM32_WPAN/ble/core/auto" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Device/ST/STM32WBxx/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/utilities" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/lpm/tiny_lpm" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/sequencer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-STM32_WPAN

clean-Middlewares-2f-STM32_WPAN:
	-$(RM) ./Middlewares/STM32_WPAN/ble_gap_aci.cyclo ./Middlewares/STM32_WPAN/ble_gap_aci.d ./Middlewares/STM32_WPAN/ble_gap_aci.o ./Middlewares/STM32_WPAN/ble_gap_aci.su ./Middlewares/STM32_WPAN/ble_gatt_aci.cyclo ./Middlewares/STM32_WPAN/ble_gatt_aci.d ./Middlewares/STM32_WPAN/ble_gatt_aci.o ./Middlewares/STM32_WPAN/ble_gatt_aci.su ./Middlewares/STM32_WPAN/ble_hal_aci.cyclo ./Middlewares/STM32_WPAN/ble_hal_aci.d ./Middlewares/STM32_WPAN/ble_hal_aci.o ./Middlewares/STM32_WPAN/ble_hal_aci.su ./Middlewares/STM32_WPAN/ble_hci_le.cyclo ./Middlewares/STM32_WPAN/ble_hci_le.d ./Middlewares/STM32_WPAN/ble_hci_le.o ./Middlewares/STM32_WPAN/ble_hci_le.su ./Middlewares/STM32_WPAN/ble_l2cap_aci.cyclo ./Middlewares/STM32_WPAN/ble_l2cap_aci.d ./Middlewares/STM32_WPAN/ble_l2cap_aci.o ./Middlewares/STM32_WPAN/ble_l2cap_aci.su ./Middlewares/STM32_WPAN/dbg_trace.cyclo ./Middlewares/STM32_WPAN/dbg_trace.d ./Middlewares/STM32_WPAN/dbg_trace.o ./Middlewares/STM32_WPAN/dbg_trace.su ./Middlewares/STM32_WPAN/dis.cyclo ./Middlewares/STM32_WPAN/dis.d ./Middlewares/STM32_WPAN/dis.o ./Middlewares/STM32_WPAN/dis.su ./Middlewares/STM32_WPAN/hci_tl.cyclo ./Middlewares/STM32_WPAN/hci_tl.d ./Middlewares/STM32_WPAN/hci_tl.o ./Middlewares/STM32_WPAN/hci_tl.su ./Middlewares/STM32_WPAN/hci_tl_if.cyclo ./Middlewares/STM32_WPAN/hci_tl_if.d ./Middlewares/STM32_WPAN/hci_tl_if.o ./Middlewares/STM32_WPAN/hci_tl_if.su ./Middlewares/STM32_WPAN/hrs.cyclo ./Middlewares/STM32_WPAN/hrs.d ./Middlewares/STM32_WPAN/hrs.o ./Middlewares/STM32_WPAN/hrs.su ./Middlewares/STM32_WPAN/hss.cyclo ./Middlewares/STM32_WPAN/hss.d ./Middlewares/STM32_WPAN/hss.o ./Middlewares/STM32_WPAN/hss.su ./Middlewares/STM32_WPAN/osal.cyclo ./Middlewares/STM32_WPAN/osal.d ./Middlewares/STM32_WPAN/osal.o ./Middlewares/STM32_WPAN/osal.su ./Middlewares/STM32_WPAN/otp.cyclo ./Middlewares/STM32_WPAN/otp.d ./Middlewares/STM32_WPAN/otp.o ./Middlewares/STM32_WPAN/otp.su ./Middlewares/STM32_WPAN/shci.cyclo ./Middlewares/STM32_WPAN/shci.d ./Middlewares/STM32_WPAN/shci.o ./Middlewares/STM32_WPAN/shci.su ./Middlewares/STM32_WPAN/shci_tl.cyclo ./Middlewares/STM32_WPAN/shci_tl.d ./Middlewares/STM32_WPAN/shci_tl.o ./Middlewares/STM32_WPAN/shci_tl.su ./Middlewares/STM32_WPAN/shci_tl_if.cyclo ./Middlewares/STM32_WPAN/shci_tl_if.d ./Middlewares/STM32_WPAN/shci_tl_if.o ./Middlewares/STM32_WPAN/shci_tl_if.su ./Middlewares/STM32_WPAN/stm_list.cyclo ./Middlewares/STM32_WPAN/stm_list.d ./Middlewares/STM32_WPAN/stm_list.o ./Middlewares/STM32_WPAN/stm_list.su ./Middlewares/STM32_WPAN/stm_queue.cyclo ./Middlewares/STM32_WPAN/stm_queue.d ./Middlewares/STM32_WPAN/stm_queue.o ./Middlewares/STM32_WPAN/stm_queue.su ./Middlewares/STM32_WPAN/svc_ctl.cyclo ./Middlewares/STM32_WPAN/svc_ctl.d ./Middlewares/STM32_WPAN/svc_ctl.o ./Middlewares/STM32_WPAN/svc_ctl.su ./Middlewares/STM32_WPAN/tl_mbox.cyclo ./Middlewares/STM32_WPAN/tl_mbox.d ./Middlewares/STM32_WPAN/tl_mbox.o ./Middlewares/STM32_WPAN/tl_mbox.su

.PHONY: clean-Middlewares-2f-STM32_WPAN


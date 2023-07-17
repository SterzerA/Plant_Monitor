################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/Target/hw_ipcc.c 

OBJS += \
./Application/User/STM32_WPAN/Target/hw_ipcc.o 

C_DEPS += \
./Application/User/STM32_WPAN/Target/hw_ipcc.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/STM32_WPAN/Target/hw_ipcc.o: C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/Target/hw_ipcc.c Application/User/STM32_WPAN/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_NUCLEO -DDEBUG -DSTM32WB55xx -c -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Core/Inc" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/svc/Src" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/BSP/P-NUCLEO-WB55.Nucleo" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Middlewares/ST/STM32_WPAN/ble/core/auto" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Device/ST/STM32WBxx/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/utilities" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/lpm/tiny_lpm" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/sequencer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-STM32_WPAN-2f-Target

clean-Application-2f-User-2f-STM32_WPAN-2f-Target:
	-$(RM) ./Application/User/STM32_WPAN/Target/hw_ipcc.cyclo ./Application/User/STM32_WPAN/Target/hw_ipcc.d ./Application/User/STM32_WPAN/Target/hw_ipcc.o ./Application/User/STM32_WPAN/Target/hw_ipcc.su

.PHONY: clean-Application-2f-User-2f-STM32_WPAN-2f-Target


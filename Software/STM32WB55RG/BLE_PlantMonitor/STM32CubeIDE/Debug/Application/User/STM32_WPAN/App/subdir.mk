################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App/app_ble.c \
C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App/dis_app.c \
C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App/hrs_app.c \
../Application/User/STM32_WPAN/App/pms_app.c 

OBJS += \
./Application/User/STM32_WPAN/App/app_ble.o \
./Application/User/STM32_WPAN/App/dis_app.o \
./Application/User/STM32_WPAN/App/hrs_app.o \
./Application/User/STM32_WPAN/App/pms_app.o 

C_DEPS += \
./Application/User/STM32_WPAN/App/app_ble.d \
./Application/User/STM32_WPAN/App/dis_app.d \
./Application/User/STM32_WPAN/App/hrs_app.d \
./Application/User/STM32_WPAN/App/pms_app.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/STM32_WPAN/App/app_ble.o: C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App/app_ble.c Application/User/STM32_WPAN/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_NUCLEO -DDEBUG -DSTM32WB55xx -c -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Core/Inc" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/svc/Src" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/BSP/P-NUCLEO-WB55.Nucleo" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Middlewares/ST/STM32_WPAN/ble/core/auto" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Device/ST/STM32WBxx/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/utilities" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/lpm/tiny_lpm" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/sequencer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/STM32_WPAN/App/dis_app.o: C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App/dis_app.c Application/User/STM32_WPAN/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_NUCLEO -DDEBUG -DSTM32WB55xx -c -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Core/Inc" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/svc/Src" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/BSP/P-NUCLEO-WB55.Nucleo" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Middlewares/ST/STM32_WPAN/ble/core/auto" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Device/ST/STM32WBxx/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/utilities" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/lpm/tiny_lpm" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/sequencer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/STM32_WPAN/App/hrs_app.o: C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App/hrs_app.c Application/User/STM32_WPAN/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_NUCLEO -DDEBUG -DSTM32WB55xx -c -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Core/Inc" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/svc/Src" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/BSP/P-NUCLEO-WB55.Nucleo" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Middlewares/ST/STM32_WPAN/ble/core/auto" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Device/ST/STM32WBxx/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/utilities" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/lpm/tiny_lpm" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/sequencer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Application/User/STM32_WPAN/App/%.o Application/User/STM32_WPAN/App/%.su Application/User/STM32_WPAN/App/%.cyclo: ../Application/User/STM32_WPAN/App/%.c Application/User/STM32_WPAN/App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DUSE_STM32WBXX_NUCLEO -DDEBUG -DSTM32WB55xx -c -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Core/Inc" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/STM32_WPAN/App" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/svc/Src" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/BSP/P-NUCLEO-WB55.Nucleo" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Projects/Plant_Monitor/Software/STM32WB55RG/BLE_PlantMonitor/Middlewares/ST/STM32_WPAN/ble/core/auto" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Device/ST/STM32WBxx/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/CMSIS/Include" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Drivers/STM32WBxx_HAL_Driver/Inc/Legacy" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/ble/core/template" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/shci" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/interface/patterns/ble_thread/tl" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Middlewares/ST/STM32_WPAN/utilities" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/lpm/tiny_lpm" -I"C:/Users/alexa/Documents/STM32/NUCLEO-WB55RG/en.stm32cubewb-v1-16-0/STM32Cube_FW_WB_V1.16.0/Utilities/sequencer" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-STM32_WPAN-2f-App

clean-Application-2f-User-2f-STM32_WPAN-2f-App:
	-$(RM) ./Application/User/STM32_WPAN/App/app_ble.cyclo ./Application/User/STM32_WPAN/App/app_ble.d ./Application/User/STM32_WPAN/App/app_ble.o ./Application/User/STM32_WPAN/App/app_ble.su ./Application/User/STM32_WPAN/App/dis_app.cyclo ./Application/User/STM32_WPAN/App/dis_app.d ./Application/User/STM32_WPAN/App/dis_app.o ./Application/User/STM32_WPAN/App/dis_app.su ./Application/User/STM32_WPAN/App/hrs_app.cyclo ./Application/User/STM32_WPAN/App/hrs_app.d ./Application/User/STM32_WPAN/App/hrs_app.o ./Application/User/STM32_WPAN/App/hrs_app.su ./Application/User/STM32_WPAN/App/pms_app.cyclo ./Application/User/STM32_WPAN/App/pms_app.d ./Application/User/STM32_WPAN/App/pms_app.o ./Application/User/STM32_WPAN/App/pms_app.su

.PHONY: clean-Application-2f-User-2f-STM32_WPAN-2f-App

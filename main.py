#╭━━━┳━━━┳━━━╮╭╮
#┃╭━╮┃╭━╮┃╭━╮┣╯┃
#┃┃╱┃┃╰━╯┃╰━━╋╮┃
#┃╰━╯┃╭╮╭┻━━╮┃┃┃
#┃╭━╮┃┃┃╰┫╰━╯┣╯╰╮
#╰╯╱╰┻╯╰━┻━━━┻━━╯

import psutil
import serial
import time

# Замените 'COM3' на ваш порт
ser = serial.Serial('COM3', 9600)

while True:
    disk_usage = psutil.disk_usage('/')
    cpu_usage = psutil.cpu_percent()
    memory_info = psutil.virtual_memory()

    # Форматируем данные для отправки
    data = f"CPU:{cpu_usage}%  "
    mem = f"Ram:{memory_info.percent}% "
    disk = f"Disk:{disk_usage.percent}%"

    # Отладочный вывод
    print(f"CPU: {cpu_usage}%, RAM: {memory_info.percent}%, Disk: {disk_usage.percent}%")

    # Отправляем данные на Arduino
    ser.write((data + mem + disk + '\n').encode())
    time.sleep(1)

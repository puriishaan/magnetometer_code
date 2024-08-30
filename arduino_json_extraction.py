import serial
import json

# Open the serial port (replace 'COM3' with your Arduino's port)
ser = serial.Serial('/dev/cu.usbmodem102', 9600)  # Adjust 'COM3' to match your port
data_list = []

try:
    while True:
        if ser.in_waiting > 0:
            line = ser.readline().decode('utf-8').strip()
            try:
                data = json.loads(line)
                data_list.append(data)
                print(data)
            except json.JSONDecodeError:
                pass

            # Stop after n readings
            if len(data_list) >= 3:  # Replace 10 with your desired number of readings
                break
except KeyboardInterrupt:
    pass
finally:
    ser.close()

# Save data to a JSON file
with open('magnetometer_data.json', 'w') as json_file:
    json.dump(data_list, json_file, indent=4)

# touchdesigner + arduino serial communication

<br>

## sending and receiving a single variable

1. upload serial_example to arduino (one variable sending and receiving)

2. run touchdesigner serial_in.toe
![td_serial_single](https://github.com/user-attachments/assets/bbc28597-f5de-45c8-b57e-e1e3c5e53c2d)

3. setup serial component
![serial_comp](https://github.com/user-attachments/assets/5701096b-119c-4ba0-a8cf-14f4a1d2f18f)

<br>

## python serial send
![python_send](https://github.com/user-attachments/assets/a1cfd14c-ae2e-4f34-a86b-817d58d94701)

<br>

```python
def onValueChange(channel, sampleIndex, val, prev):
	value = int(val)
	dataToSend = str(value) + '\n'
	serial_dat = op('serial1')
	serial_dat.send(dataToSend)
	print("sent: " + dataToSend)

	return
	
```

<br>

## sending and receiving multiple variables

1. upload multiple_serial_example to arduino (multiple variable sending and receiving + parsing)
2. run touchdesigner serial_in_multiple.toe
![td_serial_multiple](https://github.com/user-attachments/assets/4f45ac69-8fe5-444d-99da-ec3f380b8fd1)

<br>

## python receive and parse multiple variables
![python_receive_multiple](https://github.com/user-attachments/assets/bffa92ca-b451-4c29-8840-6b55507b0cc4)


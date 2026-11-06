This code generates a start condition with a write operation to set the address pointer of the encoder
Then generates a repeated start condition to read 2 consecutive bytes of data
Finally, it stops the communication


Things to improve on:
Update gpio's driver to initilaze alternate functions based on the pin and the af number
create specific rutines to recevie a data, repated start, and i2c's basic transactions


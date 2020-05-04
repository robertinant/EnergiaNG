# `BMA222`






## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
[`public  BMA222()`](#class_b_m_a222_1a02b0cc3e760a69eeb8ddf9fc1fe7eeb2) | Constructor. Initialize the library.
[`public  ~BMA222()`](#class_b_m_a222_1a6febb62c87174583f2839a843db7240a) | Decononstructor. Delete the instance.
[`public void begin(uint8_t addr)`](#class_b_m_a222_1afa7616117c3d20b703a6dfbf88b7c529) | Initialize the library.
[`public int8_t readReg(uint8_t reg)`](#class_b_m_a222_1a72a5b4d6b453786732be0545cbe351d6) | Read the raw value of a [BMA222](#class_b_m_a222) registers.
[`public uint8_t chipID()`](#class_b_m_a222_1a54a70a1bae19693d458da142a8a4ef76) | Read chip ID.
[`public int16_t readXData()`](#class_b_m_a222_1ac277ef2988461014898167f9403e049e) | Read accelerometer X data.
[`public int16_t readYData()`](#class_b_m_a222_1a43637ce36a4fbcba18dd62fc1174b3c8) | Read accelerometer Y data.
[`public int16_t readZData()`](#class_b_m_a222_1a579e07c64eed28175807bebb4b6cd62d) | Read accelerometer Z data.

## Members


### <a name="class_b_m_a222_1a02b0cc3e760a69eeb8ddf9fc1fe7eeb2"></a>`public  BMA222()`

Constructor. Initialize the library.

Create an instance of the BMA library. This instance can then be used to call the instance functions.


#### Returns
BMA instance

### <a name="class_b_m_a222_1a6febb62c87174583f2839a843db7240a"></a>`public  ~BMA222()`

Decononstructor. Delete the instance.

Delete the instance of the BMA library. After calling the deconstructor, memerber functions can no longer be called on the instance.


#### Returns
BMA instance

### <a name="class_b_m_a222_1afa7616117c3d20b703a6dfbf88b7c529"></a>`public void begin(uint8_t addr)`

Initialize the library.

Initializes the Wire interface witht the optional I2C device address.


#### Parameters
* `addr` Optional device I2C address. The default value is BMA222_DEV_ADDR (0x18).





#### Returns
none

### <a name="class_b_m_a222_1a72a5b4d6b453786732be0545cbe351d6"></a>`public int8_t readReg(uint8_t reg)`

Read the raw value of a [BMA222](#class_b_m_a222) registers.

Read the raw value of a [BMA222](#class_b_m_a222) registers. See the datasheet [datasheet](https://datasheet.octopart.com/BMA222-Bosch-datasheet-15540102.pdf) for details.


#### Parameters
* `reg` Register address.





#### Returns
Register value. If the register read is not X, Y or Z then the return should be cast to a uint8_t.

### <a name="class_b_m_a222_1a54a70a1bae19693d458da142a8a4ef76"></a>`public uint8_t chipID()`

Read chip ID.

The returned chip ID should read as 0x3.


#### Returns
Chip ID.

### <a name="class_b_m_a222_1ac277ef2988461014898167f9403e049e"></a>`public int16_t readXData()`

Read accelerometer X data.

#### Returns
Accelerometer X data.

### <a name="class_b_m_a222_1a43637ce36a4fbcba18dd62fc1174b3c8"></a>`public int16_t readYData()`

Read accelerometer Y data.

#### Returns
Accelerometer Y data.

### <a name="class_b_m_a222_1a579e07c64eed28175807bebb4b6cd62d"></a>`public int16_t readZData()`

Read accelerometer Z data.

#### Returns
Accelerometer Z data.



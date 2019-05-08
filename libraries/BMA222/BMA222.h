#include "Energia.h"
#include <Wire.h>

#ifndef BMA222_h
#define BMA222_h
#endif

#define BMA222_DEV_ADDR 0x18
#define BMA222_CHIP_ID_REG 0x00

#define BMA222_ACC_DATA_X_NEW (0x2)
#define BMA222_ACC_DATA_X     (0x3)
#define BMA222_ACC_DATA_Y_NEW (0x4)
#define BMA222_ACC_DATA_Y     (0x5)
#define BMA222_ACC_DATA_Z_NEW (0x6)
#define BMA222_ACC_DATA_Z     (0x7)

class BMA222 {
private:
	uint8_t i2cAddr;
public:
	/**
	 * @brief Constructor. Initialize the library.
	 *
	 * Create an instance of the BMA library. This instance can then be used to call the instance functions.
	 *
	 * @return BMA instance
	 */
	BMA222();
	/**
	 * @brief Decononstructor. Delete the instance.
	 *
	 * Delete the instance of the BMA library. After calling the deconstructor, memerber functions can no longer be called on the instance.
	 *
	 * @return BMA instance
	 */
	~BMA222();
	/**
	 * @brief Initialize the library.
	 *
	 * Initializes the Wire interface witht the optional I2C device address.
	 *
	 * @param addr Optional device I2C address.
	 * The default value is BMA222_DEV_ADDR (0x18).
	 *
	 * @return none
	 */
	void begin(uint8_t addr=BMA222_DEV_ADDR);
	/**
	 * @brief Read the raw value of a BMA222 registers.
	 *
	 * Read the raw value of a BMA222 registers. See the datasheet <a href="https://datasheet.octopart.com/BMA222-Bosch-datasheet-15540102.pdf">datasheet</a>
	 * for details.
	 *
	 * @param reg Register address.
	 *
	 * @return Register value. If the register read is not X, Y or Z then the return should be cast to a uint8_t.
	 */
	int8_t readReg(uint8_t reg);
	/**
	 * @brief Read chip ID.
	 *
	 * The returned chip ID should read as 0x3.
	 *
	 * @return Chip ID.
	 */
	uint8_t chipID();
	/**
	 * @brief Read accelerometer X data.
	 *
	 * @return Accelerometer X data.
	 */
	int16_t readXData();
	/**
	 * @brief Read accelerometer Y data.
	 *
	 * @return Accelerometer Y data.
	 */
	int16_t readYData();
	/**
	 * @brief Read accelerometer Z data.
	 *
	 * @return Accelerometer Z data.
	 */
	int16_t readZData();
};

#ifndef _SPEAKER_H_
#define _SPEAKER_H_

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/i2s.h>
#include <esp_err.h>
#include <Wire.h>

#define CONFIG_I2S_BCK_PIN 12  //定义I2S相关端口
#define CONFIG_I2S_LRCK_PIN 0
#define CONFIG_I2S_DATA_PIN 2
#define CONFIG_I2S_DATA_IN_PIN 34

#define Speak_I2S_NUMBER I2S_NUM_0  //定义扬声器端口

#define MODE_MIC 0  //定义工作模式
#define MODE_SPK 1
#define DATA_SIZE 1024

class Speaker {
 private:
  void Write1Byte(uint8_t Addr, uint8_t Data);
  uint8_t Read8bit(uint8_t Addr);

 public:
  void begin(void);
  bool InitI2SSpeakOrMic(int mode);
  // Plays the given amount of bytes from the given data array and returns the amount of bytes,
  // that were actually played by the speaker.
  const size_t PlaySound(const unsigned char* data, const size_t& amount_of_bytes);
};
#endif


#pragma once

#include <stdint.h>
#include "sd.h"

class FileBuffer {
 public:
  FileBuffer(FileHandlePtr file);
  virtual ~FileBuffer();
  void RewindToStart();
  bool available() const;
  int32_t BytesLeft() const;
  int32_t FileSize() const;

  // Reads the next byte, else -1 is returned for end of buffer.
  int16_t read();
  bool Read(uint8_t* dst);

 private:
  void ResetBuffer();
  void RefillBufferIfNecessary();
  void RefillBuffer();

  // Experimentally found to be as fast as larger values.
  static const int kBufferSize = 64;
  uint8_t mBuffer[kBufferSize];
  int16_t mCurrIdx;
  int16_t mLength;

  FileHandlePtr mFile;
  bool mIsOpen;
};

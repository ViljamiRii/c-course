#include "header.h"
#include <stdio.h>

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header is valid, possibly checked using validateHeader function above, and ACK bit is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */

#define SYNC_VAL 0x2a
#define ACK_MASK 0x40
#define V_MASK 0x80
#define TYPE_MASK 0x700
#define FRAME_ID_MASK 0xf800
#define SOURCE_ADDRESS_MASK 0xff0000
#define DESTINATION_ADDRESS_MASK 0xff000000
#define TYPE_SHIFT 8
#define FRAME_ID_SHIFT 11
#define SOURCE_ADDRESS_SHIFT 16
#define DESTINATION_ADDRESS_SHIFT 24


int validateHeader(uint32_t header) {

  int sync = header & 0x3f;
  int ack = header & ACK_MASK;
  int v = header & V_MASK;
  int type = (header & TYPE_MASK) >> TYPE_SHIFT;
  int sourceAddress = (header & SOURCE_ADDRESS_MASK) >> SOURCE_ADDRESS_SHIFT;
  int destAddress = (header & DESTINATION_ADDRESS_MASK) >> DESTINATION_ADDRESS_SHIFT;

  if (sync != SYNC_VAL) {
    return 0;
  }
  if (ack && !v) {
    return 0;
  }
  if (!ack && !type) {
    return 0;
  }
  if (!sourceAddress || !destAddress || sourceAddress == destAddress) {
    return 0;
  }
  return 1;
}

int getFrameId(uint32_t header) {
  if (!validateHeader(header)) {
    return -1;
  }
  int frameId = (header & FRAME_ID_MASK) >> FRAME_ID_SHIFT;
  return frameId;
}

int getFrameType(uint32_t header) {
  if (!validateHeader(header)) {
    return -1;
  }
  int ack = header & ACK_MASK;
  if (ack) {
    return 0;
  }
  int type = (header & TYPE_MASK) >> TYPE_SHIFT;
  return type;
}

int getSourceAddress(uint32_t header) {
  if (!validateHeader(header)) {
    return -1;
  }
  int sourceAddress = (header & SOURCE_ADDRESS_MASK) >> SOURCE_ADDRESS_SHIFT;
  return sourceAddress;
}

uint32_t createAckHeader(int destAddress, int sourceAddress, uint8_t frameId, char valid) {
    uint32_t header = SYNC_VAL;
    header |= ACK_MASK;
    header |= (valid != 0) ? V_MASK : 0;
    header |= (frameId & 0x1f) << FRAME_ID_SHIFT;
    header |= (sourceAddress & 0xff) << SOURCE_ADDRESS_SHIFT;
    header |= (destAddress & 0xff) << DESTINATION_ADDRESS_SHIFT;
    return header;
}

uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type)
{
    uint32_t header = SYNC_VAL;
    header |= (type << TYPE_SHIFT);
    header |= (frameId << FRAME_ID_SHIFT);
    header |= (sourceAddress & 0xff) << SOURCE_ADDRESS_SHIFT;
    header |= (destAddress & 0xff) << DESTINATION_ADDRESS_SHIFT;
    return header;
}
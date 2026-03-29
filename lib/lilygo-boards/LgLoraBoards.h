/**
 * @file        LgLoraBoards.h
 * @author      mcuw (112967559+mcuw@users.noreply.github.com)
 * @license     MIT
 * @copyright   Copyright (c) 2026 mcuw
 * @date        2026-03-26
 * @last-update 2026-03-26
 */
// https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series/blob/master/examples/TBeamFactory/TBeamFactory.ino

#ifndef LG_LORA_BOARDS_H
#define LG_LORA_BOARDS_H

#include "config.h"
#include "types/LgDevInfoTypes.h"
#include "devices/LgBluetooth.h"
#include "devices/LgButton.h"
#include "devices/LgDisplay.h"
#include "devices/LgGps.h"
#include "devices/LgLed.h"
#include "devices/LgPmu.h"
#include "devices/LgNtc.h"
#include "devices/LgSdCard.h"
#include "devices/LgTwoWire.h"

void setupRadioBoard();
void printBoardStatus();

// LoRa setup
bool setupRadio(bool restartOnFail = true);
bool beginRadioLib(bool restartOnFail = true);
// LoRa transactions
int hasRadio();
void readRadioBytes(int packetSize, byte* data);
int transmitRadioBytes(int packetSize, byte* data);


void printWakeupReason();

void getChipInfo();


extern uint32_t deviceOnline;

#endif /* LG_LORA_BOARDS_H */
#ifndef DERIVATION_H
#define DERVIATION_H

#include "util.h"
#include "keys.h"
#include "packages12.h"

#include "pki.h"

//extern const char package1_path[256];
extern const char secmon_path[256];
extern const char final_keyfile_path[256];


/**
 * @brief Finds relevant keys within package1
 * 
 * @param appstate State of the application 
 */
void derive_part0(application_ctx* appstate);

/**
 * @brief Adds in the seeds from KEYBLOB_SEEDS to the keyfile to make generating keys for other firmwares possible
 * 
 * @param appstate State of the application 
 */
void add_other_keyblob_seeds(application_ctx* appstate);

/**
 * @brief Finds relevant keys within secmon (Secure_Monitor.bin, code that runs in trustzone)
 * 
 * @param appstate State of the application 
 */
void derive_part1(application_ctx* appstate);

/**
 * @brief Does extra bits of derivation for keys we have the sources but not the extensions for and copies the keyfile to the final destination
 * 
 * @param appstate State of the application 
 */
void final_derivation(application_ctx* appstate);

#endif
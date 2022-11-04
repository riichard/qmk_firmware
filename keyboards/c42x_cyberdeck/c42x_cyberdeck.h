/* Copyright 2020 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"

#define ___ KC_NO

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments as on the physical keyboard
// The second converts the arguments into the 2-D scanned array

#define LAYOUT(                                                         \
    kF1,                                                        kF5,    \
    kF2,                                                        kF6,    \
    kF3,                                                        kF7,    \
    kF4,                                                        kF8,    \
    kPERF, kNAV, kPREV, kNEXT, kFPL, kPROG, kDIR,               kBRT,   \
                                                                kDIM,   \
    kA, kB, kC, kD, kE, kF,         k1,     k2,     k3,                 \
    kG, kH, kI, kJ, kK, kL,         k4,     k5,     k6,                 \
    kM, kN, kO, kP, kQ, kR,         k7,     k8,     k9,                 \
        kS, kT, kU, kV, kW,         kDOT,   k0,                         \
        kX, kY, kZ, kDEL, kCLR,     kMIN,   kSLASH                      \
) {                                                                     \
    { k2,  ___,    ___,  kB,  kPREV, ___,  ___,  kR, kZ,  kJ, kF2 }, \
    { k3,  ___,    ___,  kC,  kNEXT, ___,  ___,  kS, ___, kK, kF6 }, \
    { k4,  ___,    ___,  kD,  kFPL,  ___,  ___,  kT, ___, kL, kF3 }, \
    { k5,  kMIN,   ___,  kE,  kPROG, ___,  ___,  kU, ___, kM, kF7 }, \
    { k0,  k8,     ___,  ___, kPERF, kBRT, kCLR, kP, kX,  kH, kF1 }, \
    { k1,  k9,     ___,  kA,  kNAV,  kDIM, ___,  kQ, kY,  kI, kF5 }, \
    { k6,  kDOT,   ___,  kF,  kDIR,  ___,  ___,  kV, ___, kN, kF4 }, \
    { k7,  kSLASH, kDEL, kG,  ___,   ___,  ___,  kW, ___, kO, kF8 } \
}

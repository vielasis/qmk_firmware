#ifndef SATAN_H
#define SATAN_H

#include "quantum.h"

// readability
#define XXX KC_NO
#define KC_____ KC_TRNS
#define KC_F(x) F(x)

/* Satan GH60 matrix layout (3c is right of 3d, 3d is shift)
   * ,-----------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d| 49|
   * |-----------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d |
   * |-----------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2c|2d |
   * |-----------------------------------------------------------|
   * | 30 | 31| 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b|  3d | 3c |
   * |-----------------------------------------------------------|
   * | 40 | 41 | 42 |        45             | 4a | 4b | 4c | 4d  |
   * `-----------------------------------------------------------'
 */
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k49,\
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, \
	k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3c, \
	k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
	{k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
	{k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
	{k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, XXX, k2d}, \
	{k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, XXX, k3d}, \
	{k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, k49, k4a, k4b, k4c, k4d}  \
}
/* Satan GH60 ANSI layout
   * ,-----------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d    |
   * |-----------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d |
   * |-----------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2d    |
   * |-----------------------------------------------------------|
   * | 30     | 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b|    3d    |
   * |-----------------------------------------------------------|
   * | 40 | 41 | 42 |        45             | 4a | 4b | 4c | 4d  |
   * `-----------------------------------------------------------'
 */
#define KEYMAP_ANSI( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,      k2d, \
	k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b,      k3d, \
	k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
	{k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
	{k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
	{k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, XXX, k2d}, \
	{k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, XXX, k3d}, \
	{k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, XXX, k4a, k4b, k4c, k4d}  \
}

/* Satan HHKB matrix layout
   * ,------------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d| 49 |
   * |------------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d  |
   * |------------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2d     |
   * |------------------------------------------------------------|
   * | 30     | 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b| 3d   | 3c |
   * |------------------------------------------------------------|
   * | 40 | 41 | 42 |        45              | 4a | 4b | 4c | 4d  |
   * `------------------------------------------------------------'
 */

#define KEYMAP_HHKB( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k49, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b,      k2d, \
	k30,      k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3c, \
	k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
	{k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
	{k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
	{k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, XXX, k2d}, \
	{k30, XXX, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d}, \
	{k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, k49, k4a, k4b, k4c, k4d}  \
}

/* ISO w/ split right shift key matrix layout
   * ,-----------------------------------------------------------.
   * | 00 |01| 02| 03| 04| 05| 06| 07| 08| 09| 0a| 0b| 0c| 0d    |
   * |-----------------------------------------------------------|
   * | 10  | 11| 12| 13| 14| 15| 16| 17| 18| 19| 1a| 1b| 1c|  1d |
   * |-----------------------------------------------------------|
   * | 20    | 21| 22| 23| 24| 25| 26| 27| 28| 29| 2a| 2b| 2c|2d |
   * |-----------------------------------------------------------|
   * | 30 | 31| 32| 33| 34| 35| 36| 37| 38| 39| 3a| 3b|  3d  | 3c|
   * |-----------------------------------------------------------|
   * | 40 | 41 | 42 |        45             | 4a | 4b | 4c | 4d  |
   * `-----------------------------------------------------------'

   swap 3c and 3d. 3c is right of 3d in reality
 */
#define KEYMAP_ISO_SPLITRSHIFT( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, \
	k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, \
	k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, \
	k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3d, k3c, \
	k40, k41, k42,           k45,                     k4a, k4b, k4c, k4d  \
) \
{ \
	{k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d}, \
	{k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d}, \
	{k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d}, \
	{k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d}, \
	{k40, k41, k42, XXX, XXX, k45, XXX, XXX, XXX, XXX, k4a, k4b, k4c, k4d}  \
}

// For tkg.io compatibility, so you can copy paste generated keymaps in keymaps.c
#define KEYMAP_TKG( \
    K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, K0J, K0K, K0L, K0M, K0N, \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, K1L, K1M, K1N, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, K2L,      K2N, \
    K3A,      K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, K3L, K3M, K3N, \
    K4A, K4B, K4C,           K4F,                K4J, K4K, K4L, K4M, K4N  \
) { \
    { KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D, KC_##K0E, KC_##K0F, KC_##K0G, KC_##K0H, KC_##K0I, KC_##K0J, KC_##K0K, KC_##K0L, KC_##K0M, KC_##K0N }, \
    { KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D, KC_##K1E, KC_##K1F, KC_##K1G, KC_##K1H, KC_##K1I, KC_##K1J, KC_##K1K, KC_##K1L, KC_##K1M, KC_##K1N }, \
    { KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F, KC_##K2G, KC_##K2H, KC_##K2I, KC_##K2J, KC_##K2K, KC_##K2L, KC_NO,    KC_##K2N }, \
    { KC_##K3A, KC_NO,    KC_##K3C, KC_##K3D, KC_##K3E, KC_##K3F, KC_##K3G, KC_##K3H, KC_##K3I, KC_##K3J, KC_##K3K, KC_##K3L, KC_##K3M, KC_##K3N }, \
    { KC_##K4A, KC_##K4B, KC_##K4C, KC_NO,    KC_NO,    KC_##K4F, KC_NO,    KC_NO,    KC_NO,    KC_##K4J, KC_##K4K, KC_##K4L, KC_##K4M, KC_##K4N }  \
}

void matrix_init_user(void);
void matrix_scan_user(void);

#endif

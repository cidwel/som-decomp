#include "som_c.h"

/* C75C04 test_native_save_signature_pair_and_rotate_invalid_mask   [class A, 27 bytes, 12 instructions]
 * Source: src/rom/test_native_save_signature_pair_and_rotate_invalid_mask.s
 * Documented in docs/ui-native-loaded-game-save-validation.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: Y.
 */
static void test_native_save_signature_pair_and_rotate_invalid_mask(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint8_t value = BUS8(c, 0x306000 + x);
    if (value != 0xC5) {
        RAM8(0xA216) = (RAM8(0xA216) >> 1) | 0x80;
    } else {
        uint8_t value3 = BUS8(c, 0x3062BB + x);
        if (value3 == 0x3A) {
            RAM8(0xA216) >>= 1;
        } else {
            RAM8(0xA216) = (RAM8(0xA216) >> 1) | 0x80;
        }
    }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75C04, SOM_RTS, "gen", test_native_save_signature_pair_and_rotate_invalid_mask, 0, L_Y, 1, 1, 0, 27, 12)

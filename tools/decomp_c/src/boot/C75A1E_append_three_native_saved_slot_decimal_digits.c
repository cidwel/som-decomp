#include "som_c.h"

/* C75A1E append_three_native_saved_slot_decimal_digits   [class A, 20 bytes, 9 instructions]
 * Source: src/rom/append_three_native_saved_slot_decimal_digits.s
 * Documented in docs/ui-native-loaded-game-slot-descriptions.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void append_three_native_saved_slot_decimal_digits(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xA237);
    uint8_t a1;
    if (value != 0) {
        RAM8(0x9C00 + x) = value;
        a1 = value;
    } else {
        RAM8(0x9C00 + x) = 0x80;
        a1 = 0x80;
    }
    r->a = (a_hi << 8) | a1;
    r->x = (uint16_t)(x + 1);
    JSR(c, 0x5A30, 0xC75AFF); /* append_native_saved_slot_decimal_pair */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75A1E, SOM_RTS, "gen", append_three_native_saved_slot_decimal_digits, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 20, 9)

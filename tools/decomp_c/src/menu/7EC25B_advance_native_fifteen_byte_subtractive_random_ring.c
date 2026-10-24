#include "som_c.h"

/* 7EC25B advance_native_fifteen_byte_subtractive_random_ring   [class B, 45 bytes, 27 instructions]
 * Source: src/boot/advance_native_fifteen_byte_subtractive_random_ring.s
 * Documented in docs/boot-native-title-random.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$02D2.  Callers read: ABXYV.
 */
static void advance_native_fifteen_byte_subtractive_random_ring(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x02D2) { c->fail = 3; return; }
    uint8_t value = RAM8(0x102E4);
    uint8_t a1;
    if ((uint8_t)(value + 1) < 0x0F) {
        a1 = (uint8_t)(value + 1);
    } else {
        a1 = 0;
    }
    RAM8(0x102E4) = a1;
    uint8_t value2 = RAM8(0x102E5 + value);
    uint8_t value3 = RAM8(0x102E5 + a1);
    RAM8(0x102E5 + a1) = (uint8_t)(value2 - value3);
    r->a = (uint8_t)(value2 - value3);
    r->x = a1;
    r->y = value;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC25B, SOM_RTS, "gen", advance_native_fifteen_byte_subtractive_random_ring, 0, L_A | L_B | L_X | L_Y | L_V, 5, 0, 0, 45, 27)

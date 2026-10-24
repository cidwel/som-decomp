#include "som_c.h"

/* C24517 advance_native54_to_state2_after_animation   [class A, 30 bytes, 12 instructions]
 * Source: src/rom/advance_native54_to_state2_after_animation.s
 * Documented in docs/boss-native54-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void advance_native54_to_state2_after_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x009E + value);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value2 != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
    } else {
        RAM16_SET(OBJECT_PHASE + value, 2);
        RAM16_SET(0x001E + value, 3);
        RAM16_SET(OBJECT_AGE + value, 0);
        RAM16_SET(0x00B2 + value, 0);
        RAM16_SET(0x0076 + value, 0);
        a1 = 3;
        a_hi1 = 0;
        zero1 = 0;
        negative1 = 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24517, SOM_RTS, "gen", advance_native54_to_state2_after_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 30, 12)

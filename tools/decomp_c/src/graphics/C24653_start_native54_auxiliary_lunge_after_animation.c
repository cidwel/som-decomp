#include "som_c.h"

/* C24653 start_native54_auxiliary_lunge_after_animation   [class B, 47 bytes, 19 instructions]
 * Source: src/rom/start_native54_auxiliary_lunge_after_animation.s
 * Documented in docs/boss-native54-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void start_native54_auxiliary_lunge_after_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
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
        RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
        RAM8(0xF812 + y) = 0xA0;
        RAM8(0xF80E + y) = 0xD0;
        RAM16_SET(OBJECT_AGE + value, 0);
        RAM16_SET(0x003C + value, 0);
        RAM16_SET(0x0040 + value, 0);
        RAM16_SET(0x00B4 + value, 0xA000);
        RAM16_SET(0x00B6 + value, 0xD000);
        a1 = 0;
        a_hi1 = 0xD0;
        zero1 = 0;
        negative1 = 1;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24653, SOM_RTS, "gen", start_native54_auxiliary_lunge_after_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 47, 19)

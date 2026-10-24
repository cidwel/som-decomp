#include "som_c.h"

/* C24965 test_native54_negative_status_or_begin_hurt_shift   [class B, 74 bytes, 30 instructions]
 * Source: src/rom/test_native54_negative_status_or_begin_hurt_shift.s
 * Documented in docs/boss-native54-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void test_native54_negative_status_or_begin_hurt_shift(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint16_t value = RAM16(0x0190 + x);
    if (value & 0x8000) {
        uint16_t value2 = RAM16(0x0287);
        RAM16_SET(OBJECT_PHASE + value2, 0x0A);
        RAM16_SET(OBJECT_AGE + value2, 0);
        RAM16_SET(0x009E + value2, 0);
        RAM16_SET(0x003C + value2, 0xEB00);
        RAM16_SET(0x0040 + value2, 0xF200);
        RAM16_SET(0x00B4 + value2, 0xC100);
        RAM16_SET(0x00B6 + value2, 0xDE00);
        RAM8(0xF812 + y) = 0xC1;
        RAM8(0xF80E + y) = 0xDE;
        RAM8(0xF813 + y) = 0x80;
        r->a = 0xDE80;
        r->x = value2;
        r->c = 1;
        RETURN_RTS(c);
    }
    r->a = value;
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24965, SOM_RTS, "gen", test_native54_negative_status_or_begin_hurt_shift, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 74, 30)

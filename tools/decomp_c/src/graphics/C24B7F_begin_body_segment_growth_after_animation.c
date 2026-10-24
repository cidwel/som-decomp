#include "som_c.h"

/* C24B7F begin_body_segment_growth_after_animation   [class B, 70 bytes, 28 instructions]
 * Source: src/rom/begin_body_segment_growth_after_animation.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void begin_body_segment_growth_after_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value2 = RAM16(0x00B0 + RAM16(0x0287));
    RAM16_SET(0x00BC + value2, (uint16_t)(RAM16(0x00BC + value2) + 1));
    uint16_t value3 = RAM16(0x0287);
    uint16_t value4 = RAM16(0x009E + value3);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value4 != 0) {
        a1 = (uint8_t)value4;
        a_hi1 = value4 >> 8;
        x1 = value3;
        y1 = y;
        zero1 = value4 == 0;
        negative1 = value4 & 0x8000;
        overflow1 = overflow;
    } else {
        RAM16_SET(OBJECT_PHASE + value3, 4);
        RAM16_SET(0x001E + value3, 2);
        RAM16_SET(OBJECT_AGE + value3, 0);
        RAM16_SET(0x00B2 + value3, 0);
        RAM16_SET(0x00B4 + value3, 0);
        RAM16_SET(0x00B6 + value3, 0);
        RAM16_SET(0x00B8 + value3, (uint16_t)(y + 0xF803));
        RAM16_SET(0x00BA + value3, 6);
        RAM16_SET(0x00BC + value3, 0);
        r->a = 6;
        JSR(c, 0x4BBA, 0xC24BEC); /* select_native54_body_nearest_party_target */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint16_t value5 = RAM16(0x0287);
        RAM16_SET(0x00A9 + value5, a_all);
        RAM16_SET(0x0059 + value5, 0);
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = value5;
        y1 = y_ret;
        zero1 = value5 == 0;
        negative1 = value5 & 0x8000;
        overflow1 = overflow_ret;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24B7F, SOM_RTS, "gen", begin_body_segment_growth_after_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 70, 28)

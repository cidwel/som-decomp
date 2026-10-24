#include "som_c.h"

/* C241D8 allocate_descriptor_two_palette_effect_12_at_timer_six   [class A, 32 bytes, 13 instructions]
 * Source: src/rom/allocate_descriptor_two_palette_effect_12_at_timer_six.s
 * Documented in docs/boss-descriptor-two-palette.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void allocate_descriptor_two_palette_effect_12_at_timer_six(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    uint16_t y1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value2 != 6) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = value;
        y1 = y;
        zero1 = value2 == 6;
        negative1 = (uint16_t)(value2 - 6) & 0x8000;
        overflow1 = overflow;
    } else {
        r->a = 3;
        r->x = 0x12;
        r->y = 0x8F0D;
        r->c = value2 >= 6;
        JSR(c, 0x41ED, 0xC2272D); /* allocate_boss_palette_transition_object */
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint16_t value3 = RAM16(0x0287);
        RAM16_SET(OBJECT_PHASE + value3, (uint16_t)(RAM16(OBJECT_PHASE + value3) - 1));
        uint16_t value4 = RAM16(OBJECT_PHASE + value3);
        RAM16_SET(OBJECT_AGE + value3, 0);
        a1 = (uint8_t)a_all;
        a_hi1 = a_all >> 8;
        x1 = value3;
        y1 = y_ret;
        zero1 = value4 == 0;
        negative1 = value4 & 0x8000;
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
SOM_REGISTER(0xC241D8, SOM_RTS, "gen", allocate_descriptor_two_palette_effect_12_at_timer_six, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 32, 13)

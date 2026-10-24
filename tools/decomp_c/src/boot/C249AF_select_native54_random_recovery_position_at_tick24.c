#include "som_c.h"

/* C249AF select_native54_random_recovery_position_at_tick24   [class B, 68 bytes, 31 instructions]
 * Source: src/rom/select_native54_random_recovery_position_at_tick24.s
 * Documented in docs/boss-native54-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void select_native54_random_recovery_position_at_tick24(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    uint8_t a1;
    uint8_t a_hi1;
    uint16_t x1;
    bool zero1;
    bool negative1;
    bool overflow1;
    if (value2 != 0x18) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        x1 = value;
        zero1 = value2 == 0x18;
        negative1 = (uint16_t)(value2 - 0x18) & 0x8000;
        overflow1 = overflow;
    } else {
        RAM16_SET(OBJECT_PHASE + value, 1);
        r->a = 0x74;
        r->x = value;
        r->c = value2 >= 0x18;
        JSR(c, 0x49C4, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
        uint16_t value3 = RAM16(0x0042 + value);
        RAM16_SET(0x0295, (((uint8_t)value3 << 8) | (value3 >> 8)) >> 2);
        r->a = 0x0B;
        r->c = (((uint8_t)value3 << 8) | (value3 >> 8)) >> 1 & 0x01;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x49D2, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all2 = r->a;
        uint16_t value4 = RAM16(0x0295);
        uint16_t value5 = BUS16(c, 0xC249F3 + (uint16_t)((uint16_t)(a_all2 << 2) + value4));
        RAM16_SET(0x0295, value5);
        uint16_t value6 = BUS16(c, 0xC249F5 + (uint16_t)((uint16_t)(a_all2 << 2) + value4));
        RAM16_SET(0x0297, value6);
        uint16_t value7 = RAM16(0x0287);
        RAM16_SET(0x002B + value7, RAM16(0x0295));
        uint16_t value9 = RAM16(0x0297);
        RAM16_SET(0x0032 + value7, value9);
        a1 = (uint8_t)value9;
        a_hi1 = value9 >> 8;
        x1 = value7;
        zero1 = value9 == 0;
        negative1 = value9 & 0x8000;
        overflow1 = (((uint16_t)(a_all2 << 2) ^ (uint16_t)((uint16_t)(a_all2 << 2) + value4)) & (value4 ^ (uint16_t)((uint16_t)(a_all2 << 2) + value4)) & 0x8000) != 0;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->c = 0;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC249AF, SOM_RTS, "gen", select_native54_random_recovery_position_at_tick24, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 68, 31)

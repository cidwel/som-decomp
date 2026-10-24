#include "som_c.h"

/* C24C0D grow_body_segment_chain_at_four_tick_intervals   [class B, 54 bytes, 23 instructions]
 * Source: src/rom/grow_body_segment_chain_at_four_tick_intervals.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void grow_body_segment_chain_at_four_tick_intervals(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value2 = RAM16(0x00B0 + RAM16(0x0287));
    RAM16_SET(0x00BC + value2, (uint16_t)(RAM16(0x00BC + value2) + 1));
    uint16_t value3 = RAM16(0x0287);
    r->a = value2;
    r->x = value3;
    JSR(c, 0x4C1A, 0xC24DB9); /* consume_body_damage_or_parent_phase15_and_enter_hurt */
    uint16_t x_ret = r->x;
    bool carry_ret = r->c;
    if (carry_ret) {
        r->c = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(OBJECT_AGE + x_ret);
    if (value4 != 4) {
        r->a = value4;
        r->c = 0;
        r->z = value4 == 4;
        r->n = (uint16_t)(value4 - 4) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value5 = RAM16(0x00B2 + x_ret);
    if (value5 >= 0x0C) {
        RAM16_SET(0x00C2 + x_ret, 0);
        RAM16_SET(OBJECT_PHASE + x_ret, 5);
        RAM16_SET(OBJECT_AGE + x_ret, 0);
        r->a = 5;
        r->c = 0;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    RAM16_SET(OBJECT_AGE + x_ret, 0);
    r->a = value5;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x4C32, 0xC24DDE); /* grow_body_auxiliary_segment_and_publish_collision_geometry */
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24C0D, SOM_RTS, "gen", grow_body_segment_chain_at_four_tick_intervals, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 54, 23)

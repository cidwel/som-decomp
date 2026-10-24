#include "som_c.h"

/* C24BF0 begin_body_appearance_after_thirty_six_ticks   [class A, 29 bytes, 13 instructions]
 * Source: src/rom/begin_body_appearance_after_thirty_six_ticks.s
 * Documented in docs/boss-native54-body.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void begin_body_appearance_after_thirty_six_ticks(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(OBJECT_AGE + value);
    if (value2 < 0x24) {
        r->a = value2;
        r->x = value;
        r->c = 0;
        r->z = value2 == 0x24;
        r->n = (uint16_t)(value2 - 0x24) & 0x8000;
        RETURN_RTS(c);
    }
    RAM16_SET(OBJECT_PHASE + value, 1);
    r->a = 0x77;
    r->x = value;
    r->c = value2 >= 0x24;
    JSR(c, 0x4C05, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    RAM16_SET(OBJECT_AGE + value, 0);
    r->c = 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24BF0, SOM_RTS, "gen", begin_body_appearance_after_thirty_six_ticks, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 29, 13)

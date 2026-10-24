#include "som_c.h"

/* C231A3 initialize_boss_death_explosion_then_check_animation   [class B, 49 bytes, 20 instructions]
 * Source: src/rom/initialize_boss_death_explosion_then_check_animation.s
 * Documented in docs/boss-native-linked-death-effects.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void initialize_boss_death_explosion_then_check_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(0x0022 + value, 0x7FFF);
    RAM16_SET(0x000B + value, 1);
    RAM16_SET(0x0029 + value, 0);
    RAM16_SET(0x0030 + value, 0);
    RAM16_SET(0x0066 + value, 0);
    RAM16_SET(0x0000 + value, 1);
    r->a = 0x015C;
    r->x = value;
    JSR(c, 0x31C8, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    uint16_t value2 = RAM16(0x0287);
    uint16_t value3 = RAM16(0x009E + value2);
    if (value3 == 0) {
        r->a = value3;
        r->x = value2;
        r->c = 1;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value3;
    r->x = value2;
    r->c = 0;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC231A3, SOM_RTS, "gen", initialize_boss_death_explosion_then_check_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 49, 20)

#include "som_c.h"

/* C29DC6 start_pull_spell_target_follow_animation   [class A, 25 bytes, 10 instructions]
 * Source: src/rom/start_pull_spell_target_follow_animation.s
 * Documented in docs/boss-native-spell-pull-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void start_pull_spell_target_follow_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(OBJECT_AGE + value, 0);
    RAM16_SET(0x00BA + value, 0);
    RAM16_SET(0x0022 + value, 0);
    RAM16_SET(0x0090 + value, 0x993D);
    r->a = 0x993D;
    r->x = value;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9DDC, 0xC29A67); GUARD_JSR(c, sp_call, 0x9DDC); } /* start_follow_spell_target_animation */
    r->c = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29DC6, SOM_RTS, "gen", start_pull_spell_target_follow_animation, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 25, 10)

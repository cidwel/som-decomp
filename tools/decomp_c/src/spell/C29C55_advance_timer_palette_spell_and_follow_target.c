#include "som_c.h"

/* C29C55 advance_timer_palette_spell_and_follow_target   [class A, 31 bytes, 12 instructions]
 * Source: src/rom/advance_timer_palette_spell_and_follow_target.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void advance_timer_palette_spell_and_follow_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    RAM16_SET(OBJECT_PHASE + value, (uint16_t)(RAM16(OBJECT_PHASE + value) + 1));
    RAM16_SET(OBJECT_AGE + value, 0);
    RAM16_SET(0x0090 + value, 0x9C93);
    RAM16_SET(0x00BA + value, 0);
    RAM16_SET(0x0022 + value, 0);
    RAM16_SET(0x0090 + value, 0x993D);
    r->a = 0x993D;
    r->x = value;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x9C71, 0xC29A67); GUARD_JSR(c, sp_call, 0x9C71); } /* start_follow_spell_target_animation */
    r->c = 0;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC29C55, SOM_RTS, "gen", advance_timer_palette_spell_and_follow_target, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 31, 12)

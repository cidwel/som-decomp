#include "som_c.h"

/* C24477 schedule_two_boss_palette_transitions_unconditionally   [class B, 43 bytes, 17 instructions]
 * Source: src/rom/schedule_two_boss_palette_transitions_unconditionally.s
 * Documented in docs/graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void schedule_two_boss_palette_transitions_unconditionally(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    RAM8(0x033F + 0x0D) = 0x1E;
    RAM8(0x033F + 0x0E) = 0x1F;
    r->a = 0x16;
    r->x = 0x1E;
    r->y = 0x0D;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4494, 0xC2272D); GUARD_JSR(c, sp_call, 0x4494); } /* allocate_boss_palette_transition_object */
    r->a = 0x16;
    r->x = 0x1E;
    r->y = 0x0E;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x44A0, 0xC2272D); GUARD_JSR(c, sp_call, 0x44A0); } /* allocate_boss_palette_transition_object */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24477, SOM_RTS, "gen", schedule_two_boss_palette_transitions_unconditionally, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 43, 17)

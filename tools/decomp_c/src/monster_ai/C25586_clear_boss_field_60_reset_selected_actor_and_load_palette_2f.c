#include "som_c.h"

/* C25586 clear_boss_field_60_reset_selected_actor_and_load_palette_2f   [class B, 28 bytes, 10 instructions]
 * Source: src/rom/clear_boss_field_60_reset_selected_actor_and_load_palette_2f.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void clear_boss_field_60_reset_selected_actor_and_load_palette_2f(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0060 + x, 0);
    r->a = 0x8A00;
    r->z = 0;
    r->n = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x558E, 0xC23963); GUARD_JSR(c, sp_call, 0x558E); } /* boss_external_actor_command_if_selected */
    if (r->mf != 0) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    r->a = 0x2F;
    r->x = 0x0D;
    r->z = 0;
    r->n = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5597, 0xC226F9); GUARD_JSR(c, sp_call, 0x5597); } /* copy_boss_palette_with_cpu_words */
    r->a = 0x2F;
    r->x = 0x0E;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x55A0, 0xC226F9); GUARD_JSR(c, sp_call, 0x55A0); } /* copy_boss_palette_with_cpu_words */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25586, SOM_RTS, "gen", clear_boss_field_60_reset_selected_actor_and_load_palette_2f, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 28, 10)

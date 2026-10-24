#include "som_c.h"

/* C12BF7 initialize_spell_scheduler_family_two   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_scheduler_family_two.s
 * Documented in docs/actor-cast-entity-mode-two.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$01B4.  Callers read: ABXYCZNV.
 */
static void initialize_spell_scheduler_family_two(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x01B4) { c->fail = 3; return; }
    { const uint16_t sp_call = r->sp; JSL(c, 0x2BFA, 0xDCF927); GUARD_JSL(c, sp_call, 0x2BFA); } /* initialize_spell_family_two_long */
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12BF7, SOM_RTS, "hand", initialize_spell_scheduler_family_two, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 5, 2)

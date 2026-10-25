#include "som_c.h"

/* C12C06 initialize_spell_entity_twin_scheduler_family   [class A, 5 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_entity_twin_scheduler_family.s
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void initialize_spell_entity_twin_scheduler_family(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2C09, 0xC12C15); GUARD_JSL(c, sp_call, 0x2C09); } /* initialize_spell_entity_twin_family_long */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12C06, SOM_RTS, "gen", initialize_spell_entity_twin_scheduler_family, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 5, 2)

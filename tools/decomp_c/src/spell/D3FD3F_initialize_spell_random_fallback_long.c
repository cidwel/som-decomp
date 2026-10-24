#include "som_c.h"

/* D3FD3F initialize_spell_random_fallback_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/initialize_spell_random_fallback_long.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void initialize_spell_random_fallback_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0xFD41, 0xD3FD43); GUARD_JSR(c, sp_call, 0xFD41); } /* initialize_spell_random_fallback */
    RETURN_RTL(c);
}
SOM_REGISTER(0xD3FD3F, SOM_RTL, "gen", initialize_spell_random_fallback_long, 0, 0, 1, 1, 0, 4, 2)

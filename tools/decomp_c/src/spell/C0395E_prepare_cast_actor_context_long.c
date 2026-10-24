#include "som_c.h"

/* C0395E prepare_cast_actor_context_long   [class A, 4 bytes, 2 instructions]
 * Source: src/rom/prepare_cast_actor_context_long.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BXYCV.
 */
static void prepare_cast_actor_context_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    JSR(c, 0x3960, 0xC03962); /* prepare_cast_actor_context */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0395E, SOM_RTL, "gen", prepare_cast_actor_context_long, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 4, 2)

#include "som_c.h"

/* C000A5 preserve_context_and_initialize_hidden_effect   [class C, 20 bytes, 15 instructions]
 * Source: src/rom/preserve_context_and_initialize_hidden_effect.s
 * Documented in docs/boss-native59-hidden-child.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void preserve_context_and_initialize_hidden_effect(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->mf = 1;
    r->sp -= 6;
    JSR(c, 0x00B3, 0xC01024); /* initialize_hidden_effect_global_handle_and_animation017A */
    r->sp += 6;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC000A5, SOM_RTL, "gen", preserve_context_and_initialize_hidden_effect, 0, 0, 7, 0, 0, 20, 15)

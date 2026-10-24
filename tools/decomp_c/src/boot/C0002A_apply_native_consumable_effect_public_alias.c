#include "som_c.h"

/* C0002A apply_native_consumable_effect_public_alias   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/apply_native_consumable_effect_public_alias.s
 * Documented in docs/event-menu-consumable-effects.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void apply_native_consumable_effect_public_alias(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC03812, SOM_RTL); /* apply_native_consumable_effect_native_alias */
}
SOM_REGISTER(0xC0002A, SOM_RTL, "gen", apply_native_consumable_effect_public_alias, 0, L_B | L_X | L_Y | L_V, 1, 0, 0, 3, 1)

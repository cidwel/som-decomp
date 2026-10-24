#include "som_c.h"

/* C06423 jump_inventory_insert_with_explicit_hero_owner   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_inventory_insert_with_explicit_hero_owner.s
 * Documented in docs/actor-hero-initialize.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void jump_inventory_insert_with_explicit_hero_owner(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC064B3, SOM_RTL); /* insert_inventory_record_with_explicit_controller_bits */
}
SOM_REGISTER(0xC06423, SOM_RTL, "gen", jump_inventory_insert_with_explicit_hero_owner, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 3, 1)

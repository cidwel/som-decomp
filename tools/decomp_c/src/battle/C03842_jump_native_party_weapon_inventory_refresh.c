#include "som_c.h"

/* C03842 jump_native_party_weapon_inventory_refresh   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/jump_native_party_weapon_inventory_refresh.s
 * Documented in docs/event-vm-party-weapon-refresh.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void jump_native_party_weapon_inventory_refresh(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    TAIL_CALL(c, 0xC04CB8, SOM_RTL); /* refresh_three_party_weapon_records_and_rebuild_attributes */
}
SOM_REGISTER(0xC03842, SOM_RTL, "gen", jump_native_party_weapon_inventory_refresh, 0, 0, 1, 1, 1, 3, 1)

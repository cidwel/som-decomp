#include "som_c.h"

/* C0004E public_weapon_upgrade_ring_menu_alias   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/public_weapon_upgrade_ring_menu_alias.s
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCV.
 */
static void public_weapon_upgrade_ring_menu_alias(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    TAIL_CALL(c, 0xC06417, SOM_RTL); /* forward_native_weapon_upgrade_ring_menu_to_saved_context_entry */
}
SOM_REGISTER(0xC0004E, SOM_RTL, "gen", public_weapon_upgrade_ring_menu_alias, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 3, 1)

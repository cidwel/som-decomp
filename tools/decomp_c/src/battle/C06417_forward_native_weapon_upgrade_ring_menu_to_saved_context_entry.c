#include "som_c.h"

/* C06417 forward_native_weapon_upgrade_ring_menu_to_saved_context_entry   [class A, 3 bytes, 1 instructions]
 * Source: src/rom/forward_native_weapon_upgrade_ring_menu_to_saved_context_entry.s
 * Entry: M=any X=any DB=any D=any.  Callers read: ABXYCV.
 */
static void forward_native_weapon_upgrade_ring_menu_to_saved_context_entry(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    TAIL_CALL(c, 0xC06653, SOM_RTS); /* enter_public_weapon_upgrade_ring_at_first_weapon */
}
SOM_REGISTER(0xC06417, SOM_RTS, "gen", forward_native_weapon_upgrade_ring_menu_to_saved_context_entry, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 3, 1)

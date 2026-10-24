#include "som_c.h"

/* C75B17 count_active_hero_nibbles_in_selected_native_save_copy   [class A, 14 bytes, 7 instructions]
 * Source: src/rom/count_active_hero_nibbles_in_selected_native_save_copy.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void count_active_hero_nibbles_in_selected_native_save_copy(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    r->mf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0x5B1C, 0xC75D00); GUARD_JSR(c, sp_call, 0x5B1C); } /* derive_selected_save_slot_primary_or_backup_offset */
    r->sp += 2;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSL(c, 0x5B22, 0xC02A14); GUARD_JSL(c, sp_call, 0x5B22); } /* count_active_native_menu_saved_slot_nibbles */
    r->sp += 2;
    r->x = x;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75B17, SOM_RTS, "gen", count_active_hero_nibbles_in_selected_native_save_copy, 0, L_X | L_Y, 2, 1, 0, 14, 7)

#include "som_c.h"

/* C06896 poll_and_update_native_ring_until_confirm_and_cancel_are_released   [class A, 17 bytes, 7 instructions]
 * Source: src/rom/poll_and_update_native_ring_until_confirm_and_cancel_are_released.s
 * Documented in docs/event-menu-ring-waits.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void poll_and_update_native_ring_until_confirm_and_cancel_are_released(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    do {
        { const uint16_t sp_call = r->sp; JSR(c, 0x6898, 0xC0695E); GUARD_JSR_DB(c, sp_call, 0x6898, 0x00); } /* wait_vblank_before_polling_native_menu_input */
        { const uint16_t sp_call = r->sp; JSR(c, 0x689B, 0xC06BF8); GUARD_JSR_DB(c, sp_call, 0x689B, 0x00); } /* dispatch_native_menu_ring_phase_from_original_jump_table */
        i_rep(r, 0x20);
        a_lda(r, RAM16(0x1800));
        a_and(r, 0xC000);
    } while (!r->z);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06896, SOM_RTS, "hand", poll_and_update_native_ring_until_confirm_and_cancel_are_released, 0, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 17, 7)

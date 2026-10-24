#include "som_c.h"

/* C0761A publish_native_menu_transaction_result_with_real_vblank_and_ring_phase   [class B, 27 bytes, 10 instructions]
 * Source: src/rom/publish_native_menu_transaction_result_with_real_vblank_and_ring_phase.s
 * Documented in docs/event-menu-transaction-finish.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYV.
 */
static void publish_native_menu_transaction_result_with_real_vblank_and_ring_phase(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1802);
    BUS8_SET(c, (db << 0x10) + 0x1802, value | 4);
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x1803);
    BUS8_SET(c, (db << 0x10) + 0x1803, value2 | 2);
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7628, 0xC07908); GUARD_JSR(c, sp_call, 0x7628); } /* clear_native_menu_ring_blink_bit_in_twelve_rows */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x762B, 0xC07922); GUARD_JSR(c, sp_call, 0x762B); } /* clear_native_first_two_ring_rows_and_hide_hero_markers */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x762E, 0xC07971); GUARD_JSR(c, sp_call, 0x762E); } /* rebuild_native_equipment_row_attributes_and_hero_markers_after_transaction */
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x7631, 0xC06943); GUARD_JSR(c, sp_call, 0x7631); } /* await_vblank_edge_and_run_complete_menu_text_frame */
    r->mf = 0;
    TAIL_CALL(c, 0xC06BF8, SOM_RTS); /* dispatch_native_menu_ring_phase_from_original_jump_table */
}
SOM_REGISTER(0xC0761A, SOM_RTS, "gen", publish_native_menu_transaction_result_with_real_vblank_and_ring_phase, 0, L_B | L_X | L_Y | L_V, 1, -1, 0, 27, 10)

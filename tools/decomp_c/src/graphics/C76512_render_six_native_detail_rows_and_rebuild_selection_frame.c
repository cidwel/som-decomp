#include "som_c.h"

/* C76512 render_six_native_detail_rows_and_rebuild_selection_frame   [class B, 55 bytes, 22 instructions]
 * Source: src/rom/render_six_native_detail_rows_and_rebuild_selection_frame.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void render_six_native_detail_rows_and_rebuild_selection_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM16_SET(0xA18C, 0x6500);
    RAM16_SET(0xA191, 0x03C0);
    RAM16_SET(0xA199, 0x01E0);
    RAM8(0xA171) = 6;
    r->a = (a_hi << 8) | 6;
    r->z = x == 0;
    r->n = x & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x652D, 0xC75D9A); GUARD_JSR(c, sp_call, 0x652D); } /* render_native_saved_slot_text_rows_with_real_vblank */
    uint8_t db_ret = r->db;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x6531, 0xC02AE3); GUARD_JSL(c, sp_call, 0x6531); } /* reset_and_rebuild_native_menu_frame_without_heading */
    if (r->mf != 1) { c->fail = 3; return; }
    uint16_t a_all2 = r->a;
    uint8_t value = BUS8_RDP(c, (db_ret << 0x10) + 0xA202);
    RAM8(0x0000 + sp0) = value;
    BUS8_SET(c, (db_ret << 0x10) + 0xA202, 6);
    r->a = (a_all2 >> 8 << 8) | 6;
    r->z = 0;
    r->n = 0;
    r->sp -= 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0x653E, 0xC757DC); GUARD_JSL(c, sp_call, 0x653E); } /* highlight_native_saved_slot_rectangle_and_request_publication */
    r->sp += 1;
    uint8_t db_ret2 = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA202, RAM8(0x0000 + sp0));
    uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA20A);
    BUS8_SET(c, (db_ret2 << 0x10) + 0xA20A, value3 | 0x40);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC76512, SOM_RTS, "gen", render_six_native_detail_rows_and_rebuild_selection_frame, 0, 0, 2, 1, 0, 55, 22)

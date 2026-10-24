#include "som_c.h"

/* C75D9A render_native_saved_slot_text_rows_with_real_vblank   [class B, 66 bytes, 24 instructions]
 * Source: src/rom/render_native_saved_slot_text_rows_with_real_vblank.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCZV.
 */
static void render_native_saved_slot_text_rows_with_real_vblank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM8(0x9C00 + x) = 0;
    RAM8(0x1D03) = 0x7E;
    RAM16_SET(0x1D01, 0x9C00);
    RAM8(0xA1C5) = 0;
    RAM8(0xA212) &= 0xFE;
    RAM8(0x1D00) = 0;
    uint8_t a1 = 0;
    uint8_t a_hi1 = 0x9C;
    uint16_t x1 = x;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 1;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        { const uint16_t sp_call = r->sp; JSL(c, 0x5DBF, 0xC02ADB); GUARD_JSL(c, sp_call, 0x5DBF); } /* decode_native_saved_slot_font_rows_wrapper */
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x5DC3, 0xC02AEA); GUARD_JSL(c, sp_call, 0x5DC3); } /* await_native_saved_slot_menu_frame_wrapper */
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0x5DC7, 0xC02ADF); GUARD_JSL(c, sp_call, 0x5DC7); } /* upload_native_saved_slot_text_rows_wrapper */
        bool x_ret4 = r->xf;
        uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0xA18C);
        uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 0xA199);
        BUS16_SET(c, (db_ret << 0x10) + 0xA18C, (uint16_t)(value2 + value3));
        uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xA171);
        BUS8_SET(c, (db_ret << 0x10) + 0xA171, (uint8_t)(value4 - 1));
        if (x_ret4 != 0) { c->fail = 3; return; }
        a1 = (uint8_t)(value2 + value3);
        a_hi1 = (uint16_t)(value2 + value3) >> 8;
        x1 = x_ret2;
        y1 = y_ret;
        carry1 = value2 + value3 > 0xFFFF;
        zero1 = (uint8_t)(value4 - 1) == 0;
        overflow1 = ((value2 ^ (uint16_t)(value2 + value3)) & (value3 ^ (uint16_t)(value2 + value3)) & 0x8000) != 0;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!((uint8_t)(value4 - 1) != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC75D9A, SOM_RTS, "gen", render_native_saved_slot_text_rows_with_real_vblank, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_V, 1, 1, 0, 66, 24)

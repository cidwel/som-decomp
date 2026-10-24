#include "som_c.h"

/* C7541E render_four_native_selected_save_confirmation_summary_fields   [class C, 70 bytes, 31 instructions]
 * Source: src/rom/render_four_native_selected_save_confirmation_summary_fields.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCZV.
 */
static void render_four_native_selected_save_confirmation_summary_fields(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t x1 = 0;
    uint16_t y1 = 8;
    for (;;) {
        RAM8(0x9C00 + x1) = 0x7F;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    RAM8(0xA17A) = 0;
    RAM8(0xA17B) = 0;
    uint8_t a1 = 0x7F;
    uint8_t a_hi1 = a_hi;
    uint16_t x2 = x1;
    uint16_t y2 = y1;
    bool carry1 = carry;
    bool zero1 = 0;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = 0;
    for (;;) {
        uint16_t value = BUS16_RDP(c, (data_bank << 0x10) + 0xA17A);
        RAM8(0x0000 + sp0) = value >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)value;
        r->a = (a_hi1 << 8) | a1;
        r->x = value;
        r->y = y2;
        r->c = carry1;
        r->z = value == 0;
        r->n = value & 0x8000;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp;
        JSR(c, 0x5439, 0xC70000 | BUS16(c, 0xC70000 + (uint16_t)(0x5F8F + (value)))); GUARD_JSR(c, sp_call, 0x5439);
        }
        r->sp += 2;
        uint8_t db_ret = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t x_ret = r->x;
        uint8_t value2 = RAM8(0x0000 + sp0 - 1);
        uint8_t value3 = RAM8(0x0000 + sp0);
        uint16_t value4 = BUS16(c, 0xC75F97 + ((value3 << 8) | value2));
        BUS16_SET(c, (db_ret << 0x10) + 0xA18C, value4);
        uint16_t value5 = BUS16(c, 0xC75F9F + ((value3 << 8) | value2));
        BUS16_SET(c, (db_ret << 0x10) + 0xA191, value5);
        BUS8_SET(c, (db_ret << 0x10) + 0xA171, 1);
        r->y = x_ret;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x5456, 0xC75D9A); GUARD_JSR(c, sp_call, 0x5456); } /* render_native_saved_slot_text_rows_with_real_vblank */
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret2 = r->y;
        bool overflow_ret2 = r->v;
        uint8_t value6 = BUS8_RDP(c, (db_ret2 << 0x10) + 0xA17A);
        BUS8_SET(c, (db_ret2 << 0x10) + 0xA17A, (uint8_t)(value6 + 2));
        a1 = (uint8_t)(value6 + 2);
        a_hi1 = a_all2 >> 8;
        x2 = x_ret2;
        y2 = y_ret2;
        carry1 = (uint8_t)(value6 + 2) >= 8;
        zero1 = (uint8_t)(value6 + 2) == 8;
        overflow1 = overflow_ret2;
        data_bank = db_ret2;
        direct_page = dp_ret2;
        if (!(a1 != 8)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x2;
    r->y = y2;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7541E, SOM_RTS, "gen", render_four_native_selected_save_confirmation_summary_fields, 0, L_B | L_X | L_Y | L_C | L_Z | L_V, 2, 1, 0, 70, 31)

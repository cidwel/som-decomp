#include "som_c.h"

/* D0C8A3 upload_native_twelve_icon_strip_and_upper_palette   [class D, 88 bytes, 39 instructions]
 * Source: src/rom/upload_native_twelve_icon_strip_and_upper_palette.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: BXY.
 */
static void upload_native_twelve_icon_strip_and_upper_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x1810) = 0xFB;
    uint8_t a1 = 0x0C;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0x1880;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    uint8_t data_bank = 0;
    uint16_t direct_page = 0;
    for (;;) {
        RAM8(0x0000 + sp0) = a1;
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xC8B2, 0xD0C979); GUARD_JSR(c, sp_call, 0xC8B2); } /* advance_menu_icon_palette_and_select_descriptor_tile */
        r->sp += 1;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool overflow_ret = r->v;
        uint8_t value = RAM8(0x0000 + sp0);
        uint8_t a2;
        uint8_t a_hi2;
        bool overflow2;
        if (value != 5) {
            a2 = value;
            a_hi2 = a_all >> 8;
            overflow2 = overflow_ret;
        } else {
            RAM8(0x0000 + sp0) = value;
            uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x180C);
            BUS16_SET(c, (db_ret << 0x10) + 0x180C, (uint16_t)(value2 + 0x0100));
            a2 = RAM8(0x0000 + sp0);
            a_hi2 = (uint16_t)(value2 + 0x0100) >> 8;
            overflow2 = ((value2 ^ (uint16_t)(value2 + 0x0100)) & ((uint16_t)(value2 + 0x0100) ^ 0x0100) & 0x8000) != 0;
        }
        if (x_ret != 0) { c->fail = 3; return; }
        a1 = (uint8_t)(a2 - 1);
        a_hi1 = a_hi2;
        x1 = x_ret2;
        y1 = y_ret;
        overflow1 = overflow2;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!(a1 != 0)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    { const uint16_t sp_call = r->sp; JSL(c, 0xC8D0, 0xD0CB11); GUARD_JSL(c, sp_call, 0xC8D0); } /* initialize_twelve_native_icon_rows_and_publish_upper_palette */
    uint16_t y_ret2 = r->y;
    BUS8_SET(c, (data_bank << 0x10) + 0x2121, 0xC0);
    BUS8_SET(c, (data_bank << 0x10) + 0x4350, 0);
    BUS8_SET(c, (data_bank << 0x10) + 0x4351, 0x22);
    BUS16_SET(c, (data_bank << 0x10) + 0x4352, 0x0780);
    BUS8_SET(c, (data_bank << 0x10) + 0x4354, 0);
    BUS16_SET(c, (data_bank << 0x10) + 0x4355, 0x80);
    BUS8_SET(c, (data_bank << 0x10) + 0x420B, 0x20);
    r->a = 0x80;
    r->x = 0x20;
    r->y = (uint8_t)y_ret2;
    r->mf = 0;
    r->xf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0C8A3, SOM_RTS, "gen", upload_native_twelve_icon_strip_and_upper_palette, 0, L_B | L_X | L_Y, 1, 1, 0, 88, 39)

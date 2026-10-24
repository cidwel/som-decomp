#include "som_c.h"

/* D0CA10 convert_one_original_three_plane_menu_tile_to_output_with_saved_context   [class C, 94 bytes, 47 instructions]
 * Source: src/rom/convert_one_original_three_plane_menu_tile_to_output_with_saved_context.s
 * Documented in docs/event-menu-single-icon.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void convert_one_original_three_plane_menu_tile_to_output_with_saved_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 1) = 0x7E;
    RAM8(0x0000 + sp0 - 2) = 3;
    RAM8(0x0000 + sp0 - 3) = 0;
    r->sp -= 4;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCA16, 0xC064A4); GUARD_JSL(c, sp_call, 0xCA16); } /* normalize_menu_native_direct_page_and_bank */
    r->sp += 4;
    uint8_t db_ret = r->db;
    uint16_t a_all = r->a;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    BUS8_SET(c, (db_ret << 0x10) + 0x1810, (uint8_t)a_all);
    BUS16_SET(c, (db_ret << 0x10) + 0x1820, y);
    uint8_t a1 = 8;
    uint8_t a_hi1 = a_all >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0x18C0;
    for (;;) {
        RAM8(0x0000 + sp0 - 6) = a1;
        uint8_t value = BUS8(c, 0xD40000 + x1);
        BUS8_SET(c, (db_ret << 0x10) + y1, value);
        uint8_t value2 = BUS8(c, 0xD40000 + (uint16_t)(x1 + 1));
        BUS8_SET(c, (db_ret << 0x10) + 1 + y1, value2);
        uint8_t value3 = BUS8(c, 0xD40000 + (uint16_t)(x1 + 2));
        BUS8_SET(c, (db_ret << 0x10) + 0x10 + y1, value3);
        a1 = (uint8_t)(RAM8(0x0000 + sp0 - 6) - 1);
        x1 = (uint16_t)(x1 + 3);
        y1 = (uint16_t)(y1 + 2);
        if (!(a1 != 0)) break;
    }
    r->y = y1;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCA48, 0xD0CAD6); GUARD_JSR(c, sp_call, 0xCA48); } /* convert_native_menu_icon_pixels_with_selected_palette_base */
    r->sp += 6;
    uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0x1820);
    uint8_t a2 = 0x10;
    uint8_t a_hi2 = 0;
    uint16_t x2 = value5;
    uint16_t y2 = 0x18E0;
    for (;;) {
        RAM8(0x0000 + sp0 - 6) = a_hi2;
        RAM8(0x0000 + sp0 - 7) = (uint8_t)((a_hi2 << 8) | a2);
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + y2);
        RAM16_SET(0x0000 + x2, value6);
        uint8_t value7 = RAM8(0x0000 + sp0 - 7);
        uint8_t value8 = RAM8(0x0000 + sp0 - 6);
        a2 = (uint8_t)(((value8 << 8) | value7) - 1);
        a_hi2 = (uint16_t)(((value8 << 8) | value7) - 1) >> 8;
        x2 = (uint16_t)(x2 + 2);
        y2 = (uint16_t)(y2 + 2);
        if (!((uint16_t)(((value8 << 8) | value7) - 1) != 0)) break;
    }
    uint8_t value9 = RAM8(0x0000 + sp0 - 5);
    uint8_t value10 = RAM8(0x0000 + sp0 - 4);
    r->a = (uint16_t)(((value10 << 8) | value9) + 0x18);
    r->x = (uint16_t)(((value10 << 8) | value9) + 0x18);
    r->y = x2;
    r->mf = 0;
    r->xf = 0;
    TAIL_CALL_FRAME(c, 0xD0C868, SOM_RTL, 4); /* external */
}
SOM_REGISTER(0xD0CA10, SOM_RTL, "gen", convert_one_original_three_plane_menu_tile_to_output_with_saved_context, 0, 0, 8, 1, 0, 94, 47)

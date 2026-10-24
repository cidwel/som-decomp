#include "som_c.h"

static void expand_one_native_menu_icon_tile_into_output_rows(SomCtx *c);
static void expand_one_native_menu_icon_tile_into_output_rows_v2(SomCtx *c);

/* D0CA6E prepare_four_native_menu_icon_tiles_from_original_graphics   [class B, 104 bytes, 58 instructions]
 * Source: src/rom/prepare_four_native_menu_icon_tiles_from_original_graphics.s
 * Documented in docs/event-menu-navigation-icons.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void prepare_four_native_menu_icon_tiles_from_original_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000 + sp0) = (((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1 << 1 << 1 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)((((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1 << 1 << 1);
    r->x = (uint16_t)(((((a_hi << 8) | a) & 0xFF) << 1 << 1 << 1 << 1 << 1 << 1) + RAM16(0x0000 + sp0 - 1));
    r->y = 0x1900;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0xCA84, expand_one_native_menu_icon_tile_into_output_rows); GUARD_JSR(c, sp_call, 0xCA84); }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0xCA87, expand_one_native_menu_icon_tile_into_output_rows_v2); GUARD_JSR(c, sp_call, 0xCA87); }
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR_LOCAL(c, 0xCA8A, expand_one_native_menu_icon_tile_into_output_rows_v2); GUARD_JSR(c, sp_call, 0xCA8A); }
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    uint16_t a_all3 = r->a;
    uint16_t x_ret3 = r->x;
    uint16_t y_ret3 = r->y;
    RAM8(0x0000 + sp0) = x_ret3 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x_ret3;
    RAM8(0x0000 + sp0 - 2) = y_ret3 >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)y_ret3;
    uint8_t a1 = 8;
    uint8_t a_hi1 = a_all3 >> 8;
    uint16_t x1 = x_ret3;
    uint16_t y1 = 0x18C0;
    for (;;) {
        RAM8(0x0000 + sp0 - 4) = a1;
        uint8_t value2 = BUS8(c, 0xD28400 + x1);
        BUS8_SET(c, (db_ret3 << 0x10) + y1, value2);
        uint8_t value3 = BUS8(c, 0xD28400 + (uint16_t)(x1 + 1));
        BUS8_SET(c, (db_ret3 << 0x10) + 1 + y1, value3);
        uint8_t value4 = BUS8(c, 0xD28400 + (uint16_t)(x1 + 2));
        BUS8_SET(c, (db_ret3 << 0x10) + 0x10 + y1, value4);
        a1 = (uint8_t)(RAM8(0x0000 + sp0 - 4) - 1);
        x1 = (uint16_t)(x1 + 3);
        y1 = (uint16_t)(y1 + 2);
        if (!(a1 != 0)) break;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    r->y = (value7 << 8) | value6;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCAB8, 0xD0CAD6); GUARD_JSR(c, sp_call, 0xCAB8); } /* convert_native_menu_icon_pixels_with_selected_palette_base */
    r->sp += 2;
    uint8_t a2 = 0x10;
    uint8_t a_hi2 = 0;
    uint16_t x2 = 0x18E0;
    uint16_t y2 = (value7 << 8) | value6;
    for (;;) {
        RAM8(0x0000 + sp0 - 2) = a_hi2;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)((a_hi2 << 8) | a2);
        BUS16_SET(c, (db_ret3 << 0x10) + y2, RAM16(0x0000 + dp_ret3 + x2));
        uint8_t value9 = RAM8(0x0000 + sp0 - 3);
        uint8_t value10 = RAM8(0x0000 + sp0 - 2);
        a2 = (uint8_t)(((value10 << 8) | value9) - 1);
        a_hi2 = (uint16_t)(((value10 << 8) | value9) - 1) >> 8;
        x2 = (uint16_t)(x2 + 2);
        y2 = (uint16_t)(y2 + 2);
        if (!((uint16_t)(((value10 << 8) | value9) - 1) != 0)) break;
    }
    r->x = (uint16_t)(((RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1)) + 0x18);
    r->y = y2;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CA6E, SOM_RTS, "gen", prepare_four_native_menu_icon_tiles_from_original_graphics, 0, L_X | L_Y, 5, 1, 0, 104, 58)

/* D0CA8B expand_one_native_menu_icon_tile_into_output_rows   [class A, 75 bytes, 41 instructions]
 * Source: src/rom/prepare_four_native_menu_icon_tiles_from_original_graphics.s
 * Subroutine of prepare_four_native_menu_icon_tiles_from_original_graphics, translated in place.
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void expand_one_native_menu_icon_tile_into_output_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 2) = y >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
    uint8_t a1 = 8;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0x18C0;
    for (;;) {
        RAM8(0x0000 + sp0 - 4) = a1;
        uint8_t value = BUS8(c, 0xD28400 + x1);
        BUS8_SET(c, 0x000000 + y1, value);
        uint8_t value2 = BUS8(c, 0xD28400 + (uint16_t)(x1 + 1));
        BUS8_SET(c, 0x000001 + y1, value2);
        uint8_t value3 = BUS8(c, 0xD28400 + (uint16_t)(x1 + 2));
        BUS8_SET(c, 0x000010 + y1, value3);
        a1 = (uint8_t)(RAM8(0x0000 + sp0 - 4) - 1);
        x1 = (uint16_t)(x1 + 3);
        y1 = (uint16_t)(y1 + 2);
        if (!(a1 != 0)) break;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    r->y = (value6 << 8) | value5;
    r->mf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCAB8, 0xD0CAD6); GUARD_JSR(c, sp_call, 0xCAB8); } /* convert_native_menu_icon_pixels_with_selected_palette_base */
    r->sp += 2;
    uint8_t a2 = 0x10;
    uint8_t a_hi2 = 0;
    uint16_t x2 = 0x18E0;
    uint16_t y2 = (value6 << 8) | value5;
    for (;;) {
        RAM8(0x0000 + sp0 - 2) = a_hi2;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)((a_hi2 << 8) | a2);
        BUS16_SET(c, 0x000000 + y2, RAM16(0x0000 + x2));
        uint8_t value8 = RAM8(0x0000 + sp0 - 3);
        uint8_t value9 = RAM8(0x0000 + sp0 - 2);
        a2 = (uint8_t)(((value9 << 8) | value8) - 1);
        a_hi2 = (uint16_t)(((value9 << 8) | value8) - 1) >> 8;
        x2 = (uint16_t)(x2 + 2);
        y2 = (uint16_t)(y2 + 2);
        if (!((uint16_t)(((value9 << 8) | value8) - 1) != 0)) break;
    }
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)(((value11 << 8) | value10) + 0x18);
    r->x = (uint16_t)(((value11 << 8) | value10) + 0x18);
    r->y = y2;
    r->c = ((value11 << 8) | value10) + 0x18 > 0xFFFF;
    r->z = (uint16_t)(((value11 << 8) | value10) + 0x18) == 0;
    r->n = (uint16_t)(((value11 << 8) | value10) + 0x18) & 0x8000;
    r->v = ((((value11 << 8) | value10) ^ (uint16_t)(((value11 << 8) | value10) + 0x18)) & ((uint16_t)(((value11 << 8) | value10) + 0x18) ^ 0x18) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

/* D0CA8B expand_one_native_menu_icon_tile_into_output_rows_v2   [class A, 75 bytes, 41 instructions]
 * Source: src/rom/prepare_four_native_menu_icon_tiles_from_original_graphics.s
 * Subroutine of prepare_four_native_menu_icon_tiles_from_original_graphics, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void expand_one_native_menu_icon_tile_into_output_rows_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 2) = y >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)y;
    uint8_t a1 = 8;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = x;
    uint16_t y1 = 0x18C0;
    for (;;) {
        RAM8(0x0000 + sp0 - 4) = a1;
        uint8_t value = BUS8(c, 0xD28400 + x1);
        BUS8_SET(c, (db << 0x10) + y1, value);
        uint8_t value2 = BUS8(c, 0xD28400 + (uint16_t)(x1 + 1));
        BUS8_SET(c, (db << 0x10) + 1 + y1, value2);
        uint8_t value3 = BUS8(c, 0xD28400 + (uint16_t)(x1 + 2));
        BUS8_SET(c, (db << 0x10) + 0x10 + y1, value3);
        a1 = (uint8_t)(RAM8(0x0000 + sp0 - 4) - 1);
        x1 = (uint16_t)(x1 + 3);
        y1 = (uint16_t)(y1 + 2);
        if (!(a1 != 0)) break;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    r->y = (value6 << 8) | value5;
    r->mf = 1;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCAB8, 0xD0CAD6); GUARD_JSR(c, sp_call, 0xCAB8); } /* convert_native_menu_icon_pixels_with_selected_palette_base */
    r->sp += 2;
    uint8_t a2 = 0x10;
    uint8_t a_hi2 = 0;
    uint16_t x2 = 0x18E0;
    uint16_t y2 = (value6 << 8) | value5;
    for (;;) {
        RAM8(0x0000 + sp0 - 2) = a_hi2;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)((a_hi2 << 8) | a2);
        BUS16_SET(c, (db << 0x10) + y2, RAM16(0x0000 + dp + x2));
        uint8_t value8 = RAM8(0x0000 + sp0 - 3);
        uint8_t value9 = RAM8(0x0000 + sp0 - 2);
        a2 = (uint8_t)(((value9 << 8) | value8) - 1);
        a_hi2 = (uint16_t)(((value9 << 8) | value8) - 1) >> 8;
        x2 = (uint16_t)(x2 + 2);
        y2 = (uint16_t)(y2 + 2);
        if (!((uint16_t)(((value9 << 8) | value8) - 1) != 0)) break;
    }
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)(((value11 << 8) | value10) + 0x18);
    r->x = (uint16_t)(((value11 << 8) | value10) + 0x18);
    r->y = y2;
    r->c = ((value11 << 8) | value10) + 0x18 > 0xFFFF;
    r->z = (uint16_t)(((value11 << 8) | value10) + 0x18) == 0;
    r->n = (uint16_t)(((value11 << 8) | value10) + 0x18) & 0x8000;
    r->v = ((((value11 << 8) | value10) ^ (uint16_t)(((value11 << 8) | value10) + 0x18)) & ((uint16_t)(((value11 << 8) | value10) + 0x18) ^ 0x18) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

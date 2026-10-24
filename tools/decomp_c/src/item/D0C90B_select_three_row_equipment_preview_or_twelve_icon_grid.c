#include "som_c.h"

static void upload_one_equipment_preview_row_and_optional_overlay(SomCtx *c);
static void upload_one_equipment_preview_row_and_optional_overlay_v2(SomCtx *c);
static void set_native_menu_icon_vram_cursor_then_fall_through(SomCtx *c);
static void advance_menu_icon_palette_and_select_descriptor_tile(SomCtx *c);
static void expand_and_upload_two_native_menu_icon_tile_rows(SomCtx *c);
static void advance_menu_icon_palette_and_select_descriptor_tile_v2(SomCtx *c);

/* D0C90B select_three_row_equipment_preview_or_twelve_icon_grid   [class D, 241 bytes, 101 instructions]
 * Source: src/rom/select_three_row_equipment_preview_or_twelve_icon_grid.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void select_three_row_equipment_preview_or_twelve_icon_grid(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp_in = r->sp;
    const uint8_t db = r->db;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x1803);
    if (!(value & 0x80)) {
        r->a = 0x6E00;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC952, set_native_menu_icon_vram_cursor_then_fall_through, sp_in, 2); GUARD_JSR(c, sp_call, 0xC952); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC955, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC955); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC958, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC958); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC95B, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC95B); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC95E, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC95E); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC961, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC961); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC964, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC964); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC967, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC967); }
        r->a = 0x7000;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC96D, set_native_menu_icon_vram_cursor_then_fall_through, sp_in, 2); GUARD_JSR(c, sp_call, 0xC96D); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC970, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC970); }
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC973, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC973); }
        r->mf = 0;
        r->xf = 0;
        advance_menu_icon_palette_and_select_descriptor_tile(c); return;
    }
    BUS16_SET(c, (db << 0x10) + 0x180C, 0x6E00);
    r->a = 0x6E00;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC91A, upload_one_equipment_preview_row_and_optional_overlay, sp_in, 2); GUARD_JSR(c, sp_call, 0xC91A); }
    if (r->xf == 0) { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC91D, upload_one_equipment_preview_row_and_optional_overlay, sp_in, 2); GUARD_JSR(c, sp_call, 0xC91D); } else { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC91D, upload_one_equipment_preview_row_and_optional_overlay_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xC91D); }
    if (r->xf == 0) { upload_one_equipment_preview_row_and_optional_overlay(c); return; } else { upload_one_equipment_preview_row_and_optional_overlay_v2(c); return; }
}
SOM_REGISTER(0xD0C90B, SOM_RTS, "gen", select_three_row_equipment_preview_or_twelve_icon_grid, 0, L_B | L_X | L_Y | L_C | L_V, 35, 1, 0, 241, 101)

/* D0C91E upload_one_equipment_preview_row_and_optional_overlay   [class A, 45 bytes, 23 instructions]
 * Source: src/rom/select_three_row_equipment_preview_or_twelve_icon_grid.s
 * Subroutine of select_three_row_equipment_preview_or_twelve_icon_grid, translated in place.
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void upload_one_equipment_preview_row_and_optional_overlay(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC922, advance_menu_icon_palette_and_select_descriptor_tile, sp_in, 2); GUARD_JSR(c, sp_call, 0xC922); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x180C);
    RAM8(0x0000 + sp0) = value >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value;
    BUS16_SET(c, (db_ret << 0x10) + 0x180C, (uint16_t)(value + 0x01E0));
    RAM8(0x0000 + sp0 - 2) = x_ret >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x_ret;
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + (uint16_t)(x_ret - 2)));
    uint8_t a_hi2;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (value2 == 0xFFFF) {
        a_hi2 = value2 >> 8;
        y2 = y_ret;
        carry2 = value2 >= 0xFFFF;
        overflow2 = ((value ^ (uint16_t)(value + 0x01E0)) & ((uint16_t)(value + 0x01E0) ^ 0x01E0) & 0x8000) != 0;
        data_bank2 = db_ret;
        direct_page2 = dp_ret;
    } else {
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x20 + (uint16_t)(x_ret - 2)));
        uint8_t a_hi1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value3 & 0xFF00) == 0) {
            a_hi1 = (value3 & 0xFF00) >> 8;
            y1 = y_ret;
            carry1 = value2 >= 0xFFFF;
            overflow1 = ((value ^ (uint16_t)(value + 0x01E0)) & ((uint16_t)(value + 0x01E0) ^ 0x01E0) & 0x8000) != 0;
            data_bank = db_ret;
            direct_page = dp_ret;
        } else {
            uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + (uint16_t)(x_ret - 2)));
            r->a = (uint16_t)(value4 + 1);
            r->x = (uint16_t)(x_ret - 2);
            r->c = value2 >= 0xFFFF;
            r->z = (uint16_t)(value4 + 1) == 0;
            r->n = (uint16_t)(value4 + 1) & 0x8000;
            r->v = ((value ^ (uint16_t)(value + 0x01E0)) & ((uint16_t)(value + 0x01E0) ^ 0x01E0) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC944, expand_and_upload_two_native_menu_icon_tile_rows, sp_in, 2); GUARD_JSR(c, sp_call, 0xC944); }
            r->sp += 4;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            a_hi1 = a_all2 >> 8;
            y1 = y_ret2;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret2;
        }
        a_hi2 = a_hi1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    BUS16_SET(c, (data_bank2 << 0x10) + 0x180C, (value8 << 8) | value7);
    r->a = (value8 << 8) | value7;
    r->x = (value6 << 8) | value5;
    r->y = y2;
    r->c = carry2;
    r->z = ((value8 << 8) | value7) == 0;
    r->n = ((value8 << 8) | value7) & 0x8000;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank2;
    r->dp = direct_page2;
    RETURN_RTS(c);
}

/* D0C91E upload_one_equipment_preview_row_and_optional_overlay_v2   [class A, 45 bytes, 23 instructions]
 * Source: src/rom/select_three_row_equipment_preview_or_twelve_icon_grid.s
 * Subroutine of select_three_row_equipment_preview_or_twelve_icon_grid, translated in place.
 * Entry: M=any X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void upload_one_equipment_preview_row_and_optional_overlay_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    r->mf = 0;
    { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC922, advance_menu_icon_palette_and_select_descriptor_tile_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xC922); }
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    uint16_t x_ret = r->x;
    uint16_t y_ret = r->y;
    uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x180C);
    RAM8(0x0000 + sp0) = value >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value;
    BUS16_SET(c, (db_ret << 0x10) + 0x180C, (uint16_t)(value + 0x01E0));
    RAM8(0x0000 + sp0 - 2) = x_ret >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x_ret;
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp_ret + (uint16_t)(x_ret - 2)));
    uint8_t a_hi2;
    uint16_t y2;
    bool carry2;
    bool overflow2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (value2 == 0xFFFF) {
        a_hi2 = value2 >> 8;
        y2 = y_ret;
        carry2 = value2 >= 0xFFFF;
        overflow2 = ((value ^ (uint16_t)(value + 0x01E0)) & ((uint16_t)(value + 0x01E0) ^ 0x01E0) & 0x8000) != 0;
        data_bank2 = db_ret;
        direct_page2 = dp_ret;
    } else {
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x20 + (uint16_t)(x_ret - 2)));
        uint8_t a_hi1;
        uint16_t y1;
        bool carry1;
        bool overflow1;
        uint8_t data_bank;
        uint16_t direct_page;
        if ((value3 & 0xFF00) == 0) {
            a_hi1 = (value3 & 0xFF00) >> 8;
            y1 = y_ret;
            carry1 = value2 >= 0xFFFF;
            overflow1 = ((value ^ (uint16_t)(value + 0x01E0)) & ((uint16_t)(value + 0x01E0) ^ 0x01E0) & 0x8000) != 0;
            data_bank = db_ret;
            direct_page = dp_ret;
        } else {
            uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + (uint16_t)(x_ret - 2)));
            r->a = (uint16_t)(value4 + 1);
            r->x = (uint16_t)(x_ret - 2);
            r->c = value2 >= 0xFFFF;
            r->z = (uint16_t)(value4 + 1) == 0;
            r->n = (uint16_t)(value4 + 1) & 0x8000;
            r->v = ((value ^ (uint16_t)(value + 0x01E0)) & ((uint16_t)(value + 0x01E0) ^ 0x01E0) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xC944, expand_and_upload_two_native_menu_icon_tile_rows, sp_in, 2); GUARD_JSR(c, sp_call, 0xC944); }
            r->sp += 4;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            uint16_t a_all2 = r->a;
            uint16_t y_ret2 = r->y;
            bool carry_ret2 = r->c;
            bool overflow_ret2 = r->v;
            a_hi1 = a_all2 >> 8;
            y1 = y_ret2;
            carry1 = carry_ret2;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            direct_page = dp_ret2;
        }
        a_hi2 = a_hi1;
        y2 = y1;
        carry2 = carry1;
        overflow2 = overflow1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    BUS16_SET(c, (data_bank2 << 0x10) + 0x180C, (value8 << 8) | value7);
    r->a = (value8 << 8) | value7;
    r->x = (value6 << 8) | value5;
    r->y = y2;
    r->c = carry2;
    r->z = ((value8 << 8) | value7) == 0;
    r->n = ((value8 << 8) | value7) & 0x8000;
    r->v = overflow2;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank2;
    r->dp = direct_page2;
    RETURN_RTS(c);
}

/* D0C976 set_native_menu_icon_vram_cursor_then_fall_through   [class A, 134 bytes, 56 instructions]
 * Source: src/rom/select_three_row_equipment_preview_or_twelve_icon_grid.s
 * Subroutine of select_three_row_equipment_preview_or_twelve_icon_grid, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void set_native_menu_icon_vram_cursor_then_fall_through(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    BUS16_SET(c, (db << 0x10) + 0x180C, a);
    { const uint16_t sp_call = r->sp; JSR(c, 0xC97B, 0xD0C9FC); GUARD_JSR(c, sp_call, 0xC97B); } /* advance_native_menu_icon_palette_base_modulo_fifteen */
    uint16_t a_all = r->a;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + x));
    uint8_t a1;
    if (value != 0xFF) {
        a1 = value;
    } else {
        a1 = 0;
    }
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->a = (a_all >> 8 << 8) | a1;
    r->c = value >= 0xFF;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC989, 0xD0CA6E); GUARD_JSR(c, sp_call, 0xC989); } /* prepare_four_native_menu_icon_tiles_from_original_graphics */
    r->sp += 2;
    uint16_t a_all2 = r->a;
    uint16_t y_ret = r->y;
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x19F0);
    uint8_t a_hi2;
    if (value2 == 0xC0) {
        a_hi2 = a_all2 >> 8;
    } else {
        uint8_t a_hi1 = a_all2 >> 8;
        for (;;) {
            uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x4212);
            if (!(!(value3 & 0x80))) break;
        }
        a_hi2 = a_hi1;
    }
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x2116, value4);
    BUS8_SET(c, (db << 0x10) + 0x4350, 1);
    BUS8_SET(c, (db << 0x10) + 0x4351, 0x18);
    BUS16_SET(c, (db << 0x10) + 0x4352, 0x1900);
    BUS8_SET(c, (db << 0x10) + 0x4354, 0);
    BUS16_SET(c, (db << 0x10) + 0x4355, 0x40);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x20);
    uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x2116, (uint16_t)(value5 + 0x0100));
    BUS8_SET(c, (db << 0x10) + 0x4350, 1);
    BUS8_SET(c, (db << 0x10) + 0x4351, 0x18);
    BUS16_SET(c, (db << 0x10) + 0x4352, 0x1940);
    BUS8_SET(c, (db << 0x10) + 0x4354, 0);
    BUS16_SET(c, (db << 0x10) + 0x4355, 0x40);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x20);
    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x180C, (uint16_t)(value6 + 0x20));
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)(value6 + 0x20);
    r->x = (uint16_t)(((value8 << 8) | value7) + 2);
    r->y = (uint8_t)y_ret;
    r->c = value6 + 0x20 > 0xFFFF;
    r->z = (uint16_t)(((value8 << 8) | value7) + 2) == 0;
    r->n = (uint16_t)(((value8 << 8) | value7) + 2) & 0x8000;
    r->v = ((value6 ^ (uint16_t)(value6 + 0x20)) & ((uint16_t)(value6 + 0x20) ^ 0x20) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

/* D0C979 advance_menu_icon_palette_and_select_descriptor_tile   [class A, 131 bytes, 55 instructions]
 * Source: src/rom/select_three_row_equipment_preview_or_twelve_icon_grid.s
 * Subroutine of select_three_row_equipment_preview_or_twelve_icon_grid, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void advance_menu_icon_palette_and_select_descriptor_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC97B, 0xD0C9FC); GUARD_JSR(c, sp_call, 0xC97B); } /* advance_native_menu_icon_palette_base_modulo_fifteen */
    uint16_t a_all = r->a;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + x));
    uint8_t a1;
    if (value != 0xFF) {
        a1 = value;
    } else {
        a1 = 0;
    }
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->a = (a_all >> 8 << 8) | a1;
    r->c = value >= 0xFF;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC989, 0xD0CA6E); GUARD_JSR(c, sp_call, 0xC989); } /* prepare_four_native_menu_icon_tiles_from_original_graphics */
    r->sp += 2;
    uint16_t a_all2 = r->a;
    uint16_t y_ret = r->y;
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x19F0);
    uint8_t a_hi2;
    if (value2 == 0xC0) {
        a_hi2 = a_all2 >> 8;
    } else {
        uint8_t a_hi1 = a_all2 >> 8;
        for (;;) {
            uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x4212);
            if (!(!(value3 & 0x80))) break;
        }
        a_hi2 = a_hi1;
    }
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x2116, value4);
    BUS8_SET(c, (db << 0x10) + 0x4350, 1);
    BUS8_SET(c, (db << 0x10) + 0x4351, 0x18);
    BUS16_SET(c, (db << 0x10) + 0x4352, 0x1900);
    BUS8_SET(c, (db << 0x10) + 0x4354, 0);
    BUS16_SET(c, (db << 0x10) + 0x4355, 0x40);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x20);
    uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x2116, (uint16_t)(value5 + 0x0100));
    BUS8_SET(c, (db << 0x10) + 0x4350, 1);
    BUS8_SET(c, (db << 0x10) + 0x4351, 0x18);
    BUS16_SET(c, (db << 0x10) + 0x4352, 0x1940);
    BUS8_SET(c, (db << 0x10) + 0x4354, 0);
    BUS16_SET(c, (db << 0x10) + 0x4355, 0x40);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x20);
    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x180C, (uint16_t)(value6 + 0x20));
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)(value6 + 0x20);
    r->x = (uint16_t)(((value8 << 8) | value7) + 2);
    r->y = (uint8_t)y_ret;
    r->c = value6 + 0x20 > 0xFFFF;
    r->z = (uint16_t)(((value8 << 8) | value7) + 2) == 0;
    r->n = (uint16_t)(((value8 << 8) | value7) + 2) & 0x8000;
    r->v = ((value6 ^ (uint16_t)(value6 + 0x20)) & ((uint16_t)(value6 + 0x20) ^ 0x20) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

/* D0C986 expand_and_upload_two_native_menu_icon_tile_rows   [class A, 118 bytes, 49 instructions]
 * Source: src/rom/select_three_row_equipment_preview_or_twelve_icon_grid.s
 * Subroutine of select_three_row_equipment_preview_or_twelve_icon_grid, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void expand_and_upload_two_native_menu_icon_tile_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = x >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)x;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC989, 0xD0CA6E); GUARD_JSR(c, sp_call, 0xC989); } /* prepare_four_native_menu_icon_tiles_from_original_graphics */
    r->sp += 2;
    uint16_t a_all = r->a;
    uint16_t y_ret = r->y;
    uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x19F0);
    uint8_t a_hi2;
    if (value == 0xC0) {
        a_hi2 = a_all >> 8;
    } else {
        uint8_t a_hi1 = a_all >> 8;
        for (;;) {
            uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x4212);
            if (!(!(value2 & 0x80))) break;
        }
        a_hi2 = a_hi1;
    }
    uint16_t value3 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x2116, value3);
    BUS8_SET(c, (db << 0x10) + 0x4350, 1);
    BUS8_SET(c, (db << 0x10) + 0x4351, 0x18);
    BUS16_SET(c, (db << 0x10) + 0x4352, 0x1900);
    BUS8_SET(c, (db << 0x10) + 0x4354, 0);
    BUS16_SET(c, (db << 0x10) + 0x4355, 0x40);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x20);
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x2116, (uint16_t)(value4 + 0x0100));
    BUS8_SET(c, (db << 0x10) + 0x4350, 1);
    BUS8_SET(c, (db << 0x10) + 0x4351, 0x18);
    BUS16_SET(c, (db << 0x10) + 0x4352, 0x1940);
    BUS8_SET(c, (db << 0x10) + 0x4354, 0);
    BUS16_SET(c, (db << 0x10) + 0x4355, 0x40);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x20);
    uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x180C, (uint16_t)(value5 + 0x20));
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)(value5 + 0x20);
    r->x = (uint16_t)(((value7 << 8) | value6) + 2);
    r->y = (uint8_t)y_ret;
    r->c = value5 + 0x20 > 0xFFFF;
    r->z = (uint16_t)(((value7 << 8) | value6) + 2) == 0;
    r->n = (uint16_t)(((value7 << 8) | value6) + 2) & 0x8000;
    r->v = ((value5 ^ (uint16_t)(value5 + 0x20)) & ((uint16_t)(value5 + 0x20) ^ 0x20) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

/* D0C979 advance_menu_icon_palette_and_select_descriptor_tile_v2   [class A, 131 bytes, 55 instructions]
 * Source: src/rom/select_three_row_equipment_preview_or_twelve_icon_grid.s
 * Subroutine of select_three_row_equipment_preview_or_twelve_icon_grid, translated in place.
 * Entry: M=16 bit X=8 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void advance_menu_icon_palette_and_select_descriptor_tile_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 1)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint8_t x = r->x;
    const uint8_t db = r->db;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC97B, 0xD0C9FC); GUARD_JSR(c, sp_call, 0xC97B); } /* advance_native_menu_icon_palette_base_modulo_fifteen */
    uint16_t a_all = r->a;
    uint8_t value = BUS8_RDP(c, (uint16_t)(dp + x));
    uint8_t a1;
    if (value != 0xFF) {
        a1 = value;
    } else {
        a1 = 0;
    }
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = x;
    r->a = (a_all >> 8 << 8) | a1;
    r->c = value >= 0xFF;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xC989, 0xD0CA6E); GUARD_JSR(c, sp_call, 0xC989); } /* prepare_four_native_menu_icon_tiles_from_original_graphics */
    r->sp += 2;
    uint16_t a_all2 = r->a;
    uint16_t y_ret = r->y;
    uint8_t value2 = BUS8_RDP(c, (db << 0x10) + 0x19F0);
    uint8_t a_hi2;
    if (value2 == 0xC0) {
        a_hi2 = a_all2 >> 8;
    } else {
        uint8_t a_hi1 = a_all2 >> 8;
        for (;;) {
            uint8_t value3 = BUS8_RDP(c, (db << 0x10) + 0x4212);
            if (!(!(value3 & 0x80))) break;
        }
        a_hi2 = a_hi1;
    }
    uint16_t value4 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x2116, value4);
    BUS8_SET(c, (db << 0x10) + 0x4350, 1);
    BUS8_SET(c, (db << 0x10) + 0x4351, 0x18);
    BUS16_SET(c, (db << 0x10) + 0x4352, 0x1900);
    BUS8_SET(c, (db << 0x10) + 0x4354, 0);
    BUS16_SET(c, (db << 0x10) + 0x4355, 0x40);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x20);
    uint16_t value5 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x2116, (uint16_t)(value5 + 0x0100));
    BUS8_SET(c, (db << 0x10) + 0x4350, 1);
    BUS8_SET(c, (db << 0x10) + 0x4351, 0x18);
    BUS16_SET(c, (db << 0x10) + 0x4352, 0x1940);
    BUS8_SET(c, (db << 0x10) + 0x4354, 0);
    BUS16_SET(c, (db << 0x10) + 0x4355, 0x40);
    BUS8_SET(c, (db << 0x10) + 0x420B, 0x20);
    uint16_t value6 = BUS16_RDP(c, (db << 0x10) + 0x180C);
    BUS16_SET(c, (db << 0x10) + 0x180C, (uint16_t)(value6 + 0x20));
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->a = (uint16_t)(value6 + 0x20);
    r->x = (uint16_t)(((value8 << 8) | value7) + 2);
    r->y = (uint8_t)y_ret;
    r->c = value6 + 0x20 > 0xFFFF;
    r->z = (uint16_t)(((value8 << 8) | value7) + 2) == 0;
    r->n = (uint16_t)(((value8 << 8) | value7) + 2) & 0x8000;
    r->v = ((value6 ^ (uint16_t)(value6 + 0x20)) & ((uint16_t)(value6 + 0x20) ^ 0x20) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}

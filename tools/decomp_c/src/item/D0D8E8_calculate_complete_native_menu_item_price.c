#include "som_c.h"

/* D0D8E8 calculate_complete_native_menu_item_price   [class C, 204 bytes, 96 instructions]
 * Source: src/rom/calculate_complete_native_menu_item_price.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: AB.
 */
static void calculate_complete_native_menu_item_price(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    uint8_t value = RAM8(0x1847);
    if ((uint8_t)(value - 1) == 0) {
        uint8_t ring_cursor = RAM8(RING_CURSOR);
        uint16_t value2 = RAM16(0x183C);
        uint16_t value3 = BUS16(c, 0xD80000 + (uint16_t)((((a >> 8 << 8) | ring_cursor) & 0xFF) + value2));
        RAM8(0x0000 + sp0) = 0;
        RAM8(0x0000 + sp0 - 1) = value3 & 0xFF;
        r->a = value3 & 0xFF;
        r->x = (uint16_t)((((a >> 8 << 8) | ring_cursor) & 0xFF) + value2);
        r->c = (((a >> 8 << 8) | ring_cursor) & 0xFF) + value2 > 0xFFFF;
        r->z = (value3 & 0xFF) == 0;
        r->n = value3 & 0xFF & 0x8000;
        r->v = (((((a >> 8 << 8) | ring_cursor) & 0xFF) ^ (uint16_t)((((a >> 8 << 8) | ring_cursor) & 0xFF) + value2)) & (value2 ^ (uint16_t)((((a >> 8 << 8) | ring_cursor) & 0xFF) + value2)) & 0x8000) != 0;
        r->sp -= 2;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD97B, 0xC0793D); GUARD_JSL(c, sp_call, 0xD97B); } /* hide_shop_hero_markers_before_price_selection */
        r->sp += 2;
        uint16_t a_all = r->a;
        uint8_t a1 = (uint8_t)a_all;
        uint8_t a_hi1 = a_all >> 8;
        uint16_t x1 = 0xFFFA;
        for (;;) {
            uint16_t value4 = BUS16(c, 0xD8FB84 + (uint16_t)(x1 + 6));
            uint16_t value5 = RAM16(0x0000 + sp0 - 1);
            if (value4 != value5) {
                if (value4 >= value5) {
                    a1 = (uint8_t)value4;
                    a_hi1 = value4 >> 8;
                    x1 = (uint16_t)(x1 + 6);
                    continue;
                }
            }
            a1 = (uint8_t)value4;
            a_hi1 = value4 >> 8;
            x1 = (uint16_t)(x1 + 6);
            break;
        }
        uint8_t value6 = RAM8(0x0000 + sp0 - 1);
        uint8_t value7 = RAM8(0x0000 + sp0);
        RAM8(0x0000 + sp0) = a_hi1;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)((a_hi1 << 8) | a1);
        uint16_t value8 = RAM16(0x0000 + sp0 - 1);
        RAM8(0x0000 + sp0 - 2) = (uint16_t)(((value7 << 8) | value6) - value8) >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)(((value7 << 8) | value6) - value8);
        RAM8(0x0000 + sp0 - 4) = x1 >> 8;
        RAM8(0x0000 + sp0 - 5) = (uint8_t)x1;
        RAM8(0x0000 + sp0 - 6) = (((((uint16_t)(((value7 << 8) | value6) - value8) >> 0x0F << 7) | ((((((value7 << 8) | value6) ^ value8) & (((value7 << 8) | value6) ^ (uint16_t)(((value7 << 8) | value6) - value8)) & 0x8000) != 0) << 6)) | (d_entry << 3)) | (i_entry << 2)) | (((uint16_t)(((value7 << 8) | value6) - value8) == 0) << 1) | ((value7 << 8) | value6) >= value8;
        uint16_t value9 = BUS16(c, 0xD8FB86 + x1);
        r->a = (uint16_t)((uint16_t)(((value7 << 8) | value6) - value8) + value9);
        r->x = x1;
        r->y = (value7 << 8) | value6;
        r->c = (uint16_t)(((value7 << 8) | value6) - value8) + value9 > 0xFFFF;
        r->z = (uint16_t)((uint16_t)(((value7 << 8) | value6) - value8) + value9) == 0;
        r->n = (uint16_t)((uint16_t)(((value7 << 8) | value6) - value8) + value9) & 0x8000;
        r->v = (((uint16_t)(((value7 << 8) | value6) - value8) ^ (uint16_t)((uint16_t)(((value7 << 8) | value6) - value8) + value9)) & (value9 ^ (uint16_t)((uint16_t)(((value7 << 8) | value6) - value8) + value9)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD99F, 0xD0D9F6); GUARD_JSR(c, sp_call, 0xD99F); } /* publish_shop_item_eligible_hero_markers */
        r->sp += 7;
        uint16_t a_all2 = r->a;
        uint8_t value10 = RAM8(0x0000 + sp0 - 6);
        if (value10 & 0x10) {
            uint8_t value11 = RAM8(0x0000 + sp0 - 5);
            if (value10 & 0x20) {
                uint8_t value12 = RAM8(0x0000 + sp0 - 4);
                uint8_t value13 = RAM8(0x0000 + sp0 - 3);
                uint8_t value14 = BUS8(c, 0xD8FB88 + value11);
                uint8_t value15 = BUS8(c, 0xD80000 + (uint8_t)((a_all2 >> 8 << 8) | (uint8_t)((uint8_t)(value12 << 1) + value14)));
                r->a = (a_all2 >> 8 << 8) | value15;
                r->x = (uint8_t)((a_all2 >> 8 << 8) | (uint8_t)((uint8_t)(value12 << 1) + value14));
                r->y = value13;
                r->c = (uint8_t)(value12 << 1) + value14 > 0xFF;
                r->z = value15 == 0;
                r->n = value15 & 0x80;
                r->v = (((uint8_t)(value12 << 1) ^ (uint8_t)((uint8_t)(value12 << 1) + value14)) & (value14 ^ (uint8_t)((uint8_t)(value12 << 1) + value14)) & 0x80) != 0;
                r->mf = 1;
                r->xf = 1;
                r->i = value10 & 0x04;
                r->d = value10 & 0x08;
                r->sp -= 3;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD9B2, 0xC07CD4); GUARD_JSL(c, sp_call, 0xD9B2); } /* adjust_menu_price_for_shop_and_inventory_modes */
                r->sp += 3;
                uint8_t value16 = RAM8(0x0000 + sp0 - 2);
                uint8_t value17 = RAM8(0x0000 + sp0 - 1);
                r->mf = 0;
                r->xf = 1;
                TAIL_CALL_FRAME(c, 0xD00000 | (uint16_t)(((value17 << 8) | value16) + 1), SOM_RTS, 1); /* jump through a pushed address */
            } else {
                uint8_t value18 = RAM8(0x0000 + sp0 - 4);
                uint8_t value19 = RAM8(0x0000 + sp0 - 3);
                uint8_t value20 = RAM8(0x0000 + sp0 - 2);
                uint16_t value21 = BUS16(c, 0xD8FB88 + value11);
                uint16_t value22 = BUS16(c, 0xD80000 + (uint8_t)((uint16_t)(((value19 << 8) | value18) << 1) + value21));
                r->a = value22;
                r->x = (uint8_t)((uint16_t)(((value19 << 8) | value18) << 1) + value21);
                r->y = value20;
                r->c = (uint16_t)(((value19 << 8) | value18) << 1) + value21 > 0xFFFF;
                r->z = value22 == 0;
                r->n = value22 & 0x8000;
                r->v = (((uint16_t)(((value19 << 8) | value18) << 1) ^ (uint16_t)((uint16_t)(((value19 << 8) | value18) << 1) + value21)) & (value21 ^ (uint16_t)((uint16_t)(((value19 << 8) | value18) << 1) + value21)) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 1;
                r->i = value10 & 0x04;
                r->d = value10 & 0x08;
                r->sp -= 2;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD9B2, 0xC07CD4); GUARD_JSL(c, sp_call, 0xD9B2); } /* adjust_menu_price_for_shop_and_inventory_modes */
                r->sp += 2;
                uint8_t value23 = RAM8(0x0000 + sp0 - 1);
                uint8_t value24 = RAM8(0x0000 + sp0);
                r->mf = 0;
                r->xf = 1;
                TAIL_CALL_DYN(c, 0xD00000 | (uint16_t)(((value24 << 8) | value23) + 1), SOM_RTS); /* jump through a pushed address */
            }
        } else {
            uint8_t value25 = RAM8(0x0000 + sp0 - 5);
            uint8_t value26 = RAM8(0x0000 + sp0 - 4);
            if (value10 & 0x20) {
                c->fail = 3;
                return;
            } else {
                uint8_t value32 = RAM8(0x0000 + sp0 - 3);
                uint8_t value33 = RAM8(0x0000 + sp0 - 2);
                uint8_t value34 = RAM8(0x0000 + sp0 - 1);
                uint8_t value35 = RAM8(0x0000 + sp0);
                uint16_t value36 = BUS16(c, 0xD8FB88 + ((value26 << 8) | value25));
                uint16_t value37 = BUS16(c, 0xD80000 + (uint16_t)((uint16_t)(((value33 << 8) | value32) << 1) + value36));
                r->a = value37;
                r->x = (uint16_t)((uint16_t)(((value33 << 8) | value32) << 1) + value36);
                r->y = (value35 << 8) | value34;
                r->c = (uint16_t)(((value33 << 8) | value32) << 1) + value36 > 0xFFFF;
                r->z = value37 == 0;
                r->n = value37 & 0x8000;
                r->v = (((uint16_t)(((value33 << 8) | value32) << 1) ^ (uint16_t)((uint16_t)(((value33 << 8) | value32) << 1) + value36)) & (value36 ^ (uint16_t)((uint16_t)(((value33 << 8) | value32) << 1) + value36)) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->i = value10 & 0x04;
                r->d = value10 & 0x08;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD9B2, 0xC07CD4); GUARD_JSL(c, sp_call, 0xD9B2); } /* adjust_menu_price_for_shop_and_inventory_modes */
                r->mf = 0;
                r->xf = 0;
                RETURN_RTS(c);
            }
        }
    }
    if ((uint8_t)(value - 2) == 0) {
        uint8_t ring_category = RAM8(RING_CATEGORY);
        uint16_t x4;
        uint16_t y3;
        if (ring_category == 4) {
            x4 = 0x24;
            y3 = 0x12;
        } else {
            uint16_t x3;
            uint16_t y2;
            if (ring_category == 5) {
                x3 = 0x30;
                y2 = 0x0C;
            } else {
                uint16_t x2;
                uint16_t y1;
                if (ring_category == 6) {
                    x2 = 0x3C;
                    y1 = 6;
                } else {
                    x2 = 0x48;
                    y1 = 0;
                }
                x3 = x2;
                y2 = y1;
            }
            x4 = x3;
            y3 = y2;
        }
        r->a = (a >> 8 << 8) | ring_category;
        r->x = x4;
        r->y = y3;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD93B, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD93B); } /* calculate_wrapped_native_menu_row_index */
        uint16_t a_all7 = r->a;
        RAM8(0x0000 + sp0) = x4 >> 8;
        RAM8(0x0000 + sp0 - 1) = (uint8_t)x4;
        uint16_t value39 = RAM16(0xCC00 + (uint16_t)((a_all7 & 0xFF) + RAM16(0x0000 + sp0 - 1)));
        uint8_t a2;
        uint8_t a_hi2;
        if (y3 != 0) {
            uint16_t value40 = BUS16(c, 0xD8FB86 + y3);
            a2 = (uint8_t)((value39 & 0x3F) - value40);
            a_hi2 = (uint16_t)((value39 & 0x3F) - value40) >> 8;
        } else {
            a2 = value39 & 0x1F;
            a_hi2 = 0;
        }
        uint16_t value41 = BUS16(c, 0xD8FB88 + y3);
        uint16_t value42 = BUS16(c, 0xD80000 + (uint16_t)((uint16_t)(((a_hi2 << 8) | a2) << 1) + value41));
        r->a = value42;
        r->x = (uint16_t)((uint16_t)(((a_hi2 << 8) | a2) << 1) + value41);
        r->c = (uint16_t)(((a_hi2 << 8) | a2) << 1) + value41 > 0xFFFF;
        r->z = value42 == 0;
        r->n = value42 & 0x8000;
        r->v = (((uint16_t)(((a_hi2 << 8) | a2) << 1) ^ (uint16_t)((uint16_t)(((a_hi2 << 8) | a2) << 1) + value41)) & (value41 ^ (uint16_t)((uint16_t)(((a_hi2 << 8) | a2) << 1) + value41)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD9B2, 0xC07CD4); GUARD_JSL(c, sp_call, 0xD9B2); } /* adjust_menu_price_for_shop_and_inventory_modes */
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = (a >> 8 << 8) | (uint8_t)(value - 2);
    r->z = (uint8_t)(value - 2) == 0;
    r->n = (uint8_t)(value - 2) & 0x80;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xD8FA, 0xC07C4C); GUARD_JSL(c, sp_call, 0xD8FA); } /* resolve_selected_armor_inventory_row_and_description_id */
    uint16_t a_all9 = r->a;
    uint8_t value43 = RAM8(0x1842);
    uint16_t value44 = BUS16(c, 0xD8FB82);
    uint16_t value45 = BUS16(c, 0xD80000 + (uint16_t)(((((a_all9 >> 8 << 8) | value43) & 0xFF) << 1) + value44));
    r->a = value45;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D8E8, SOM_RTS, "gen", calculate_complete_native_menu_item_price, SOM_UNWINDS, L_A | L_B, 7, 0, 0, 204, 96)

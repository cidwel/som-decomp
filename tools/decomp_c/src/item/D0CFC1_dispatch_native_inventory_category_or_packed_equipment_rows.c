#include "som_c.h"

static void append_one_native_packed_equipment_row_and_eligibility_flags(SomCtx *c);
static void append_one_native_packed_equipment_row_and_eligibility_flags_v2(SomCtx *c);

/* D0CFC1 dispatch_native_inventory_category_or_packed_equipment_rows   [class C, 225 bytes, 108 instructions]
 * Source: src/rom/dispatch_native_inventory_category_or_packed_equipment_rows.s
 * Documented in docs/event-menu-inventory-builder.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void dispatch_native_inventory_category_or_packed_equipment_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t sp_in = r->sp;
    if (RAM8(0x1847) != 2) {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFD6, 0xD0D308); GUARD_JSR(c, sp_call, 0xCFD6); } /* clear_native_menu_descriptor_row_attributes */
        if ((RAM16(0x1803) & 0x80) != 0) {
            uint16_t ring_owner = RAM16(RING_OWNER);
            uint8_t a1;
            uint16_t x1;
            if ((uint16_t)((ring_owner & 0xFF) - 1) != 0) {
                r->a = (uint16_t)((ring_owner & 0xFF) - 1);
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD017, 0xD0D0DA); GUARD_JSL(c, sp_call, 0xD017); } /* locate_selected_armor_with_nonzero_level */
                uint16_t a_all2 = r->a;
                uint16_t x_ret2 = r->x;
                RAM8(0x0000 + sp0) = a_all2 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all2;
                uint16_t value3 = BUS16(c, 0x001878 + x_ret2);
                a1 = value3 & 0x0F;
                x1 = x_ret2;
            } else {
                r->a = (uint16_t)((ring_owner & 0xFF) - 1);
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD006, 0xD0D0B0); GUARD_JSL(c, sp_call, 0xD006); } /* locate_selected_weapon_with_nonzero_level */
                uint16_t a_all3 = r->a;
                uint16_t x_ret3 = r->x;
                RAM8(0x0000 + sp0) = a_all3 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all3;
                uint16_t value4 = BUS16(c, 0x001878 + x_ret3);
                a1 = (value4 & 0xF0) >> 4;
                x1 = x_ret3;
            }
            RAM16_SET(0x182E, a1);
            uint16_t x2;
            if (x1 != 7) {
                x2 = x1;
            } else {
                x2 = (uint16_t)(x1 - 1);
            }
            RAM8(0x0000 + sp0 - 2) = (uint16_t)(x2 << 1) >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)(x2 << 1);
            uint16_t value5 = RAM16(0x0000 + sp0 - 3);
            RAM16_SET(0x0000 + sp0 - 3, (uint16_t)((uint16_t)(x2 << 2) + value5));
            uint16_t ring_owner2 = RAM16(RING_OWNER);
            uint8_t a_hi1;
            if ((ring_owner2 & 1) == 0) {
                a_hi1 = ring_owner2 >> 8;
            } else {
                uint16_t value6 = RAM16(0x0000 + sp0 - 3);
                RAM16_SET(0x0000 + sp0 - 3, (uint16_t)(value6 + 3));
                a_hi1 = (uint16_t)(value6 + 3) >> 8;
            }
            RAM16_SET(0x184F, (RAM8(0x0000 + sp0 - 2) << 8) | RAM8(0x0000 + sp0 - 3));
            uint16_t value9 = BUS16(c, 0xD8FD70 + (uint16_t)(x2 << 1));
            RAM16_SET(0x1828, value9);
            r->a = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
            r->x = 0;
            r->v = (((uint16_t)(x2 << 2) ^ (uint16_t)((uint16_t)(x2 << 2) + value5)) & (value5 ^ (uint16_t)((uint16_t)(x2 << 2) + value5)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD054, append_one_native_packed_equipment_row_and_eligibility_flags, sp_in, 2); GUARD_JSR(c, sp_call, 0xD054); }
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD057, append_one_native_packed_equipment_row_and_eligibility_flags_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xD057); }
            r->mf = 0;
            r->xf = 0;
            append_one_native_packed_equipment_row_and_eligibility_flags_v2(c); return;
        }
        uint16_t ring_category = RAM16(RING_CATEGORY);
        r->a = (ring_category & 0xFF) << 1;
        r->x = (ring_category & 0xFF) << 1;
        r->c = ring_category & 0xFF & 0x8000;
        r->z = (ring_category & 0xFF) << 1 == 0;
        r->n = (ring_category & 0xFF) << 1 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        switch ((ring_category & 0xFF) << 1) {
        case 0x0000: TAIL_CALL_DYN(c, 0xD0D0FB, SOM_RTS); /* build_native_consumable_inventory_descriptor_rows */
        case 0x0002: TAIL_CALL_DYN(c, 0xD0D128, SOM_RTS); /* build_native_owned_weapon_inventory_descriptor_rows */
        case 0x0004: TAIL_CALL_DYN(c, 0xD0D1AE, SOM_RTS); /* build_fixed_seven_native_menu_descriptor_rows */
        case 0x0006: TAIL_CALL_DYN(c, 0xD0D1CF, SOM_RTS); /* build_native_armor_inventory_descriptor_rows */
        case 0x0008: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        case 0x000A: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        case 0x000C: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        default: TAIL_CALL_DYN(c, 0xD00000 | BUS16(c, 0xD00000 + (uint16_t)(0xCFEC + ((ring_category & 0xFF) << 1))), SOM_RTS);
        }
    }
    uint8_t ring_category2 = RAM8(RING_CATEGORY);
    if (ring_category2 == 0) {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFD6, 0xD0D308); GUARD_JSR(c, sp_call, 0xCFD6); } /* clear_native_menu_descriptor_row_attributes */
        if ((RAM16(0x1803) & 0x80) != 0) {
            uint16_t ring_owner3 = RAM16(RING_OWNER);
            uint8_t a2;
            uint16_t x3;
            if ((uint16_t)((ring_owner3 & 0xFF) - 1) != 0) {
                r->a = (uint16_t)((ring_owner3 & 0xFF) - 1);
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD017, 0xD0D0DA); GUARD_JSL(c, sp_call, 0xD017); } /* locate_selected_armor_with_nonzero_level */
                uint16_t a_all7 = r->a;
                uint16_t x_ret7 = r->x;
                RAM8(0x0000 + sp0) = a_all7 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all7;
                uint16_t value13 = BUS16(c, 0x001878 + x_ret7);
                a2 = value13 & 0x0F;
                x3 = x_ret7;
            } else {
                r->a = (uint16_t)((ring_owner3 & 0xFF) - 1);
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD006, 0xD0D0B0); GUARD_JSL(c, sp_call, 0xD006); } /* locate_selected_weapon_with_nonzero_level */
                uint16_t a_all8 = r->a;
                uint16_t x_ret8 = r->x;
                RAM8(0x0000 + sp0) = a_all8 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all8;
                uint16_t value14 = BUS16(c, 0x001878 + x_ret8);
                a2 = (value14 & 0xF0) >> 4;
                x3 = x_ret8;
            }
            RAM16_SET(0x182E, a2);
            uint16_t x4;
            if (x3 != 7) {
                x4 = x3;
            } else {
                x4 = (uint16_t)(x3 - 1);
            }
            RAM8(0x0000 + sp0 - 2) = (uint16_t)(x4 << 1) >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)(x4 << 1);
            uint16_t value15 = RAM16(0x0000 + sp0 - 3);
            RAM16_SET(0x0000 + sp0 - 3, (uint16_t)((uint16_t)(x4 << 2) + value15));
            uint16_t ring_owner4 = RAM16(RING_OWNER);
            uint8_t a_hi2;
            if ((ring_owner4 & 1) == 0) {
                a_hi2 = ring_owner4 >> 8;
            } else {
                uint16_t value16 = RAM16(0x0000 + sp0 - 3);
                RAM16_SET(0x0000 + sp0 - 3, (uint16_t)(value16 + 3));
                a_hi2 = (uint16_t)(value16 + 3) >> 8;
            }
            RAM16_SET(0x184F, (RAM8(0x0000 + sp0 - 2) << 8) | RAM8(0x0000 + sp0 - 3));
            uint16_t value19 = BUS16(c, 0xD8FD70 + (uint16_t)(x4 << 1));
            RAM16_SET(0x1828, value19);
            r->a = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
            r->x = 0;
            r->v = (((uint16_t)(x4 << 2) ^ (uint16_t)((uint16_t)(x4 << 2) + value15)) & (value15 ^ (uint16_t)((uint16_t)(x4 << 2) + value15)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD054, append_one_native_packed_equipment_row_and_eligibility_flags, sp_in, 2); GUARD_JSR(c, sp_call, 0xD054); }
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD057, append_one_native_packed_equipment_row_and_eligibility_flags_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xD057); }
            r->mf = 0;
            r->xf = 0;
            append_one_native_packed_equipment_row_and_eligibility_flags_v2(c); return;
        }
        uint16_t ring_category3 = RAM16(RING_CATEGORY);
        r->a = (ring_category3 & 0xFF) << 1;
        r->x = (ring_category3 & 0xFF) << 1;
        r->c = ring_category3 & 0xFF & 0x8000;
        r->z = (ring_category3 & 0xFF) << 1 == 0;
        r->n = (ring_category3 & 0xFF) << 1 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        switch ((ring_category3 & 0xFF) << 1) {
        case 0x0000: TAIL_CALL_DYN(c, 0xD0D0FB, SOM_RTS); /* build_native_consumable_inventory_descriptor_rows */
        case 0x0002: TAIL_CALL_DYN(c, 0xD0D128, SOM_RTS); /* build_native_owned_weapon_inventory_descriptor_rows */
        case 0x0004: TAIL_CALL_DYN(c, 0xD0D1AE, SOM_RTS); /* build_fixed_seven_native_menu_descriptor_rows */
        case 0x0006: TAIL_CALL_DYN(c, 0xD0D1CF, SOM_RTS); /* build_native_armor_inventory_descriptor_rows */
        case 0x0008: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        case 0x000A: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        case 0x000C: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        default: TAIL_CALL_DYN(c, 0xD00000 | BUS16(c, 0xD00000 + (uint16_t)(0xCFEC + ((ring_category3 & 0xFF) << 1))), SOM_RTS);
        }
    }
    if (ring_category2 >= 4) {
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0xCFD6, 0xD0D308); GUARD_JSR(c, sp_call, 0xCFD6); } /* clear_native_menu_descriptor_row_attributes */
        if ((RAM16(0x1803) & 0x80) != 0) {
            uint16_t ring_owner5 = RAM16(RING_OWNER);
            uint8_t a3;
            uint16_t x5;
            if ((uint16_t)((ring_owner5 & 0xFF) - 1) != 0) {
                r->a = (uint16_t)((ring_owner5 & 0xFF) - 1);
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD017, 0xD0D0DA); GUARD_JSL(c, sp_call, 0xD017); } /* locate_selected_armor_with_nonzero_level */
                uint16_t a_all12 = r->a;
                uint16_t x_ret12 = r->x;
                RAM8(0x0000 + sp0) = a_all12 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all12;
                uint16_t value23 = BUS16(c, 0x001878 + x_ret12);
                a3 = value23 & 0x0F;
                x5 = x_ret12;
            } else {
                r->a = (uint16_t)((ring_owner5 & 0xFF) - 1);
                r->mf = 0;
                r->xf = 0;
                { const uint16_t sp_call = r->sp; JSL(c, 0xD006, 0xD0D0B0); GUARD_JSL(c, sp_call, 0xD006); } /* locate_selected_weapon_with_nonzero_level */
                uint16_t a_all13 = r->a;
                uint16_t x_ret13 = r->x;
                RAM8(0x0000 + sp0) = a_all13 >> 8;
                RAM8(0x0000 + sp0 - 1) = (uint8_t)a_all13;
                uint16_t value24 = BUS16(c, 0x001878 + x_ret13);
                a3 = (value24 & 0xF0) >> 4;
                x5 = x_ret13;
            }
            RAM16_SET(0x182E, a3);
            uint16_t x6;
            if (x5 != 7) {
                x6 = x5;
            } else {
                x6 = (uint16_t)(x5 - 1);
            }
            RAM8(0x0000 + sp0 - 2) = (uint16_t)(x6 << 1) >> 8;
            RAM8(0x0000 + sp0 - 3) = (uint8_t)(x6 << 1);
            uint16_t value25 = RAM16(0x0000 + sp0 - 3);
            RAM16_SET(0x0000 + sp0 - 3, (uint16_t)((uint16_t)(x6 << 2) + value25));
            uint16_t ring_owner6 = RAM16(RING_OWNER);
            uint8_t a_hi3;
            if ((ring_owner6 & 1) == 0) {
                a_hi3 = ring_owner6 >> 8;
            } else {
                uint16_t value26 = RAM16(0x0000 + sp0 - 3);
                RAM16_SET(0x0000 + sp0 - 3, (uint16_t)(value26 + 3));
                a_hi3 = (uint16_t)(value26 + 3) >> 8;
            }
            RAM16_SET(0x184F, (RAM8(0x0000 + sp0 - 2) << 8) | RAM8(0x0000 + sp0 - 3));
            uint16_t value29 = BUS16(c, 0xD8FD70 + (uint16_t)(x6 << 1));
            RAM16_SET(0x1828, value29);
            r->a = (RAM8(0x0000 + sp0) << 8) | RAM8(0x0000 + sp0 - 1);
            r->x = 0;
            r->v = (((uint16_t)(x6 << 2) ^ (uint16_t)((uint16_t)(x6 << 2) + value25)) & (value25 ^ (uint16_t)((uint16_t)(x6 << 2) + value25)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD054, append_one_native_packed_equipment_row_and_eligibility_flags, sp_in, 2); GUARD_JSR(c, sp_call, 0xD054); }
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR_SUB(c, 0xD057, append_one_native_packed_equipment_row_and_eligibility_flags_v2, sp_in, 2); GUARD_JSR(c, sp_call, 0xD057); }
            r->mf = 0;
            r->xf = 0;
            append_one_native_packed_equipment_row_and_eligibility_flags_v2(c); return;
        }
        uint16_t ring_category4 = RAM16(RING_CATEGORY);
        r->a = (ring_category4 & 0xFF) << 1;
        r->x = (ring_category4 & 0xFF) << 1;
        r->c = ring_category4 & 0xFF & 0x8000;
        r->z = (ring_category4 & 0xFF) << 1 == 0;
        r->n = (ring_category4 & 0xFF) << 1 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        switch ((ring_category4 & 0xFF) << 1) {
        case 0x0000: TAIL_CALL_DYN(c, 0xD0D0FB, SOM_RTS); /* build_native_consumable_inventory_descriptor_rows */
        case 0x0002: TAIL_CALL_DYN(c, 0xD0D128, SOM_RTS); /* build_native_owned_weapon_inventory_descriptor_rows */
        case 0x0004: TAIL_CALL_DYN(c, 0xD0D1AE, SOM_RTS); /* build_fixed_seven_native_menu_descriptor_rows */
        case 0x0006: TAIL_CALL_DYN(c, 0xD0D1CF, SOM_RTS); /* build_native_armor_inventory_descriptor_rows */
        case 0x0008: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        case 0x000A: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        case 0x000C: TAIL_CALL_DYN(c, 0xD0D22F, SOM_RTS); /* build_native_category_inventory_descriptor_rows */
        default: TAIL_CALL_DYN(c, 0xD00000 | BUS16(c, 0xD00000 + (uint16_t)(0xCFEC + ((ring_category4 & 0xFF) << 1))), SOM_RTS);
        }
    }
    SET_A8(r, ring_category2);
    r->c = ring_category2 >= 4;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0CFC1, SOM_RTS, "gen", dispatch_native_inventory_category_or_packed_equipment_rows, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_V, 18, 0, 0, 239, 108)

/* D0D058 append_one_native_packed_equipment_row_and_eligibility_flags   [class A, 88 bytes, 42 instructions]
 * Source: src/rom/dispatch_native_inventory_category_or_packed_equipment_rows.s
 * Subroutine of dispatch_native_inventory_category_or_packed_equipment_rows, translated in place.
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void append_one_native_packed_equipment_row_and_eligibility_flags(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = a >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 2) = x >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x;
    uint8_t a_hi3;
    uint16_t y1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((a & 1) == 0) {
        a_hi3 = 0;
        y1 = y;
        overflow1 = overflow;
        data_bank = 0;
        direct_page = 0;
    } else {
        uint16_t ring_owner = RAM16(RING_OWNER);
        uint8_t a_hi1;
        uint16_t x1;
        if ((uint16_t)((ring_owner & 0xFF) - 1) != 0) {
            a_hi1 = (uint16_t)((ring_owner & 0xFF) - 1) >> 8;
            x1 = x;
        } else {
            a_hi1 = (uint16_t)(x + 6) >> 8;
            x1 = (uint16_t)(x + 6);
        }
        uint16_t value = RAM16(0x1828);
        uint16_t value2 = BUS16(c, 0xD80000 + (uint16_t)(x1 + value));
        BUS16_SET(c, 0x000000 + y, value2 & 0xFF7F);
        uint8_t value3 = BUS8(c, 0xD80000 + (uint16_t)(x1 + value));
        BUS8_SET(c, 0x000021 + y, value3 & 0x80);
        r->a = ((value2 & 0xFF7F) >> 8 << 8) | RAM8(0x184F);
        r->v = ((x1 ^ (uint16_t)(x1 + value)) & (value ^ (uint16_t)(x1 + value)) & 0x8000) != 0;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD08F, 0xD0CEBF); GUARD_JSL(c, sp_call, 0xD08F); } /* external */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD095, 0xC073AC); GUARD_JSL(c, sp_call, 0xD095); } /* test_native_equipment_row_eligibility_from_hero_state_and_level */
        r->sp += 4;
        uint16_t a_all2 = r->a;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        bool m_flag;
        uint8_t a_hi2;
        if (carry_ret2) {
            m_flag = 1;
            a_hi2 = a_all2 >> 8;
        } else {
            uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0x20 + y);
            BUS16_SET(c, (db_ret << 0x10) + 0x20 + y, value5 | 0x4000);
            m_flag = 0;
            a_hi2 = (value5 | 0x4000) >> 8;
        }
        a_hi3 = a_hi2;
        y1 = (uint16_t)(y + 2);
        overflow1 = overflow_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    uint16_t value6 = BUS16_RDP(c, (data_bank << 0x10) + 0x184F);
    BUS16_RMW_SET(c, (data_bank << 0x10) + 0x184F, (uint16_t)(value6 + 1));
    uint8_t value7 = RAM8(0x0000 + sp0 - 3);
    uint8_t value8 = RAM8(0x0000 + sp0 - 2);
    uint8_t value9 = RAM8(0x0000 + sp0 - 1);
    uint8_t value10 = RAM8(0x0000 + sp0);
    r->a = ((value10 << 8) | value9) >> 1;
    r->x = (uint16_t)(((value8 << 8) | value7) + 2);
    r->y = y1;
    r->c = ((value10 << 8) | value9) & 0x01;
    r->z = ((value10 << 8) | value9) >> 1 == 0;
    r->n = ((value10 << 8) | value9) >> 1 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}

/* D0D058 append_one_native_packed_equipment_row_and_eligibility_flags_v2   [class A, 88 bytes, 42 instructions]
 * Source: src/rom/dispatch_native_inventory_category_or_packed_equipment_rows.s
 * Subroutine of dispatch_native_inventory_category_or_packed_equipment_rows, translated in place.
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void append_one_native_packed_equipment_row_and_eligibility_flags_v2(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    RAM8(0x0000 + sp0) = a >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 2) = x >> 8;
    RAM8(0x0000 + sp0 - 3) = (uint8_t)x;
    uint8_t a_hi3;
    uint16_t y1;
    bool overflow1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((a & 1) == 0) {
        a_hi3 = 0;
        y1 = y;
        overflow1 = overflow;
        data_bank = db;
        direct_page = dp;
    } else {
        uint16_t value = BUS16_RDP(c, (db << 0x10) + 0x1808);
        uint8_t a_hi1;
        uint16_t x1;
        if ((uint16_t)((value & 0xFF) - 1) != 0) {
            a_hi1 = (uint16_t)((value & 0xFF) - 1) >> 8;
            x1 = x;
        } else {
            a_hi1 = (uint16_t)(x + 6) >> 8;
            x1 = (uint16_t)(x + 6);
        }
        uint16_t value2 = BUS16_RDP(c, (db << 0x10) + 0x1828);
        uint16_t value3 = BUS16(c, 0xD80000 + (uint16_t)(x1 + value2));
        BUS16_SET(c, (db << 0x10) + y, value3 & 0xFF7F);
        uint8_t value4 = BUS8(c, 0xD80000 + (uint16_t)(x1 + value2));
        BUS8_SET(c, (db << 0x10) + 0x21 + y, value4 & 0x80);
        uint8_t value5 = BUS8_RDP(c, (db << 0x10) + 0x184F);
        r->a = ((value3 & 0xFF7F) >> 8 << 8) | value5;
        r->v = ((x1 ^ (uint16_t)(x1 + value2)) & (value2 ^ (uint16_t)(x1 + value2)) & 0x8000) != 0;
        r->mf = 1;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD08F, 0xD0CEBF); GUARD_JSL(c, sp_call, 0xD08F); } /* external */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD095, 0xC073AC); GUARD_JSL(c, sp_call, 0xD095); } /* test_native_equipment_row_eligibility_from_hero_state_and_level */
        r->sp += 4;
        uint16_t a_all2 = r->a;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        bool m_flag;
        uint8_t a_hi2;
        if (carry_ret2) {
            m_flag = 1;
            a_hi2 = a_all2 >> 8;
        } else {
            uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0x20 + y);
            BUS16_SET(c, (db_ret << 0x10) + 0x20 + y, value6 | 0x4000);
            m_flag = 0;
            a_hi2 = (value6 | 0x4000) >> 8;
        }
        a_hi3 = a_hi2;
        y1 = (uint16_t)(y + 2);
        overflow1 = overflow_ret2;
        data_bank = db_ret;
        direct_page = dp_ret;
    }
    uint16_t value7 = BUS16_RDP(c, (data_bank << 0x10) + 0x184F);
    BUS16_RMW_SET(c, (data_bank << 0x10) + 0x184F, (uint16_t)(value7 + 1));
    uint8_t value8 = RAM8(0x0000 + sp0 - 3);
    uint8_t value9 = RAM8(0x0000 + sp0 - 2);
    uint8_t value10 = RAM8(0x0000 + sp0 - 1);
    uint8_t value11 = RAM8(0x0000 + sp0);
    r->a = ((value11 << 8) | value10) >> 1;
    r->x = (uint16_t)(((value9 << 8) | value8) + 2);
    r->y = y1;
    r->c = ((value11 << 8) | value10) & 0x01;
    r->z = ((value11 << 8) | value10) >> 1 == 0;
    r->n = ((value11 << 8) | value10) >> 1 & 0x8000;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank;
    r->dp = direct_page;
    RETURN_RTS(c);
}

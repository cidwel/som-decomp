#include "som_c.h"

/* D0D6C0 compare_armor_stat_using_temporary_real_equipment_rebuild   [class B, 96 bytes, 38 instructions]
 * Source: src/rom/compare_armor_stat_using_temporary_real_equipment_rebuild.s
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void compare_armor_stat_using_temporary_real_equipment_rebuild(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD6C2, 0xD0D9CE); GUARD_JSR(c, sp_call, 0xD6C2); } /* rebuild_selected_hero_attributes_for_menu_description */
    uint8_t db_ret = r->db;
    BUS16_SET(c, (db_ret << 0x10) + 0x19D4, 0x1559);
    uint16_t value = BUS16_RDP(c, (db_ret << 0x10) + 0x1849);
    uint16_t value2 = RAM16(0xE1E8 + value);
    RAM8(0x0000 + sp0) = value2 >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)value2;
    r->a = RAM16(ACTOR_ATTACK_POWER + value);
    r->x = 0x19D6;
    r->z = 0;
    r->n = 0;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 2;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD6DC, 0xD0D787); GUARD_JSR(c, sp_call, 0xD6DC); } /* append_menu_stat_value_and_separator */
    r->sp += 2;
    uint8_t db_ret2 = r->db;
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    uint16_t y_ret2 = r->y;
    if (x_ret3) {
        RAM8(0x0000 + sp0 - 2) = (uint8_t)x_ret4;
        r->x = (uint8_t)x_ret4;
        r->y = (uint8_t)y_ret2;
        r->xf = 1;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD6E1, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD6E1); } /* calculate_wrapped_native_menu_row_index */
        r->sp += 3;
        uint16_t a_all3 = r->a;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        uint8_t a1 = (uint8_t)a_all3;
        uint8_t a_hi1 = a_all3 >> 8;
        uint8_t x1 = 0x54;
        uint8_t y1 = (uint8_t)a_all3;
        bool carry1 = carry_ret3;
        for (;;) {
            uint8_t value4 = RAM8(0xCC00 + x1);
            if (value4 == 0xFF) {
                a1 = value4;
                x1 = (uint8_t)(x1 + 1);
                carry1 = value4 >= 0xFF;
                continue;
            }
            a1 = value4;
            x1 = (uint8_t)(x1 + 1);
            y1 = (uint8_t)(y1 - 1);
            carry1 = value4 >= 0xFF;
            if (!(!(y1 & 0x80))) break;
        }
        r->a = (a_hi1 << 8) | a1;
        r->x = (uint8_t)(x1 - 1);
        r->y = y1;
        r->c = carry1;
        r->z = (uint8_t)(x1 - 1) == 0;
        r->n = (uint8_t)(x1 - 1) & 0x80;
        r->v = overflow_ret3;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD6F9, 0xD0D1FB); GUARD_JSL(c, sp_call, 0xD6F9); } /* offset_armor_inventory_description_by_position */
        r->sp += 3;
        uint16_t a_all4 = r->a;
        uint16_t value5 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x1849);
        RAM8(0xE1E8 + value5) = (uint8_t)a_all4;
        r->x = value5;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 3;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD705, 0xD0D9CE); GUARD_JSR(c, sp_call, 0xD705); } /* rebuild_selected_hero_attributes_for_menu_description */
        r->sp += 3;
        uint8_t db_ret3 = r->db;
        bool x_ret6 = r->xf;
        uint16_t y_ret3 = r->y;
        if (x_ret6) {
            uint8_t value6 = BUS8_RDP(c, (db_ret3 << 0x10) + 0x1849);
            uint16_t value7 = RAM16(ACTOR_ATTACK_POWER + value6);
            uint8_t value8 = RAM8(0x0000 + sp0 - 2);
            r->a = value7;
            r->x = value8;
            r->y = (uint8_t)y_ret3;
            r->z = value8 == 0;
            r->n = value8 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD712, 0xD0D7A9); GUARD_JSR(c, sp_call, 0xD712); } /* append_menu_stat_value_and_terminator */
            r->sp += 2;
            uint8_t db_ret4 = r->db;
            bool m_ret4 = r->mf;
            bool x_ret8 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t y_ret4 = r->y;
            if (m_ret4) {
                uint8_t value9 = RAM8(0x0000 + sp0 - 1);
                if (x_ret8) {
                    uint8_t value10 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value10) = value9;
                    r->a = (a_all6 >> 8 << 8) | value9;
                    r->x = value10;
                    r->y = (uint8_t)y_ret4;
                    r->z = value10 == 0;
                    r->n = value10 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL_FRAME(c, 0xD0D9CE, SOM_RTS, 1); /* rebuild_selected_hero_attributes_for_menu_description */
                } else {
                    uint16_t value11 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value11) = value9;
                    r->a = (a_all6 >> 8 << 8) | value9;
                    r->x = value11;
                    r->z = value11 == 0;
                    r->n = value11 & 0x8000;
                    r->mf = 1;
                    r->xf = 0;
                    TAIL_CALL_FRAME(c, 0xD0D9CE, SOM_RTS, 1); /* rebuild_selected_hero_attributes_for_menu_description */
                }
            } else {
                uint8_t value12 = RAM8(0x0000 + sp0 - 1);
                uint8_t value13 = RAM8(0x0000 + sp0);
                if (x_ret8) {
                    uint8_t value14 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value14) = (uint8_t)((value13 << 8) | value12);
                    r->a = (value13 << 8) | value12;
                    r->x = value14;
                    r->y = (uint8_t)y_ret4;
                    r->z = value14 == 0;
                    r->n = value14 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL(c, 0xD0D9CE, SOM_RTS); /* rebuild_selected_hero_attributes_for_menu_description */
                } else {
                    uint16_t value15 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value15) = (uint8_t)((value13 << 8) | value12);
                    r->a = (value13 << 8) | value12;
                    r->x = value15;
                    r->z = value15 == 0;
                    r->n = value15 & 0x8000;
                    r->mf = 1;
                    r->xf = 0;
                    TAIL_CALL(c, 0xD0D9CE, SOM_RTS); /* rebuild_selected_hero_attributes_for_menu_description */
                }
            }
        } else {
            uint16_t value16 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x1849);
            uint16_t value17 = RAM16(ACTOR_ATTACK_POWER + value16);
            uint8_t value18 = RAM8(0x0000 + sp0 - 2);
            uint8_t value19 = RAM8(0x0000 + sp0 - 1);
            r->a = value17;
            r->x = (value19 << 8) | value18;
            r->z = ((value19 << 8) | value18) == 0;
            r->n = ((value19 << 8) | value18) & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD712, 0xD0D7A9); GUARD_JSR(c, sp_call, 0xD712); } /* append_menu_stat_value_and_terminator */
            r->sp += 1;
            uint8_t db_ret5 = r->db;
            bool m_ret5 = r->mf;
            bool x_ret10 = r->xf;
            uint16_t a_all7 = r->a;
            uint16_t y_ret5 = r->y;
            if (m_ret5) {
                uint8_t value20 = RAM8(0x0000 + sp0);
                if (x_ret10) {
                    uint8_t value21 = BUS8_RDP(c, (db_ret5 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value21) = value20;
                    r->a = (a_all7 >> 8 << 8) | value20;
                    r->x = value21;
                    r->y = (uint8_t)y_ret5;
                    r->z = value21 == 0;
                    r->n = value21 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL(c, 0xD0D9CE, SOM_RTS); /* rebuild_selected_hero_attributes_for_menu_description */
                } else {
                    uint16_t value22 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value22) = value20;
                    r->a = (a_all7 >> 8 << 8) | value20;
                    r->x = value22;
                    r->z = value22 == 0;
                    r->n = value22 & 0x8000;
                    r->mf = 1;
                    r->xf = 0;
                    TAIL_CALL(c, 0xD0D9CE, SOM_RTS); /* rebuild_selected_hero_attributes_for_menu_description */
                }
            } else {
                c->fail = 3;
                return;
            }
        }
    } else {
        RAM8(0x0000 + sp0 - 2) = x_ret4 >> 8;
        RAM8(0x0000 + sp0 - 3) = (uint8_t)x_ret4;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD6E1, 0xC06BE2); GUARD_JSL(c, sp_call, 0xD6E1); } /* calculate_wrapped_native_menu_row_index */
        r->sp += 4;
        uint16_t a_all8 = r->a;
        bool carry_ret8 = r->c;
        bool overflow_ret8 = r->v;
        uint8_t a2 = (uint8_t)a_all8;
        uint8_t a_hi2 = a_all8 >> 8;
        uint8_t x2 = 0x54;
        uint8_t y2 = (uint8_t)a_all8;
        bool carry2 = carry_ret8;
        for (;;) {
            uint8_t value23 = RAM8(0xCC00 + x2);
            if (value23 == 0xFF) {
                a2 = value23;
                x2 = (uint8_t)(x2 + 1);
                carry2 = value23 >= 0xFF;
                continue;
            }
            a2 = value23;
            x2 = (uint8_t)(x2 + 1);
            y2 = (uint8_t)(y2 - 1);
            carry2 = value23 >= 0xFF;
            if (!(!(y2 & 0x80))) break;
        }
        r->a = (a_hi2 << 8) | a2;
        r->x = (uint8_t)(x2 - 1);
        r->y = y2;
        r->c = carry2;
        r->z = (uint8_t)(x2 - 1) == 0;
        r->n = (uint8_t)(x2 - 1) & 0x80;
        r->v = overflow_ret8;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSL(c, 0xD6F9, 0xD0D1FB); GUARD_JSL(c, sp_call, 0xD6F9); } /* offset_armor_inventory_description_by_position */
        r->sp += 4;
        uint16_t a_all9 = r->a;
        uint16_t value24 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x1849);
        RAM8(0xE1E8 + value24) = (uint8_t)a_all9;
        r->x = value24;
        r->z = value24 == 0;
        r->n = value24 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD705, 0xD0D9CE); GUARD_JSR(c, sp_call, 0xD705); } /* rebuild_selected_hero_attributes_for_menu_description */
        r->sp += 4;
        uint8_t db_ret6 = r->db;
        bool x_ret13 = r->xf;
        uint16_t y_ret6 = r->y;
        if (x_ret13) {
            uint8_t value25 = BUS8_RDP(c, (db_ret6 << 0x10) + 0x1849);
            uint16_t value26 = RAM16(ACTOR_ATTACK_POWER + value25);
            uint8_t value27 = RAM8(0x0000 + sp0 - 3);
            r->a = value26;
            r->x = value27;
            r->y = (uint8_t)y_ret6;
            r->z = value27 == 0;
            r->n = value27 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 3;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD712, 0xD0D7A9); GUARD_JSR(c, sp_call, 0xD712); } /* append_menu_stat_value_and_terminator */
            r->sp += 3;
            uint8_t db_ret7 = r->db;
            bool m_ret7 = r->mf;
            bool x_ret15 = r->xf;
            uint16_t a_all11 = r->a;
            uint16_t y_ret7 = r->y;
            if (m_ret7) {
                uint8_t value28 = RAM8(0x0000 + sp0 - 2);
                if (x_ret15) {
                    uint8_t value29 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value29) = value28;
                    r->a = (a_all11 >> 8 << 8) | value28;
                    r->x = value29;
                    r->y = (uint8_t)y_ret7;
                    r->z = value29 == 0;
                    r->n = value29 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL_FRAME(c, 0xD0D9CE, SOM_RTS, 2); /* rebuild_selected_hero_attributes_for_menu_description */
                } else {
                    uint16_t value30 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value30) = value28;
                    r->a = (a_all11 >> 8 << 8) | value28;
                    r->x = value30;
                    r->z = value30 == 0;
                    r->n = value30 & 0x8000;
                    r->mf = 1;
                    r->xf = 0;
                    TAIL_CALL_FRAME(c, 0xD0D9CE, SOM_RTS, 2); /* rebuild_selected_hero_attributes_for_menu_description */
                }
            } else {
                uint8_t value31 = RAM8(0x0000 + sp0 - 2);
                uint8_t value32 = RAM8(0x0000 + sp0 - 1);
                if (x_ret15) {
                    uint8_t value33 = BUS8_RDP(c, (db_ret7 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value33) = (uint8_t)((value32 << 8) | value31);
                    r->a = (value32 << 8) | value31;
                    r->x = value33;
                    r->y = (uint8_t)y_ret7;
                    r->z = value33 == 0;
                    r->n = value33 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL_FRAME(c, 0xD0D9CE, SOM_RTS, 1); /* rebuild_selected_hero_attributes_for_menu_description */
                } else {
                    uint16_t value34 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value34) = (uint8_t)((value32 << 8) | value31);
                    r->a = (value32 << 8) | value31;
                    r->x = value34;
                    r->z = value34 == 0;
                    r->n = value34 & 0x8000;
                    r->mf = 1;
                    r->xf = 0;
                    TAIL_CALL_FRAME(c, 0xD0D9CE, SOM_RTS, 1); /* rebuild_selected_hero_attributes_for_menu_description */
                }
            }
        } else {
            uint16_t value35 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x1849);
            uint16_t value36 = RAM16(ACTOR_ATTACK_POWER + value35);
            uint8_t value37 = RAM8(0x0000 + sp0 - 3);
            uint8_t value38 = RAM8(0x0000 + sp0 - 2);
            r->a = value36;
            r->x = (value38 << 8) | value37;
            r->z = ((value38 << 8) | value37) == 0;
            r->n = ((value38 << 8) | value37) & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 2;
            { const uint16_t sp_call = r->sp; JSR(c, 0xD712, 0xD0D7A9); GUARD_JSR(c, sp_call, 0xD712); } /* append_menu_stat_value_and_terminator */
            r->sp += 2;
            uint8_t db_ret8 = r->db;
            bool m_ret8 = r->mf;
            bool x_ret17 = r->xf;
            uint16_t a_all12 = r->a;
            uint16_t y_ret8 = r->y;
            if (m_ret8) {
                uint8_t value39 = RAM8(0x0000 + sp0 - 1);
                if (x_ret17) {
                    uint8_t value40 = BUS8_RDP(c, (db_ret8 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value40) = value39;
                    r->a = (a_all12 >> 8 << 8) | value39;
                    r->x = value40;
                    r->y = (uint8_t)y_ret8;
                    r->z = value40 == 0;
                    r->n = value40 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL_FRAME(c, 0xD0D9CE, SOM_RTS, 1); /* rebuild_selected_hero_attributes_for_menu_description */
                } else {
                    uint16_t value41 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value41) = value39;
                    r->a = (a_all12 >> 8 << 8) | value39;
                    r->x = value41;
                    r->z = value41 == 0;
                    r->n = value41 & 0x8000;
                    r->mf = 1;
                    r->xf = 0;
                    TAIL_CALL_FRAME(c, 0xD0D9CE, SOM_RTS, 1); /* rebuild_selected_hero_attributes_for_menu_description */
                }
            } else {
                uint8_t value42 = RAM8(0x0000 + sp0 - 1);
                uint8_t value43 = RAM8(0x0000 + sp0);
                if (x_ret17) {
                    uint8_t value44 = BUS8_RDP(c, (db_ret8 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value44) = (uint8_t)((value43 << 8) | value42);
                    r->a = (value43 << 8) | value42;
                    r->x = value44;
                    r->y = (uint8_t)y_ret8;
                    r->z = value44 == 0;
                    r->n = value44 & 0x80;
                    r->mf = 1;
                    r->xf = 1;
                    TAIL_CALL(c, 0xD0D9CE, SOM_RTS); /* rebuild_selected_hero_attributes_for_menu_description */
                } else {
                    uint16_t value45 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x1849);
                    RAM8(0xE1E8 + value45) = (uint8_t)((value43 << 8) | value42);
                    r->a = (value43 << 8) | value42;
                    r->x = value45;
                    r->z = value45 == 0;
                    r->n = value45 & 0x8000;
                    r->mf = 1;
                    r->xf = 0;
                    TAIL_CALL(c, 0xD0D9CE, SOM_RTS); /* rebuild_selected_hero_attributes_for_menu_description */
                }
            }
        }
    }
}
SOM_REGISTER(0xD0D6C0, SOM_RTS, "gen", compare_armor_stat_using_temporary_real_equipment_rebuild, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 0, 0, 96, 38)

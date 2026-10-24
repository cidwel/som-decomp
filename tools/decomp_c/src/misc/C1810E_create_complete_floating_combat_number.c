#include "som_c.h"

/* C1810E create_complete_floating_combat_number   [class B, 129 bytes, 51 instructions]
 * Source: src/rom/create_complete_floating_combat_number.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BXYCV.
 */
static void create_complete_floating_combat_number(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    RAM16_SET(0x0014, x);
    uint8_t value = RAM8(0xE060 + x);
    if (value == 0) {
        r->a = (a_hi << 8) | value;
        r->z = value == 0;
        r->n = value & 0x80;
        { const uint16_t sp_call = r->sp; JSR(c, 0x811E, 0xC185F1); GUARD_JSR(c, sp_call, 0x811E); } /* load_floating_combat_number_graphic_planes */
        uint8_t db_ret = r->db;
        uint16_t value2 = RAM16(0x0014);
        r->x = value2;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 1;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8123, 0xC185D8); GUARD_JSR(c, sp_call, 0x8123); } /* load_object_weapon_palette_from_field_04f */
        uint16_t value3 = RAM16(0x0014);
        BUS8_SET(c, (db_ret << 0x10) + 0xE084 + value3, 3);
        BUS8_SET(c, (db_ret << 0x10) + 0xE060 + value3, 0x40);
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0xE092 + value3);
        uint16_t value5 = BUS16_RDP(c, (db_ret << 0x10) + 0xE086 + value3);
        BUS16_SET(c, (db_ret << 0x10) + 0xE0D2 + value3, (value4 & 0x3000) | value5);
        BUS16_SET(c, (db_ret << 0x10) + 0xE0D6 + value3, (uint16_t)(((value4 & 0x3000) | value5) + 2));
        uint8_t a1;
        uint8_t a_hi1;
        bool carry1;
        bool overflow1;
        if (((uint16_t)(((value4 & 0x3000) | value5) + 4) & 0x10) == 0) {
            a1 = (uint8_t)(((value4 & 0x3000) | value5) + 4);
            a_hi1 = (uint16_t)(((value4 & 0x3000) | value5) + 4) >> 8;
            carry1 = (uint16_t)(((value4 & 0x3000) | value5) + 2) + 2 > 0xFFFF;
            overflow1 = (((uint16_t)(((value4 & 0x3000) | value5) + 2) ^ (uint16_t)(((value4 & 0x3000) | value5) + 4)) & ((uint16_t)(((value4 & 0x3000) | value5) + 4) ^ 2) & 0x8000) != 0;
        } else {
            a1 = (uint8_t)((uint16_t)(((value4 & 0x3000) | value5) + 4) + 0x10 + ((uint16_t)(((value4 & 0x3000) | value5) + 2) + 2 > 0xFFFF));
            a_hi1 = (uint16_t)((uint16_t)(((value4 & 0x3000) | value5) + 4) + 0x10 + ((uint16_t)(((value4 & 0x3000) | value5) + 2) + 2 > 0xFFFF)) >> 8;
            carry1 = (uint16_t)(((value4 & 0x3000) | value5) + 4) + 0x10 + ((uint16_t)(((value4 & 0x3000) | value5) + 2) + 2 > 0xFFFF) > 0xFFFF;
            overflow1 = (((uint16_t)(((value4 & 0x3000) | value5) + 4) ^ (uint16_t)((uint16_t)(((value4 & 0x3000) | value5) + 4) + 0x10 + ((uint16_t)(((value4 & 0x3000) | value5) + 2) + 2 > 0xFFFF))) & ((uint16_t)((uint16_t)(((value4 & 0x3000) | value5) + 4) + 0x10 + ((uint16_t)(((value4 & 0x3000) | value5) + 2) + 2 > 0xFFFF)) ^ 0x10) & 0x8000) != 0;
        }
        BUS16_SET(c, (db_ret << 0x10) + 0xE0DA + value3, (a_hi1 << 8) | a1);
        BUS16_SET(c, (db_ret << 0x10) + 0xE0D0 + value3, 0xF4);
        BUS16_SET(c, (db_ret << 0x10) + 0xE0D4 + value3, 0xFC);
        BUS16_SET(c, (db_ret << 0x10) + 0xE0D8 + value3, 4);
        BUS16_SET(c, (db_ret << 0x10) + 0xE118 + value3, 0);
        uint16_t value6 = BUS16_RDP(c, (db_ret << 0x10) + 0xE074 + value3);
        BUS16_SET(c, (db_ret << 0x10) + 0xE11A + value3, value6 & 0x7F);
        BUS16_SET(c, (db_ret << 0x10) + 0xE11C + value3, 0x2808);
        BUS16_SET(c, (db_ret << 0x10) + 0xE11E + value3, 0);
        r->a = 0x2808;
        r->x = value3;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0xC18425); GUARD_JSR(c, sp_call, 0x8181); } /* build_floating_combat_number_tile_records */
        uint16_t a_all3 = r->a;
        uint16_t y_ret3 = r->y;
        bool overflow_ret2 = r->v;
        bool m_flag;
        bool x_flag;
        uint8_t a_hi2;
        uint16_t y1;
        bool carry2;
        bool overflow2;
        uint8_t data_bank;
        if (value3 >= 0x0600) {
            m_flag = 0;
            x_flag = 0;
            a_hi2 = a_all3 >> 8;
            y1 = y_ret3;
            carry2 = value3 >= 0x0600;
            overflow2 = overflow_ret2;
            data_bank = db_ret;
        } else {
            r->c = value3 >= 0x0600;
            r->z = value3 == 0x0600;
            r->n = (uint16_t)(value3 - 0x0600) & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8189, 0xC1E326); GUARD_JSR(c, sp_call, 0x8189); } /* wait_for_native_nmi_and_refresh_party_hud_numbers */
            uint8_t db_ret2 = r->db;
            bool x_ret4 = r->xf;
            uint16_t a_all4 = r->a;
            uint16_t y_ret4 = r->y;
            bool carry_ret4 = r->c;
            bool overflow_ret3 = r->v;
            m_flag = 1;
            x_flag = x_ret4;
            a_hi2 = a_all4 >> 8;
            y1 = y_ret4;
            carry2 = carry_ret4;
            overflow2 = overflow_ret3;
            data_bank = db_ret2;
        }
        uint16_t value7 = RAM16(0x0014);
        r->a = (a_hi2 << 8) | a;
        r->x = value7;
        r->y = y1;
        r->c = carry2;
        r->v = overflow2;
        r->mf = m_flag;
        r->xf = 0;
        r->db = data_bank;
        RETURN_RTS(c);
    }
    if (value == 0x40) {
        uint16_t value8 = RAM16(0x0014);
        r->a = (a_hi << 8) | value;
        r->x = value8;
        r->c = value >= 0x40;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8123, 0xC185D8); GUARD_JSR(c, sp_call, 0x8123); } /* load_object_weapon_palette_from_field_04f */
        uint16_t value9 = RAM16(0x0014);
        RAM8(0xE084 + value9) = 3;
        RAM8(0xE060 + value9) = 0x40;
        uint16_t value10 = RAM16(0xE092 + value9);
        uint16_t value11 = RAM16(0xE086 + value9);
        RAM16_SET(0xE0D2 + value9, (value10 & 0x3000) | value11);
        RAM16_SET(0xE0D6 + value9, (uint16_t)(((value10 & 0x3000) | value11) + 2));
        uint8_t a2;
        uint8_t a_hi3;
        bool carry3;
        bool overflow3;
        if (((uint16_t)(((value10 & 0x3000) | value11) + 4) & 0x10) == 0) {
            a2 = (uint8_t)(((value10 & 0x3000) | value11) + 4);
            a_hi3 = (uint16_t)(((value10 & 0x3000) | value11) + 4) >> 8;
            carry3 = (uint16_t)(((value10 & 0x3000) | value11) + 2) + 2 > 0xFFFF;
            overflow3 = (((uint16_t)(((value10 & 0x3000) | value11) + 2) ^ (uint16_t)(((value10 & 0x3000) | value11) + 4)) & ((uint16_t)(((value10 & 0x3000) | value11) + 4) ^ 2) & 0x8000) != 0;
        } else {
            a2 = (uint8_t)((uint16_t)(((value10 & 0x3000) | value11) + 4) + 0x10 + ((uint16_t)(((value10 & 0x3000) | value11) + 2) + 2 > 0xFFFF));
            a_hi3 = (uint16_t)((uint16_t)(((value10 & 0x3000) | value11) + 4) + 0x10 + ((uint16_t)(((value10 & 0x3000) | value11) + 2) + 2 > 0xFFFF)) >> 8;
            carry3 = (uint16_t)(((value10 & 0x3000) | value11) + 4) + 0x10 + ((uint16_t)(((value10 & 0x3000) | value11) + 2) + 2 > 0xFFFF) > 0xFFFF;
            overflow3 = (((uint16_t)(((value10 & 0x3000) | value11) + 4) ^ (uint16_t)((uint16_t)(((value10 & 0x3000) | value11) + 4) + 0x10 + ((uint16_t)(((value10 & 0x3000) | value11) + 2) + 2 > 0xFFFF))) & ((uint16_t)((uint16_t)(((value10 & 0x3000) | value11) + 4) + 0x10 + ((uint16_t)(((value10 & 0x3000) | value11) + 2) + 2 > 0xFFFF)) ^ 0x10) & 0x8000) != 0;
        }
        RAM16_SET(0xE0DA + value9, (a_hi3 << 8) | a2);
        RAM16_SET(0xE0D0 + value9, 0xF4);
        RAM16_SET(0xE0D4 + value9, 0xFC);
        RAM16_SET(0xE0D8 + value9, 4);
        RAM16_SET(0xE118 + value9, 0);
        RAM16_SET(0xE11A + value9, RAM16(0xE074 + value9) & 0x7F);
        RAM16_SET(0xE11C + value9, 0x2808);
        RAM16_SET(0xE11E + value9, 0);
        r->a = 0x2808;
        r->x = value9;
        r->c = carry3;
        r->z = 0;
        r->n = 0;
        r->v = overflow3;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8181, 0xC18425); GUARD_JSR(c, sp_call, 0x8181); } /* build_floating_combat_number_tile_records */
        uint16_t a_all6 = r->a;
        uint16_t y_ret6 = r->y;
        bool overflow_ret4 = r->v;
        bool m_flag2;
        bool x_flag2;
        uint8_t a_hi4;
        uint16_t y2;
        bool carry4;
        bool overflow4;
        uint8_t data_bank2;
        if (value9 >= 0x0600) {
            m_flag2 = 0;
            x_flag2 = 0;
            a_hi4 = a_all6 >> 8;
            y2 = y_ret6;
            carry4 = value9 >= 0x0600;
            overflow4 = overflow_ret4;
            data_bank2 = 0x7E;
        } else {
            r->c = value9 >= 0x0600;
            r->z = value9 == 0x0600;
            r->n = (uint16_t)(value9 - 0x0600) & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8189, 0xC1E326); GUARD_JSR(c, sp_call, 0x8189); } /* wait_for_native_nmi_and_refresh_party_hud_numbers */
            uint8_t db_ret3 = r->db;
            bool x_ret8 = r->xf;
            uint16_t a_all7 = r->a;
            uint16_t y_ret7 = r->y;
            bool carry_ret7 = r->c;
            bool overflow_ret5 = r->v;
            m_flag2 = 1;
            x_flag2 = x_ret8;
            a_hi4 = a_all7 >> 8;
            y2 = y_ret7;
            carry4 = carry_ret7;
            overflow4 = overflow_ret5;
            data_bank2 = db_ret3;
        }
        uint16_t value13 = RAM16(0x0014);
        r->a = (a_hi4 << 8) | a;
        r->x = value13;
        r->y = y2;
        r->c = carry4;
        r->v = overflow4;
        r->mf = m_flag2;
        r->xf = 0;
        r->db = data_bank2;
        RETURN_RTS(c);
    }
    r->c = value >= 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1810E, SOM_RTS, "gen", create_complete_floating_combat_number, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 129, 51)

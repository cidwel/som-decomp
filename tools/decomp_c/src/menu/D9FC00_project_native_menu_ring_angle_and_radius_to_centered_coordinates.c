#include "som_c.h"

/* D9FC00 project_native_menu_ring_angle_and_radius_to_centered_coordinates   [class B, 80 bytes, 35 instructions]
 * Source: src/rom/project_native_menu_ring_angle_and_radius_to_centered_coordinates.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABYC.
 */
static void project_native_menu_ring_angle_and_radius_to_centered_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x1868);
    if (((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) == 0) {
        r->a = (((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF;
        r->y = value & 0xFF;
        r->z = ((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) == 0;
        r->n = (((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC16, 0xD9FC73); GUARD_JSR(c, sp_call, 0xFC16); } /* select_native_ring_quarter_wave_index_then_fall_through */
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC19, 0xD9FC54); GUARD_JSR(c, sp_call, 0xFC19); } /* accumulate_native_ring_vertical_component */
        uint8_t db_ret2 = r->db;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC1C, 0xD9FC5C); GUARD_JSR(c, sp_call, 0xFC1C); } /* project_native_ring_complementary_quarter_wave_component */
        bool m_ret3 = r->mf;
        bool x_ret4 = r->xf;
        uint16_t a_all3 = r->a;
        if (m_ret3) {
            c->fail = 3; /* operand size does not fit the register width on this path */
            return;
        } else {
            uint16_t value2 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x186C);
            if (x_ret4) {
                uint8_t value3 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x186A);
                r->a = (uint16_t)((uint16_t)((a_all3 ^ 0xFFFF) + 1) + value2);
                r->y = value3;
                r->c = (uint16_t)((a_all3 ^ 0xFFFF) + 1) + value2 > 0xFFFF;
                r->mf = 0;
                r->xf = 1;
                RETURN_RTL(c);
            } else {
                uint16_t value4 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x186A);
                r->a = (uint16_t)((uint16_t)((a_all3 ^ 0xFFFF) + 1) + value2);
                r->y = value4;
                r->c = (uint16_t)((a_all3 ^ 0xFFFF) + 1) + value2 > 0xFFFF;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTL(c);
            }
        }
    }
    if ((uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 1) == 0) {
        r->a = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 1);
        r->y = value & 0xFF;
        r->z = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 1) == 0;
        r->n = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 1) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC24, 0xD9FC5C); GUARD_JSR(c, sp_call, 0xFC24); } /* project_native_ring_complementary_quarter_wave_component */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC27, 0xD9FC54); GUARD_JSR(c, sp_call, 0xFC27); } /* accumulate_native_ring_vertical_component */
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC2A, 0xD9FC73); GUARD_JSR(c, sp_call, 0xFC2A); } /* select_native_ring_quarter_wave_index_then_fall_through */
        uint8_t db_ret4 = r->db;
        bool m_ret5 = r->mf;
        bool x_ret8 = r->xf;
        uint16_t a_all6 = r->a;
        if (m_ret5) {
            uint8_t value5 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x186C);
            if (x_ret8) {
                uint8_t value6 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x186A);
                SET_A8(r, (uint8_t)((uint8_t)a_all6 + value5));
                r->y = value6;
                r->c = (uint8_t)a_all6 + value5 > 0xFF;
                r->mf = 1;
                r->xf = 1;
                RETURN_RTL(c);
            } else {
                uint16_t value7 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x186A);
                SET_A8(r, (uint8_t)((uint8_t)a_all6 + value5));
                r->y = value7;
                r->c = (uint8_t)a_all6 + value5 > 0xFF;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
        } else {
            uint16_t value8 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x186C);
            if (x_ret8) {
                uint8_t value9 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x186A);
                r->a = (uint16_t)(a_all6 + value8);
                r->y = value9;
                r->c = a_all6 + value8 > 0xFFFF;
                r->mf = 0;
                r->xf = 1;
                RETURN_RTL(c);
            } else {
                uint16_t value10 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x186A);
                r->a = (uint16_t)(a_all6 + value8);
                r->y = value10;
                r->c = a_all6 + value8 > 0xFFFF;
                r->mf = 0;
                r->xf = 0;
                RETURN_RTL(c);
            }
        }
    }
    bool m_flag;
    bool x_flag;
    uint8_t a1;
    uint8_t a_hi1;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 2) != 0) {
        r->a = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 2);
        r->y = value & 0xFF;
        r->z = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 2) == 0;
        r->n = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 2) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC3D, 0xD9FC5C); GUARD_JSR(c, sp_call, 0xFC3D); } /* project_native_ring_complementary_quarter_wave_component */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC40, 0xD9FC50); GUARD_JSR(c, sp_call, 0xFC40); } /* negate_native_ring_component_then_accumulate_vertical_center */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC43, 0xD9FC73); GUARD_JSR(c, sp_call, 0xFC43); } /* select_native_ring_quarter_wave_index_then_fall_through */
        uint16_t dp_ret5 = r->dp;
        uint8_t db_ret5 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret11 = r->xf;
        uint16_t a_all9 = r->a;
        m_flag = 0;
        x_flag = x_ret11;
        a1 = (uint8_t)((a_all9 ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)((a_all9 ^ 0xFFFF) + 1) >> 8;
        data_bank = db_ret5;
        direct_page = dp_ret5;
    } else {
        r->a = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 2);
        r->y = value & 0xFF;
        r->z = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 2) == 0;
        r->n = (uint16_t)(((((uint8_t)(value & 0x03FF) << 8) | ((value & 0x03FF) >> 8)) & 0xFF) - 2) & 0x8000;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC32, 0xD9FC73); GUARD_JSR(c, sp_call, 0xFC32); } /* select_native_ring_quarter_wave_index_then_fall_through */
        uint16_t dp_ret6 = r->dp;
        uint8_t db_ret6 = r->db;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC35, 0xD9FC50); GUARD_JSR(c, sp_call, 0xFC35); } /* negate_native_ring_component_then_accumulate_vertical_center */
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC38, 0xD9FC5C); GUARD_JSR(c, sp_call, 0xFC38); } /* project_native_ring_complementary_quarter_wave_component */
        bool m_ret8 = r->mf;
        bool x_ret16 = r->xf;
        uint16_t a_all12 = r->a;
        m_flag = m_ret8;
        x_flag = x_ret16;
        a1 = (uint8_t)a_all12;
        a_hi1 = a_all12 >> 8;
        data_bank = db_ret6;
        direct_page = dp_ret6;
    }
    if (m_flag) {
        uint8_t value11 = BUS8_RDP(c, (data_bank << 0x10) + 0x186C);
        if (x_flag) {
            uint8_t value12 = BUS8_RDP(c, (data_bank << 0x10) + 0x186A);
            r->a = (a_hi1 << 8) | (uint8_t)(a1 + value11);
            r->y = value12;
            r->c = a1 + value11 > 0xFF;
            r->mf = 1;
            r->xf = 1;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTL(c);
        } else {
            uint16_t value13 = BUS16_RDP(c, (data_bank << 0x10) + 0x186A);
            r->a = (a_hi1 << 8) | (uint8_t)(a1 + value11);
            r->y = value13;
            r->c = a1 + value11 > 0xFF;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTL(c);
        }
    } else {
        uint16_t value14 = BUS16_RDP(c, (data_bank << 0x10) + 0x186C);
        if (x_flag) {
            uint8_t value15 = BUS8_RDP(c, (data_bank << 0x10) + 0x186A);
            r->a = (uint16_t)(((a_hi1 << 8) | a1) + value14);
            r->y = value15;
            r->c = ((a_hi1 << 8) | a1) + value14 > 0xFFFF;
            r->mf = 0;
            r->xf = 1;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTL(c);
        } else {
            uint16_t value16 = BUS16_RDP(c, (data_bank << 0x10) + 0x186A);
            r->a = (uint16_t)(((a_hi1 << 8) | a1) + value14);
            r->y = value16;
            r->c = ((a_hi1 << 8) | a1) + value14 > 0xFFFF;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            RETURN_RTL(c);
        }
    }
}
SOM_REGISTER(0xD9FC00, SOM_RTL, "gen", project_native_menu_ring_angle_and_radius_to_centered_coordinates, 0, L_A | L_B | L_Y | L_C, 2, 0, 0, 80, 35)

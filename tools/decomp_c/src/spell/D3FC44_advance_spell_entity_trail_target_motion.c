#include "som_c.h"

/* D3FC44 advance_spell_entity_trail_target_motion   [class B, 99 bytes, 48 instructions]
 * Source: src/rom/advance_spell_entity_trail_target_motion.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_spell_entity_trail_target_motion(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), 0);
    uint16_t value = RAM16(0x0146 + y);
    uint16_t value2 = RAM16(0x014A + y);
    RAM16_SET(0x0146 + y, (uint16_t)(value + value2));
    uint16_t value3 = RAM16(0x0142 + y);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value + value2) >= value3) {
        a1 = (uint8_t)((uint16_t)(value + value2) - value3);
        a_hi1 = (uint16_t)((uint16_t)(value + value2) - value3) >> 8;
    } else {
        a1 = (uint8_t)(((uint16_t)((uint16_t)(value + value2) - value3) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)((uint16_t)(value + value2) - value3) ^ 0xFFFF) + 1) >> 8;
    }
    if (((a_hi1 << 8) | a1) < 0x10) {
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 5)) + 1));
    }
    uint16_t value4 = RAM16(0x0144 + y);
    uint16_t value5 = RAM16(0x0148 + y);
    RAM16_SET(0x0144 + y, (uint16_t)(value4 + value5));
    uint16_t value6 = RAM16(0x0140 + y);
    uint8_t a2;
    uint8_t a_hi2;
    if ((uint16_t)(value4 + value5) >= value6) {
        a2 = (uint8_t)((uint16_t)(value4 + value5) - value6);
        a_hi2 = (uint16_t)((uint16_t)(value4 + value5) - value6) >> 8;
    } else {
        a2 = (uint8_t)(((uint16_t)((uint16_t)(value4 + value5) - value6) ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)(((uint16_t)((uint16_t)(value4 + value5) - value6) ^ 0xFFFF) + 1) >> 8;
    }
    bool m_flag2;
    bool x_flag2;
    uint8_t a_hi4;
    uint16_t x2;
    uint16_t y2;
    uint8_t data_bank2;
    if (((a_hi2 << 8) | a2) >= 0x10) {
        r->a = (a_hi2 << 8) | a2;
        r->x = y;
        r->c = ((a_hi2 << 8) | a2) >= 0x10;
        r->z = ((a_hi2 << 8) | a2) == 0x10;
        r->n = (uint16_t)(((a_hi2 << 8) | a2) - 0x10) & 0x8000;
        r->v = (((uint16_t)(value4 + value5) ^ value6) & ((uint16_t)(value4 + value5) ^ (uint16_t)((uint16_t)(value4 + value5) - value6)) & 0x8000) != 0;
        r->mf = 0;
        r->dp = (uint16_t)(sp0 - 5);
        r->sp -= 5;
        { const uint16_t sp_call = r->sp; JSR(c, 0xFC8D, 0xD3FB3F); GUARD_JSR(c, sp_call, 0xFC8D); } /* launch_spell_entity_trail_child */
        r->sp += 5;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret = r->xf;
        uint16_t a_all = r->a;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        m_flag2 = 0;
        x_flag2 = x_ret;
        a_hi4 = a_all >> 8;
        x2 = x_ret2;
        y2 = y_ret;
        data_bank2 = db_ret;
    } else {
        uint16_t value7 = RAM16(0x0001 + (uint16_t)(sp0 - 5));
        bool m_flag;
        bool x_flag;
        uint8_t a_hi3;
        uint16_t x1;
        uint16_t y1;
        uint8_t data_bank;
        if (value7 == 0) {
            r->a = (a_hi2 << 8) | a2;
            r->x = y;
            r->y = value7;
            r->c = ((a_hi2 << 8) | a2) >= 0x10;
            r->z = value7 == 0;
            r->n = value7 & 0x8000;
            r->v = (((uint16_t)(value4 + value5) ^ value6) & ((uint16_t)(value4 + value5) ^ (uint16_t)((uint16_t)(value4 + value5) - value6)) & 0x8000) != 0;
            r->mf = 0;
            r->dp = (uint16_t)(sp0 - 5);
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFC8D, 0xD3FB3F); GUARD_JSR(c, sp_call, 0xFC8D); } /* launch_spell_entity_trail_child */
            r->sp += 5;
            uint8_t db_ret2 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret3 = r->xf;
            uint16_t a_all2 = r->a;
            uint16_t x_ret4 = r->x;
            uint16_t y_ret2 = r->y;
            m_flag = 0;
            x_flag = x_ret3;
            a_hi3 = a_all2 >> 8;
            x1 = x_ret4;
            y1 = y_ret2;
            data_bank = db_ret2;
        } else {
            r->a = (a_hi2 << 8) | a2;
            r->x = y;
            r->y = value7;
            r->c = ((a_hi2 << 8) | a2) >= 0x10;
            r->z = value7 == 0;
            r->n = value7 & 0x8000;
            r->v = (((uint16_t)(value4 + value5) ^ value6) & ((uint16_t)(value4 + value5) ^ (uint16_t)((uint16_t)(value4 + value5) - value6)) & 0x8000) != 0;
            r->mf = 0;
            r->dp = (uint16_t)(sp0 - 5);
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xFC88, 0xD3FBB6); GUARD_JSR(c, sp_call, 0xFC88); } /* finish_spell_entity_trail_target_arrival */
            r->sp += 5;
            bool m_ret = r->mf;
            bool x_ret5 = r->xf;
            uint16_t a_all3 = r->a;
            uint16_t y_ret3 = r->y;
            m_flag = m_ret;
            x_flag = x_ret5;
            a_hi3 = a_all3 >> 8;
            x1 = y;
            y1 = y_ret3;
            data_bank = 0x7E;
        }
        m_flag2 = m_flag;
        x_flag2 = x_flag;
        a_hi4 = a_hi3;
        x2 = x1;
        y2 = y1;
        data_bank2 = data_bank;
    }
    if (m_flag2) {
        uint8_t value8 = BUS8_RDP(c, (data_bank2 << 0x10) + 0x0146 + x2);
        BUS8_SET(c, (data_bank2 << 0x10) + 4 + y2, value8);
        uint8_t value9 = BUS8_RDP(c, (data_bank2 << 0x10) + 0x0144 + x2);
        BUS8_SET(c, (data_bank2 << 0x10) + 2 + y2, value9);
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        uint16_t value10 = BUS16_RDP(c, (data_bank2 << 0x10) + 0x0146 + x2);
        BUS16_SET(c, (data_bank2 << 0x10) + 4 + y2, value10);
        uint16_t value11 = BUS16_RDP(c, (data_bank2 << 0x10) + 0x0144 + x2);
        BUS16_SET(c, (data_bank2 << 0x10) + 2 + y2, value11);
        BUS16_SET(c, (data_bank2 << 0x10) + 8 + y2, 1);
        uint8_t value13 = RAM8(0x0000 + sp0 - 3);
        uint8_t value14 = RAM8(0x0000 + sp0 - 2);
        uint8_t value15 = RAM8(0x0000 + sp0 - 1);
        uint8_t value16 = RAM8(0x0000 + sp0);
        r->a = value13;
        r->x = x2;
        r->y = y2;
        r->c = value14 & 0x01;
        r->z = ((value16 << 8) | value15) == 0;
        r->n = ((value16 << 8) | value15) & 0x8000;
        r->v = value14 & 0x40;
        r->mf = value14 & 0x20;
        r->xf = value14 & 0x10;
        r->db = data_bank2;
        r->dp = (value16 << 8) | value15;
        r->i = value14 & 0x04;
        r->d = value14 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xD3FC44, SOM_RTS, "gen", advance_spell_entity_trail_target_motion, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 1, 0, 99, 48)

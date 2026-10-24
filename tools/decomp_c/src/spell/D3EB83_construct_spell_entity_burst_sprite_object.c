#include "som_c.h"

/* D3EB83 construct_spell_entity_burst_sprite_object   [class B, 124 bytes, 63 instructions]
 * Source: src/rom/construct_spell_entity_burst_sprite_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void construct_spell_entity_burst_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_ebc6 = 0;
    uint8_t x_ebc6 = 0;
    uint8_t y_ebc6 = 0;
    bool carry_ebc6 = 0;
    bool overflow_ebc6 = 0;
    uint16_t direct_page_ebc6 = 0;
    uint8_t data_bank_ebc6 = 0;
    uint8_t a_hi_ebc62 = 0;
    uint16_t x_ebc62 = 0;
    uint16_t y_ebc62 = 0;
    bool carry_ebc62 = 0;
    bool overflow_ebc62 = 0;
    uint16_t direct_page_ebc62 = 0;
    uint8_t data_bank_ebc62 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = (uint8_t)value;
    uint8_t value2 = RAM8(0x0018 + x);
    RAM8(0x0006 + (uint16_t)(sp0 - 0x0B)) = (value2 >> 4) & 7;
    r->a = (value >> 8 << 8) | 0;
    r->x = 0x58;
    r->c = value2 >> 3 & 0x01;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 6) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEBA8, 0xC12E78); GUARD_JSL(c, sp_call, 0xEBA8); } /* allocate_and_fill_spell_entity_bytes_long */
    r->sp += 11;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0002 + (uint16_t)(sp0 - 0x0B)) = (uint8_t)x_ret2;
        RAM16_SET(0x0054 + (uint8_t)x_ret2, 0x32);
        uint16_t value3 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0B));
        r->a = value3;
        r->x = (uint8_t)((uint8_t)x_ret2 + 0x50);
        r->y = (uint8_t)y_ret;
        r->c = (uint8_t)x_ret2 + 0x50 > 0xFFFF;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->v = (((uint8_t)x_ret2 ^ (uint8_t)x_ret2 + 0x50) & ((uint8_t)x_ret2 + 0x50 ^ 0x50) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEBBE, 0xC12EB1); GUARD_JSL(c, sp_call, 0xEBBE); } /* position_spell_entity_from_actor_long */
        r->sp += 11;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        bool carry_ret2 = r->c;
        bool overflow_ret2 = r->v;
        if (x_ret3) {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
            BUS16_SET(c, (uint16_t)(dp_ret + 7), 5);
            a_hi_ebc6 = 0;
            x_ebc6 = value4;
            y_ebc6 = (uint8_t)y_ret2;
            carry_ebc6 = carry_ret2;
            overflow_ebc6 = overflow_ret2;
            direct_page_ebc6 = dp_ret;
            data_bank_ebc6 = db_ret;
            goto shared_EBC6;
        } else {
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
            BUS16_SET(c, (uint16_t)(dp_ret + 7), 5);
            a_hi_ebc62 = 0;
            x_ebc62 = value5;
            y_ebc62 = y_ret2;
            carry_ebc62 = carry_ret2;
            overflow_ebc62 = overflow_ret2;
            direct_page_ebc62 = dp_ret;
            data_bank_ebc62 = db_ret;
            goto shared_EBC6_1;
        }
    } else {
        RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0B), x_ret2);
        RAM16_SET(0x0054 + x_ret2, 0x32);
        uint16_t value6 = RAM16(0x0001 + (uint16_t)(sp0 - 0x0B));
        r->a = value6;
        r->x = (uint16_t)(x_ret2 + 0x50);
        r->c = x_ret2 + 0x50 > 0xFFFF;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->v = ((x_ret2 ^ (uint16_t)(x_ret2 + 0x50)) & ((uint16_t)(x_ret2 + 0x50) ^ 0x50) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEBBE, 0xC12EB1); GUARD_JSL(c, sp_call, 0xEBBE); } /* position_spell_entity_from_actor_long */
        r->sp += 11;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        bool x_ret5 = r->xf;
        uint16_t y_ret3 = r->y;
        bool carry_ret3 = r->c;
        bool overflow_ret3 = r->v;
        if (x_ret5) {
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 2));
            BUS16_SET(c, (uint16_t)(dp_ret2 + 7), 5);
            a_hi_ebc6 = 0;
            x_ebc6 = value7;
            y_ebc6 = (uint8_t)y_ret3;
            carry_ebc6 = carry_ret3;
            overflow_ebc6 = overflow_ret3;
            direct_page_ebc6 = dp_ret2;
            data_bank_ebc6 = db_ret2;
            goto shared_EBC6;
        } else {
            uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
            BUS16_SET(c, (uint16_t)(dp_ret2 + 7), 5);
            a_hi_ebc62 = 0;
            x_ebc62 = value8;
            y_ebc62 = y_ret3;
            carry_ebc62 = carry_ret3;
            overflow_ebc62 = overflow_ret3;
            direct_page_ebc62 = dp_ret2;
            data_bank_ebc62 = db_ret2;
            goto shared_EBC6_1;
        }
    }
    shared_EBC6:;
    BUS8_SET(c, (uint16_t)(direct_page_ebc6 + 4), x_ebc6);
    r->a = 0x0F;
    r->x = x_ebc6;
    r->y = y_ebc6;
    r->c = carry_ebc6;
    r->z = 0;
    r->n = 0;
    r->v = overflow_ebc6;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_ebc6;
    r->dp = direct_page_ebc6;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEBCE, 0xC12E80); GUARD_JSL(c, sp_call, 0xEBCE); } /* activate_native_entity_sprite_long */
    r->sp += 11;
    uint16_t dp_ret3 = r->dp;
    uint8_t db_ret3 = r->db;
    bool m_ret2 = r->mf;
    bool x_ret7 = r->xf;
    uint16_t a_all4 = r->a;
    uint16_t x_ret8 = r->x;
    if (m_ret2) {
        if (x_ret7) {
            uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 4));
            BUS8_SET(c, (db_ret3 << 0x10) + value9, (uint8_t)x_ret8);
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
            r->a = (a_all4 >> 8 << 8) | (uint8_t)x_ret8;
            r->x = value10;
            r->y = value9;
            r->z = value10 == 0;
            r->n = value10 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEBD9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xEBD9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEBE0, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEBE0); } /* draw_spell_entity_bounded_random_long */
            r->sp += 11;
            uint8_t db_ret5 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret11 = r->xf;
            uint16_t a_all6 = r->a;
            uint16_t y_ret6 = r->y;
            if (x_ret11) {
                uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (db_ret5 << 0x10) + 0x0E + value11, (uint16_t)((a_all6 ^ 0xFFFF) + 1));
                uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value12 - 1));
                if ((uint16_t)(value12 - 1) != 0) {
                    a_hi_ebc6 = value11 + 0x10 >> 8;
                    x_ebc6 = (uint8_t)(value11 + 0x10);
                    y_ebc6 = (uint8_t)y_ret6;
                    carry_ebc6 = value11 + 0x10 > 0xFFFF;
                    overflow_ebc6 = ((value11 ^ value11 + 0x10) & (value11 + 0x10 ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc6 = dp_ret3;
                    data_bank_ebc6 = db_ret5;
                    goto shared_EBC6;
                }
                uint8_t value13 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value14 = RAM8(0x0000 + sp0 - 2);
                uint8_t value15 = RAM8(0x0000 + sp0 - 1);
                uint8_t value16 = RAM8(0x0000 + sp0);
                r->x = value13;
                r->y = (uint8_t)y_ret6;
                r->mf = value14 & 0x20;
                r->xf = value14 & 0x10;
                r->dp = (value16 << 8) | value15;
                r->i = value14 & 0x04;
                r->d = value14 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (db_ret5 << 0x10) + 0x0E + value17, (uint16_t)((a_all6 ^ 0xFFFF) + 1));
                uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value18 - 1));
                if ((uint16_t)(value18 - 1) != 0) {
                    a_hi_ebc62 = (uint16_t)(value17 + 0x10) >> 8;
                    x_ebc62 = (uint16_t)(value17 + 0x10);
                    y_ebc62 = y_ret6;
                    carry_ebc62 = value17 + 0x10 > 0xFFFF;
                    overflow_ebc62 = ((value17 ^ (uint16_t)(value17 + 0x10)) & ((uint16_t)(value17 + 0x10) ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc62 = dp_ret3;
                    data_bank_ebc62 = db_ret5;
                    goto shared_EBC6_1;
                }
                uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value20 = RAM8(0x0000 + sp0 - 2);
                uint8_t value21 = RAM8(0x0000 + sp0 - 1);
                uint8_t value22 = RAM8(0x0000 + sp0);
                r->x = value19;
                r->mf = value20 & 0x20;
                r->xf = value20 & 0x10;
                r->dp = (value22 << 8) | value21;
                r->i = value20 & 0x04;
                r->d = value20 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 4));
            BUS8_SET(c, (db_ret3 << 0x10) + value23, (uint8_t)x_ret8);
            uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
            r->a = (a_all4 >> 8 << 8) | (uint8_t)x_ret8;
            r->x = value24;
            r->y = value23;
            r->z = value24 == 0;
            r->n = value24 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEBD9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xEBD9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEBE0, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEBE0); } /* draw_spell_entity_bounded_random_long */
            r->sp += 11;
            uint8_t db_ret7 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret15 = r->xf;
            uint16_t a_all8 = r->a;
            uint16_t y_ret8 = r->y;
            if (x_ret15) {
                uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (db_ret7 << 0x10) + 0x0E + value25, (uint16_t)((a_all8 ^ 0xFFFF) + 1));
                uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value26 - 1));
                if ((uint16_t)(value26 - 1) != 0) {
                    a_hi_ebc6 = value25 + 0x10 >> 8;
                    x_ebc6 = (uint8_t)(value25 + 0x10);
                    y_ebc6 = (uint8_t)y_ret8;
                    carry_ebc6 = value25 + 0x10 > 0xFFFF;
                    overflow_ebc6 = ((value25 ^ value25 + 0x10) & (value25 + 0x10 ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc6 = dp_ret3;
                    data_bank_ebc6 = db_ret7;
                    goto shared_EBC6;
                }
                uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value28 = RAM8(0x0000 + sp0 - 2);
                uint8_t value29 = RAM8(0x0000 + sp0 - 1);
                uint8_t value30 = RAM8(0x0000 + sp0);
                r->x = value27;
                r->y = (uint8_t)y_ret8;
                r->mf = value28 & 0x20;
                r->xf = value28 & 0x10;
                r->dp = (value30 << 8) | value29;
                r->i = value28 & 0x04;
                r->d = value28 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (db_ret7 << 0x10) + 0x0E + value31, (uint16_t)((a_all8 ^ 0xFFFF) + 1));
                uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value32 - 1));
                if ((uint16_t)(value32 - 1) != 0) {
                    a_hi_ebc62 = (uint16_t)(value31 + 0x10) >> 8;
                    x_ebc62 = (uint16_t)(value31 + 0x10);
                    y_ebc62 = y_ret8;
                    carry_ebc62 = value31 + 0x10 > 0xFFFF;
                    overflow_ebc62 = ((value31 ^ (uint16_t)(value31 + 0x10)) & ((uint16_t)(value31 + 0x10) ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc62 = dp_ret3;
                    data_bank_ebc62 = db_ret7;
                    goto shared_EBC6_1;
                }
                uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value34 = RAM8(0x0000 + sp0 - 2);
                uint8_t value35 = RAM8(0x0000 + sp0 - 1);
                uint8_t value36 = RAM8(0x0000 + sp0);
                r->x = value33;
                r->mf = value34 & 0x20;
                r->xf = value34 & 0x10;
                r->dp = (value36 << 8) | value35;
                r->i = value34 & 0x04;
                r->d = value34 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    } else {
        if (x_ret7) {
            uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 4));
            BUS16_SET(c, (db_ret3 << 0x10) + value37, (uint8_t)x_ret8);
            uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
            r->a = (uint8_t)x_ret8;
            r->x = value38;
            r->y = value37;
            r->z = value38 == 0;
            r->n = value38 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEBD9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xEBD9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEBE0, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEBE0); } /* draw_spell_entity_bounded_random_long */
            r->sp += 11;
            uint8_t db_ret9 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret19 = r->xf;
            uint16_t a_all10 = r->a;
            uint16_t y_ret10 = r->y;
            if (x_ret19) {
                uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (db_ret9 << 0x10) + 0x0E + value39, (uint16_t)((a_all10 ^ 0xFFFF) + 1));
                uint16_t value40 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value40 - 1));
                if ((uint16_t)(value40 - 1) != 0) {
                    a_hi_ebc6 = value39 + 0x10 >> 8;
                    x_ebc6 = (uint8_t)(value39 + 0x10);
                    y_ebc6 = (uint8_t)y_ret10;
                    carry_ebc6 = value39 + 0x10 > 0xFFFF;
                    overflow_ebc6 = ((value39 ^ value39 + 0x10) & (value39 + 0x10 ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc6 = dp_ret3;
                    data_bank_ebc6 = db_ret9;
                    goto shared_EBC6;
                }
                uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value42 = RAM8(0x0000 + sp0 - 2);
                uint8_t value43 = RAM8(0x0000 + sp0 - 1);
                uint8_t value44 = RAM8(0x0000 + sp0);
                r->x = value41;
                r->y = (uint8_t)y_ret10;
                r->mf = value42 & 0x20;
                r->xf = value42 & 0x10;
                r->dp = (value44 << 8) | value43;
                r->i = value42 & 0x04;
                r->d = value42 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (db_ret9 << 0x10) + 0x0E + value45, (uint16_t)((a_all10 ^ 0xFFFF) + 1));
                uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value46 - 1));
                if ((uint16_t)(value46 - 1) != 0) {
                    a_hi_ebc62 = (uint16_t)(value45 + 0x10) >> 8;
                    x_ebc62 = (uint16_t)(value45 + 0x10);
                    y_ebc62 = y_ret10;
                    carry_ebc62 = value45 + 0x10 > 0xFFFF;
                    overflow_ebc62 = ((value45 ^ (uint16_t)(value45 + 0x10)) & ((uint16_t)(value45 + 0x10) ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc62 = dp_ret3;
                    data_bank_ebc62 = db_ret9;
                    goto shared_EBC6_1;
                }
                uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value48 = RAM8(0x0000 + sp0 - 2);
                uint8_t value49 = RAM8(0x0000 + sp0 - 1);
                uint8_t value50 = RAM8(0x0000 + sp0);
                r->x = value47;
                r->mf = value48 & 0x20;
                r->xf = value48 & 0x10;
                r->dp = (value50 << 8) | value49;
                r->i = value48 & 0x04;
                r->d = value48 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value51 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 4));
            BUS16_SET(c, (db_ret3 << 0x10) + value51, x_ret8);
            uint16_t value52 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
            r->a = x_ret8;
            r->x = value52;
            r->y = value51;
            r->z = value52 == 0;
            r->n = value52 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEBD9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xEBD9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEBE0, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEBE0); } /* draw_spell_entity_bounded_random_long */
            r->sp += 11;
            uint8_t db_ret11 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret23 = r->xf;
            uint16_t a_all12 = r->a;
            uint16_t y_ret12 = r->y;
            if (x_ret23) {
                uint8_t value53 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (db_ret11 << 0x10) + 0x0E + value53, (uint16_t)((a_all12 ^ 0xFFFF) + 1));
                uint16_t value54 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value54 - 1));
                if ((uint16_t)(value54 - 1) != 0) {
                    a_hi_ebc6 = value53 + 0x10 >> 8;
                    x_ebc6 = (uint8_t)(value53 + 0x10);
                    y_ebc6 = (uint8_t)y_ret12;
                    carry_ebc6 = value53 + 0x10 > 0xFFFF;
                    overflow_ebc6 = ((value53 ^ value53 + 0x10) & (value53 + 0x10 ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc6 = dp_ret3;
                    data_bank_ebc6 = db_ret11;
                    goto shared_EBC6;
                }
                uint8_t value55 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value56 = RAM8(0x0000 + sp0 - 2);
                uint8_t value57 = RAM8(0x0000 + sp0 - 1);
                uint8_t value58 = RAM8(0x0000 + sp0);
                r->x = value55;
                r->y = (uint8_t)y_ret12;
                r->mf = value56 & 0x20;
                r->xf = value56 & 0x10;
                r->dp = (value58 << 8) | value57;
                r->i = value56 & 0x04;
                r->d = value56 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value59 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 4));
                BUS16_SET(c, (db_ret11 << 0x10) + 0x0E + value59, (uint16_t)((a_all12 ^ 0xFFFF) + 1));
                uint16_t value60 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 7), (uint16_t)(value60 - 1));
                if ((uint16_t)(value60 - 1) != 0) {
                    a_hi_ebc62 = (uint16_t)(value59 + 0x10) >> 8;
                    x_ebc62 = (uint16_t)(value59 + 0x10);
                    y_ebc62 = y_ret12;
                    carry_ebc62 = value59 + 0x10 > 0xFFFF;
                    overflow_ebc62 = ((value59 ^ (uint16_t)(value59 + 0x10)) & ((uint16_t)(value59 + 0x10) ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc62 = dp_ret3;
                    data_bank_ebc62 = db_ret11;
                    goto shared_EBC6_1;
                }
                uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
                uint8_t value62 = RAM8(0x0000 + sp0 - 2);
                uint8_t value63 = RAM8(0x0000 + sp0 - 1);
                uint8_t value64 = RAM8(0x0000 + sp0);
                r->x = value61;
                r->mf = value62 & 0x20;
                r->xf = value62 & 0x10;
                r->dp = (value64 << 8) | value63;
                r->i = value62 & 0x04;
                r->d = value62 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
    shared_EBC6_1:;
    BUS16_SET(c, (uint16_t)(direct_page_ebc62 + 4), x_ebc62);
    r->a = 0x0F;
    r->x = x_ebc62;
    r->y = y_ebc62;
    r->c = carry_ebc62;
    r->z = 0;
    r->n = 0;
    r->v = overflow_ebc62;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_ebc62;
    r->dp = direct_page_ebc62;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEBCE, 0xC12E80); GUARD_JSL(c, sp_call, 0xEBCE); } /* activate_native_entity_sprite_long */
    r->sp += 11;
    uint16_t dp_ret4 = r->dp;
    uint8_t db_ret12 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret25 = r->xf;
    uint16_t a_all13 = r->a;
    uint16_t x_ret26 = r->x;
    if (m_ret3) {
        if (x_ret25) {
            uint8_t value65 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 4));
            BUS8_SET(c, (db_ret12 << 0x10) + value65, (uint8_t)x_ret26);
            uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
            r->a = (a_all13 >> 8 << 8) | (uint8_t)x_ret26;
            r->x = value66;
            r->y = value65;
            r->z = value66 == 0;
            r->n = value66 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEBD9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xEBD9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEBE0, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEBE0); } /* draw_spell_entity_bounded_random_long */
            r->sp += 11;
            uint8_t db_ret14 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret29 = r->xf;
            uint16_t a_all15 = r->a;
            uint16_t y_ret15 = r->y;
            if (x_ret29) {
                uint8_t value67 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 4));
                BUS16_SET(c, (db_ret14 << 0x10) + 0x0E + value67, (uint16_t)((a_all15 ^ 0xFFFF) + 1));
                uint16_t value68 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 7), (uint16_t)(value68 - 1));
                if ((uint16_t)(value68 - 1) != 0) {
                    a_hi_ebc6 = value67 + 0x10 >> 8;
                    x_ebc6 = (uint8_t)(value67 + 0x10);
                    y_ebc6 = (uint8_t)y_ret15;
                    carry_ebc6 = value67 + 0x10 > 0xFFFF;
                    overflow_ebc6 = ((value67 ^ value67 + 0x10) & (value67 + 0x10 ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc6 = dp_ret4;
                    data_bank_ebc6 = db_ret14;
                    goto shared_EBC6;
                }
                uint8_t value69 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value70 = RAM8(0x0000 + sp0 - 2);
                uint8_t value71 = RAM8(0x0000 + sp0 - 1);
                uint8_t value72 = RAM8(0x0000 + sp0);
                r->x = value69;
                r->y = (uint8_t)y_ret15;
                r->mf = value70 & 0x20;
                r->xf = value70 & 0x10;
                r->dp = (value72 << 8) | value71;
                r->i = value70 & 0x04;
                r->d = value70 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value73 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 4));
                BUS16_SET(c, (db_ret14 << 0x10) + 0x0E + value73, (uint16_t)((a_all15 ^ 0xFFFF) + 1));
                uint16_t value74 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 7), (uint16_t)(value74 - 1));
                if ((uint16_t)(value74 - 1) != 0) {
                    a_hi_ebc62 = (uint16_t)(value73 + 0x10) >> 8;
                    x_ebc62 = (uint16_t)(value73 + 0x10);
                    y_ebc62 = y_ret15;
                    carry_ebc62 = value73 + 0x10 > 0xFFFF;
                    overflow_ebc62 = ((value73 ^ (uint16_t)(value73 + 0x10)) & ((uint16_t)(value73 + 0x10) ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc62 = dp_ret4;
                    data_bank_ebc62 = db_ret14;
                    goto shared_EBC6_1;
                }
                uint16_t value75 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value76 = RAM8(0x0000 + sp0 - 2);
                uint8_t value77 = RAM8(0x0000 + sp0 - 1);
                uint8_t value78 = RAM8(0x0000 + sp0);
                r->x = value75;
                r->mf = value76 & 0x20;
                r->xf = value76 & 0x10;
                r->dp = (value78 << 8) | value77;
                r->i = value76 & 0x04;
                r->d = value76 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value79 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 4));
            BUS8_SET(c, (db_ret12 << 0x10) + value79, (uint8_t)x_ret26);
            uint16_t value80 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
            r->a = (a_all13 >> 8 << 8) | (uint8_t)x_ret26;
            r->x = value80;
            r->y = value79;
            r->z = value80 == 0;
            r->n = value80 & 0x8000;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEBD9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xEBD9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEBE0, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEBE0); } /* draw_spell_entity_bounded_random_long */
            r->sp += 11;
            uint8_t db_ret16 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret33 = r->xf;
            uint16_t a_all17 = r->a;
            uint16_t y_ret17 = r->y;
            if (x_ret33) {
                uint8_t value81 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 4));
                BUS16_SET(c, (db_ret16 << 0x10) + 0x0E + value81, (uint16_t)((a_all17 ^ 0xFFFF) + 1));
                uint16_t value82 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 7), (uint16_t)(value82 - 1));
                if ((uint16_t)(value82 - 1) != 0) {
                    a_hi_ebc6 = value81 + 0x10 >> 8;
                    x_ebc6 = (uint8_t)(value81 + 0x10);
                    y_ebc6 = (uint8_t)y_ret17;
                    carry_ebc6 = value81 + 0x10 > 0xFFFF;
                    overflow_ebc6 = ((value81 ^ value81 + 0x10) & (value81 + 0x10 ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc6 = dp_ret4;
                    data_bank_ebc6 = db_ret16;
                    goto shared_EBC6;
                }
                uint8_t value83 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value84 = RAM8(0x0000 + sp0 - 2);
                uint8_t value85 = RAM8(0x0000 + sp0 - 1);
                uint8_t value86 = RAM8(0x0000 + sp0);
                r->x = value83;
                r->y = (uint8_t)y_ret17;
                r->mf = value84 & 0x20;
                r->xf = value84 & 0x10;
                r->dp = (value86 << 8) | value85;
                r->i = value84 & 0x04;
                r->d = value84 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value87 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 4));
                BUS16_SET(c, (db_ret16 << 0x10) + 0x0E + value87, (uint16_t)((a_all17 ^ 0xFFFF) + 1));
                uint16_t value88 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 7), (uint16_t)(value88 - 1));
                if ((uint16_t)(value88 - 1) != 0) {
                    a_hi_ebc62 = (uint16_t)(value87 + 0x10) >> 8;
                    x_ebc62 = (uint16_t)(value87 + 0x10);
                    y_ebc62 = y_ret17;
                    carry_ebc62 = value87 + 0x10 > 0xFFFF;
                    overflow_ebc62 = ((value87 ^ (uint16_t)(value87 + 0x10)) & ((uint16_t)(value87 + 0x10) ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc62 = dp_ret4;
                    data_bank_ebc62 = db_ret16;
                    goto shared_EBC6_1;
                }
                uint16_t value89 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value90 = RAM8(0x0000 + sp0 - 2);
                uint8_t value91 = RAM8(0x0000 + sp0 - 1);
                uint8_t value92 = RAM8(0x0000 + sp0);
                r->x = value89;
                r->mf = value90 & 0x20;
                r->xf = value90 & 0x10;
                r->dp = (value92 << 8) | value91;
                r->i = value90 & 0x04;
                r->d = value90 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    } else {
        if (x_ret25) {
            uint8_t value93 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 4));
            BUS16_SET(c, (db_ret12 << 0x10) + value93, (uint8_t)x_ret26);
            uint8_t value94 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
            r->a = (uint8_t)x_ret26;
            r->x = value94;
            r->y = value93;
            r->z = value94 == 0;
            r->n = value94 & 0x80;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEBD9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xEBD9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEBE0, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEBE0); } /* draw_spell_entity_bounded_random_long */
            r->sp += 11;
            uint8_t db_ret18 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret37 = r->xf;
            uint16_t a_all19 = r->a;
            uint16_t y_ret19 = r->y;
            if (x_ret37) {
                uint8_t value95 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 4));
                BUS16_SET(c, (db_ret18 << 0x10) + 0x0E + value95, (uint16_t)((a_all19 ^ 0xFFFF) + 1));
                uint16_t value96 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 7), (uint16_t)(value96 - 1));
                if ((uint16_t)(value96 - 1) != 0) {
                    a_hi_ebc6 = value95 + 0x10 >> 8;
                    x_ebc6 = (uint8_t)(value95 + 0x10);
                    y_ebc6 = (uint8_t)y_ret19;
                    carry_ebc6 = value95 + 0x10 > 0xFFFF;
                    overflow_ebc6 = ((value95 ^ value95 + 0x10) & (value95 + 0x10 ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc6 = dp_ret4;
                    data_bank_ebc6 = db_ret18;
                    goto shared_EBC6;
                }
                uint8_t value97 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value98 = RAM8(0x0000 + sp0 - 2);
                uint8_t value99 = RAM8(0x0000 + sp0 - 1);
                uint8_t value100 = RAM8(0x0000 + sp0);
                r->x = value97;
                r->y = (uint8_t)y_ret19;
                r->mf = value98 & 0x20;
                r->xf = value98 & 0x10;
                r->dp = (value100 << 8) | value99;
                r->i = value98 & 0x04;
                r->d = value98 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value101 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 4));
                BUS16_SET(c, (db_ret18 << 0x10) + 0x0E + value101, (uint16_t)((a_all19 ^ 0xFFFF) + 1));
                uint16_t value102 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 7), (uint16_t)(value102 - 1));
                if ((uint16_t)(value102 - 1) != 0) {
                    a_hi_ebc62 = (uint16_t)(value101 + 0x10) >> 8;
                    x_ebc62 = (uint16_t)(value101 + 0x10);
                    y_ebc62 = y_ret19;
                    carry_ebc62 = value101 + 0x10 > 0xFFFF;
                    overflow_ebc62 = ((value101 ^ (uint16_t)(value101 + 0x10)) & ((uint16_t)(value101 + 0x10) ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc62 = dp_ret4;
                    data_bank_ebc62 = db_ret18;
                    goto shared_EBC6_1;
                }
                uint16_t value103 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value104 = RAM8(0x0000 + sp0 - 2);
                uint8_t value105 = RAM8(0x0000 + sp0 - 1);
                uint8_t value106 = RAM8(0x0000 + sp0);
                r->x = value103;
                r->mf = value104 & 0x20;
                r->xf = value104 & 0x10;
                r->dp = (value106 << 8) | value105;
                r->i = value104 & 0x04;
                r->d = value104 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            uint16_t value107 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 4));
            BUS16_SET(c, (db_ret12 << 0x10) + value107, x_ret26);
            uint16_t value108 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
            r->a = x_ret26;
            r->x = value108;
            r->y = value107;
            r->z = value108 == 0;
            r->n = value108 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSR(c, 0xEBD9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xEBD9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 11;
            if (r->mf != 0) { c->fail = 3; return; }
            r->a = 0x80;
            r->z = 0;
            r->n = 0;
            r->sp -= 11;
            { const uint16_t sp_call = r->sp; JSL(c, 0xEBE0, 0xC12ED1); GUARD_JSL(c, sp_call, 0xEBE0); } /* draw_spell_entity_bounded_random_long */
            r->sp += 11;
            uint8_t db_ret20 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret41 = r->xf;
            uint16_t a_all21 = r->a;
            uint16_t y_ret21 = r->y;
            if (x_ret41) {
                uint8_t value109 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 4));
                BUS16_SET(c, (db_ret20 << 0x10) + 0x0E + value109, (uint16_t)((a_all21 ^ 0xFFFF) + 1));
                uint16_t value110 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 7), (uint16_t)(value110 - 1));
                if ((uint16_t)(value110 - 1) != 0) {
                    a_hi_ebc6 = value109 + 0x10 >> 8;
                    x_ebc6 = (uint8_t)(value109 + 0x10);
                    y_ebc6 = (uint8_t)y_ret21;
                    carry_ebc6 = value109 + 0x10 > 0xFFFF;
                    overflow_ebc6 = ((value109 ^ value109 + 0x10) & (value109 + 0x10 ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc6 = dp_ret4;
                    data_bank_ebc6 = db_ret20;
                    goto shared_EBC6;
                }
                uint8_t value111 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value112 = RAM8(0x0000 + sp0 - 2);
                uint8_t value113 = RAM8(0x0000 + sp0 - 1);
                uint8_t value114 = RAM8(0x0000 + sp0);
                r->x = value111;
                r->y = (uint8_t)y_ret21;
                r->mf = value112 & 0x20;
                r->xf = value112 & 0x10;
                r->dp = (value114 << 8) | value113;
                r->i = value112 & 0x04;
                r->d = value112 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value115 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 4));
                BUS16_SET(c, (db_ret20 << 0x10) + 0x0E + value115, (uint16_t)((a_all21 ^ 0xFFFF) + 1));
                uint16_t value116 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 7));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret4 + 7), (uint16_t)(value116 - 1));
                if ((uint16_t)(value116 - 1) != 0) {
                    a_hi_ebc62 = (uint16_t)(value115 + 0x10) >> 8;
                    x_ebc62 = (uint16_t)(value115 + 0x10);
                    y_ebc62 = y_ret21;
                    carry_ebc62 = value115 + 0x10 > 0xFFFF;
                    overflow_ebc62 = ((value115 ^ (uint16_t)(value115 + 0x10)) & ((uint16_t)(value115 + 0x10) ^ 0x10) & 0x8000) != 0;
                    direct_page_ebc62 = dp_ret4;
                    data_bank_ebc62 = db_ret20;
                    goto shared_EBC6_1;
                }
                uint16_t value117 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
                uint8_t value118 = RAM8(0x0000 + sp0 - 2);
                uint8_t value119 = RAM8(0x0000 + sp0 - 1);
                uint8_t value120 = RAM8(0x0000 + sp0);
                r->x = value117;
                r->mf = value118 & 0x20;
                r->xf = value118 & 0x10;
                r->dp = (value120 << 8) | value119;
                r->i = value118 & 0x04;
                r->d = value118 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0xD3EB83, SOM_RTS, "gen", construct_spell_entity_burst_sprite_object, 0, L_X | L_Y, 11, 1, 0, 124, 63)

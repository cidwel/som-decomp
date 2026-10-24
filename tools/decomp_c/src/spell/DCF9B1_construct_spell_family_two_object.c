#include "som_c.h"

/* DCF9B1 construct_spell_family_two_object   [class B, 83 bytes, 47 instructions]
 * Source: src/rom/construct_spell_family_two_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: XY.
 */
static void construct_spell_family_two_object(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0001 + (uint16_t)(sp0 - 7)) = (uint8_t)value;
    uint8_t value2 = RAM8(0x0018 + x);
    RAM8(0x0004 + (uint16_t)(sp0 - 7)) = (value2 >> 4) & 7;
    r->a = (value >> 8 << 8) | 0;
    r->x = 0x26;
    r->c = value2 >> 3 & 0x01;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF9D6, 0xC12E78); GUARD_JSL(c, sp_call, 0xF9D6); } /* allocate_and_fill_spell_entity_bytes_long */
    r->sp += 7;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0002 + (uint16_t)(sp0 - 7)) = (uint8_t)x_ret2;
        uint8_t value3 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
        r->a = ((uint8_t)x_ret2 + 0x20 >> 8 << 8) | value3;
        r->x = (uint8_t)((uint8_t)x_ret2 + 0x20);
        r->y = (uint8_t)y_ret;
        r->c = (uint8_t)x_ret2 + 0x20 > 0xFFFF;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->v = (((uint8_t)x_ret2 ^ (uint8_t)x_ret2 + 0x20) & ((uint8_t)x_ret2 + 0x20 ^ 0x20) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF9E8, 0xC12EB1); GUARD_JSL(c, sp_call, 0xF9E8); } /* position_spell_entity_from_actor_long */
        r->sp += 7;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        if (x_ret3) {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (db_ret << 0x10) + 0x24 + value4, value5 & 1);
            uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 4));
            r->a = (value6 << 8) | 0x10;
            r->x = value4;
            r->y = (uint8_t)y_ret2;
            r->z = 0;
            r->n = 0;
            r->xf = 1;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF9FA, 0xC12EB5); GUARD_JSL(c, sp_call, 0xF9FA); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 7;
            uint16_t dp_ret2 = r->dp;
            bool m_ret2 = r->mf;
            bool x_ret5 = r->xf;
            uint16_t y_ret3 = r->y;
            if (x_ret5) {
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 2));
                if (m_ret2) {
                    uint8_t value12 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value13 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value14 = RAM8(0x0000 + sp0);
                    r->x = value7;
                    r->y = (uint8_t)y_ret3;
                    r->mf = value12 & 0x20;
                    r->xf = value12 & 0x10;
                    r->dp = (value14 << 8) | value13;
                    r->i = value12 & 0x04;
                    r->d = value12 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            } else {
                uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
                if (m_ret2) {
                    uint8_t value26 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value27 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value28 = RAM8(0x0000 + sp0);
                    r->x = value21;
                    r->mf = value26 & 0x20;
                    r->xf = value26 & 0x10;
                    r->dp = (value28 << 8) | value27;
                    r->i = value26 & 0x04;
                    r->d = value26 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
        } else {
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
            uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (db_ret << 0x10) + 0x24 + value35, value36 & 1);
            uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp_ret + 4));
            r->a = (value37 << 8) | 0x10;
            r->x = value35;
            r->z = 0;
            r->n = 0;
            r->xf = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF9FA, 0xC12EB5); GUARD_JSL(c, sp_call, 0xF9FA); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 7;
            uint16_t dp_ret3 = r->dp;
            bool m_ret3 = r->mf;
            bool x_ret7 = r->xf;
            uint16_t y_ret4 = r->y;
            if (x_ret7) {
                uint8_t value38 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
                if (m_ret3) {
                    uint8_t value43 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value44 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value45 = RAM8(0x0000 + sp0);
                    r->x = value38;
                    r->y = (uint8_t)y_ret4;
                    r->mf = value43 & 0x20;
                    r->xf = value43 & 0x10;
                    r->dp = (value45 << 8) | value44;
                    r->i = value43 & 0x04;
                    r->d = value43 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            } else {
                uint16_t value52 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
                if (m_ret3) {
                    uint8_t value57 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value58 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value59 = RAM8(0x0000 + sp0);
                    r->x = value52;
                    r->mf = value57 & 0x20;
                    r->xf = value57 & 0x10;
                    r->dp = (value59 << 8) | value58;
                    r->i = value57 & 0x04;
                    r->d = value57 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
        }
    } else {
        RAM16_SET(0x0002 + (uint16_t)(sp0 - 7), x_ret2);
        uint8_t value66 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
        r->a = ((uint16_t)(x_ret2 + 0x20) >> 8 << 8) | value66;
        r->x = (uint16_t)(x_ret2 + 0x20);
        r->c = x_ret2 + 0x20 > 0xFFFF;
        r->z = value66 == 0;
        r->n = value66 & 0x80;
        r->v = ((x_ret2 ^ (uint16_t)(x_ret2 + 0x20)) & ((uint16_t)(x_ret2 + 0x20) ^ 0x20) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF9E8, 0xC12EB1); GUARD_JSL(c, sp_call, 0xF9E8); } /* position_spell_entity_from_actor_long */
        r->sp += 7;
        uint16_t dp_ret4 = r->dp;
        uint8_t db_ret4 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret9 = r->xf;
        uint16_t y_ret5 = r->y;
        if (x_ret9) {
            uint8_t value67 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
            uint8_t value68 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
            BUS8_SET(c, (db_ret4 << 0x10) + 0x24 + value67, value68 & 1);
            uint8_t value69 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 4));
            r->a = (value69 << 8) | 0x10;
            r->x = value67;
            r->y = (uint8_t)y_ret5;
            r->z = 0;
            r->n = 0;
            r->xf = 1;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF9FA, 0xC12EB5); GUARD_JSL(c, sp_call, 0xF9FA); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 7;
            uint16_t dp_ret5 = r->dp;
            bool m_ret4 = r->mf;
            bool x_ret11 = r->xf;
            uint16_t y_ret6 = r->y;
            if (x_ret11) {
                uint8_t value70 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 2));
                if (m_ret4) {
                    uint8_t value75 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value76 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value77 = RAM8(0x0000 + sp0);
                    r->x = value70;
                    r->y = (uint8_t)y_ret6;
                    r->mf = value75 & 0x20;
                    r->xf = value75 & 0x10;
                    r->dp = (value77 << 8) | value76;
                    r->i = value75 & 0x04;
                    r->d = value75 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            } else {
                uint16_t value84 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 2));
                if (m_ret4) {
                    uint8_t value89 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value90 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value91 = RAM8(0x0000 + sp0);
                    r->x = value84;
                    r->mf = value89 & 0x20;
                    r->xf = value89 & 0x10;
                    r->dp = (value91 << 8) | value90;
                    r->i = value89 & 0x04;
                    r->d = value89 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
        } else {
            uint16_t value98 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
            uint8_t value99 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
            BUS8_SET(c, (db_ret4 << 0x10) + 0x24 + value98, value99 & 1);
            uint8_t value100 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 4));
            r->a = (value100 << 8) | 0x10;
            r->x = value98;
            r->z = 0;
            r->n = 0;
            r->xf = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0xF9FA, 0xC12EB5); GUARD_JSL(c, sp_call, 0xF9FA); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 7;
            uint16_t dp_ret6 = r->dp;
            bool m_ret5 = r->mf;
            bool x_ret13 = r->xf;
            uint16_t y_ret7 = r->y;
            if (x_ret13) {
                uint8_t value101 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 2));
                if (m_ret5) {
                    uint8_t value106 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value107 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value108 = RAM8(0x0000 + sp0);
                    r->x = value101;
                    r->y = (uint8_t)y_ret7;
                    r->mf = value106 & 0x20;
                    r->xf = value106 & 0x10;
                    r->dp = (value108 << 8) | value107;
                    r->i = value106 & 0x04;
                    r->d = value106 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            } else {
                uint16_t value115 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 2));
                if (m_ret5) {
                    uint8_t value120 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value121 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value122 = RAM8(0x0000 + sp0);
                    r->x = value115;
                    r->mf = value120 & 0x20;
                    r->xf = value120 & 0x10;
                    r->dp = (value122 << 8) | value121;
                    r->i = value120 & 0x04;
                    r->d = value120 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
        }
    }
}
SOM_REGISTER(0xDCF9B1, SOM_RTS, "gen", construct_spell_family_two_object, 0, L_X | L_Y, 7, 1, 0, 83, 47)

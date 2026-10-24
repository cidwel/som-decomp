#include "som_c.h"

/* C12CC7 construct_spell_entity_twin_sprite_object   [class B, 109 bytes, 59 instructions]
 * Source: src/rom/construct_spell_entity_twin_sprite_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XY.
 */
static void construct_spell_entity_twin_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0001 + (uint16_t)(sp0 - 7)) = (uint8_t)value;
    uint8_t value2 = RAM8(0x0018 + x);
    RAM8(0x0004 + (uint16_t)(sp0 - 7)) = (value2 >> 4) & 7;
    r->a = (value >> 8 << 8) | 0;
    r->x = 0x3A;
    r->c = value2 >> 3 & 0x01;
    r->z = 1;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSL(c, 0x2CEC, 0xC12E78); GUARD_JSL(c, sp_call, 0x2CEC); } /* allocate_and_fill_spell_entity_bytes_long */
    r->sp += 7;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    if (x_ret) {
        RAM8(0x0002 + (uint16_t)(sp0 - 7)) = (uint8_t)x_ret2;
        uint8_t value3 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
        r->a = ((uint8_t)x_ret2 + 0x34 >> 8 << 8) | value3;
        r->x = (uint8_t)((uint8_t)x_ret2 + 0x34);
        r->y = (uint8_t)y_ret;
        r->c = (uint8_t)x_ret2 + 0x34 > 0xFFFF;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->v = (((uint8_t)x_ret2 ^ (uint8_t)x_ret2 + 0x34) & ((uint8_t)x_ret2 + 0x34 ^ 0x34) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2CFE, 0xC12EB1); GUARD_JSL(c, sp_call, 0x2CFE); } /* position_spell_entity_from_actor_long */
        r->sp += 7;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret3 = r->xf;
        uint16_t y_ret2 = r->y;
        if (x_ret3) {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
            BUS8_SET(c, (db_ret << 0x10) + 0x39 + value4, 0x14);
            BUS8_SET(c, (db_ret << 0x10) + 0x18 + value4, 0x0A);
            BUS8_SET(c, (db_ret << 0x10) + 0x32 + value4, 0x0A);
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 4));
            r->a = (value5 << 8) | 0x0A;
            r->x = value4;
            r->y = (uint8_t)y_ret2;
            r->z = 0;
            r->n = 0;
            r->xf = 1;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2D16, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D16); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 7;
            uint16_t dp_ret2 = r->dp;
            bool x_ret5 = r->xf;
            uint16_t y_ret3 = r->y;
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 2));
            if (x_ret5) {
                uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 4));
                r->a = (value7 << 8) | 0x0A;
                r->x = (uint8_t)(value6 + 0x1A);
                r->y = (uint8_t)y_ret3;
                r->c = value6 + 0x1A > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value6 ^ (uint16_t)(value6 + 0x1A)) & ((uint16_t)(value6 + 0x1A) ^ 0x1A) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2D2A, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D2A); } /* allocate_spell_entity_sprite_pointer_group_long */
                r->sp += 7;
                uint16_t dp_ret3 = r->dp;
                bool m_ret3 = r->mf;
                bool x_ret7 = r->xf;
                uint16_t y_ret4 = r->y;
                if (x_ret7) {
                    uint8_t value8 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 2));
                    if (m_ret3) {
                        uint8_t value13 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value14 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value15 = RAM8(0x0000 + sp0);
                        r->x = value8;
                        r->y = (uint8_t)y_ret4;
                        r->mf = value13 & 0x20;
                        r->xf = value13 & 0x10;
                        r->dp = (value15 << 8) | value14;
                        r->i = value13 & 0x04;
                        r->d = value13 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                } else {
                    uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 2));
                    if (m_ret3) {
                        uint8_t value27 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value28 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value29 = RAM8(0x0000 + sp0);
                        r->x = value22;
                        r->mf = value27 & 0x20;
                        r->xf = value27 & 0x10;
                        r->dp = (value29 << 8) | value28;
                        r->i = value27 & 0x04;
                        r->d = value27 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                }
            } else {
                uint8_t value36 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 4));
                r->a = (value36 << 8) | 0x0A;
                r->x = (uint16_t)(value6 + 0x1A);
                r->c = value6 + 0x1A > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value6 ^ (uint16_t)(value6 + 0x1A)) & ((uint16_t)(value6 + 0x1A) ^ 0x1A) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2D2A, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D2A); } /* allocate_spell_entity_sprite_pointer_group_long */
                r->sp += 7;
                uint16_t dp_ret4 = r->dp;
                bool m_ret4 = r->mf;
                bool x_ret9 = r->xf;
                uint16_t y_ret5 = r->y;
                if (x_ret9) {
                    uint8_t value37 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 2));
                    if (m_ret4) {
                        uint8_t value42 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value43 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value44 = RAM8(0x0000 + sp0);
                        r->x = value37;
                        r->y = (uint8_t)y_ret5;
                        r->mf = value42 & 0x20;
                        r->xf = value42 & 0x10;
                        r->dp = (value44 << 8) | value43;
                        r->i = value42 & 0x04;
                        r->d = value42 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                } else {
                    uint16_t value51 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 2));
                    if (m_ret4) {
                        uint8_t value56 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value57 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value58 = RAM8(0x0000 + sp0);
                        r->x = value51;
                        r->mf = value56 & 0x20;
                        r->xf = value56 & 0x10;
                        r->dp = (value58 << 8) | value57;
                        r->i = value56 & 0x04;
                        r->d = value56 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                }
            }
        } else {
            uint16_t value65 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
            BUS8_SET(c, (db_ret << 0x10) + 0x39 + value65, 0x14);
            BUS8_SET(c, (db_ret << 0x10) + 0x18 + value65, 0x0A);
            BUS8_SET(c, (db_ret << 0x10) + 0x32 + value65, 0x0A);
            uint8_t value66 = BUS8_RDP(c, (uint16_t)(dp_ret + 4));
            r->a = (value66 << 8) | 0x0A;
            r->x = value65;
            r->z = 0;
            r->n = 0;
            r->xf = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2D16, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D16); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 7;
            uint16_t dp_ret5 = r->dp;
            bool x_ret11 = r->xf;
            uint16_t y_ret6 = r->y;
            uint16_t value67 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 2));
            if (x_ret11) {
                uint8_t value68 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 4));
                r->a = (value68 << 8) | 0x0A;
                r->x = (uint8_t)(value67 + 0x1A);
                r->y = (uint8_t)y_ret6;
                r->c = value67 + 0x1A > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value67 ^ (uint16_t)(value67 + 0x1A)) & ((uint16_t)(value67 + 0x1A) ^ 0x1A) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2D2A, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D2A); } /* allocate_spell_entity_sprite_pointer_group_long */
                r->sp += 7;
                uint16_t dp_ret6 = r->dp;
                bool m_ret6 = r->mf;
                bool x_ret13 = r->xf;
                uint16_t y_ret7 = r->y;
                if (x_ret13) {
                    uint8_t value69 = BUS8_RDP(c, (uint16_t)(dp_ret6 + 2));
                    if (m_ret6) {
                        uint8_t value74 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value75 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value76 = RAM8(0x0000 + sp0);
                        r->x = value69;
                        r->y = (uint8_t)y_ret7;
                        r->mf = value74 & 0x20;
                        r->xf = value74 & 0x10;
                        r->dp = (value76 << 8) | value75;
                        r->i = value74 & 0x04;
                        r->d = value74 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                } else {
                    uint16_t value83 = BUS16_RDP(c, (uint16_t)(dp_ret6 + 2));
                    if (m_ret6) {
                        uint8_t value88 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value89 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value90 = RAM8(0x0000 + sp0);
                        r->x = value83;
                        r->mf = value88 & 0x20;
                        r->xf = value88 & 0x10;
                        r->dp = (value90 << 8) | value89;
                        r->i = value88 & 0x04;
                        r->d = value88 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                }
            } else {
                uint8_t value97 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 4));
                r->a = (value97 << 8) | 0x0A;
                r->x = (uint16_t)(value67 + 0x1A);
                r->c = value67 + 0x1A > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value67 ^ (uint16_t)(value67 + 0x1A)) & ((uint16_t)(value67 + 0x1A) ^ 0x1A) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2D2A, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D2A); } /* allocate_spell_entity_sprite_pointer_group_long */
                r->sp += 7;
                uint16_t dp_ret7 = r->dp;
                bool m_ret7 = r->mf;
                bool x_ret15 = r->xf;
                uint16_t y_ret8 = r->y;
                if (x_ret15) {
                    uint8_t value98 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 2));
                    if (m_ret7) {
                        uint8_t value103 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value104 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value105 = RAM8(0x0000 + sp0);
                        r->x = value98;
                        r->y = (uint8_t)y_ret8;
                        r->mf = value103 & 0x20;
                        r->xf = value103 & 0x10;
                        r->dp = (value105 << 8) | value104;
                        r->i = value103 & 0x04;
                        r->d = value103 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                } else {
                    uint16_t value112 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 2));
                    if (m_ret7) {
                        uint8_t value117 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value118 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value119 = RAM8(0x0000 + sp0);
                        r->x = value112;
                        r->mf = value117 & 0x20;
                        r->xf = value117 & 0x10;
                        r->dp = (value119 << 8) | value118;
                        r->i = value117 & 0x04;
                        r->d = value117 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                }
            }
        }
    } else {
        RAM16_SET(0x0002 + (uint16_t)(sp0 - 7), x_ret2);
        uint8_t value126 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
        r->a = ((uint16_t)(x_ret2 + 0x34) >> 8 << 8) | value126;
        r->x = (uint16_t)(x_ret2 + 0x34);
        r->c = x_ret2 + 0x34 > 0xFFFF;
        r->z = value126 == 0;
        r->n = value126 & 0x80;
        r->v = ((x_ret2 ^ (uint16_t)(x_ret2 + 0x34)) & ((uint16_t)(x_ret2 + 0x34) ^ 0x34) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSL(c, 0x2CFE, 0xC12EB1); GUARD_JSL(c, sp_call, 0x2CFE); } /* position_spell_entity_from_actor_long */
        r->sp += 7;
        uint16_t dp_ret8 = r->dp;
        uint8_t db_ret8 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret17 = r->xf;
        uint16_t y_ret9 = r->y;
        if (x_ret17) {
            uint8_t value127 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 2));
            BUS8_SET(c, (db_ret8 << 0x10) + 0x39 + value127, 0x14);
            BUS8_SET(c, (db_ret8 << 0x10) + 0x18 + value127, 0x0A);
            BUS8_SET(c, (db_ret8 << 0x10) + 0x32 + value127, 0x0A);
            uint8_t value128 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 4));
            r->a = (value128 << 8) | 0x0A;
            r->x = value127;
            r->y = (uint8_t)y_ret9;
            r->z = 0;
            r->n = 0;
            r->xf = 1;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2D16, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D16); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 7;
            uint16_t dp_ret9 = r->dp;
            bool x_ret19 = r->xf;
            uint16_t y_ret10 = r->y;
            uint16_t value129 = BUS16_RDP(c, (uint16_t)(dp_ret9 + 2));
            if (x_ret19) {
                uint8_t value130 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 4));
                r->a = (value130 << 8) | 0x0A;
                r->x = (uint8_t)(value129 + 0x1A);
                r->y = (uint8_t)y_ret10;
                r->c = value129 + 0x1A > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value129 ^ (uint16_t)(value129 + 0x1A)) & ((uint16_t)(value129 + 0x1A) ^ 0x1A) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2D2A, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D2A); } /* allocate_spell_entity_sprite_pointer_group_long */
                r->sp += 7;
                uint16_t dp_ret10 = r->dp;
                bool m_ret9 = r->mf;
                bool x_ret21 = r->xf;
                uint16_t y_ret11 = r->y;
                if (x_ret21) {
                    uint8_t value131 = BUS8_RDP(c, (uint16_t)(dp_ret10 + 2));
                    if (m_ret9) {
                        uint8_t value136 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value137 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value138 = RAM8(0x0000 + sp0);
                        r->x = value131;
                        r->y = (uint8_t)y_ret11;
                        r->mf = value136 & 0x20;
                        r->xf = value136 & 0x10;
                        r->dp = (value138 << 8) | value137;
                        r->i = value136 & 0x04;
                        r->d = value136 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                } else {
                    uint16_t value145 = BUS16_RDP(c, (uint16_t)(dp_ret10 + 2));
                    if (m_ret9) {
                        uint8_t value150 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value151 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value152 = RAM8(0x0000 + sp0);
                        r->x = value145;
                        r->mf = value150 & 0x20;
                        r->xf = value150 & 0x10;
                        r->dp = (value152 << 8) | value151;
                        r->i = value150 & 0x04;
                        r->d = value150 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                }
            } else {
                uint8_t value159 = BUS8_RDP(c, (uint16_t)(dp_ret9 + 4));
                r->a = (value159 << 8) | 0x0A;
                r->x = (uint16_t)(value129 + 0x1A);
                r->c = value129 + 0x1A > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value129 ^ (uint16_t)(value129 + 0x1A)) & ((uint16_t)(value129 + 0x1A) ^ 0x1A) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2D2A, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D2A); } /* allocate_spell_entity_sprite_pointer_group_long */
                r->sp += 7;
                uint16_t dp_ret11 = r->dp;
                bool m_ret10 = r->mf;
                bool x_ret23 = r->xf;
                uint16_t y_ret12 = r->y;
                if (x_ret23) {
                    uint8_t value160 = BUS8_RDP(c, (uint16_t)(dp_ret11 + 2));
                    if (m_ret10) {
                        uint8_t value165 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value166 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value167 = RAM8(0x0000 + sp0);
                        r->x = value160;
                        r->y = (uint8_t)y_ret12;
                        r->mf = value165 & 0x20;
                        r->xf = value165 & 0x10;
                        r->dp = (value167 << 8) | value166;
                        r->i = value165 & 0x04;
                        r->d = value165 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                } else {
                    uint16_t value174 = BUS16_RDP(c, (uint16_t)(dp_ret11 + 2));
                    if (m_ret10) {
                        uint8_t value179 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value180 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value181 = RAM8(0x0000 + sp0);
                        r->x = value174;
                        r->mf = value179 & 0x20;
                        r->xf = value179 & 0x10;
                        r->dp = (value181 << 8) | value180;
                        r->i = value179 & 0x04;
                        r->d = value179 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                }
            }
        } else {
            uint16_t value188 = BUS16_RDP(c, (uint16_t)(dp_ret8 + 2));
            BUS8_SET(c, (db_ret8 << 0x10) + 0x39 + value188, 0x14);
            BUS8_SET(c, (db_ret8 << 0x10) + 0x18 + value188, 0x0A);
            BUS8_SET(c, (db_ret8 << 0x10) + 0x32 + value188, 0x0A);
            uint8_t value189 = BUS8_RDP(c, (uint16_t)(dp_ret8 + 4));
            r->a = (value189 << 8) | 0x0A;
            r->x = value188;
            r->z = 0;
            r->n = 0;
            r->xf = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0x2D16, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D16); } /* allocate_spell_entity_sprite_pointer_group_long */
            r->sp += 7;
            uint16_t dp_ret12 = r->dp;
            bool x_ret25 = r->xf;
            uint16_t y_ret13 = r->y;
            uint16_t value190 = BUS16_RDP(c, (uint16_t)(dp_ret12 + 2));
            if (x_ret25) {
                uint8_t value191 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 4));
                r->a = (value191 << 8) | 0x0A;
                r->x = (uint8_t)(value190 + 0x1A);
                r->y = (uint8_t)y_ret13;
                r->c = value190 + 0x1A > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value190 ^ (uint16_t)(value190 + 0x1A)) & ((uint16_t)(value190 + 0x1A) ^ 0x1A) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2D2A, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D2A); } /* allocate_spell_entity_sprite_pointer_group_long */
                r->sp += 7;
                uint16_t dp_ret13 = r->dp;
                bool m_ret12 = r->mf;
                bool x_ret27 = r->xf;
                uint16_t y_ret14 = r->y;
                if (x_ret27) {
                    uint8_t value192 = BUS8_RDP(c, (uint16_t)(dp_ret13 + 2));
                    if (m_ret12) {
                        uint8_t value197 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value198 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value199 = RAM8(0x0000 + sp0);
                        r->x = value192;
                        r->y = (uint8_t)y_ret14;
                        r->mf = value197 & 0x20;
                        r->xf = value197 & 0x10;
                        r->dp = (value199 << 8) | value198;
                        r->i = value197 & 0x04;
                        r->d = value197 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                } else {
                    uint16_t value206 = BUS16_RDP(c, (uint16_t)(dp_ret13 + 2));
                    if (m_ret12) {
                        uint8_t value211 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value212 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value213 = RAM8(0x0000 + sp0);
                        r->x = value206;
                        r->mf = value211 & 0x20;
                        r->xf = value211 & 0x10;
                        r->dp = (value213 << 8) | value212;
                        r->i = value211 & 0x04;
                        r->d = value211 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                }
            } else {
                uint8_t value220 = BUS8_RDP(c, (uint16_t)(dp_ret12 + 4));
                r->a = (value220 << 8) | 0x0A;
                r->x = (uint16_t)(value190 + 0x1A);
                r->c = value190 + 0x1A > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = ((value190 ^ (uint16_t)(value190 + 0x1A)) & ((uint16_t)(value190 + 0x1A) ^ 0x1A) & 0x8000) != 0;
                r->mf = 1;
                r->xf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0x2D2A, 0xC12EB5); GUARD_JSL(c, sp_call, 0x2D2A); } /* allocate_spell_entity_sprite_pointer_group_long */
                r->sp += 7;
                uint16_t dp_ret14 = r->dp;
                bool m_ret13 = r->mf;
                bool x_ret29 = r->xf;
                uint16_t y_ret15 = r->y;
                if (x_ret29) {
                    uint8_t value221 = BUS8_RDP(c, (uint16_t)(dp_ret14 + 2));
                    if (m_ret13) {
                        uint8_t value226 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value227 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value228 = RAM8(0x0000 + sp0);
                        r->x = value221;
                        r->y = (uint8_t)y_ret15;
                        r->mf = value226 & 0x20;
                        r->xf = value226 & 0x10;
                        r->dp = (value228 << 8) | value227;
                        r->i = value226 & 0x04;
                        r->d = value226 & 0x08;
                        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                        RETURN_RTS(c);
                    } else {
                        c->fail = 3;
                        return;
                    }
                } else {
                    uint16_t value235 = BUS16_RDP(c, (uint16_t)(dp_ret14 + 2));
                    if (m_ret13) {
                        uint8_t value240 = RAM8(0x0000 + sp0 - 2);
                        uint8_t value241 = RAM8(0x0000 + sp0 - 1);
                        uint8_t value242 = RAM8(0x0000 + sp0);
                        r->x = value235;
                        r->mf = value240 & 0x20;
                        r->xf = value240 & 0x10;
                        r->dp = (value242 << 8) | value241;
                        r->i = value240 & 0x04;
                        r->d = value240 & 0x08;
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
}
SOM_REGISTER(0xC12CC7, SOM_RTS, "gen", construct_spell_entity_twin_sprite_object, 0, L_X | L_Y, 7, 1, 0, 109, 59)

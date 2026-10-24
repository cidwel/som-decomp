#include "som_c.h"

/* D3FE71 advance_random_fallback_particles   [class B, 138 bytes, 71 instructions]
 * Source: src/rom/advance_random_fallback_particles.s
 * Entry: M=any X=16 bit DB=$7E D=$0300.  Callers read: AB.
 */
static void advance_random_fallback_particles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t m_entry = r->mf;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = (((((negative << 7) | (overflow << 6)) | (m_entry << 5)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), 0);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), 0x14);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint8_t data_bank = 0x7E;
    uint16_t direct_page = (uint16_t)(sp0 - 7);
    for (;;) {
        uint16_t value = BUS16_RDP(c, (data_bank << 0x10) + 0x0C + x1);
        if ((uint16_t)(value + 1) == 0) {
            uint16_t value2 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
            BUS16_RMW_SET(c, (uint16_t)(direct_page + 1), (uint16_t)(value2 - 1));
            if ((uint16_t)(value2 - 1) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 0x10);
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                continue;
            }
            uint8_t a_hi1_next2 = (uint16_t)(x1 + 0x10) >> 8;
            uint16_t x1_next2 = (uint16_t)(x1 + 0x10);
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            break;
        }
        uint16_t value3 = BUS16_RDP(c, (data_bank << 0x10) + 0x0E + x1);
        BUS16_RMW_SET(c, (data_bank << 0x10) + 0x0E + x1, (uint16_t)(value3 - 1));
        if ((uint16_t)(value3 - 1) != 0) {
            uint16_t value4 = BUS16_RDP(c, (data_bank << 0x10) + 0x0C + x1);
            RAM8(0x0000 + sp0 - 7) = x1 >> 8;
            RAM8(0x0000 + sp0 - 8) = (uint8_t)x1;
            uint16_t value5 = BUS16_RDP(c, (data_bank << 0x10) + 2 + x1);
            RAM8(0x0000 + sp0 - 9) = value5 >> 8;
            RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value5;
            uint8_t value6 = BUS8_RDP(c, (data_bank << 0x10) + 0x0A + x1);
            uint8_t value7 = BUS8_RDP(c, (data_bank << 0x10) + 6 + x1);
            BUS8_SET(c, (data_bank << 0x10) + 6 + x1, (uint8_t)(value6 + value7));
            uint16_t value8 = BUS16_RDP(c, (data_bank << 0x10) + 4 + x1);
            uint16_t value9 = BUS16_RDP(c, (data_bank << 0x10) + 8 + x1);
            RAM8(0x0000 + sp0 - 0x0B) = (uint16_t)(value8 + value9 + (value6 + value7 > 0xFF)) >> 8;
            RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)(value8 + value9 + (value6 + value7 > 0xFF));
            BUS16_SET(c, (data_bank << 0x10) + 4 + x1, (uint16_t)(value8 + value9 + (value6 + value7 > 0xFF)));
            if (!((uint16_t)((uint16_t)(value8 + value9 + (value6 + value7 > 0xFF)) + 8) & 0x8000)) {
                uint16_t value10 = BUS16_RDP(c, (uint16_t)(direct_page + 3));
                BUS16_RMW_SET(c, (uint16_t)(direct_page + 3), (uint16_t)(value10 + 1));
                r->a = (uint16_t)((uint16_t)(value8 + value9 + (value6 + value7 > 0xFF)) + 8);
                r->x = ((uint16_t)(value4 << 1) & 0xFF) + 0x0682;
                r->y = x1;
                r->c = (uint16_t)(value8 + value9 + (value6 + value7 > 0xFF)) + 8 > 0xFFFF;
                r->z = (uint16_t)(value10 + 1) == 0;
                r->n = (uint16_t)(value10 + 1) & 0x8000;
                r->v = (((uint16_t)(value8 + value9 + (value6 + value7 > 0xFF)) ^ (uint16_t)((uint16_t)(value8 + value9 + (value6 + value7 > 0xFF)) + 8)) & ((uint16_t)((uint16_t)(value8 + value9 + (value6 + value7 > 0xFF)) + 8) ^ 8) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->db = data_bank;
                r->dp = direct_page;
                r->sp -= 13;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFEE0, 0xC12E94); GUARD_JSL(c, sp_call, 0xFEE0); } /* project_packed_spell_entity_sprite_record_long */
                r->sp += 13;
                uint16_t dp_ret = r->dp;
                uint8_t db_ret = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint8_t value15 = RAM8(0x0000 + sp0 - 8);
                uint8_t value16 = RAM8(0x0000 + sp0 - 7);
                uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret + 1), (uint16_t)(value17 - 1));
                if ((uint16_t)(value17 - 1) != 0) {
                    a_hi1 = (uint16_t)(((value16 << 8) | value15) + 0x10) >> 8;
                    x1 = (uint16_t)(((value16 << 8) | value15) + 0x10);
                    data_bank = db_ret;
                    direct_page = dp_ret;
                    continue;
                }
                a_hi1 = (uint16_t)(((value16 << 8) | value15) + 0x10) >> 8;
                x1 = (uint16_t)(((value16 << 8) | value15) + 0x10);
                data_bank = db_ret;
                direct_page = dp_ret;
                break;
            }
            BUS16_SET(c, (data_bank << 0x10) + 0x0C + x1, 0xFFFF);
            uint8_t value22 = RAM8(0x0000 + sp0 - 8);
            uint8_t value23 = RAM8(0x0000 + sp0 - 7);
            uint16_t value24 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
            BUS16_RMW_SET(c, (uint16_t)(direct_page + 1), (uint16_t)(value24 - 1));
            if ((uint16_t)(value24 - 1) != 0) {
                a_hi1 = (uint16_t)(((value23 << 8) | value22) + 0x10) >> 8;
                x1 = (uint16_t)(((value23 << 8) | value22) + 0x10);
                continue;
            }
            a_hi1 = (uint16_t)(((value23 << 8) | value22) + 0x10) >> 8;
            x1 = (uint16_t)(((value23 << 8) | value22) + 0x10);
            break;
        }
        if ((uint16_t)(value + 1) < 4) {
            BUS16_SET(c, (data_bank << 0x10) + 0x0C + x1, (uint16_t)(value + 1));
            BUS16_SET(c, (data_bank << 0x10) + 0x0E + x1, 4);
            uint16_t value25 = BUS16_RDP(c, (data_bank << 0x10) + 0x0C + x1);
            RAM8(0x0000 + sp0 - 7) = x1 >> 8;
            RAM8(0x0000 + sp0 - 8) = (uint8_t)x1;
            uint16_t value26 = BUS16_RDP(c, (data_bank << 0x10) + 2 + x1);
            RAM8(0x0000 + sp0 - 9) = value26 >> 8;
            RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value26;
            uint8_t value27 = BUS8_RDP(c, (data_bank << 0x10) + 0x0A + x1);
            uint8_t value28 = BUS8_RDP(c, (data_bank << 0x10) + 6 + x1);
            BUS8_SET(c, (data_bank << 0x10) + 6 + x1, (uint8_t)(value27 + value28));
            uint16_t value29 = BUS16_RDP(c, (data_bank << 0x10) + 4 + x1);
            uint16_t value30 = BUS16_RDP(c, (data_bank << 0x10) + 8 + x1);
            RAM8(0x0000 + sp0 - 0x0B) = (uint16_t)(value29 + value30 + (value27 + value28 > 0xFF)) >> 8;
            RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)(value29 + value30 + (value27 + value28 > 0xFF));
            BUS16_SET(c, (data_bank << 0x10) + 4 + x1, (uint16_t)(value29 + value30 + (value27 + value28 > 0xFF)));
            if (!((uint16_t)((uint16_t)(value29 + value30 + (value27 + value28 > 0xFF)) + 8) & 0x8000)) {
                uint16_t value31 = BUS16_RDP(c, (uint16_t)(direct_page + 3));
                BUS16_RMW_SET(c, (uint16_t)(direct_page + 3), (uint16_t)(value31 + 1));
                r->a = (uint16_t)((uint16_t)(value29 + value30 + (value27 + value28 > 0xFF)) + 8);
                r->x = ((uint16_t)(value25 << 1) & 0xFF) + 0x0682;
                r->y = x1;
                r->c = (uint16_t)(value29 + value30 + (value27 + value28 > 0xFF)) + 8 > 0xFFFF;
                r->z = (uint16_t)(value31 + 1) == 0;
                r->n = (uint16_t)(value31 + 1) & 0x8000;
                r->v = (((uint16_t)(value29 + value30 + (value27 + value28 > 0xFF)) ^ (uint16_t)((uint16_t)(value29 + value30 + (value27 + value28 > 0xFF)) + 8)) & ((uint16_t)((uint16_t)(value29 + value30 + (value27 + value28 > 0xFF)) + 8) ^ 8) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->db = data_bank;
                r->dp = direct_page;
                r->sp -= 13;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFEE0, 0xC12E94); GUARD_JSL(c, sp_call, 0xFEE0); } /* project_packed_spell_entity_sprite_record_long */
                r->sp += 13;
                uint16_t dp_ret2 = r->dp;
                uint8_t db_ret2 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint8_t value36 = RAM8(0x0000 + sp0 - 8);
                uint8_t value37 = RAM8(0x0000 + sp0 - 7);
                uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS16_RMW_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value38 - 1));
                if ((uint16_t)(value38 - 1) != 0) {
                    a_hi1 = (uint16_t)(((value37 << 8) | value36) + 0x10) >> 8;
                    x1 = (uint16_t)(((value37 << 8) | value36) + 0x10);
                    data_bank = db_ret2;
                    direct_page = dp_ret2;
                    continue;
                }
                a_hi1 = (uint16_t)(((value37 << 8) | value36) + 0x10) >> 8;
                x1 = (uint16_t)(((value37 << 8) | value36) + 0x10);
                data_bank = db_ret2;
                direct_page = dp_ret2;
                break;
            }
            BUS16_SET(c, (data_bank << 0x10) + 0x0C + x1, 0xFFFF);
            uint8_t value43 = RAM8(0x0000 + sp0 - 8);
            uint8_t value44 = RAM8(0x0000 + sp0 - 7);
            uint16_t value45 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
            BUS16_RMW_SET(c, (uint16_t)(direct_page + 1), (uint16_t)(value45 - 1));
            if ((uint16_t)(value45 - 1) != 0) {
                a_hi1 = (uint16_t)(((value44 << 8) | value43) + 0x10) >> 8;
                x1 = (uint16_t)(((value44 << 8) | value43) + 0x10);
                continue;
            }
            a_hi1 = (uint16_t)(((value44 << 8) | value43) + 0x10) >> 8;
            x1 = (uint16_t)(((value44 << 8) | value43) + 0x10);
            break;
        }
        BUS16_SET(c, (data_bank << 0x10) + 0x0C + x1, 0);
        BUS16_SET(c, (data_bank << 0x10) + 0x0E + x1, 4);
        uint16_t value46 = BUS16_RDP(c, (data_bank << 0x10) + 0x0C + x1);
        RAM8(0x0000 + sp0 - 7) = x1 >> 8;
        RAM8(0x0000 + sp0 - 8) = (uint8_t)x1;
        uint16_t value47 = BUS16_RDP(c, (data_bank << 0x10) + 2 + x1);
        RAM8(0x0000 + sp0 - 9) = value47 >> 8;
        RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)value47;
        uint8_t value48 = BUS8_RDP(c, (data_bank << 0x10) + 0x0A + x1);
        uint8_t value49 = BUS8_RDP(c, (data_bank << 0x10) + 6 + x1);
        BUS8_SET(c, (data_bank << 0x10) + 6 + x1, (uint8_t)(value48 + value49));
        uint16_t value50 = BUS16_RDP(c, (data_bank << 0x10) + 4 + x1);
        uint16_t value51 = BUS16_RDP(c, (data_bank << 0x10) + 8 + x1);
        RAM8(0x0000 + sp0 - 0x0B) = (uint16_t)(value50 + value51 + (value48 + value49 > 0xFF)) >> 8;
        RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)(value50 + value51 + (value48 + value49 > 0xFF));
        BUS16_SET(c, (data_bank << 0x10) + 4 + x1, (uint16_t)(value50 + value51 + (value48 + value49 > 0xFF)));
        if (!((uint16_t)((uint16_t)(value50 + value51 + (value48 + value49 > 0xFF)) + 8) & 0x8000)) {
            uint16_t value52 = BUS16_RDP(c, (uint16_t)(direct_page + 3));
            BUS16_RMW_SET(c, (uint16_t)(direct_page + 3), (uint16_t)(value52 + 1));
            r->a = (uint16_t)((uint16_t)(value50 + value51 + (value48 + value49 > 0xFF)) + 8);
            r->x = ((uint16_t)(value46 << 1) & 0xFF) + 0x0682;
            r->y = x1;
            r->c = (uint16_t)(value50 + value51 + (value48 + value49 > 0xFF)) + 8 > 0xFFFF;
            r->z = (uint16_t)(value52 + 1) == 0;
            r->n = (uint16_t)(value52 + 1) & 0x8000;
            r->v = (((uint16_t)(value50 + value51 + (value48 + value49 > 0xFF)) ^ (uint16_t)((uint16_t)(value50 + value51 + (value48 + value49 > 0xFF)) + 8)) & ((uint16_t)((uint16_t)(value50 + value51 + (value48 + value49 > 0xFF)) + 8) ^ 8) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 13;
            { const uint16_t sp_call = r->sp; JSL(c, 0xFEE0, 0xC12E94); GUARD_JSL(c, sp_call, 0xFEE0); } /* project_packed_spell_entity_sprite_record_long */
            r->sp += 13;
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint8_t value57 = RAM8(0x0000 + sp0 - 8);
            uint8_t value58 = RAM8(0x0000 + sp0 - 7);
            uint16_t value59 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret3 + 1), (uint16_t)(value59 - 1));
            if ((uint16_t)(value59 - 1) != 0) {
                a_hi1 = (uint16_t)(((value58 << 8) | value57) + 0x10) >> 8;
                x1 = (uint16_t)(((value58 << 8) | value57) + 0x10);
                data_bank = db_ret3;
                direct_page = dp_ret3;
                continue;
            }
            a_hi1 = (uint16_t)(((value58 << 8) | value57) + 0x10) >> 8;
            x1 = (uint16_t)(((value58 << 8) | value57) + 0x10);
            data_bank = db_ret3;
            direct_page = dp_ret3;
            break;
        }
        BUS16_SET(c, (data_bank << 0x10) + 0x0C + x1, 0xFFFF);
        uint8_t value64 = RAM8(0x0000 + sp0 - 8);
        uint8_t value65 = RAM8(0x0000 + sp0 - 7);
        uint16_t value66 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
        BUS16_RMW_SET(c, (uint16_t)(direct_page + 1), (uint16_t)(value66 - 1));
        if ((uint16_t)(value66 - 1) != 0) {
            a_hi1 = (uint16_t)(((value65 << 8) | value64) + 0x10) >> 8;
            x1 = (uint16_t)(((value65 << 8) | value64) + 0x10);
            continue;
        }
        a_hi1 = (uint16_t)(((value65 << 8) | value64) + 0x10) >> 8;
        x1 = (uint16_t)(((value65 << 8) | value64) + 0x10);
        break;
    }
    uint16_t value67 = BUS16_RDP(c, (uint16_t)(direct_page + 3));
    RAM8(0x0000 + sp0 - 3) = (uint8_t)value67;
    uint8_t value71 = RAM8(0x0000 + sp0 - 3);
    uint8_t value72 = RAM8(0x0000 + sp0 - 2);
    uint8_t value73 = RAM8(0x0000 + sp0 - 1);
    uint8_t value74 = RAM8(0x0000 + sp0);
    r->a = (value67 >> 8 << 8) | value71;
    r->mf = value72 & 0x20;
    r->xf = value72 & 0x10;
    r->db = data_bank;
    r->dp = (value74 << 8) | value73;
    r->i = value72 & 0x04;
    r->d = value72 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FE71, SOM_RTS, "gen", advance_random_fallback_particles, 0, L_A | L_B, 13, -1, 0, 138, 71)

#include "som_c.h"

/* D3FEFB spawn_random_fallback_particle   [class B, 190 bytes, 88 instructions]
 * Source: src/rom/spawn_random_fallback_particle.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXCZNV.
 */
static void spawn_random_fallback_particle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_ffae = 0;
    uint16_t direct_page_ffae = 0;
    uint8_t data_bank_ffae = 0;
    uint8_t a_hi_ffae2 = 0;
    uint16_t direct_page_ffae2 = 0;
    uint8_t data_bank_ffae2 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), x);
    uint16_t value = RAM16(0x0144 + x);
    uint8_t a1;
    uint8_t a_hi1;
    if ((uint16_t)(value + 1) < 0x14) {
        a1 = (uint8_t)(value + 1);
        a_hi1 = (uint16_t)(value + 1) >> 8;
    } else {
        a1 = 0;
        a_hi1 = 0;
    }
    RAM16_SET(0x0144 + x, (a_hi1 << 8) | a1);
    BUS16_SET(c, 0x004202, (a1 << 8) | 0x10);
    RAM8(0x0000 + sp0 - 7) = a1;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)((a1 << 8) | 0x10);
    uint16_t value2 = BUS16(c, 0x004216);
    uint16_t value3 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
    uint16_t value4 = RAM16(0x000C + (uint16_t)(value2 + value3));
    if ((uint16_t)(value4 + 1) != 0) {
        a_hi_ffae = (uint16_t)(value4 + 1) >> 8;
        direct_page_ffae = (uint16_t)(sp0 - 7);
        data_bank_ffae = 0x7E;
        goto shared_FFAE;
    }
    RAM16_SET(0x000C + (uint16_t)(value2 + value3), (uint16_t)(value4 + 1));
    RAM16_SET(0x0004 + (uint16_t)(value2 + value3), 0x0110);
    RAM16_SET(0x000E + (uint16_t)(value2 + value3), 1);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (uint16_t)(value2 + value3));
    r->a = 0;
    r->y = (uint16_t)(value2 + value3);
    r->c = value2 + value3 > 0xFFFF;
    r->z = 1;
    r->n = 0;
    r->v = ((value2 ^ (uint16_t)(value2 + value3)) & (value3 ^ (uint16_t)(value2 + value3)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSL(c, 0xFF4A, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF4A); } /* draw_spell_entity_bounded_random_long */
    r->sp += 7;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        uint8_t value5 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
        BUS8_SET(c, (db_ret << 0x10) + 0x0A + value5, (uint8_t)a_all);
        r->a = (a_all >> 8 << 8) | 1;
        r->x = (uint8_t)x_ret2;
        r->y = value5;
        r->z = 0;
        r->n = 0;
        r->xf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFF55, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF55); } /* draw_spell_entity_bounded_random_long */
        r->sp += 7;
        uint8_t db_ret2 = r->db;
        bool x_ret3 = r->xf;
        uint16_t a_all2 = r->a;
        uint16_t x_ret4 = r->x;
        if (x_ret3) {
            uint8_t value6 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
            BUS16_SET(c, (db_ret2 << 0x10) + 8 + value6, (uint16_t)(a_all2 + 1) ^ 0xFFFF);
            r->a = 0x40;
            r->x = (uint8_t)x_ret4;
            r->y = value6;
            r->c = a_all2 + 1 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((a_all2 ^ (uint16_t)(a_all2 + 1)) & ((uint16_t)(a_all2 + 1) ^ 1) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0xFF6A, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF6A); } /* draw_spell_entity_bounded_random_long */
            r->sp += 7;
            uint8_t db_ret3 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret5 = r->xf;
            uint16_t a_all3 = r->a;
            if (x_ret5) {
                uint8_t value7 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                uint8_t value8 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                uint16_t value9 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0140 + value7);
                BUS16_SET(c, (db_ret3 << 0x10) + 2 + value8, (uint16_t)((uint16_t)(a_all3 - 0x20) + value9));
                r->a = 0x20;
                r->x = value7;
                r->y = value8;
                r->c = (uint16_t)(a_all3 - 0x20) + value9 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(a_all3 - 0x20) ^ (uint16_t)((uint16_t)(a_all3 - 0x20) + value9)) & (value9 ^ (uint16_t)((uint16_t)(a_all3 - 0x20) + value9)) & 0x8000) != 0;
                r->xf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFF80, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF80); } /* draw_spell_entity_bounded_random_long */
                r->sp += 7;
                uint8_t db_ret4 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret7 = r->xf;
                uint16_t a_all4 = r->a;
                if (x_ret7) {
                    uint8_t value10 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret4 << 0x10) + 0x0148 + value10, (uint16_t)(a_all4 + 4));
                    uint16_t value11 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x0146 + value10);
                    BUS16_RMW_SET(c, (db_ret4 << 0x10) + 0x0146 + value10, (uint16_t)(value11 - 1));
                    uint8_t a_hi2;
                    if ((uint16_t)(value11 - 1) != 0) {
                        a_hi2 = (uint16_t)(a_all4 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret4 << 0x10) + 0x0148 + value10, 0);
                        uint8_t value12 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value13 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret4 << 0x10) + 4 + value12, (uint16_t)(value13 + 0x0110));
                        uint16_t value14 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret4 << 0x10) + 0x8434, (uint16_t)(value14 << 4));
                        BUS16_SET(c, (db_ret4 << 0x10) + 0x0A + value12, 0);
                        a_hi2 = 0;
                    }
                    a_hi_ffae2 = a_hi2;
                    direct_page_ffae2 = (uint16_t)(sp0 - 7);
                    data_bank_ffae2 = db_ret4;
                    goto shared_FFAE_1;
                } else {
                    uint16_t value15 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret4 << 0x10) + 0x0148 + value15, (uint16_t)(a_all4 + 4));
                    uint16_t value16 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x0146 + value15);
                    BUS16_RMW_SET(c, (db_ret4 << 0x10) + 0x0146 + value15, (uint16_t)(value16 - 1));
                    uint8_t a_hi3;
                    if ((uint16_t)(value16 - 1) != 0) {
                        a_hi3 = (uint16_t)(a_all4 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret4 << 0x10) + 0x0148 + value15, 0);
                        uint16_t value17 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value18 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret4 << 0x10) + 4 + value17, (uint16_t)(value18 + 0x0110));
                        uint16_t value19 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret4 << 0x10) + 0x8434, (uint16_t)(value19 << 4));
                        BUS16_SET(c, (db_ret4 << 0x10) + 0x0A + value17, 0);
                        a_hi3 = 0;
                    }
                    a_hi_ffae = a_hi3;
                    direct_page_ffae = (uint16_t)(sp0 - 7);
                    data_bank_ffae = db_ret4;
                    goto shared_FFAE;
                }
            } else {
                uint16_t value20 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                uint16_t value21 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                uint16_t value22 = BUS16_RDP(c, (db_ret3 << 0x10) + 0x0140 + value20);
                BUS16_SET(c, (db_ret3 << 0x10) + 2 + value21, (uint16_t)((uint16_t)(a_all3 - 0x20) + value22));
                r->a = 0x20;
                r->x = value20;
                r->y = value21;
                r->c = (uint16_t)(a_all3 - 0x20) + value22 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(a_all3 - 0x20) ^ (uint16_t)((uint16_t)(a_all3 - 0x20) + value22)) & (value22 ^ (uint16_t)((uint16_t)(a_all3 - 0x20) + value22)) & 0x8000) != 0;
                r->xf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFF80, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF80); } /* draw_spell_entity_bounded_random_long */
                r->sp += 7;
                uint8_t db_ret5 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret9 = r->xf;
                uint16_t a_all5 = r->a;
                if (x_ret9) {
                    uint8_t value23 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret5 << 0x10) + 0x0148 + value23, (uint16_t)(a_all5 + 4));
                    uint16_t value24 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x0146 + value23);
                    BUS16_RMW_SET(c, (db_ret5 << 0x10) + 0x0146 + value23, (uint16_t)(value24 - 1));
                    uint8_t a_hi4;
                    if ((uint16_t)(value24 - 1) != 0) {
                        a_hi4 = (uint16_t)(a_all5 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret5 << 0x10) + 0x0148 + value23, 0);
                        uint8_t value25 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value26 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret5 << 0x10) + 4 + value25, (uint16_t)(value26 + 0x0110));
                        uint16_t value27 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret5 << 0x10) + 0x8434, (uint16_t)(value27 << 4));
                        BUS16_SET(c, (db_ret5 << 0x10) + 0x0A + value25, 0);
                        a_hi4 = 0;
                    }
                    a_hi_ffae2 = a_hi4;
                    direct_page_ffae2 = (uint16_t)(sp0 - 7);
                    data_bank_ffae2 = db_ret5;
                    goto shared_FFAE_1;
                } else {
                    uint16_t value28 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret5 << 0x10) + 0x0148 + value28, (uint16_t)(a_all5 + 4));
                    uint16_t value29 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x0146 + value28);
                    BUS16_RMW_SET(c, (db_ret5 << 0x10) + 0x0146 + value28, (uint16_t)(value29 - 1));
                    uint8_t a_hi5;
                    if ((uint16_t)(value29 - 1) != 0) {
                        a_hi5 = (uint16_t)(a_all5 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret5 << 0x10) + 0x0148 + value28, 0);
                        uint16_t value30 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value31 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret5 << 0x10) + 4 + value30, (uint16_t)(value31 + 0x0110));
                        uint16_t value32 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret5 << 0x10) + 0x8434, (uint16_t)(value32 << 4));
                        BUS16_SET(c, (db_ret5 << 0x10) + 0x0A + value30, 0);
                        a_hi5 = 0;
                    }
                    a_hi_ffae = a_hi5;
                    direct_page_ffae = (uint16_t)(sp0 - 7);
                    data_bank_ffae = db_ret5;
                    goto shared_FFAE;
                }
            }
        } else {
            uint16_t value33 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
            BUS16_SET(c, (db_ret2 << 0x10) + 8 + value33, (uint16_t)(a_all2 + 1) ^ 0xFFFF);
            r->a = 0x40;
            r->y = value33;
            r->c = a_all2 + 1 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((a_all2 ^ (uint16_t)(a_all2 + 1)) & ((uint16_t)(a_all2 + 1) ^ 1) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0xFF6A, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF6A); } /* draw_spell_entity_bounded_random_long */
            r->sp += 7;
            uint8_t db_ret6 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret11 = r->xf;
            uint16_t a_all6 = r->a;
            if (x_ret11) {
                uint8_t value34 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                uint8_t value35 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                uint16_t value36 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x0140 + value34);
                BUS16_SET(c, (db_ret6 << 0x10) + 2 + value35, (uint16_t)((uint16_t)(a_all6 - 0x20) + value36));
                r->a = 0x20;
                r->x = value34;
                r->y = value35;
                r->c = (uint16_t)(a_all6 - 0x20) + value36 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(a_all6 - 0x20) ^ (uint16_t)((uint16_t)(a_all6 - 0x20) + value36)) & (value36 ^ (uint16_t)((uint16_t)(a_all6 - 0x20) + value36)) & 0x8000) != 0;
                r->xf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFF80, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF80); } /* draw_spell_entity_bounded_random_long */
                r->sp += 7;
                uint8_t db_ret7 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret13 = r->xf;
                uint16_t a_all7 = r->a;
                if (x_ret13) {
                    uint8_t value37 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret7 << 0x10) + 0x0148 + value37, (uint16_t)(a_all7 + 4));
                    uint16_t value38 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x0146 + value37);
                    BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x0146 + value37, (uint16_t)(value38 - 1));
                    uint8_t a_hi6;
                    if ((uint16_t)(value38 - 1) != 0) {
                        a_hi6 = (uint16_t)(a_all7 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x0148 + value37, 0);
                        uint8_t value39 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value40 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret7 << 0x10) + 4 + value39, (uint16_t)(value40 + 0x0110));
                        uint16_t value41 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x8434, (uint16_t)(value41 << 4));
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x0A + value39, 0);
                        a_hi6 = 0;
                    }
                    a_hi_ffae2 = a_hi6;
                    direct_page_ffae2 = (uint16_t)(sp0 - 7);
                    data_bank_ffae2 = db_ret7;
                    goto shared_FFAE_1;
                } else {
                    uint16_t value42 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret7 << 0x10) + 0x0148 + value42, (uint16_t)(a_all7 + 4));
                    uint16_t value43 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x0146 + value42);
                    BUS16_RMW_SET(c, (db_ret7 << 0x10) + 0x0146 + value42, (uint16_t)(value43 - 1));
                    uint8_t a_hi7;
                    if ((uint16_t)(value43 - 1) != 0) {
                        a_hi7 = (uint16_t)(a_all7 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x0148 + value42, 0);
                        uint16_t value44 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value45 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret7 << 0x10) + 4 + value44, (uint16_t)(value45 + 0x0110));
                        uint16_t value46 = BUS16_RDP(c, (db_ret7 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x8434, (uint16_t)(value46 << 4));
                        BUS16_SET(c, (db_ret7 << 0x10) + 0x0A + value44, 0);
                        a_hi7 = 0;
                    }
                    a_hi_ffae = a_hi7;
                    direct_page_ffae = (uint16_t)(sp0 - 7);
                    data_bank_ffae = db_ret7;
                    goto shared_FFAE;
                }
            } else {
                uint16_t value47 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                uint16_t value48 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                uint16_t value49 = BUS16_RDP(c, (db_ret6 << 0x10) + 0x0140 + value47);
                BUS16_SET(c, (db_ret6 << 0x10) + 2 + value48, (uint16_t)((uint16_t)(a_all6 - 0x20) + value49));
                r->a = 0x20;
                r->x = value47;
                r->y = value48;
                r->c = (uint16_t)(a_all6 - 0x20) + value49 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(a_all6 - 0x20) ^ (uint16_t)((uint16_t)(a_all6 - 0x20) + value49)) & (value49 ^ (uint16_t)((uint16_t)(a_all6 - 0x20) + value49)) & 0x8000) != 0;
                r->xf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFF80, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF80); } /* draw_spell_entity_bounded_random_long */
                r->sp += 7;
                uint8_t db_ret8 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret15 = r->xf;
                uint16_t a_all8 = r->a;
                if (x_ret15) {
                    uint8_t value50 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret8 << 0x10) + 0x0148 + value50, (uint16_t)(a_all8 + 4));
                    uint16_t value51 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x0146 + value50);
                    BUS16_RMW_SET(c, (db_ret8 << 0x10) + 0x0146 + value50, (uint16_t)(value51 - 1));
                    uint8_t a_hi8;
                    if ((uint16_t)(value51 - 1) != 0) {
                        a_hi8 = (uint16_t)(a_all8 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret8 << 0x10) + 0x0148 + value50, 0);
                        uint8_t value52 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value53 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret8 << 0x10) + 4 + value52, (uint16_t)(value53 + 0x0110));
                        uint16_t value54 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret8 << 0x10) + 0x8434, (uint16_t)(value54 << 4));
                        BUS16_SET(c, (db_ret8 << 0x10) + 0x0A + value52, 0);
                        a_hi8 = 0;
                    }
                    a_hi_ffae2 = a_hi8;
                    direct_page_ffae2 = (uint16_t)(sp0 - 7);
                    data_bank_ffae2 = db_ret8;
                    goto shared_FFAE_1;
                } else {
                    uint16_t value55 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret8 << 0x10) + 0x0148 + value55, (uint16_t)(a_all8 + 4));
                    uint16_t value56 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x0146 + value55);
                    BUS16_RMW_SET(c, (db_ret8 << 0x10) + 0x0146 + value55, (uint16_t)(value56 - 1));
                    uint8_t a_hi9;
                    if ((uint16_t)(value56 - 1) != 0) {
                        a_hi9 = (uint16_t)(a_all8 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret8 << 0x10) + 0x0148 + value55, 0);
                        uint16_t value57 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value58 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret8 << 0x10) + 4 + value57, (uint16_t)(value58 + 0x0110));
                        uint16_t value59 = BUS16_RDP(c, (db_ret8 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret8 << 0x10) + 0x8434, (uint16_t)(value59 << 4));
                        BUS16_SET(c, (db_ret8 << 0x10) + 0x0A + value57, 0);
                        a_hi9 = 0;
                    }
                    a_hi_ffae = a_hi9;
                    direct_page_ffae = (uint16_t)(sp0 - 7);
                    data_bank_ffae = db_ret8;
                    goto shared_FFAE;
                }
            }
        }
    } else {
        uint16_t value60 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        BUS8_SET(c, (db_ret << 0x10) + 0x0A + value60, (uint8_t)a_all);
        r->a = (a_all >> 8 << 8) | 1;
        r->y = value60;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSL(c, 0xFF55, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF55); } /* draw_spell_entity_bounded_random_long */
        r->sp += 7;
        uint8_t db_ret9 = r->db;
        bool x_ret17 = r->xf;
        uint16_t a_all9 = r->a;
        uint16_t x_ret18 = r->x;
        if (x_ret17) {
            uint8_t value61 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
            BUS16_SET(c, (db_ret9 << 0x10) + 8 + value61, (uint16_t)(a_all9 + 1) ^ 0xFFFF);
            r->a = 0x40;
            r->x = (uint8_t)x_ret18;
            r->y = value61;
            r->c = a_all9 + 1 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((a_all9 ^ (uint16_t)(a_all9 + 1)) & ((uint16_t)(a_all9 + 1) ^ 1) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 1;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0xFF6A, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF6A); } /* draw_spell_entity_bounded_random_long */
            r->sp += 7;
            uint8_t db_ret10 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret19 = r->xf;
            uint16_t a_all10 = r->a;
            if (x_ret19) {
                uint8_t value62 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                uint8_t value63 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                uint16_t value64 = BUS16_RDP(c, (db_ret10 << 0x10) + 0x0140 + value62);
                BUS16_SET(c, (db_ret10 << 0x10) + 2 + value63, (uint16_t)((uint16_t)(a_all10 - 0x20) + value64));
                r->a = 0x20;
                r->x = value62;
                r->y = value63;
                r->c = (uint16_t)(a_all10 - 0x20) + value64 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(a_all10 - 0x20) ^ (uint16_t)((uint16_t)(a_all10 - 0x20) + value64)) & (value64 ^ (uint16_t)((uint16_t)(a_all10 - 0x20) + value64)) & 0x8000) != 0;
                r->xf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFF80, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF80); } /* draw_spell_entity_bounded_random_long */
                r->sp += 7;
                uint8_t db_ret11 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret21 = r->xf;
                uint16_t a_all11 = r->a;
                if (x_ret21) {
                    uint8_t value65 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret11 << 0x10) + 0x0148 + value65, (uint16_t)(a_all11 + 4));
                    uint16_t value66 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x0146 + value65);
                    BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0x0146 + value65, (uint16_t)(value66 - 1));
                    uint8_t a_hi10;
                    if ((uint16_t)(value66 - 1) != 0) {
                        a_hi10 = (uint16_t)(a_all11 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x0148 + value65, 0);
                        uint8_t value67 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value68 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret11 << 0x10) + 4 + value67, (uint16_t)(value68 + 0x0110));
                        uint16_t value69 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x8434, (uint16_t)(value69 << 4));
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x0A + value67, 0);
                        a_hi10 = 0;
                    }
                    a_hi_ffae2 = a_hi10;
                    direct_page_ffae2 = (uint16_t)(sp0 - 7);
                    data_bank_ffae2 = db_ret11;
                    goto shared_FFAE_1;
                } else {
                    uint16_t value70 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret11 << 0x10) + 0x0148 + value70, (uint16_t)(a_all11 + 4));
                    uint16_t value71 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x0146 + value70);
                    BUS16_RMW_SET(c, (db_ret11 << 0x10) + 0x0146 + value70, (uint16_t)(value71 - 1));
                    uint8_t a_hi11;
                    if ((uint16_t)(value71 - 1) != 0) {
                        a_hi11 = (uint16_t)(a_all11 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x0148 + value70, 0);
                        uint16_t value72 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value73 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret11 << 0x10) + 4 + value72, (uint16_t)(value73 + 0x0110));
                        uint16_t value74 = BUS16_RDP(c, (db_ret11 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x8434, (uint16_t)(value74 << 4));
                        BUS16_SET(c, (db_ret11 << 0x10) + 0x0A + value72, 0);
                        a_hi11 = 0;
                    }
                    a_hi_ffae = a_hi11;
                    direct_page_ffae = (uint16_t)(sp0 - 7);
                    data_bank_ffae = db_ret11;
                    goto shared_FFAE;
                }
            } else {
                uint16_t value75 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                uint16_t value76 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                uint16_t value77 = BUS16_RDP(c, (db_ret10 << 0x10) + 0x0140 + value75);
                BUS16_SET(c, (db_ret10 << 0x10) + 2 + value76, (uint16_t)((uint16_t)(a_all10 - 0x20) + value77));
                r->a = 0x20;
                r->x = value75;
                r->y = value76;
                r->c = (uint16_t)(a_all10 - 0x20) + value77 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(a_all10 - 0x20) ^ (uint16_t)((uint16_t)(a_all10 - 0x20) + value77)) & (value77 ^ (uint16_t)((uint16_t)(a_all10 - 0x20) + value77)) & 0x8000) != 0;
                r->xf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFF80, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF80); } /* draw_spell_entity_bounded_random_long */
                r->sp += 7;
                uint8_t db_ret12 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret23 = r->xf;
                uint16_t a_all12 = r->a;
                if (x_ret23) {
                    uint8_t value78 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret12 << 0x10) + 0x0148 + value78, (uint16_t)(a_all12 + 4));
                    uint16_t value79 = BUS16_RDP(c, (db_ret12 << 0x10) + 0x0146 + value78);
                    BUS16_RMW_SET(c, (db_ret12 << 0x10) + 0x0146 + value78, (uint16_t)(value79 - 1));
                    uint8_t a_hi12;
                    if ((uint16_t)(value79 - 1) != 0) {
                        a_hi12 = (uint16_t)(a_all12 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret12 << 0x10) + 0x0148 + value78, 0);
                        uint8_t value80 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value81 = BUS16_RDP(c, (db_ret12 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret12 << 0x10) + 4 + value80, (uint16_t)(value81 + 0x0110));
                        uint16_t value82 = BUS16_RDP(c, (db_ret12 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret12 << 0x10) + 0x8434, (uint16_t)(value82 << 4));
                        BUS16_SET(c, (db_ret12 << 0x10) + 0x0A + value80, 0);
                        a_hi12 = 0;
                    }
                    a_hi_ffae2 = a_hi12;
                    direct_page_ffae2 = (uint16_t)(sp0 - 7);
                    data_bank_ffae2 = db_ret12;
                    goto shared_FFAE_1;
                } else {
                    uint16_t value83 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret12 << 0x10) + 0x0148 + value83, (uint16_t)(a_all12 + 4));
                    uint16_t value84 = BUS16_RDP(c, (db_ret12 << 0x10) + 0x0146 + value83);
                    BUS16_RMW_SET(c, (db_ret12 << 0x10) + 0x0146 + value83, (uint16_t)(value84 - 1));
                    uint8_t a_hi13;
                    if ((uint16_t)(value84 - 1) != 0) {
                        a_hi13 = (uint16_t)(a_all12 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret12 << 0x10) + 0x0148 + value83, 0);
                        uint16_t value85 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value86 = BUS16_RDP(c, (db_ret12 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret12 << 0x10) + 4 + value85, (uint16_t)(value86 + 0x0110));
                        uint16_t value87 = BUS16_RDP(c, (db_ret12 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret12 << 0x10) + 0x8434, (uint16_t)(value87 << 4));
                        BUS16_SET(c, (db_ret12 << 0x10) + 0x0A + value85, 0);
                        a_hi13 = 0;
                    }
                    a_hi_ffae = a_hi13;
                    direct_page_ffae = (uint16_t)(sp0 - 7);
                    data_bank_ffae = db_ret12;
                    goto shared_FFAE;
                }
            }
        } else {
            uint16_t value88 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
            BUS16_SET(c, (db_ret9 << 0x10) + 8 + value88, (uint16_t)(a_all9 + 1) ^ 0xFFFF);
            r->a = 0x40;
            r->y = value88;
            r->c = a_all9 + 1 > 0xFFFF;
            r->z = 0;
            r->n = 0;
            r->v = ((a_all9 ^ (uint16_t)(a_all9 + 1)) & ((uint16_t)(a_all9 + 1) ^ 1) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSL(c, 0xFF6A, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF6A); } /* draw_spell_entity_bounded_random_long */
            r->sp += 7;
            uint8_t db_ret13 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret25 = r->xf;
            uint16_t a_all13 = r->a;
            if (x_ret25) {
                uint8_t value89 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                uint8_t value90 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                uint16_t value91 = BUS16_RDP(c, (db_ret13 << 0x10) + 0x0140 + value89);
                BUS16_SET(c, (db_ret13 << 0x10) + 2 + value90, (uint16_t)((uint16_t)(a_all13 - 0x20) + value91));
                r->a = 0x20;
                r->x = value89;
                r->y = value90;
                r->c = (uint16_t)(a_all13 - 0x20) + value91 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(a_all13 - 0x20) ^ (uint16_t)((uint16_t)(a_all13 - 0x20) + value91)) & (value91 ^ (uint16_t)((uint16_t)(a_all13 - 0x20) + value91)) & 0x8000) != 0;
                r->xf = 1;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFF80, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF80); } /* draw_spell_entity_bounded_random_long */
                r->sp += 7;
                uint8_t db_ret14 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret27 = r->xf;
                uint16_t a_all14 = r->a;
                if (x_ret27) {
                    uint8_t value92 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret14 << 0x10) + 0x0148 + value92, (uint16_t)(a_all14 + 4));
                    uint16_t value93 = BUS16_RDP(c, (db_ret14 << 0x10) + 0x0146 + value92);
                    BUS16_RMW_SET(c, (db_ret14 << 0x10) + 0x0146 + value92, (uint16_t)(value93 - 1));
                    uint8_t a_hi14;
                    if ((uint16_t)(value93 - 1) != 0) {
                        a_hi14 = (uint16_t)(a_all14 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret14 << 0x10) + 0x0148 + value92, 0);
                        uint8_t value94 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value95 = BUS16_RDP(c, (db_ret14 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret14 << 0x10) + 4 + value94, (uint16_t)(value95 + 0x0110));
                        uint16_t value96 = BUS16_RDP(c, (db_ret14 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret14 << 0x10) + 0x8434, (uint16_t)(value96 << 4));
                        BUS16_SET(c, (db_ret14 << 0x10) + 0x0A + value94, 0);
                        a_hi14 = 0;
                    }
                    a_hi_ffae2 = a_hi14;
                    direct_page_ffae2 = (uint16_t)(sp0 - 7);
                    data_bank_ffae2 = db_ret14;
                    goto shared_FFAE_1;
                } else {
                    uint16_t value97 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret14 << 0x10) + 0x0148 + value97, (uint16_t)(a_all14 + 4));
                    uint16_t value98 = BUS16_RDP(c, (db_ret14 << 0x10) + 0x0146 + value97);
                    BUS16_RMW_SET(c, (db_ret14 << 0x10) + 0x0146 + value97, (uint16_t)(value98 - 1));
                    uint8_t a_hi15;
                    if ((uint16_t)(value98 - 1) != 0) {
                        a_hi15 = (uint16_t)(a_all14 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret14 << 0x10) + 0x0148 + value97, 0);
                        uint16_t value99 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value100 = BUS16_RDP(c, (db_ret14 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret14 << 0x10) + 4 + value99, (uint16_t)(value100 + 0x0110));
                        uint16_t value101 = BUS16_RDP(c, (db_ret14 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret14 << 0x10) + 0x8434, (uint16_t)(value101 << 4));
                        BUS16_SET(c, (db_ret14 << 0x10) + 0x0A + value99, 0);
                        a_hi15 = 0;
                    }
                    a_hi_ffae = a_hi15;
                    direct_page_ffae = (uint16_t)(sp0 - 7);
                    data_bank_ffae = db_ret14;
                    goto shared_FFAE;
                }
            } else {
                uint16_t value102 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                uint16_t value103 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                uint16_t value104 = BUS16_RDP(c, (db_ret13 << 0x10) + 0x0140 + value102);
                BUS16_SET(c, (db_ret13 << 0x10) + 2 + value103, (uint16_t)((uint16_t)(a_all13 - 0x20) + value104));
                r->a = 0x20;
                r->x = value102;
                r->y = value103;
                r->c = (uint16_t)(a_all13 - 0x20) + value104 > 0xFFFF;
                r->z = 0;
                r->n = 0;
                r->v = (((uint16_t)(a_all13 - 0x20) ^ (uint16_t)((uint16_t)(a_all13 - 0x20) + value104)) & (value104 ^ (uint16_t)((uint16_t)(a_all13 - 0x20) + value104)) & 0x8000) != 0;
                r->xf = 0;
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSL(c, 0xFF80, 0xC12ED1); GUARD_JSL(c, sp_call, 0xFF80); } /* draw_spell_entity_bounded_random_long */
                r->sp += 7;
                uint8_t db_ret15 = r->db;
                if (r->mf != 0) { c->fail = 3; return; }
                bool x_ret29 = r->xf;
                uint16_t a_all15 = r->a;
                if (x_ret29) {
                    uint8_t value105 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret15 << 0x10) + 0x0148 + value105, (uint16_t)(a_all15 + 4));
                    uint16_t value106 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x0146 + value105);
                    BUS16_RMW_SET(c, (db_ret15 << 0x10) + 0x0146 + value105, (uint16_t)(value106 - 1));
                    uint8_t a_hi16;
                    if ((uint16_t)(value106 - 1) != 0) {
                        a_hi16 = (uint16_t)(a_all15 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret15 << 0x10) + 0x0148 + value105, 0);
                        uint8_t value107 = RAM8(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value108 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret15 << 0x10) + 4 + value107, (uint16_t)(value108 + 0x0110));
                        uint16_t value109 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret15 << 0x10) + 0x8434, (uint16_t)(value109 << 4));
                        BUS16_SET(c, (db_ret15 << 0x10) + 0x0A + value107, 0);
                        a_hi16 = 0;
                    }
                    a_hi_ffae2 = a_hi16;
                    direct_page_ffae2 = (uint16_t)(sp0 - 7);
                    data_bank_ffae2 = db_ret15;
                    goto shared_FFAE_1;
                } else {
                    uint16_t value110 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
                    BUS16_SET(c, (db_ret15 << 0x10) + 0x0148 + value110, (uint16_t)(a_all15 + 4));
                    uint16_t value111 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x0146 + value110);
                    BUS16_RMW_SET(c, (db_ret15 << 0x10) + 0x0146 + value110, (uint16_t)(value111 - 1));
                    uint8_t a_hi17;
                    if ((uint16_t)(value111 - 1) != 0) {
                        a_hi17 = (uint16_t)(a_all15 + 4) >> 8;
                    } else {
                        BUS16_SET(c, (db_ret15 << 0x10) + 0x0148 + value110, 0);
                        uint16_t value112 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                        uint16_t value113 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret15 << 0x10) + 4 + value112, (uint16_t)(value113 + 0x0110));
                        uint16_t value114 = BUS16_RDP(c, (db_ret15 << 0x10) + 0x8434);
                        BUS16_SET(c, (db_ret15 << 0x10) + 0x8434, (uint16_t)(value114 << 4));
                        BUS16_SET(c, (db_ret15 << 0x10) + 0x0A + value112, 0);
                        a_hi17 = 0;
                    }
                    a_hi_ffae = a_hi17;
                    direct_page_ffae = (uint16_t)(sp0 - 7);
                    data_bank_ffae = db_ret15;
                    goto shared_FFAE;
                }
            }
        }
    }
    shared_FFAE:;
    uint16_t value115 = BUS16_RDP(c, (uint16_t)(direct_page_ffae + 1));
    uint8_t value119 = RAM8(0x0000 + sp0 - 3);
    uint8_t value120 = RAM8(0x0000 + sp0 - 2);
    uint8_t value121 = RAM8(0x0000 + sp0 - 1);
    uint8_t value122 = RAM8(0x0000 + sp0);
    r->a = (a_hi_ffae << 8) | value119;
    r->x = value115;
    r->c = value120 & 0x01;
    r->z = ((value122 << 8) | value121) == 0;
    r->n = ((value122 << 8) | value121) & 0x8000;
    r->v = value120 & 0x40;
    r->mf = value120 & 0x20;
    r->xf = value120 & 0x10;
    r->db = data_bank_ffae;
    r->dp = (value122 << 8) | value121;
    r->i = value120 & 0x04;
    r->d = value120 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
    shared_FFAE_1:;
    uint8_t value123 = BUS8_RDP(c, (uint16_t)(direct_page_ffae2 + 1));
    uint8_t value127 = RAM8(0x0000 + sp0 - 3);
    uint8_t value128 = RAM8(0x0000 + sp0 - 2);
    uint8_t value129 = RAM8(0x0000 + sp0 - 1);
    uint8_t value130 = RAM8(0x0000 + sp0);
    r->a = (a_hi_ffae2 << 8) | value127;
    r->x = value123;
    r->c = value128 & 0x01;
    r->z = ((value130 << 8) | value129) == 0;
    r->n = ((value130 << 8) | value129) & 0x8000;
    r->v = value128 & 0x40;
    r->mf = value128 & 0x20;
    r->xf = value128 & 0x10;
    r->db = data_bank_ffae2;
    r->dp = (value130 << 8) | value129;
    r->i = value128 & 0x04;
    r->d = value128 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3FEFB, SOM_RTS, "gen", spawn_random_fallback_particle, 0, L_A | L_B | L_X | L_C | L_Z | L_N | L_V, 9, 1, 0, 190, 88)

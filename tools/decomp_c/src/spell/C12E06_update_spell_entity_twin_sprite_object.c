#include "som_c.h"

/* C12E06 update_spell_entity_twin_sprite_object   [class B, 114 bytes, 60 instructions]
 * Source: src/rom/update_spell_entity_twin_sprite_object.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void update_spell_entity_twin_sprite_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint8_t value = RAM8(0x0039 + x);
    if (value == 0) {
        RAM8(0x0000 + sp0 - 3) = value;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), x);
    uint8_t value6 = RAM8(0x0038 + x);
    RAM8(0x0038 + x) = value6 ^ 0xFF;
    if ((value6 ^ 0xFF) == 0) {
        RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), x);
        uint8_t a_hi1 = (uint16_t)(sp0 - 7) >> 8;
        uint16_t x1 = x;
        bool overflow1 = (((uint16_t)(sp0 - 3) ^ 4) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
        uint8_t data_bank = 0x7E;
        for (;;) {
            uint8_t value7 = BUS8_RDP(c, (data_bank << 0x10) + 0x18 + x1);
            if (value7 & 0x80) {
                break;
            }
            if (value7 < 0x0A) {
                r->a = (a_hi1 << 8) | value7;
                r->x = x1;
                r->c = value7 >= 0x0A;
                r->z = value7 == 0x0A;
                r->n = (uint8_t)(value7 - 0x0A) & 0x80;
                r->v = overflow1;
                r->mf = 1;
                r->xf = 0;
                r->db = data_bank;
                r->dp = (uint16_t)(sp0 - 7);
                r->sp -= 7;
                { const uint16_t sp_call = r->sp; JSR(c, 0x2E60, 0xC12D63); GUARD_JSR(c, sp_call, 0x2E60); } /* publish_spell_entity_twin_sprite_group */
                r->sp += 7;
                uint8_t db_ret = r->db;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all = r->a;
                bool overflow_ret = r->v;
                uint16_t value8 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
                a_hi1 = a_all >> 8;
                x1 = value8;
                overflow1 = overflow_ret;
                data_bank = db_ret;
                break;
            }
            uint16_t value9 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
            uint8_t value10 = BUS8_RDP(c, (data_bank << 0x10) + 0x39 + value9);
            BUS8_SET(c, (data_bank << 0x10) + 0x39 + value9, (uint8_t)(value10 - 1));
            if ((uint8_t)(value10 - 1) < 2) {
                BUS8_SET(c, (data_bank << 0x10) + 0x18 + x1, 0x80);
                break;
            }
            r->a = (uint16_t)(value9 + 0x34);
            r->x = x1;
            r->y = (uint16_t)(value9 + 0x34);
            r->c = value9 + 0x34 > 0xFFFF;
            r->z = (uint16_t)(value9 + 0x34) == 0;
            r->n = (uint16_t)(value9 + 0x34) & 0x8000;
            r->v = ((value9 ^ (uint16_t)(value9 + 0x34)) & ((uint16_t)(value9 + 0x34) ^ 0x34) & 0x8000) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2E52, 0xC12DB0); GUARD_JSR(c, sp_call, 0x2E52); } /* place_spell_entity_twin_sprite_group_randomly */
            r->sp += 7;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all2 = r->a;
            bool overflow_ret2 = r->v;
            uint16_t value11 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
            a_hi1 = a_all2 >> 8;
            x1 = value11;
            overflow1 = overflow_ret2;
            data_bank = db_ret2;
            continue;
        }
        uint8_t value12 = BUS8_RDP(c, (data_bank << 0x10) + 0x18 + x1);
        BUS8_SET(c, (data_bank << 0x10) + 0x18 + x1, (uint8_t)(value12 + 1));
        uint8_t value14 = BUS8_RDP(c, (data_bank << 0x10) + 0x39 + RAM16(0x0001 + (uint16_t)(sp0 - 7)));
        if (value14 == 0) {
            RAM8(0x0000 + sp0 - 3) = value14;
            uint8_t value19 = RAM8(0x0000 + sp0 - 2);
            uint8_t value20 = RAM8(0x0000 + sp0 - 1);
            uint8_t value21 = RAM8(0x0000 + sp0);
            r->mf = value19 & 0x20;
            r->xf = value19 & 0x10;
            r->db = data_bank;
            r->dp = (value21 << 8) | value20;
            r->i = value19 & 0x04;
            r->d = value19 & 0x08;
            RETURN_RTS(c);
        }
        RAM8(0x0000 + sp0 - 3) = 0xFF;
        uint8_t value26 = RAM8(0x0000 + sp0 - 2);
        uint8_t value27 = RAM8(0x0000 + sp0 - 1);
        uint8_t value28 = RAM8(0x0000 + sp0);
        r->mf = value26 & 0x20;
        r->xf = value26 & 0x10;
        r->db = data_bank;
        r->dp = (value28 << 8) | value27;
        r->i = value26 & 0x04;
        r->d = value26 & 0x08;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), (uint16_t)(x + 0x1A));
    uint8_t a_hi2 = (uint16_t)(x + 0x1A) >> 8;
    uint16_t x2 = (uint16_t)(x + 0x1A);
    bool overflow2 = ((x ^ (uint16_t)(x + 0x1A)) & ((uint16_t)(x + 0x1A) ^ 0x1A) & 0x8000) != 0;
    uint8_t data_bank2 = 0x7E;
    for (;;) {
        uint8_t value29 = BUS8_RDP(c, (data_bank2 << 0x10) + 0x18 + x2);
        if (value29 & 0x80) {
            break;
        }
        if (value29 < 0x0A) {
            r->a = (a_hi2 << 8) | value29;
            r->x = x2;
            r->c = value29 >= 0x0A;
            r->z = value29 == 0x0A;
            r->n = (uint8_t)(value29 - 0x0A) & 0x80;
            r->v = overflow2;
            r->mf = 1;
            r->xf = 0;
            r->db = data_bank2;
            r->dp = (uint16_t)(sp0 - 7);
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2E60, 0xC12D63); GUARD_JSR(c, sp_call, 0x2E60); } /* publish_spell_entity_twin_sprite_group */
            r->sp += 7;
            uint8_t db_ret3 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all3 = r->a;
            bool overflow_ret3 = r->v;
            uint16_t value30 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
            a_hi2 = a_all3 >> 8;
            x2 = value30;
            overflow2 = overflow_ret3;
            data_bank2 = db_ret3;
            break;
        }
        uint16_t value31 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
        uint8_t value32 = BUS8_RDP(c, (data_bank2 << 0x10) + 0x39 + value31);
        BUS8_SET(c, (data_bank2 << 0x10) + 0x39 + value31, (uint8_t)(value32 - 1));
        if ((uint8_t)(value32 - 1) < 2) {
            BUS8_SET(c, (data_bank2 << 0x10) + 0x18 + x2, 0x80);
            break;
        }
        r->a = (uint16_t)(value31 + 0x34);
        r->x = x2;
        r->y = (uint16_t)(value31 + 0x34);
        r->c = value31 + 0x34 > 0xFFFF;
        r->z = (uint16_t)(value31 + 0x34) == 0;
        r->n = (uint16_t)(value31 + 0x34) & 0x8000;
        r->v = ((value31 ^ (uint16_t)(value31 + 0x34)) & ((uint16_t)(value31 + 0x34) ^ 0x34) & 0x8000) != 0;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank2;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x2E52, 0xC12DB0); GUARD_JSR(c, sp_call, 0x2E52); } /* place_spell_entity_twin_sprite_group_randomly */
        r->sp += 7;
        uint8_t db_ret4 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all4 = r->a;
        bool overflow_ret4 = r->v;
        uint16_t value33 = RAM16(0x0003 + (uint16_t)(sp0 - 7));
        a_hi2 = a_all4 >> 8;
        x2 = value33;
        overflow2 = overflow_ret4;
        data_bank2 = db_ret4;
        continue;
    }
    uint8_t value34 = BUS8_RDP(c, (data_bank2 << 0x10) + 0x18 + x2);
    BUS8_SET(c, (data_bank2 << 0x10) + 0x18 + x2, (uint8_t)(value34 + 1));
    uint8_t value36 = BUS8_RDP(c, (data_bank2 << 0x10) + 0x39 + RAM16(0x0001 + (uint16_t)(sp0 - 7)));
    if (value36 == 0) {
        RAM8(0x0000 + sp0 - 3) = value36;
        uint8_t value41 = RAM8(0x0000 + sp0 - 2);
        uint8_t value42 = RAM8(0x0000 + sp0 - 1);
        uint8_t value43 = RAM8(0x0000 + sp0);
        r->mf = value41 & 0x20;
        r->xf = value41 & 0x10;
        r->db = data_bank2;
        r->dp = (value43 << 8) | value42;
        r->i = value41 & 0x04;
        r->d = value41 & 0x08;
        RETURN_RTS(c);
    }
    RAM8(0x0000 + sp0 - 3) = 0xFF;
    uint8_t value48 = RAM8(0x0000 + sp0 - 2);
    uint8_t value49 = RAM8(0x0000 + sp0 - 1);
    uint8_t value50 = RAM8(0x0000 + sp0);
    r->mf = value48 & 0x20;
    r->xf = value48 & 0x10;
    r->db = data_bank2;
    r->dp = (value50 << 8) | value49;
    r->i = value48 & 0x04;
    r->d = value48 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC12E06, SOM_RTS, "gen", update_spell_entity_twin_sprite_object, 0, 0, 7, 1, 0, 114, 60)

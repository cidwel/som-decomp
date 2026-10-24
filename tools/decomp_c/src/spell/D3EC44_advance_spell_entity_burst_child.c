#include "som_c.h"

/* D3EC44 advance_spell_entity_burst_child   [class B, 197 bytes, 93 instructions]
 * Source: src/rom/advance_spell_entity_burst_child.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: A.
 */
static void advance_spell_entity_burst_child(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x6 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = RAM16(0x000E + y);
    if (value & 0x8000) {
        RAM16_SET(0x000E + y, (uint16_t)(value + 1));
        uint16_t value2 = RAM16(0x0000 + y);
        r->a = (uint16_t)(value + 1);
        r->x = value2;
        r->c = (uint16_t)(sp0 - 3) >= 6;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
        r->mf = 0;
        r->dp = (uint16_t)(sp0 - 9);
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEC5E, 0xC12E8C); GUARD_JSL(c, sp_call, 0xEC5E); } /* hide_burst_child_sprite_through_native_long_call_wrapper */
        r->sp += 9;
        if (r->mf != 0) { c->fail = 3; return; }
        RAM16_SET(0x0000 + sp0 - 4, 0);
        uint8_t value3 = RAM8(0x0000 + sp0 - 4);
        uint8_t value4 = RAM8(0x0000 + sp0 - 3);
        uint8_t value5 = RAM8(0x0000 + sp0 - 2);
        uint8_t value6 = RAM8(0x0000 + sp0 - 1);
        uint8_t value7 = RAM8(0x0000 + sp0);
        r->a = (value4 << 8) | value3;
        r->mf = value5 & 0x20;
        r->xf = value5 & 0x10;
        r->dp = (value7 << 8) | value6;
        r->i = value5 & 0x04;
        r->d = value5 & 0x08;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 9), x);
    RAM16_SET(0x0005 + (uint16_t)(sp0 - 9), y);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), (uint16_t)(value + 1));
    uint8_t a1 = (uint8_t)(value + 1);
    uint8_t a_hi1 = (uint16_t)(value + 1) >> 8;
    do {
        uint8_t value8 = RAM8(0x0002 + y);
        uint8_t value9 = RAM8(0x0008 + y);
        RAM8(0x0002 + y) = (uint8_t)(value8 + value9);
        uint16_t value10 = RAM16(0x0003 + y);
        uint16_t value11 = RAM16(0x0009 + y);
        RAM16_SET(0x0003 + y, (uint16_t)(value10 + value11 + (value8 + value9 > 0xFF)));
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 9)) - 1));
        a1 = (uint8_t)(value10 + value11 + (value8 + value9 > 0xFF));
        a_hi1 = (uint16_t)(value10 + value11 + (value8 + value9 > 0xFF)) >> 8;
    } while (RAM16(0x0001 + (uint16_t)(sp0 - 9)) != 0);
    RAM8(0x0000 + sp0 - 9) = a_hi1;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)((a_hi1 << 8) | a1);
    uint16_t value12 = RAM16(0x000E + y);
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), (uint16_t)(value12 + 1));
    uint8_t a2 = (uint8_t)(value12 + 1);
    uint8_t a_hi2 = (uint16_t)(value12 + 1) >> 8;
    do {
        uint8_t value13 = RAM8(0x0005 + y);
        uint8_t value14 = RAM8(0x000B + y);
        RAM8(0x0005 + y) = (uint8_t)(value13 + value14);
        uint16_t value15 = RAM16(0x0006 + y);
        uint16_t value16 = RAM16(0x000C + y);
        RAM16_SET(0x0006 + y, (uint16_t)(value15 + value16 + (value13 + value14 > 0xFF)));
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 9)) - 1));
        a2 = (uint8_t)(value15 + value16 + (value13 + value14 > 0xFF));
        a_hi2 = (uint16_t)(value15 + value16 + (value13 + value14 > 0xFF)) >> 8;
    } while (RAM16(0x0001 + (uint16_t)(sp0 - 9)) != 0);
    RAM8(0x0000 + sp0 - 0x0B) = a_hi2;
    RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)((a_hi2 << 8) | a2);
    uint16_t value17 = RAM16(0x000E + y);
    uint8_t value18 = RAM8(0x000E + y);
    BUS16_SET(c, 0x004202, ((uint8_t)value17 << 8) | value18);
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)value17;
    RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)(((uint8_t)value17 << 8) | value18);
    uint16_t value19 = BUS16(c, 0x004216);
    BUS16_SET(c, 0x004204, value19);
    BUS8_SET(c, 0x004206, 0x25);
    RAM8(0x0000 + sp0 - 0x0D) = value19 >> 8;
    RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)((value19 >> 8 << 8) | 0x25);
    RAM8(0x0000 + sp0 - 0x0D) = value19 >> 8;
    RAM8(0x0000 + sp0 - 0x0E) = (uint8_t)((value19 >> 8 << 8) | 0x25);
    uint16_t value20 = BUS16(c, 0x004214);
    r->a = (uint16_t)((value20 & 0xFFFE) + 0x2E);
    r->x = (uint16_t)((value20 & 0xFFFE) + 0x2E);
    r->y = y;
    r->c = (uint16_t)((value20 & 0xFFFE) + 0xF82E) >= 0xF800;
    r->z = (uint16_t)((value20 & 0xFFFE) + 0x2E) == 0;
    r->n = (uint16_t)((value20 & 0xFFFE) + 0x2E) & 0x8000;
    r->v = (((uint16_t)((value20 & 0xFFFE) + 0xF82E) ^ 0xF800) & ((uint16_t)((value20 & 0xFFFE) + 0xF82E) ^ (uint16_t)((value20 & 0xFFFE) + 0x2E)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSL(c, 0xECE4, 0xC12E94); GUARD_JSL(c, sp_call, 0xECE4); } /* project_packed_spell_entity_sprite_record_long */
    r->sp += 13;
    uint16_t dp_ret2 = r->dp;
    uint8_t db_ret2 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    if (x_ret3) {
        uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
        uint16_t value26 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0E + value25);
        BUS16_SET(c, (db_ret2 << 0x10) + 0x0E + value25, (uint16_t)(value26 + 1));
        bool x_flag;
        uint8_t a_hi3;
        uint8_t data_bank;
        if ((uint16_t)(value26 + 1) < 0x14) {
            x_flag = 1;
            a_hi3 = (uint16_t)(value26 + 1) >> 8;
            data_bank = db_ret2;
        } else {
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 3));
            r->a = (uint16_t)(value26 + 1);
            r->x = value27;
            r->y = value25;
            r->c = (uint16_t)(value26 + 1) >= 0x14;
            r->z = value27 == 0;
            r->n = value27 & 0x80;
            r->xf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xECF9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xECF9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 9;
            uint8_t db_ret3 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret5 = r->xf;
            uint16_t a_all3 = r->a;
            x_flag = x_ret5;
            a_hi3 = a_all3 >> 8;
            data_bank = db_ret3;
        }
        RAM16_SET(0x0000 + sp0 - 4, 0xFFFF);
        uint8_t value28 = RAM8(0x0000 + sp0 - 4);
        uint8_t value29 = RAM8(0x0000 + sp0 - 3);
        uint8_t value30 = RAM8(0x0000 + sp0 - 2);
        uint8_t value31 = RAM8(0x0000 + sp0 - 1);
        uint8_t value32 = RAM8(0x0000 + sp0);
        r->a = (value29 << 8) | value28;
        r->mf = value30 & 0x20;
        r->xf = value30 & 0x10;
        r->db = data_bank;
        r->dp = (value32 << 8) | value31;
        r->i = value30 & 0x04;
        r->d = value30 & 0x08;
        RETURN_RTS(c);
    } else {
        uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
        uint16_t value34 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x0E + value33);
        BUS16_SET(c, (db_ret2 << 0x10) + 0x0E + value33, (uint16_t)(value34 + 1));
        bool x_flag2;
        uint8_t a_hi4;
        uint8_t data_bank2;
        if ((uint16_t)(value34 + 1) < 0x14) {
            x_flag2 = 0;
            a_hi4 = (uint16_t)(value34 + 1) >> 8;
            data_bank2 = db_ret2;
        } else {
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
            r->a = (uint16_t)(value34 + 1);
            r->x = value35;
            r->y = value33;
            r->c = (uint16_t)(value34 + 1) >= 0x14;
            r->z = value35 == 0;
            r->n = value35 & 0x8000;
            r->xf = 0;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xECF9, 0xD3EA93); GUARD_JSR(c, sp_call, 0xECF9); } /* seed_spell_entity_burst_child_velocity */
            r->sp += 9;
            uint8_t db_ret4 = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            bool x_ret7 = r->xf;
            uint16_t a_all4 = r->a;
            x_flag2 = x_ret7;
            a_hi4 = a_all4 >> 8;
            data_bank2 = db_ret4;
        }
        RAM16_SET(0x0000 + sp0 - 4, 0xFFFF);
        uint8_t value36 = RAM8(0x0000 + sp0 - 4);
        uint8_t value37 = RAM8(0x0000 + sp0 - 3);
        uint8_t value38 = RAM8(0x0000 + sp0 - 2);
        uint8_t value39 = RAM8(0x0000 + sp0 - 1);
        uint8_t value40 = RAM8(0x0000 + sp0);
        r->a = (value37 << 8) | value36;
        r->mf = value38 & 0x20;
        r->xf = value38 & 0x10;
        r->db = data_bank2;
        r->dp = (value40 << 8) | value39;
        r->i = value38 & 0x04;
        r->d = value38 & 0x08;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xD3EC44, SOM_RTS, "gen", advance_spell_entity_burst_child, 0, L_A, 15, 1, 0, 197, 93)

#include "som_c.h"

/* D3EE60 initialize_spell_entity_summon_sprites   [class B, 276 bytes, 134 instructions]
 * Source: src/rom/initialize_spell_entity_summon_sprites.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: nothing.
 */
static void initialize_spell_entity_summon_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0B) + 0x8 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_eeaf = 0;
    uint8_t x_eeaf = 0;
    uint16_t direct_page_eeaf = 0;
    uint8_t data_bank_eeaf = 0;
    uint8_t a_hi_eeaf2 = 0;
    uint16_t x_eeaf2 = 0;
    uint16_t direct_page_eeaf2 = 0;
    uint8_t data_bank_eeaf2 = 0;
    uint8_t a_hi_ef2c = 0;
    uint8_t x_ef2c = 0;
    uint8_t y_ef2c = 0;
    uint16_t direct_page_ef2c = 0;
    uint8_t data_bank_ef2c = 0;
    uint8_t a_hi_ef2c2 = 0;
    uint16_t x_ef2c2 = 0;
    uint16_t y_ef2c2 = 0;
    uint16_t direct_page_ef2c2 = 0;
    uint8_t data_bank_ef2c2 = 0;
    uint8_t a_hi_ef63 = 0;
    uint8_t y_ef63 = 0;
    uint16_t direct_page_ef63 = 0;
    uint8_t data_bank_ef63 = 0;
    uint8_t a_hi_ef632 = 0;
    uint16_t y_ef632 = 0;
    uint16_t direct_page_ef632 = 0;
    uint8_t data_bank_ef632 = 0;
    RAM8(0x0000 + sp0) = 3;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0C) = 0x7E;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0B), y);
    r->a = ((uint16_t)(sp0 - 0x0B) >> 8 << 8) | 0x7E;
    r->x = 0xF8A3;
    r->c = (uint16_t)(sp0 - 3) >= 8;
    r->z = 0;
    r->n = 1;
    r->v = (((uint16_t)(sp0 - 3) ^ 8) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0B)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0B);
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEE7C, 0xC12E90); GUARD_JSL(c, sp_call, 0xEE7C); } /* construct_spell_graphics_audio_resources_long */
    r->sp += 12;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        RAM8(0x0007 + (uint16_t)(sp0 - 0x0B)) = (uint8_t)x_ret2;
        RAM16_SET(0x0012 + (uint8_t)x_ret2, (uint16_t)(RAM16(0x0012 + (uint8_t)x_ret2) + 1));
        uint8_t value = RAM8(0x0002 + (uint16_t)(sp0 - 0x0B));
        RAM16_SET(0x001A + value, (uint8_t)x_ret2);
        RAM16_SET(0x002A + value, 0xF0);
        RAM16_SET(0x001C + value, 0x3711);
        RAM16_SET(0x001E + value, 0x345A);
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0B)) = 0xC0;
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = RAM8(0x0027 + value);
        a_hi_eeaf = 0;
        x_eeaf = value;
        direct_page_eeaf = (uint16_t)(sp0 - 0x0B);
        data_bank_eeaf = 0x7E;
        goto shared_EEAF;
    } else {
        RAM16_SET(0x0007 + (uint16_t)(sp0 - 0x0B), x_ret2);
        RAM16_SET(0x0012 + x_ret2, (uint16_t)(RAM16(0x0012 + x_ret2) + 1));
        uint16_t value3 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0B));
        RAM16_SET(0x001A + value3, x_ret2);
        RAM16_SET(0x002A + value3, 0xF0);
        RAM16_SET(0x001C + value3, 0x3711);
        RAM16_SET(0x001E + value3, 0x345A);
        RAM8(0x0006 + (uint16_t)(sp0 - 0x0B)) = 0xC0;
        RAM8(0x0001 + (uint16_t)(sp0 - 0x0B)) = RAM8(0x0027 + value3);
        a_hi_eeaf2 = value3 >> 8;
        x_eeaf2 = value3;
        direct_page_eeaf2 = (uint16_t)(sp0 - 0x0B);
        data_bank_eeaf2 = 0x7E;
        goto shared_EEAF_1;
    }
    shared_EEAF:;
    BUS8_SET(c, (uint16_t)(direct_page_eeaf + 4), x_eeaf);
    uint8_t value5 = BUS8_RDP(c, (data_bank_eeaf << 0x10) + x_eeaf);
    uint8_t value6 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 2));
    uint8_t value7 = BUS8_RDP(c, (data_bank_eeaf << 0x10) + 0x24 + value6);
    uint8_t value8 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 6));
    uint8_t value9 = BUS8_RDP(c, (data_bank_eeaf << 0x10) + 0x20 + value6);
    uint8_t value10 = BUS8_RDP(c, (data_bank_eeaf << 0x10) + 0x22 + value6);
    uint8_t value11 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 7));
    r->a = (uint8_t)((value5 << 8) | (uint8_t)(value7 + value8));
    r->x = (uint8_t)((value9 << 8) | value10);
    r->y = value11;
    r->c = value7 + value8 > 0xFF;
    r->z = value11 == 0;
    r->n = value11 & 0x80;
    r->v = ((value7 ^ (uint8_t)(value7 + value8)) & (value8 ^ (uint8_t)(value7 + value8)) & 0x80) != 0;
    r->mf = 0;
    r->xf = 1;
    r->db = data_bank_eeaf;
    r->dp = direct_page_eeaf;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEECD, 0xD3ED5F); GUARD_JSR(c, sp_call, 0xEECD); } /* construct_temporary_spell_sprite_object */
    r->sp += 12;
    uint8_t db_ret = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret3 = r->xf;
    uint16_t x_ret4 = r->x;
    if (x_ret3) {
        uint8_t value12 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 4));
        BUS16_SET(c, (db_ret << 0x10) + 2 + value12, (uint8_t)x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value12, 0x2BED);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value12, 0x2BF2);
        uint8_t value13 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 6));
        BUS8_SET(c, (uint16_t)(direct_page_eeaf + 6), (uint8_t)(value13 + 0x40));
        uint8_t value14 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 1));
        BUS8_SET(c, (uint16_t)(direct_page_eeaf + 1), (uint8_t)(value14 - 1));
        if ((uint8_t)(value14 - 1) != 0) {
            a_hi_eeaf = value12 + 8 >> 8;
            x_eeaf = (uint8_t)(value12 + 8);
            data_bank_eeaf = db_ret;
            goto shared_EEAF;
        }
        uint8_t value15 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 2));
        uint8_t value16 = BUS8_RDP(c, (db_ret << 0x10) + 2 + value15);
        BUS8_SET(c, (db_ret << 0x10) + 0x023D + value16, 2);
        uint8_t value17 = BUS8_RDP(c, (db_ret << 0x10) + 0x0A + value15);
        if (value17 != 0) {
            a_hi_ef2c = value12 + 8 >> 8;
            x_ef2c = value15;
            y_ef2c = value17;
            direct_page_ef2c = direct_page_eeaf;
            data_bank_ef2c = db_ret;
            goto shared_EF2C;
        }
        uint8_t value18 = BUS8_RDP(c, (db_ret << 0x10) + 0x20 + value15);
        uint8_t value19 = BUS8_RDP(c, (db_ret << 0x10) + 0x22 + value15);
        uint8_t value20 = BUS8_RDP(c, (db_ret << 0x10) + 8 + value15);
        uint8_t value21 = BUS8_RDP(c, (db_ret << 0x10) + 0x24 + value15);
        r->a = (value20 << 8) | value21;
        r->x = (uint8_t)((value18 << 8) | value19);
        r->y = (uint8_t)((value18 << 8) | value19);
        r->c = value13 + 0x40 > 0xFF;
        r->z = (uint8_t)((value18 << 8) | value19) == 0;
        r->n = (uint8_t)((value18 << 8) | value19) & 0x80;
        r->v = ((value13 ^ (uint8_t)(value13 + 0x40)) & ((uint8_t)(value13 + 0x40) ^ 0x40) & 0x80) != 0;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEF14, 0xD3ED5F); GUARD_JSR(c, sp_call, 0xEF14); } /* construct_temporary_spell_sprite_object */
        r->sp += 12;
        uint8_t db_ret2 = r->db;
        bool x_ret5 = r->xf;
        uint16_t x_ret6 = r->x;
        if (x_ret5) {
            uint8_t value22 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 2));
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0A + value22, (uint8_t)x_ret6);
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0C + value22, 0x2BED);
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0E + value22, 0x2BF2);
            a_hi_ef2c = 0x2B;
            x_ef2c = value22;
            y_ef2c = (uint8_t)x_ret6;
            direct_page_ef2c = direct_page_eeaf;
            data_bank_ef2c = db_ret2;
            goto shared_EF2C;
        } else {
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf + 2));
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0A + value23, x_ret6);
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0C + value23, 0x2BED);
            BUS16_SET(c, (db_ret2 << 0x10) + 0x0E + value23, 0x2BF2);
            a_hi_ef2c2 = 0x2B;
            x_ef2c2 = value23;
            y_ef2c2 = x_ret6;
            direct_page_ef2c2 = direct_page_eeaf;
            data_bank_ef2c2 = db_ret2;
            goto shared_EF2C_1;
        }
    } else {
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf + 4));
        BUS16_SET(c, (db_ret << 0x10) + 2 + value24, x_ret4);
        BUS16_SET(c, (db_ret << 0x10) + 4 + value24, 0x2BED);
        BUS16_SET(c, (db_ret << 0x10) + 6 + value24, 0x2BF2);
        uint8_t value25 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 6));
        BUS8_SET(c, (uint16_t)(direct_page_eeaf + 6), (uint8_t)(value25 + 0x40));
        uint8_t value26 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 1));
        BUS8_SET(c, (uint16_t)(direct_page_eeaf + 1), (uint8_t)(value26 - 1));
        if ((uint8_t)(value26 - 1) != 0) {
            a_hi_eeaf2 = (uint16_t)(value24 + 8) >> 8;
            x_eeaf2 = (uint16_t)(value24 + 8);
            direct_page_eeaf2 = direct_page_eeaf;
            data_bank_eeaf2 = db_ret;
            goto shared_EEAF_1;
        }
        uint16_t value27 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf + 2));
        uint16_t value28 = BUS16_RDP(c, (db_ret << 0x10) + 2 + value27);
        BUS8_SET(c, (db_ret << 0x10) + 0x023D + value28, 2);
        uint16_t value29 = BUS16_RDP(c, (db_ret << 0x10) + 0x0A + value27);
        if (value29 != 0) {
            a_hi_ef2c2 = (uint16_t)(value24 + 8) >> 8;
            x_ef2c2 = value27;
            y_ef2c2 = value29;
            direct_page_ef2c2 = direct_page_eeaf;
            data_bank_ef2c2 = db_ret;
            goto shared_EF2C_1;
        }
        uint8_t value30 = BUS8_RDP(c, (db_ret << 0x10) + 0x20 + value27);
        uint8_t value31 = BUS8_RDP(c, (db_ret << 0x10) + 0x22 + value27);
        uint8_t value32 = BUS8_RDP(c, (db_ret << 0x10) + 8 + value27);
        uint8_t value33 = BUS8_RDP(c, (db_ret << 0x10) + 0x24 + value27);
        r->a = (value32 << 8) | value33;
        r->x = (value30 << 8) | value31;
        r->y = (value30 << 8) | value31;
        r->c = value25 + 0x40 > 0xFF;
        r->z = ((value30 << 8) | value31) == 0;
        r->n = ((value30 << 8) | value31) & 0x8000;
        r->v = ((value25 ^ (uint8_t)(value25 + 0x40)) & ((uint8_t)(value25 + 0x40) ^ 0x40) & 0x80) != 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEF14, 0xD3ED5F); GUARD_JSR(c, sp_call, 0xEF14); } /* construct_temporary_spell_sprite_object */
        r->sp += 12;
        uint8_t db_ret3 = r->db;
        bool x_ret7 = r->xf;
        uint16_t x_ret8 = r->x;
        if (x_ret7) {
            uint8_t value34 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf + 2));
            BUS16_SET(c, (db_ret3 << 0x10) + 0x0A + value34, (uint8_t)x_ret8);
            BUS16_SET(c, (db_ret3 << 0x10) + 0x0C + value34, 0x2BED);
            BUS16_SET(c, (db_ret3 << 0x10) + 0x0E + value34, 0x2BF2);
            a_hi_ef2c = 0x2B;
            x_ef2c = value34;
            y_ef2c = (uint8_t)x_ret8;
            direct_page_ef2c = direct_page_eeaf;
            data_bank_ef2c = db_ret3;
            goto shared_EF2C;
        } else {
            uint16_t value35 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf + 2));
            BUS16_SET(c, (db_ret3 << 0x10) + 0x0A + value35, x_ret8);
            BUS16_SET(c, (db_ret3 << 0x10) + 0x0C + value35, 0x2BED);
            BUS16_SET(c, (db_ret3 << 0x10) + 0x0E + value35, 0x2BF2);
            a_hi_ef2c2 = 0x2B;
            x_ef2c2 = value35;
            y_ef2c2 = x_ret8;
            direct_page_ef2c2 = direct_page_eeaf;
            data_bank_ef2c2 = db_ret3;
            goto shared_EF2C_1;
        }
    }
    shared_EEAF_1:;
    BUS16_SET(c, (uint16_t)(direct_page_eeaf2 + 4), x_eeaf2);
    uint8_t value36 = BUS8_RDP(c, (data_bank_eeaf2 << 0x10) + x_eeaf2);
    uint16_t value37 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf2 + 2));
    uint8_t value38 = BUS8_RDP(c, (data_bank_eeaf2 << 0x10) + 0x24 + value37);
    uint8_t value39 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 6));
    uint8_t value40 = BUS8_RDP(c, (data_bank_eeaf2 << 0x10) + 0x20 + value37);
    uint8_t value41 = BUS8_RDP(c, (data_bank_eeaf2 << 0x10) + 0x22 + value37);
    uint16_t value42 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf2 + 7));
    r->a = (value36 << 8) | (uint8_t)(value38 + value39);
    r->x = (value40 << 8) | value41;
    r->y = value42;
    r->c = value38 + value39 > 0xFF;
    r->z = value42 == 0;
    r->n = value42 & 0x8000;
    r->v = ((value38 ^ (uint8_t)(value38 + value39)) & (value39 ^ (uint8_t)(value38 + value39)) & 0x80) != 0;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_eeaf2;
    r->dp = direct_page_eeaf2;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEECD, 0xD3ED5F); GUARD_JSR(c, sp_call, 0xEECD); } /* construct_temporary_spell_sprite_object */
    r->sp += 12;
    uint8_t db_ret4 = r->db;
    if (r->mf != 0) { c->fail = 3; return; }
    bool x_ret9 = r->xf;
    uint16_t x_ret10 = r->x;
    if (x_ret9) {
        uint8_t value43 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 4));
        BUS16_SET(c, (db_ret4 << 0x10) + 2 + value43, (uint8_t)x_ret10);
        BUS16_SET(c, (db_ret4 << 0x10) + 4 + value43, 0x2BED);
        BUS16_SET(c, (db_ret4 << 0x10) + 6 + value43, 0x2BF2);
        uint8_t value44 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 6));
        BUS8_SET(c, (uint16_t)(direct_page_eeaf2 + 6), (uint8_t)(value44 + 0x40));
        uint8_t value45 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_eeaf2 + 1), (uint8_t)(value45 - 1));
        if ((uint8_t)(value45 - 1) != 0) {
            a_hi_eeaf = value43 + 8 >> 8;
            x_eeaf = (uint8_t)(value43 + 8);
            direct_page_eeaf = direct_page_eeaf2;
            data_bank_eeaf = db_ret4;
            goto shared_EEAF;
        }
        uint8_t value46 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 2));
        uint8_t value47 = BUS8_RDP(c, (db_ret4 << 0x10) + 2 + value46);
        BUS8_SET(c, (db_ret4 << 0x10) + 0x023D + value47, 2);
        uint8_t value48 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x0A + value46);
        if (value48 != 0) {
            a_hi_ef2c = value43 + 8 >> 8;
            x_ef2c = value46;
            y_ef2c = value48;
            direct_page_ef2c = direct_page_eeaf2;
            data_bank_ef2c = db_ret4;
            goto shared_EF2C;
        }
        uint8_t value49 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x20 + value46);
        uint8_t value50 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x22 + value46);
        uint8_t value51 = BUS8_RDP(c, (db_ret4 << 0x10) + 8 + value46);
        uint8_t value52 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x24 + value46);
        r->a = (value51 << 8) | value52;
        r->x = (uint8_t)((value49 << 8) | value50);
        r->y = (uint8_t)((value49 << 8) | value50);
        r->c = value44 + 0x40 > 0xFF;
        r->z = (uint8_t)((value49 << 8) | value50) == 0;
        r->n = (uint8_t)((value49 << 8) | value50) & 0x80;
        r->v = ((value44 ^ (uint8_t)(value44 + 0x40)) & ((uint8_t)(value44 + 0x40) ^ 0x40) & 0x80) != 0;
        r->mf = 1;
        r->xf = 1;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEF14, 0xD3ED5F); GUARD_JSR(c, sp_call, 0xEF14); } /* construct_temporary_spell_sprite_object */
        r->sp += 12;
        uint8_t db_ret5 = r->db;
        bool x_ret11 = r->xf;
        uint16_t x_ret12 = r->x;
        if (x_ret11) {
            uint8_t value53 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 2));
            BUS16_SET(c, (db_ret5 << 0x10) + 0x0A + value53, (uint8_t)x_ret12);
            BUS16_SET(c, (db_ret5 << 0x10) + 0x0C + value53, 0x2BED);
            BUS16_SET(c, (db_ret5 << 0x10) + 0x0E + value53, 0x2BF2);
            a_hi_ef2c = 0x2B;
            x_ef2c = value53;
            y_ef2c = (uint8_t)x_ret12;
            direct_page_ef2c = direct_page_eeaf2;
            data_bank_ef2c = db_ret5;
            goto shared_EF2C;
        } else {
            uint16_t value54 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf2 + 2));
            BUS16_SET(c, (db_ret5 << 0x10) + 0x0A + value54, x_ret12);
            BUS16_SET(c, (db_ret5 << 0x10) + 0x0C + value54, 0x2BED);
            BUS16_SET(c, (db_ret5 << 0x10) + 0x0E + value54, 0x2BF2);
            a_hi_ef2c2 = 0x2B;
            x_ef2c2 = value54;
            y_ef2c2 = x_ret12;
            direct_page_ef2c2 = direct_page_eeaf2;
            data_bank_ef2c2 = db_ret5;
            goto shared_EF2C_1;
        }
    } else {
        uint16_t value55 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf2 + 4));
        BUS16_SET(c, (db_ret4 << 0x10) + 2 + value55, x_ret10);
        BUS16_SET(c, (db_ret4 << 0x10) + 4 + value55, 0x2BED);
        BUS16_SET(c, (db_ret4 << 0x10) + 6 + value55, 0x2BF2);
        uint8_t value56 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 6));
        BUS8_SET(c, (uint16_t)(direct_page_eeaf2 + 6), (uint8_t)(value56 + 0x40));
        uint8_t value57 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 1));
        BUS8_SET(c, (uint16_t)(direct_page_eeaf2 + 1), (uint8_t)(value57 - 1));
        if ((uint8_t)(value57 - 1) != 0) {
            a_hi_eeaf2 = (uint16_t)(value55 + 8) >> 8;
            x_eeaf2 = (uint16_t)(value55 + 8);
            data_bank_eeaf2 = db_ret4;
            goto shared_EEAF_1;
        }
        uint16_t value58 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf2 + 2));
        uint16_t value59 = BUS16_RDP(c, (db_ret4 << 0x10) + 2 + value58);
        BUS8_SET(c, (db_ret4 << 0x10) + 0x023D + value59, 2);
        uint16_t value60 = BUS16_RDP(c, (db_ret4 << 0x10) + 0x0A + value58);
        if (value60 != 0) {
            a_hi_ef2c2 = (uint16_t)(value55 + 8) >> 8;
            x_ef2c2 = value58;
            y_ef2c2 = value60;
            direct_page_ef2c2 = direct_page_eeaf2;
            data_bank_ef2c2 = db_ret4;
            goto shared_EF2C_1;
        }
        uint8_t value61 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x20 + value58);
        uint8_t value62 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x22 + value58);
        uint8_t value63 = BUS8_RDP(c, (db_ret4 << 0x10) + 8 + value58);
        uint8_t value64 = BUS8_RDP(c, (db_ret4 << 0x10) + 0x24 + value58);
        r->a = (value63 << 8) | value64;
        r->x = (value61 << 8) | value62;
        r->y = (value61 << 8) | value62;
        r->c = value56 + 0x40 > 0xFF;
        r->z = ((value61 << 8) | value62) == 0;
        r->n = ((value61 << 8) | value62) & 0x8000;
        r->v = ((value56 ^ (uint8_t)(value56 + 0x40)) & ((uint8_t)(value56 + 0x40) ^ 0x40) & 0x80) != 0;
        r->mf = 1;
        r->xf = 0;
        r->sp -= 12;
        { const uint16_t sp_call = r->sp; JSR(c, 0xEF14, 0xD3ED5F); GUARD_JSR(c, sp_call, 0xEF14); } /* construct_temporary_spell_sprite_object */
        r->sp += 12;
        uint8_t db_ret6 = r->db;
        bool x_ret13 = r->xf;
        uint16_t x_ret14 = r->x;
        if (x_ret13) {
            uint8_t value65 = BUS8_RDP(c, (uint16_t)(direct_page_eeaf2 + 2));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x0A + value65, (uint8_t)x_ret14);
            BUS16_SET(c, (db_ret6 << 0x10) + 0x0C + value65, 0x2BED);
            BUS16_SET(c, (db_ret6 << 0x10) + 0x0E + value65, 0x2BF2);
            a_hi_ef2c = 0x2B;
            x_ef2c = value65;
            y_ef2c = (uint8_t)x_ret14;
            direct_page_ef2c = direct_page_eeaf2;
            data_bank_ef2c = db_ret6;
            goto shared_EF2C;
        } else {
            uint16_t value66 = BUS16_RDP(c, (uint16_t)(direct_page_eeaf2 + 2));
            BUS16_SET(c, (db_ret6 << 0x10) + 0x0A + value66, x_ret14);
            BUS16_SET(c, (db_ret6 << 0x10) + 0x0C + value66, 0x2BED);
            BUS16_SET(c, (db_ret6 << 0x10) + 0x0E + value66, 0x2BF2);
            a_hi_ef2c2 = 0x2B;
            x_ef2c2 = value66;
            y_ef2c2 = x_ret14;
            direct_page_ef2c2 = direct_page_eeaf2;
            data_bank_ef2c2 = db_ret6;
            goto shared_EF2C_1;
        }
    }
    shared_EF2C:;
    BUS8_SET(c, (data_bank_ef2c << 0x10) + 0x023D + y_ef2c, 3);
    uint8_t value67 = BUS8_RDP(c, (data_bank_ef2c << 0x10) + 0x12 + x_ef2c);
    if (value67 != 0) {
        a_hi_ef63 = a_hi_ef2c;
        y_ef63 = value67;
        direct_page_ef63 = direct_page_ef2c;
        data_bank_ef63 = data_bank_ef2c;
        goto shared_EF63;
    }
    uint8_t value68 = BUS8_RDP(c, (data_bank_ef2c << 0x10) + 0x20 + x_ef2c);
    uint8_t value69 = BUS8_RDP(c, (data_bank_ef2c << 0x10) + 0x22 + x_ef2c);
    uint8_t value70 = BUS8_RDP(c, (data_bank_ef2c << 0x10) + 0x10 + x_ef2c);
    uint8_t value71 = BUS8_RDP(c, (data_bank_ef2c << 0x10) + 0x24 + x_ef2c);
    r->a = (value70 << 8) | (uint8_t)(value71 + 0x40);
    r->x = (uint8_t)((value68 << 8) | value69);
    r->y = (uint8_t)((value68 << 8) | value69);
    r->c = value71 + 0x40 > 0xFF;
    r->z = (uint8_t)((value68 << 8) | value69) == 0;
    r->n = (uint8_t)((value68 << 8) | value69) & 0x80;
    r->v = ((value71 ^ (uint8_t)(value71 + 0x40)) & ((uint8_t)(value71 + 0x40) ^ 0x40) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_ef2c;
    r->dp = direct_page_ef2c;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEF4B, 0xD3ED5F); GUARD_JSR(c, sp_call, 0xEF4B); } /* construct_temporary_spell_sprite_object */
    r->sp += 12;
    uint8_t db_ret7 = r->db;
    bool x_ret15 = r->xf;
    uint16_t x_ret16 = r->x;
    if (x_ret15) {
        uint8_t value72 = BUS8_RDP(c, (uint16_t)(direct_page_ef2c + 2));
        BUS16_SET(c, (db_ret7 << 0x10) + 0x12 + value72, (uint8_t)x_ret16);
        BUS16_SET(c, (db_ret7 << 0x10) + 0x14 + value72, 0x2BED);
        BUS16_SET(c, (db_ret7 << 0x10) + 0x16 + value72, 0x2BF2);
        a_hi_ef63 = 0x2B;
        y_ef63 = (uint8_t)x_ret16;
        direct_page_ef63 = direct_page_ef2c;
        data_bank_ef63 = db_ret7;
        goto shared_EF63;
    } else {
        uint16_t value73 = BUS16_RDP(c, (uint16_t)(direct_page_ef2c + 2));
        BUS16_SET(c, (db_ret7 << 0x10) + 0x12 + value73, x_ret16);
        BUS16_SET(c, (db_ret7 << 0x10) + 0x14 + value73, 0x2BED);
        BUS16_SET(c, (db_ret7 << 0x10) + 0x16 + value73, 0x2BF2);
        a_hi_ef632 = 0x2B;
        y_ef632 = x_ret16;
        direct_page_ef632 = direct_page_ef2c;
        data_bank_ef632 = db_ret7;
        goto shared_EF63_1;
    }
    shared_EF2C_1:;
    BUS8_SET(c, (data_bank_ef2c2 << 0x10) + 0x023D + y_ef2c2, 3);
    uint16_t value74 = BUS16_RDP(c, (data_bank_ef2c2 << 0x10) + 0x12 + x_ef2c2);
    if (value74 != 0) {
        a_hi_ef632 = a_hi_ef2c2;
        y_ef632 = value74;
        direct_page_ef632 = direct_page_ef2c2;
        data_bank_ef632 = data_bank_ef2c2;
        goto shared_EF63_1;
    }
    uint8_t value75 = BUS8_RDP(c, (data_bank_ef2c2 << 0x10) + 0x20 + x_ef2c2);
    uint8_t value76 = BUS8_RDP(c, (data_bank_ef2c2 << 0x10) + 0x22 + x_ef2c2);
    uint8_t value77 = BUS8_RDP(c, (data_bank_ef2c2 << 0x10) + 0x10 + x_ef2c2);
    uint8_t value78 = BUS8_RDP(c, (data_bank_ef2c2 << 0x10) + 0x24 + x_ef2c2);
    r->a = (value77 << 8) | (uint8_t)(value78 + 0x40);
    r->x = (value75 << 8) | value76;
    r->y = (value75 << 8) | value76;
    r->c = value78 + 0x40 > 0xFF;
    r->z = ((value75 << 8) | value76) == 0;
    r->n = ((value75 << 8) | value76) & 0x8000;
    r->v = ((value78 ^ (uint8_t)(value78 + 0x40)) & ((uint8_t)(value78 + 0x40) ^ 0x40) & 0x80) != 0;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_ef2c2;
    r->dp = direct_page_ef2c2;
    r->sp -= 12;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEF4B, 0xD3ED5F); GUARD_JSR(c, sp_call, 0xEF4B); } /* construct_temporary_spell_sprite_object */
    r->sp += 12;
    uint8_t db_ret8 = r->db;
    bool x_ret17 = r->xf;
    uint16_t x_ret18 = r->x;
    if (x_ret17) {
        uint8_t value79 = BUS8_RDP(c, (uint16_t)(direct_page_ef2c2 + 2));
        BUS16_SET(c, (db_ret8 << 0x10) + 0x12 + value79, (uint8_t)x_ret18);
        BUS16_SET(c, (db_ret8 << 0x10) + 0x14 + value79, 0x2BED);
        BUS16_SET(c, (db_ret8 << 0x10) + 0x16 + value79, 0x2BF2);
        a_hi_ef63 = 0x2B;
        y_ef63 = (uint8_t)x_ret18;
        direct_page_ef63 = direct_page_ef2c2;
        data_bank_ef63 = db_ret8;
        goto shared_EF63;
    } else {
        uint16_t value80 = BUS16_RDP(c, (uint16_t)(direct_page_ef2c2 + 2));
        BUS16_SET(c, (db_ret8 << 0x10) + 0x12 + value80, x_ret18);
        BUS16_SET(c, (db_ret8 << 0x10) + 0x14 + value80, 0x2BED);
        BUS16_SET(c, (db_ret8 << 0x10) + 0x16 + value80, 0x2BF2);
        a_hi_ef632 = 0x2B;
        y_ef632 = x_ret18;
        direct_page_ef632 = direct_page_ef2c2;
        data_bank_ef632 = db_ret8;
        goto shared_EF63_1;
    }
    shared_EF63:;
    BUS8_SET(c, (data_bank_ef63 << 0x10) + 0x023D + y_ef63, 6);
    uint8_t value81 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value82 = RAM8(0x0000 + sp0 - 2);
    uint8_t value83 = RAM8(0x0000 + sp0 - 1);
    uint8_t value84 = RAM8(0x0000 + sp0);
    r->mf = value82 & 0x20;
    r->xf = value82 & 0x10;
    r->db = value81;
    r->dp = (value84 << 8) | value83;
    r->i = value82 & 0x04;
    r->d = value82 & 0x08;
    RETURN_RTS(c);
    shared_EF63_1:;
    BUS8_SET(c, (data_bank_ef632 << 0x10) + 0x023D + y_ef632, 6);
    uint8_t value85 = RAM8(0x0000 + sp0 - 0x0B);
    uint8_t value86 = RAM8(0x0000 + sp0 - 2);
    uint8_t value87 = RAM8(0x0000 + sp0 - 1);
    uint8_t value88 = RAM8(0x0000 + sp0);
    r->mf = value86 & 0x20;
    r->xf = value86 & 0x10;
    r->db = value85;
    r->dp = (value88 << 8) | value87;
    r->i = value86 & 0x04;
    r->d = value86 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3EE60, SOM_RTS, "gen", initialize_spell_entity_summon_sprites, 0, 0, 13, 1, 0, 276, 134)

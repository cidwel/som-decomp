#include "som_c.h"

/* D3EA04 initialize_spell_entity_burst_sprites   [class B, 143 bytes, 69 instructions]
 * Source: src/rom/initialize_spell_entity_burst_sprites.s
 * Documented in docs/actor-cast-entity-burst-init.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: nothing.
 */
static void initialize_spell_entity_burst_sprites(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;   /* the entry width of A is dead (PHD / PHP / REP #$20 first); callers enter with M=8 and M=16 */
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 0x0A) + 0x7 > 0x1FFF) { c->fail = 3; return; }
    uint8_t a_hi_ea58 = 0;
    uint8_t x_ea58 = 0;
    uint8_t y_ea58 = 0;
    bool carry_ea58 = 0;
    bool overflow_ea58 = 0;
    uint16_t direct_page_ea58 = 0;
    uint8_t data_bank_ea58 = 0;
    uint8_t a_hi_ea582 = 0;
    uint16_t x_ea582 = 0;
    uint16_t y_ea582 = 0;
    bool carry_ea582 = 0;
    bool overflow_ea582 = 0;
    uint16_t direct_page_ea582 = 0;
    uint8_t data_bank_ea582 = 0;
    uint16_t direct_page_ea87 = 0;
    uint8_t data_bank_ea87 = 0;
    uint16_t direct_page_ea872 = 0;
    uint8_t data_bank_ea872 = 0;
    uint16_t direct_page_ea873 = 0;
    uint8_t data_bank_ea873 = 0;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | (r->mf ? 0x20 : 0)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 0x0A) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    uint16_t value = RAM16(0x002C + y);
    if (value == 0) {
        RAM16_SET(0x0002 + (uint16_t)(sp0 - 0x0A), y);
        r->x = 0xF81E;
        r->c = (uint16_t)(sp0 - 3) >= 7;
        r->z = 0;
        r->n = 1;
        r->v = (((uint16_t)(sp0 - 3) ^ 7) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
        r->mf = 0;
        r->dp = (uint16_t)(sp0 - 0x0A);
        r->sp -= 11;
        { const uint16_t sp_call = r->sp; JSL(c, 0xEA30, 0xC12E90); GUARD_JSL(c, sp_call, 0xEA30); } /* construct_spell_graphics_audio_resources_long */
        r->sp += 11;
        bool x_ret = r->xf;
        uint16_t x_ret2 = r->x;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        if (x_ret) {
            RAM8(0x0006 + (uint16_t)(sp0 - 0x0A)) = (uint8_t)x_ret2;
            uint8_t value2 = RAM8(0x0002 + (uint16_t)(sp0 - 0x0A));
            RAM16_SET(0x001A + value2, (uint8_t)x_ret2);
            RAM16_SET(0x002C + value2, 1);
            RAM16_SET(0x002A + value2, 0);
            RAM16_SET(0x001C + value2, 0x3711);
            RAM16_SET(0x001E + value2, 0x345A);
            RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = RAM8(0x0027 + value2);
            a_hi_ea58 = 0x34;
            x_ea58 = value2;
            y_ea58 = (uint8_t)y_ret;
            carry_ea58 = carry_ret;
            overflow_ea58 = overflow_ret;
            direct_page_ea58 = (uint16_t)(sp0 - 0x0A);
            data_bank_ea58 = 0x7E;
            goto shared_EA58;
        } else {
            RAM16_SET(0x0006 + (uint16_t)(sp0 - 0x0A), x_ret2);
            uint16_t value4 = RAM16(0x0002 + (uint16_t)(sp0 - 0x0A));
            RAM16_SET(0x001A + value4, x_ret2);
            RAM16_SET(0x002C + value4, 1);
            RAM16_SET(0x002A + value4, 0);
            RAM16_SET(0x001C + value4, 0x3711);
            RAM16_SET(0x001E + value4, 0x345A);
            RAM8(0x0001 + (uint16_t)(sp0 - 0x0A)) = RAM8(0x0027 + value4);
            a_hi_ea582 = 0x34;
            x_ea582 = value4;
            y_ea582 = y_ret;
            carry_ea582 = carry_ret;
            overflow_ea582 = overflow_ret;
            direct_page_ea582 = (uint16_t)(sp0 - 0x0A);
            data_bank_ea582 = 0x7E;
            goto shared_EA58_1;
        }
    }
    RAM8(0x0000 + sp0 - 0x0B) = y >> 8;
    RAM8(0x0000 + sp0 - 0x0C) = (uint8_t)y;
    r->c = (uint16_t)(sp0 - 3) >= 7;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->v = (((uint16_t)(sp0 - 3) ^ 7) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0A)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x0A);
    r->sp -= 13;
    { const uint16_t sp_call = r->sp; JSL(c, 0xEA21, 0xC12C15); GUARD_JSL(c, sp_call, 0xEA21); } /* initialize_spell_entity_twin_family_long */
    r->sp += 13;
    bool m_ret = r->mf;
    uint8_t value6 = RAM8(0x0000 + sp0 - 0x0C);
    uint8_t value7 = RAM8(0x0000 + sp0 - 0x0B);
    if (m_ret) {
        RAM8(0x002C + ((value7 << 8) | value6)) = 0;
        direct_page_ea87 = (uint16_t)(sp0 - 0x0A);
        data_bank_ea87 = 0x7E;
        goto shared_EA87;
    } else {
        RAM16_SET(0x002C + ((value7 << 8) | value6), 0);
        direct_page_ea872 = (uint16_t)(sp0 - 0x0A);
        data_bank_ea872 = 0x7E;
        goto shared_EA87_1;
    }
    shared_EA58:;
    RAM8(0x0004 + direct_page_ea58) = x_ea58;
    uint8_t value8 = BUS8_RDP(c, (data_bank_ea58 << 0x10) + x_ea58);
    uint8_t value9 = RAM8(0x0006 + direct_page_ea58);
    r->a = (a_hi_ea58 << 8) | value8;
    r->x = value9;
    r->y = y_ea58;
    r->c = carry_ea58;
    r->z = value9 == 0;
    r->n = value9 & 0x80;
    r->v = overflow_ea58;
    r->mf = 1;
    r->xf = 1;
    r->db = data_bank_ea58;
    r->dp = direct_page_ea58;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEA61, 0xD3EB83); GUARD_JSR(c, sp_call, 0xEA61); } /* construct_spell_entity_burst_sprite_object */
    r->sp += 11;
    uint8_t db_ret = r->db;
    bool m_ret2 = r->mf;
    bool x_ret4 = r->xf;
    uint16_t x_ret5 = r->x;
    uint16_t y_ret3 = r->y;
    if (m_ret2) {
        BUS8_SET(c, (db_ret << 0x10) + 0x56 + x_ret5, RAM8(0x0001 + direct_page_ea58));
        if (x_ret4) {
            uint8_t value11 = RAM8(0x0004 + direct_page_ea58);
            BUS16_SET(c, (db_ret << 0x10) + 2 + value11, (uint8_t)x_ret5);
            BUS16_SET(c, (db_ret << 0x10) + 4 + value11, 0x2805);
            BUS16_SET(c, (db_ret << 0x10) + 6 + value11, 0x280A);
            RAM8(0x0001 + direct_page_ea58)--;
            if (RAM8(0x0001 + direct_page_ea58) != 0) {
                a_hi_ea58 = value11 + 8 >> 8;
                x_ea58 = (uint8_t)(value11 + 8);
                y_ea58 = (uint8_t)y_ret3;
                carry_ea58 = value11 + 8 > 0xFFFF;
                overflow_ea58 = ((value11 ^ value11 + 8) & (value11 + 8 ^ 8) & 0x8000) != 0;
                data_bank_ea58 = db_ret;
                goto shared_EA58;
            }
            direct_page_ea873 = direct_page_ea58;
            data_bank_ea873 = db_ret;
            goto shared_EA87_2;
        } else {
            uint16_t value12 = RAM16(0x0004 + direct_page_ea58);
            BUS16_SET(c, (db_ret << 0x10) + 2 + value12, x_ret5);
            BUS16_SET(c, (db_ret << 0x10) + 4 + value12, 0x2805);
            BUS16_SET(c, (db_ret << 0x10) + 6 + value12, 0x280A);
            RAM8(0x0001 + direct_page_ea58)--;
            if (RAM8(0x0001 + direct_page_ea58) != 0) {
                a_hi_ea582 = (uint16_t)(value12 + 8) >> 8;
                x_ea582 = (uint16_t)(value12 + 8);
                y_ea582 = y_ret3;
                carry_ea582 = value12 + 8 > 0xFFFF;
                overflow_ea582 = ((value12 ^ (uint16_t)(value12 + 8)) & ((uint16_t)(value12 + 8) ^ 8) & 0x8000) != 0;
                direct_page_ea582 = direct_page_ea58;
                data_bank_ea582 = db_ret;
                goto shared_EA58_1;
            }
            direct_page_ea87 = direct_page_ea58;
            data_bank_ea87 = db_ret;
            goto shared_EA87;
        }
    } else {
        BUS16_SET(c, (db_ret << 0x10) + 0x56 + x_ret5, RAM16(0x0001 + direct_page_ea58));
        if (x_ret4) {
            uint8_t value14 = RAM8(0x0004 + direct_page_ea58);
            BUS16_SET(c, (db_ret << 0x10) + 2 + value14, (uint8_t)x_ret5);
            BUS16_SET(c, (db_ret << 0x10) + 4 + value14, 0x2805);
            BUS16_SET(c, (db_ret << 0x10) + 6 + value14, 0x280A);
            RAM8(0x0001 + direct_page_ea58)--;
            if (RAM8(0x0001 + direct_page_ea58) != 0) {
                a_hi_ea58 = value14 + 8 >> 8;
                x_ea58 = (uint8_t)(value14 + 8);
                y_ea58 = (uint8_t)y_ret3;
                carry_ea58 = value14 + 8 > 0xFFFF;
                overflow_ea58 = ((value14 ^ value14 + 8) & (value14 + 8 ^ 8) & 0x8000) != 0;
                data_bank_ea58 = db_ret;
                goto shared_EA58;
            }
            direct_page_ea873 = direct_page_ea58;
            data_bank_ea873 = db_ret;
            goto shared_EA87_2;
        } else {
            uint16_t value15 = RAM16(0x0004 + direct_page_ea58);
            BUS16_SET(c, (db_ret << 0x10) + 2 + value15, x_ret5);
            BUS16_SET(c, (db_ret << 0x10) + 4 + value15, 0x2805);
            BUS16_SET(c, (db_ret << 0x10) + 6 + value15, 0x280A);
            RAM8(0x0001 + direct_page_ea58)--;
            if (RAM8(0x0001 + direct_page_ea58) != 0) {
                a_hi_ea582 = (uint16_t)(value15 + 8) >> 8;
                x_ea582 = (uint16_t)(value15 + 8);
                y_ea582 = y_ret3;
                carry_ea582 = value15 + 8 > 0xFFFF;
                overflow_ea582 = ((value15 ^ (uint16_t)(value15 + 8)) & ((uint16_t)(value15 + 8) ^ 8) & 0x8000) != 0;
                direct_page_ea582 = direct_page_ea58;
                data_bank_ea582 = db_ret;
                goto shared_EA58_1;
            }
            direct_page_ea87 = direct_page_ea58;
            data_bank_ea87 = db_ret;
            goto shared_EA87;
        }
    }
    shared_EA58_1:;
    RAM16_SET(0x0004 + direct_page_ea582, x_ea582);
    uint8_t value16 = BUS8_RDP(c, (data_bank_ea582 << 0x10) + x_ea582);
    uint16_t value17 = RAM16(0x0006 + direct_page_ea582);
    r->a = (a_hi_ea582 << 8) | value16;
    r->x = value17;
    r->y = y_ea582;
    r->c = carry_ea582;
    r->z = value17 == 0;
    r->n = value17 & 0x8000;
    r->v = overflow_ea582;
    r->mf = 1;
    r->xf = 0;
    r->db = data_bank_ea582;
    r->dp = direct_page_ea582;
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xEA61, 0xD3EB83); GUARD_JSR(c, sp_call, 0xEA61); } /* construct_spell_entity_burst_sprite_object */
    r->sp += 11;
    uint8_t db_ret2 = r->db;
    bool m_ret3 = r->mf;
    bool x_ret6 = r->xf;
    uint16_t x_ret7 = r->x;
    uint16_t y_ret4 = r->y;
    if (m_ret3) {
        BUS8_SET(c, (db_ret2 << 0x10) + 0x56 + x_ret7, RAM8(0x0001 + direct_page_ea582));
        if (x_ret6) {
            uint8_t value19 = RAM8(0x0004 + direct_page_ea582);
            BUS16_SET(c, (db_ret2 << 0x10) + 2 + value19, (uint8_t)x_ret7);
            BUS16_SET(c, (db_ret2 << 0x10) + 4 + value19, 0x2805);
            BUS16_SET(c, (db_ret2 << 0x10) + 6 + value19, 0x280A);
            RAM8(0x0001 + direct_page_ea582)--;
            if (RAM8(0x0001 + direct_page_ea582) != 0) {
                a_hi_ea58 = value19 + 8 >> 8;
                x_ea58 = (uint8_t)(value19 + 8);
                y_ea58 = (uint8_t)y_ret4;
                carry_ea58 = value19 + 8 > 0xFFFF;
                overflow_ea58 = ((value19 ^ value19 + 8) & (value19 + 8 ^ 8) & 0x8000) != 0;
                direct_page_ea58 = direct_page_ea582;
                data_bank_ea58 = db_ret2;
                goto shared_EA58;
            }
            direct_page_ea873 = direct_page_ea582;
            data_bank_ea873 = db_ret2;
            goto shared_EA87_2;
        } else {
            uint16_t value20 = RAM16(0x0004 + direct_page_ea582);
            BUS16_SET(c, (db_ret2 << 0x10) + 2 + value20, x_ret7);
            BUS16_SET(c, (db_ret2 << 0x10) + 4 + value20, 0x2805);
            BUS16_SET(c, (db_ret2 << 0x10) + 6 + value20, 0x280A);
            RAM8(0x0001 + direct_page_ea582)--;
            if (RAM8(0x0001 + direct_page_ea582) != 0) {
                a_hi_ea582 = (uint16_t)(value20 + 8) >> 8;
                x_ea582 = (uint16_t)(value20 + 8);
                y_ea582 = y_ret4;
                carry_ea582 = value20 + 8 > 0xFFFF;
                overflow_ea582 = ((value20 ^ (uint16_t)(value20 + 8)) & ((uint16_t)(value20 + 8) ^ 8) & 0x8000) != 0;
                data_bank_ea582 = db_ret2;
                goto shared_EA58_1;
            }
            direct_page_ea87 = direct_page_ea582;
            data_bank_ea87 = db_ret2;
            goto shared_EA87;
        }
    } else {
        BUS16_SET(c, (db_ret2 << 0x10) + 0x56 + x_ret7, RAM16(0x0001 + direct_page_ea582));
        if (x_ret6) {
            uint8_t value22 = RAM8(0x0004 + direct_page_ea582);
            BUS16_SET(c, (db_ret2 << 0x10) + 2 + value22, (uint8_t)x_ret7);
            BUS16_SET(c, (db_ret2 << 0x10) + 4 + value22, 0x2805);
            BUS16_SET(c, (db_ret2 << 0x10) + 6 + value22, 0x280A);
            RAM8(0x0001 + direct_page_ea582)--;
            if (RAM8(0x0001 + direct_page_ea582) != 0) {
                a_hi_ea58 = value22 + 8 >> 8;
                x_ea58 = (uint8_t)(value22 + 8);
                y_ea58 = (uint8_t)y_ret4;
                carry_ea58 = value22 + 8 > 0xFFFF;
                overflow_ea58 = ((value22 ^ value22 + 8) & (value22 + 8 ^ 8) & 0x8000) != 0;
                direct_page_ea58 = direct_page_ea582;
                data_bank_ea58 = db_ret2;
                goto shared_EA58;
            }
            direct_page_ea873 = direct_page_ea582;
            data_bank_ea873 = db_ret2;
            goto shared_EA87_2;
        } else {
            uint16_t value23 = RAM16(0x0004 + direct_page_ea582);
            BUS16_SET(c, (db_ret2 << 0x10) + 2 + value23, x_ret7);
            BUS16_SET(c, (db_ret2 << 0x10) + 4 + value23, 0x2805);
            BUS16_SET(c, (db_ret2 << 0x10) + 6 + value23, 0x280A);
            RAM8(0x0001 + direct_page_ea582)--;
            if (RAM8(0x0001 + direct_page_ea582) != 0) {
                a_hi_ea582 = (uint16_t)(value23 + 8) >> 8;
                x_ea582 = (uint16_t)(value23 + 8);
                y_ea582 = y_ret4;
                carry_ea582 = value23 + 8 > 0xFFFF;
                overflow_ea582 = ((value23 ^ (uint16_t)(value23 + 8)) & ((uint16_t)(value23 + 8) ^ 8) & 0x8000) != 0;
                data_bank_ea582 = db_ret2;
                goto shared_EA58_1;
            }
            direct_page_ea87 = direct_page_ea582;
            data_bank_ea87 = db_ret2;
            goto shared_EA87;
        }
    }
    shared_EA87:;
    uint8_t value24 = RAM8(0x0000 + sp0 - 0x0A);
    uint8_t value25 = RAM8(0x0000 + sp0 - 2);
    uint8_t value26 = RAM8(0x0000 + sp0 - 1);
    uint8_t value27 = RAM8(0x0000 + sp0);
    r->mf = value25 & 0x20;
    r->xf = value25 & 0x10;
    r->db = value24;
    r->dp = (value27 << 8) | value26;
    r->i = value25 & 0x04;
    r->d = value25 & 0x08;
    RETURN_RTS(c);
    shared_EA87_1:;
    uint8_t value28 = RAM8(0x0000 + sp0 - 0x0A);
    uint8_t value29 = RAM8(0x0000 + sp0 - 2);
    uint8_t value30 = RAM8(0x0000 + sp0 - 1);
    uint8_t value31 = RAM8(0x0000 + sp0);
    r->mf = value29 & 0x20;
    r->xf = value29 & 0x10;
    r->db = value28;
    r->dp = (value31 << 8) | value30;
    r->i = value29 & 0x04;
    r->d = value29 & 0x08;
    RETURN_RTS(c);
    shared_EA87_2:;
    uint8_t value32 = RAM8(0x0000 + sp0 - 0x0A);
    uint8_t value33 = RAM8(0x0000 + sp0 - 2);
    uint8_t value34 = RAM8(0x0000 + sp0 - 1);
    uint8_t value35 = RAM8(0x0000 + sp0);
    r->mf = value33 & 0x20;
    r->xf = value33 & 0x10;
    r->db = value32;
    r->dp = (value35 << 8) | value34;
    r->i = value33 & 0x04;
    r->d = value33 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD3EA04, SOM_RTS, "hand", initialize_spell_entity_burst_sprites, 0, 0, 13, -1, 0, 143, 69)

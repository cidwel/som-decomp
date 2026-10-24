#include "som_c.h"

/* D3F0B1 derive_spell_sprite_object_target_vectors   [class B, 168 bytes, 87 instructions]
 * Source: src/rom/derive_spell_sprite_object_target_vectors.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: XY.
 */
static void derive_spell_sprite_object_target_vectors(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 0x0F) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x0F), x);
    r->a = (RAM8(0x0238 + x) << 8) | 0x52;
    r->c = (uint16_t)(sp0 - 3) >= 0x0C;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 0x0C) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 0x0F)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 0x0F);
    r->sp -= 15;
    { const uint16_t sp_call = r->sp; JSL(c, 0xF0C9, 0xC12EBD); GUARD_JSL(c, sp_call, 0xF0C9); } /* send_spell_entity_positional_sound_long */
    r->sp += 15;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t y_ret = r->y;
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 0x0230 + value2);
        uint16_t value4 = BUS16_RDP(c, (db_ret << 0x10) + 0x0235 + value2);
        BUS16_SET(c, (uint16_t)(dp_ret + 3), 0);
        uint8_t a1;
        uint8_t a_hi1;
        if (((uint16_t)(value3 - value4) & 0x8000) == 0) {
            a1 = (uint8_t)(value3 - value4);
            a_hi1 = (uint16_t)(value3 - value4) >> 8;
        } else {
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value5 - 1));
            a1 = (uint8_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1);
            a_hi1 = (uint16_t)(((uint16_t)(value3 - value4) ^ 0xFFFF) + 1) >> 8;
        }
        uint8_t value6 = BUS8_RDP(c, (db_ret << 0x10) + 0x023A + value2);
        RAM8(0x0000 + sp0 - 0x0F) = a1 >> 1;
        RAM8(0x0000 + sp0 - 0x10) = (uint8_t)((a1 >> 1 << 8) | value6);
        r->a = (a1 >> 1 << 8) | value6;
        r->x = value2;
        r->y = (uint8_t)y_ret;
        r->c = a1 & 0x01;
        r->z = value6 == 0;
        r->n = value6 & 0x80;
        r->v = ((value3 ^ value4) & (value3 ^ (uint16_t)(value3 - value4)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 17;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF0EF, 0xC12EC5); GUARD_JSL(c, sp_call, 0xF0EF); } /* scale_native_spell_sprite_angle_coefficient_long */
        r->sp += 17;
        uint16_t a_all2 = r->a;
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value7 << 1));
        uint8_t a2;
        uint8_t a_hi2;
        if (!(value7 & 0x8000)) {
            a2 = (uint8_t)a_all2;
            a_hi2 = a_all2 >> 8;
        } else {
            a2 = (uint8_t)((a_all2 ^ 0xFFFF) + 1);
            a_hi2 = (uint16_t)((a_all2 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 5), (a_hi2 << 8) | a2);
        uint8_t value8 = RAM8(0x0000 + sp0 - 0x10);
        uint8_t value9 = RAM8(0x0000 + sp0 - 0x0F);
        r->a = (value9 << 8) | value8;
        r->c = value7 & 0x8000;
        r->z = ((value9 << 8) | value8) == 0;
        r->n = ((value9 << 8) | value8) & 0x8000;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 15;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF0FE, 0xC12EC1); GUARD_JSL(c, sp_call, 0xF0FE); } /* scale_native_spell_sprite_quarter_turn_coefficient_long */
        r->sp += 15;
        uint16_t a_all3 = r->a;
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value10 << 1));
        uint8_t a3;
        uint8_t a_hi3;
        if (!(value10 & 0x8000)) {
            a3 = (uint8_t)a_all3;
            a_hi3 = a_all3 >> 8;
        } else {
            a3 = (uint8_t)((a_all3 ^ 0xFFFF) + 1);
            a_hi3 = (uint16_t)((a_all3 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 7), (a_hi3 << 8) | a3);
        uint8_t value11 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        uint16_t value12 = BUS16_RDP(c, (db_ret << 0x10) + 0x0232 + value11);
        uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0x0238 + value11);
        BUS16_SET(c, (uint16_t)(dp_ret + 3), 0);
        uint8_t a4;
        uint8_t a_hi4;
        if (((uint16_t)(value12 - value13) & 0x8000) == 0) {
            a4 = (uint8_t)(value12 - value13);
            a_hi4 = (uint16_t)(value12 - value13) >> 8;
        } else {
            uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value14 - 1));
            a4 = (uint8_t)(((uint16_t)(value12 - value13) ^ 0xFFFF) + 1);
            a_hi4 = (uint16_t)(((uint16_t)(value12 - value13) ^ 0xFFFF) + 1) >> 8;
        }
        uint8_t value15 = BUS8_RDP(c, (db_ret << 0x10) + 0x023A + value11);
        r->a = (a4 >> 1 << 8) | value15;
        r->x = value11;
        r->c = a4 & 0x01;
        r->z = value15 == 0;
        r->n = value15 & 0x80;
        r->v = ((value12 ^ value13) & (value12 ^ (uint16_t)(value12 - value13)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 17;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF12C, 0xC12EC5); GUARD_JSL(c, sp_call, 0xF12C); } /* scale_native_spell_sprite_angle_coefficient_long */
        r->sp += 17;
        uint16_t a_all4 = r->a;
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value16 << 1));
        uint8_t a5;
        uint8_t a_hi5;
        if (!(value16 & 0x8000)) {
            a5 = (uint8_t)a_all4;
            a_hi5 = a_all4 >> 8;
        } else {
            a5 = (uint8_t)((a_all4 ^ 0xFFFF) + 1);
            a_hi5 = (uint16_t)((a_all4 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 9), (a_hi5 << 8) | a5);
        r->a = (a4 >> 1 << 8) | value15;
        r->c = value16 & 0x8000;
        r->z = ((a4 >> 1 << 8) | value15) == 0;
        r->n = ((a4 >> 1 << 8) | value15) & 0x8000;
        r->mf = 0;
        r->xf = 1;
        r->sp -= 15;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF13B, 0xC12EC1); GUARD_JSL(c, sp_call, 0xF13B); } /* scale_native_spell_sprite_quarter_turn_coefficient_long */
        r->sp += 15;
        uint16_t a_all5 = r->a;
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value17 << 1));
        uint8_t a6;
        uint8_t a_hi6;
        if (!(value17 & 0x8000)) {
            a6 = (uint8_t)a_all5;
            a_hi6 = a_all5 >> 8;
        } else {
            a6 = (uint8_t)((a_all5 ^ 0xFFFF) + 1);
            a_hi6 = (uint16_t)((a_all5 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 0x0B), (a_hi6 << 8) | a6);
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret + 7));
        uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret + 9));
        uint8_t value21 = RAM8(0x0000 + sp0 - 2);
        uint8_t value22 = RAM8(0x0000 + sp0 - 1);
        uint8_t value23 = RAM8(0x0000 + sp0);
        r->x = (uint8_t)(((a_hi6 << 8) | a6) + value18);
        r->y = (uint8_t)(value19 - value20);
        r->mf = value21 & 0x20;
        r->xf = value21 & 0x10;
        r->dp = (value23 << 8) | value22;
        r->i = value21 & 0x04;
        r->d = value21 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        uint16_t value25 = BUS16_RDP(c, (db_ret << 0x10) + 0x0230 + value24);
        uint16_t value26 = BUS16_RDP(c, (db_ret << 0x10) + 0x0235 + value24);
        BUS16_SET(c, (uint16_t)(dp_ret + 3), 0);
        uint8_t a7;
        uint8_t a_hi7;
        if (((uint16_t)(value25 - value26) & 0x8000) == 0) {
            a7 = (uint8_t)(value25 - value26);
            a_hi7 = (uint16_t)(value25 - value26) >> 8;
        } else {
            uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value27 - 1));
            a7 = (uint8_t)(((uint16_t)(value25 - value26) ^ 0xFFFF) + 1);
            a_hi7 = (uint16_t)(((uint16_t)(value25 - value26) ^ 0xFFFF) + 1) >> 8;
        }
        uint8_t value28 = BUS8_RDP(c, (db_ret << 0x10) + 0x023A + value24);
        RAM8(0x0000 + sp0 - 0x0F) = a7 >> 1;
        RAM8(0x0000 + sp0 - 0x10) = (uint8_t)((a7 >> 1 << 8) | value28);
        r->a = (a7 >> 1 << 8) | value28;
        r->x = value24;
        r->c = a7 & 0x01;
        r->z = value28 == 0;
        r->n = value28 & 0x80;
        r->v = ((value25 ^ value26) & (value25 ^ (uint16_t)(value25 - value26)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 17;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF0EF, 0xC12EC5); GUARD_JSL(c, sp_call, 0xF0EF); } /* scale_native_spell_sprite_angle_coefficient_long */
        r->sp += 17;
        uint16_t a_all6 = r->a;
        uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value29 << 1));
        uint8_t a8;
        uint8_t a_hi8;
        if (!(value29 & 0x8000)) {
            a8 = (uint8_t)a_all6;
            a_hi8 = a_all6 >> 8;
        } else {
            a8 = (uint8_t)((a_all6 ^ 0xFFFF) + 1);
            a_hi8 = (uint16_t)((a_all6 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 5), (a_hi8 << 8) | a8);
        uint8_t value30 = RAM8(0x0000 + sp0 - 0x10);
        uint8_t value31 = RAM8(0x0000 + sp0 - 0x0F);
        r->a = (value31 << 8) | value30;
        r->c = value29 & 0x8000;
        r->z = ((value31 << 8) | value30) == 0;
        r->n = ((value31 << 8) | value30) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 15;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF0FE, 0xC12EC1); GUARD_JSL(c, sp_call, 0xF0FE); } /* scale_native_spell_sprite_quarter_turn_coefficient_long */
        r->sp += 15;
        uint16_t a_all7 = r->a;
        uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value32 << 1));
        uint8_t a9;
        uint8_t a_hi9;
        if (!(value32 & 0x8000)) {
            a9 = (uint8_t)a_all7;
            a_hi9 = a_all7 >> 8;
        } else {
            a9 = (uint8_t)((a_all7 ^ 0xFFFF) + 1);
            a_hi9 = (uint16_t)((a_all7 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 7), (a_hi9 << 8) | a9);
        uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        uint16_t value34 = BUS16_RDP(c, (db_ret << 0x10) + 0x0232 + value33);
        uint16_t value35 = BUS16_RDP(c, (db_ret << 0x10) + 0x0238 + value33);
        BUS16_SET(c, (uint16_t)(dp_ret + 3), 0);
        uint8_t a10;
        uint8_t a_hi10;
        if (((uint16_t)(value34 - value35) & 0x8000) == 0) {
            a10 = (uint8_t)(value34 - value35);
            a_hi10 = (uint16_t)(value34 - value35) >> 8;
        } else {
            uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
            BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value36 - 1));
            a10 = (uint8_t)(((uint16_t)(value34 - value35) ^ 0xFFFF) + 1);
            a_hi10 = (uint16_t)(((uint16_t)(value34 - value35) ^ 0xFFFF) + 1) >> 8;
        }
        uint8_t value37 = BUS8_RDP(c, (db_ret << 0x10) + 0x023A + value33);
        r->a = (a10 >> 1 << 8) | value37;
        r->x = value33;
        r->c = a10 & 0x01;
        r->z = value37 == 0;
        r->n = value37 & 0x80;
        r->v = ((value34 ^ value35) & (value34 ^ (uint16_t)(value34 - value35)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 17;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF12C, 0xC12EC5); GUARD_JSL(c, sp_call, 0xF12C); } /* scale_native_spell_sprite_angle_coefficient_long */
        r->sp += 17;
        uint16_t a_all8 = r->a;
        uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value38 << 1));
        uint8_t a11;
        uint8_t a_hi11;
        if (!(value38 & 0x8000)) {
            a11 = (uint8_t)a_all8;
            a_hi11 = a_all8 >> 8;
        } else {
            a11 = (uint8_t)((a_all8 ^ 0xFFFF) + 1);
            a_hi11 = (uint16_t)((a_all8 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 9), (a_hi11 << 8) | a11);
        r->a = (a10 >> 1 << 8) | value37;
        r->c = value38 & 0x8000;
        r->z = ((a10 >> 1 << 8) | value37) == 0;
        r->n = ((a10 >> 1 << 8) | value37) & 0x8000;
        r->mf = 0;
        r->xf = 0;
        r->sp -= 15;
        { const uint16_t sp_call = r->sp; JSL(c, 0xF13B, 0xC12EC1); GUARD_JSL(c, sp_call, 0xF13B); } /* scale_native_spell_sprite_quarter_turn_coefficient_long */
        r->sp += 15;
        uint16_t a_all9 = r->a;
        uint16_t value39 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
        BUS16_RMW_SET(c, (uint16_t)(dp_ret + 3), (uint16_t)(value39 << 1));
        uint8_t a12;
        uint8_t a_hi12;
        if (!(value39 & 0x8000)) {
            a12 = (uint8_t)a_all9;
            a_hi12 = a_all9 >> 8;
        } else {
            a12 = (uint8_t)((a_all9 ^ 0xFFFF) + 1);
            a_hi12 = (uint16_t)((a_all9 ^ 0xFFFF) + 1) >> 8;
        }
        BUS16_SET(c, (uint16_t)(dp_ret + 0x0B), (a_hi12 << 8) | a12);
        uint16_t value40 = BUS16_RDP(c, (uint16_t)(dp_ret + 5));
        uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret + 7));
        uint16_t value42 = BUS16_RDP(c, (uint16_t)(dp_ret + 9));
        uint8_t value43 = RAM8(0x0000 + sp0 - 2);
        uint8_t value44 = RAM8(0x0000 + sp0 - 1);
        uint8_t value45 = RAM8(0x0000 + sp0);
        r->x = (uint16_t)(((a_hi12 << 8) | a12) + value40);
        r->y = (uint16_t)(value41 - value42);
        r->mf = value43 & 0x20;
        r->xf = value43 & 0x10;
        r->dp = (value45 << 8) | value44;
        r->i = value43 & 0x04;
        r->d = value43 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xD3F0B1, SOM_RTS, "gen", derive_spell_sprite_object_target_vectors, 0, L_X | L_Y, 17, 1, 0, 168, 87)

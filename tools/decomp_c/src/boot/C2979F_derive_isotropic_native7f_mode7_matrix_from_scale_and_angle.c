#include "som_c.h"

/* C2979F derive_isotropic_native7f_mode7_matrix_from_scale_and_angle   [class B, 94 bytes, 42 instructions]
 * Source: src/rom/derive_isotropic_native7f_mode7_matrix_from_scale_and_angle.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void derive_isotropic_native7f_mode7_matrix_from_scale_and_angle_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t y = r->y;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM16_SET(0x0395, RAM16(0x00B0 + battle_defence_work));
    uint16_t value2 = RAM16(0x00B2 + battle_defence_work);
    r->a = value2;
    r->x = battle_defence_work;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x97AB, 0xC22A60); GUARD_JSR(c, sp_call, 0x97AB); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, (uint16_t)(dp_ret + 0x97), (uint8_t)a_all);
        if (x_ret) {
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xB2 + value3);
            r->a = (a_all >> 8 << 8) | value4;
            r->x = value3;
            r->y = (uint8_t)y;
            r->z = value4 == 0;
            r->n = value4 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97B5, 0xC22A59); GUARD_JSR(c, sp_call, 0x97B5); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all2 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all2);
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value5);
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value6);
            r->a = value6;
            r->z = value6 == 0;
            r->n = value6 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97C2, 0xC22B94); GUARD_JSR(c, sp_call, 0x97C2); } /* multiply_signed_words_to_double_word */
            uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9B), value7);
            uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value8);
            uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value9);
            r->a = value9;
            r->z = value9 == 0;
            r->n = value9 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97D1, 0xC22B94); GUARD_JSR(c, sp_call, 0x97D1); } /* multiply_signed_words_to_double_word */
            uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9D), value10);
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), (uint16_t)((value11 ^ value12) + 1));
            uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value13);
            r->a = value13;
            r->z = value13 == 0;
            r->n = value13 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0xC22B94); GUARD_JSR(c, sp_call, 0x97E3); } /* multiply_signed_words_to_double_word */
            uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9F), value14);
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CD, value15);
            uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CF, value16);
            uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9F));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D1, value17);
            uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D3, value18);
            r->a = value18;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint8_t value20 = BUS8_RDP(c, (db_ret << 0x10) + 0xB2 + value19);
            r->a = (a_all >> 8 << 8) | value20;
            r->x = value19;
            r->z = value20 == 0;
            r->n = value20 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97B5, 0xC22A59); GUARD_JSR(c, sp_call, 0x97B5); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all6 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all6);
            uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value21);
            uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value22);
            r->a = value22;
            r->z = value22 == 0;
            r->n = value22 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97C2, 0xC22B94); GUARD_JSR(c, sp_call, 0x97C2); } /* multiply_signed_words_to_double_word */
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9B), value23);
            uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value24);
            uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value25);
            r->a = value25;
            r->z = value25 == 0;
            r->n = value25 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97D1, 0xC22B94); GUARD_JSR(c, sp_call, 0x97D1); } /* multiply_signed_words_to_double_word */
            uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9D), value26);
            uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), (uint16_t)((value27 ^ value28) + 1));
            uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value29);
            r->a = value29;
            r->z = value29 == 0;
            r->n = value29 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0xC22B94); GUARD_JSR(c, sp_call, 0x97E3); } /* multiply_signed_words_to_double_word */
            uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9F), value30);
            uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CD, value31);
            uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CF, value32);
            uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9F));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D1, value33);
            uint16_t value34 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D3, value34);
            r->a = value34;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 0x97), a_all);
        if (x_ret) {
            uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint16_t value36 = BUS16_RDP(c, (db_ret << 0x10) + 0xB2 + value35);
            r->a = value36;
            r->x = value35;
            r->y = (uint8_t)y;
            r->z = value36 == 0;
            r->n = value36 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97B5, 0xC22A59); GUARD_JSR(c, sp_call, 0x97B5); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all10 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all10);
            uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value37);
            uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value38);
            r->a = value38;
            r->z = value38 == 0;
            r->n = value38 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97C2, 0xC22B94); GUARD_JSR(c, sp_call, 0x97C2); } /* multiply_signed_words_to_double_word */
            uint16_t value39 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9B), value39);
            uint16_t value40 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value40);
            uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value41);
            r->a = value41;
            r->z = value41 == 0;
            r->n = value41 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97D1, 0xC22B94); GUARD_JSR(c, sp_call, 0x97D1); } /* multiply_signed_words_to_double_word */
            uint16_t value42 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9D), value42);
            uint16_t value43 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            uint16_t value44 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), (uint16_t)((value43 ^ value44) + 1));
            uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value45);
            r->a = value45;
            r->z = value45 == 0;
            r->n = value45 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0xC22B94); GUARD_JSR(c, sp_call, 0x97E3); } /* multiply_signed_words_to_double_word */
            uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9F), value46);
            uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CD, value47);
            uint16_t value48 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CF, value48);
            uint16_t value49 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9F));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D1, value49);
            uint16_t value50 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D3, value50);
            r->a = value50;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value51 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint16_t value52 = BUS16_RDP(c, (db_ret << 0x10) + 0xB2 + value51);
            r->a = value52;
            r->x = value51;
            r->z = value52 == 0;
            r->n = value52 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97B5, 0xC22A59); GUARD_JSR(c, sp_call, 0x97B5); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all14 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all14);
            uint16_t value53 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value53);
            uint16_t value54 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value54);
            r->a = value54;
            r->z = value54 == 0;
            r->n = value54 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97C2, 0xC22B94); GUARD_JSR(c, sp_call, 0x97C2); } /* multiply_signed_words_to_double_word */
            uint16_t value55 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9B), value55);
            uint16_t value56 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value56);
            uint16_t value57 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value57);
            r->a = value57;
            r->z = value57 == 0;
            r->n = value57 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97D1, 0xC22B94); GUARD_JSR(c, sp_call, 0x97D1); } /* multiply_signed_words_to_double_word */
            uint16_t value58 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9D), value58);
            uint16_t value59 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            uint16_t value60 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), (uint16_t)((value59 ^ value60) + 1));
            uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value61);
            r->a = value61;
            r->z = value61 == 0;
            r->n = value61 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0xC22B94); GUARD_JSR(c, sp_call, 0x97E3); } /* multiply_signed_words_to_double_word */
            uint16_t value62 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9F), value62);
            uint16_t value63 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CD, value63);
            uint16_t value64 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CF, value64);
            uint16_t value65 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9F));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D1, value65);
            uint16_t value66 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D3, value66);
            r->a = value66;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}

/* C2979F derive_isotropic_native7f_mode7_matrix_from_scale_and_angle   [class B, 94 bytes, 42 instructions]
 * Source: src/rom/derive_isotropic_native7f_mode7_matrix_from_scale_and_angle.s
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void derive_isotropic_native7f_mode7_matrix_from_scale_and_angle_m8x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t y = r->y;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM8(0x0395) = RAM8(0x00B0 + battle_defence_work);
    uint8_t value2 = RAM8(0x00B2 + battle_defence_work);
    r->a = (a_hi << 8) | value2;
    r->x = battle_defence_work;
    r->z = value2 == 0;
    r->n = value2 & 0x80;
    { const uint16_t sp_call = r->sp; JSR(c, 0x97AB, 0xC22A60); GUARD_JSR(c, sp_call, 0x97AB); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, (uint16_t)(dp_ret + 0x97), (uint8_t)a_all);
        if (x_ret) {
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 0xB2 + value3);
            r->a = (a_all >> 8 << 8) | value4;
            r->x = value3;
            r->y = (uint8_t)y;
            r->z = value4 == 0;
            r->n = value4 & 0x80;
            r->mf = 1;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97B5, 0xC22A59); GUARD_JSR(c, sp_call, 0x97B5); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all2 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all2);
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value5);
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value6);
            r->a = value6;
            r->z = value6 == 0;
            r->n = value6 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97C2, 0xC22B94); GUARD_JSR(c, sp_call, 0x97C2); } /* multiply_signed_words_to_double_word */
            uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9B), value7);
            uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value8);
            uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value9);
            r->a = value9;
            r->z = value9 == 0;
            r->n = value9 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97D1, 0xC22B94); GUARD_JSR(c, sp_call, 0x97D1); } /* multiply_signed_words_to_double_word */
            uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9D), value10);
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), (uint16_t)((value11 ^ value12) + 1));
            uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value13);
            r->a = value13;
            r->z = value13 == 0;
            r->n = value13 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0xC22B94); GUARD_JSR(c, sp_call, 0x97E3); } /* multiply_signed_words_to_double_word */
            uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9F), value14);
            uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CD, value15);
            uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CF, value16);
            uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9F));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D1, value17);
            uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D3, value18);
            r->a = value18;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint8_t value20 = BUS8_RDP(c, (db_ret << 0x10) + 0xB2 + value19);
            r->a = (a_all >> 8 << 8) | value20;
            r->x = value19;
            r->z = value20 == 0;
            r->n = value20 & 0x80;
            r->mf = 1;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97B5, 0xC22A59); GUARD_JSR(c, sp_call, 0x97B5); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all6 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all6);
            uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value21);
            uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value22);
            r->a = value22;
            r->z = value22 == 0;
            r->n = value22 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97C2, 0xC22B94); GUARD_JSR(c, sp_call, 0x97C2); } /* multiply_signed_words_to_double_word */
            uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9B), value23);
            uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value24);
            uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value25);
            r->a = value25;
            r->z = value25 == 0;
            r->n = value25 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97D1, 0xC22B94); GUARD_JSR(c, sp_call, 0x97D1); } /* multiply_signed_words_to_double_word */
            uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9D), value26);
            uint16_t value27 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), (uint16_t)((value27 ^ value28) + 1));
            uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value29);
            r->a = value29;
            r->z = value29 == 0;
            r->n = value29 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0xC22B94); GUARD_JSR(c, sp_call, 0x97E3); } /* multiply_signed_words_to_double_word */
            uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9F), value30);
            uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CD, value31);
            uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CF, value32);
            uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9F));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D1, value33);
            uint16_t value34 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D3, value34);
            r->a = value34;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 0x97), a_all);
        if (x_ret) {
            uint8_t value35 = BUS8_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint16_t value36 = BUS16_RDP(c, (db_ret << 0x10) + 0xB2 + value35);
            r->a = value36;
            r->x = value35;
            r->y = (uint8_t)y;
            r->z = value36 == 0;
            r->n = value36 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97B5, 0xC22A59); GUARD_JSR(c, sp_call, 0x97B5); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all10 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all10);
            uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value37);
            uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value38);
            r->a = value38;
            r->z = value38 == 0;
            r->n = value38 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97C2, 0xC22B94); GUARD_JSR(c, sp_call, 0x97C2); } /* multiply_signed_words_to_double_word */
            uint16_t value39 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9B), value39);
            uint16_t value40 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value40);
            uint16_t value41 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value41);
            r->a = value41;
            r->z = value41 == 0;
            r->n = value41 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97D1, 0xC22B94); GUARD_JSR(c, sp_call, 0x97D1); } /* multiply_signed_words_to_double_word */
            uint16_t value42 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9D), value42);
            uint16_t value43 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            uint16_t value44 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), (uint16_t)((value43 ^ value44) + 1));
            uint16_t value45 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value45);
            r->a = value45;
            r->z = value45 == 0;
            r->n = value45 & 0x8000;
            r->mf = 0;
            r->xf = 1;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0xC22B94); GUARD_JSR(c, sp_call, 0x97E3); } /* multiply_signed_words_to_double_word */
            uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9F), value46);
            uint16_t value47 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CD, value47);
            uint16_t value48 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CF, value48);
            uint16_t value49 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9F));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D1, value49);
            uint16_t value50 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D3, value50);
            r->a = value50;
            r->mf = 0;
            r->xf = 1;
            RETURN_RTS(c);
        } else {
            uint16_t value51 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x87));
            uint16_t value52 = BUS16_RDP(c, (db_ret << 0x10) + 0xB2 + value51);
            r->a = value52;
            r->x = value51;
            r->z = value52 == 0;
            r->n = value52 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97B5, 0xC22A59); GUARD_JSR(c, sp_call, 0x97B5); } /* derive_cosine_by_adding_quarter_turn */
            uint16_t a_all14 = r->a;
            BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all14);
            uint16_t value53 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value53);
            uint16_t value54 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value54);
            r->a = value54;
            r->z = value54 == 0;
            r->n = value54 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97C2, 0xC22B94); GUARD_JSR(c, sp_call, 0x97C2); } /* multiply_signed_words_to_double_word */
            uint16_t value55 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9B), value55);
            uint16_t value56 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value56);
            uint16_t value57 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value57);
            r->a = value57;
            r->z = value57 == 0;
            r->n = value57 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97D1, 0xC22B94); GUARD_JSR(c, sp_call, 0x97D1); } /* multiply_signed_words_to_double_word */
            uint16_t value58 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9D), value58);
            uint16_t value59 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
            uint16_t value60 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC7));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x46), (uint16_t)((value59 ^ value60) + 1));
            uint16_t value61 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value61);
            r->a = value61;
            r->z = value61 == 0;
            r->n = value61 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            { const uint16_t sp_call = r->sp; JSR(c, 0x97E3, 0xC22B94); GUARD_JSR(c, sp_call, 0x97E3); } /* multiply_signed_words_to_double_word */
            uint16_t value62 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
            BUS16_SET(c, (uint16_t)(dp_ret + 0x9F), value62);
            uint16_t value63 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CD, value63);
            uint16_t value64 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9D));
            BUS16_SET(c, (db_ret << 0x10) + 0x02CF, value64);
            uint16_t value65 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9F));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D1, value65);
            uint16_t value66 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x9B));
            BUS16_SET(c, (db_ret << 0x10) + 0x02D3, value66);
            r->a = value66;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
    }
}

/* Entered with M16/X16, M8/X16 accumulator/index widths: one body per width pair. */
static void derive_isotropic_native7f_mode7_matrix_from_scale_and_angle(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { derive_isotropic_native7f_mode7_matrix_from_scale_and_angle_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 0) { derive_isotropic_native7f_mode7_matrix_from_scale_and_angle_m8x16(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC2979F, SOM_RTS, "gen", derive_isotropic_native7f_mode7_matrix_from_scale_and_angle, 0, L_B | L_X | L_Y | L_C | L_V, 1, -1, -1, 94, 42)

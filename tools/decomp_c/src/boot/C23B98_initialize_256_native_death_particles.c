#include "som_c.h"

/* C23B98 initialize_256_native_death_particles   [class B, 118 bytes, 54 instructions]
 * Source: src/rom/initialize_256_native_death_particles.s
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: YCV.
 */
static void initialize_256_native_death_particles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a_hi_3b9d = 0;
    uint16_t x_3b9d = 0;
    uint16_t y_3b9d = 0;
    bool carry_3b9d = 0;
    bool overflow_3b9d = 0;
    uint16_t direct_page_3b9d = 0;
    uint8_t data_bank_3b9d = 0;
    RAM16_SET(0x031A, 0x2000);
    a_hi_3b9d = 0x20;
    x_3b9d = x;
    y_3b9d = y;
    carry_3b9d = carry;
    overflow_3b9d = overflow;
    direct_page_3b9d = 0x0300;
    data_bank_3b9d = 0x7E;
    shared_3B9D:;
    uint16_t value = BUS16_RDP(c, (uint16_t)(direct_page_3b9d + 0xC5));
    r->a = value;
    r->x = x_3b9d;
    r->y = y_3b9d;
    r->c = carry_3b9d;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->v = overflow_3b9d;
    r->mf = 0;
    r->xf = 0;
    r->db = data_bank_3b9d;
    r->dp = direct_page_3b9d;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3BA1, 0xC2300B); GUARD_JSR(c, sp_call, 0x3BA1); } /* draw_boss_frame_random_number */
    uint16_t a_all = r->a;
    BUS16_SET(c, (uint16_t)(direct_page_3b9d + 0x95), a_all);
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3BA6, 0xC22A59); GUARD_JSR(c, sp_call, 0x3BA6); } /* derive_cosine_by_adding_quarter_turn */
    uint16_t a_all2 = r->a;
    BUS16_SET(c, (uint16_t)(direct_page_3b9d + 0x97), a_all2);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(direct_page_3b9d + 0x95));
    r->a = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x3BAD, 0xC22A60); GUARD_JSR(c, sp_call, 0x3BAD); } /* mask_angle_and_derive_native_sine */
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    uint16_t a_all3 = r->a;
    if (m_ret) {
        BUS8_SET(c, (uint16_t)(dp_ret + 0x99), (uint8_t)a_all3);
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 0xC5));
        r->a = (a_all3 >> 8 << 8) | value3;
        r->z = value3 == 0;
        r->n = value3 & 0x80;
        r->mf = 1;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BB4, 0xC2300B); GUARD_JSR(c, sp_call, 0x3BB4); } /* draw_boss_frame_random_number */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BB7, 0xC22A59); GUARD_JSR(c, sp_call, 0x3BB7); } /* derive_cosine_by_adding_quarter_turn */
        uint16_t a_all5 = r->a;
        uint16_t x_ret6 = r->x;
        BUS16_SET(c, (uint16_t)(dp_ret + 0x46), a_all5);
        BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), 0x02C0);
        r->a = 0x02C0;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BC1, 0xC22AC3); GUARD_JSR(c, sp_call, 0x3BC1); } /* multiply_unsigned_words_with_four_hardware_products */
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x95), value4);
        BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value4);
        uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value5);
        r->a = value5;
        r->z = value5 == 0;
        r->n = value5 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BCE, 0xC22AC3); GUARD_JSR(c, sp_call, 0x3BCE); } /* multiply_unsigned_words_with_four_hardware_products */
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x97), value6);
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value7);
        uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value8);
        r->a = value8;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BDD, 0xC22AC3); GUARD_JSR(c, sp_call, 0x3BDD); } /* multiply_unsigned_words_with_four_hardware_products */
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x99), value9);
        RAM8(0x0000 + sp0) = db_ret;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x1A));
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC5));
        BUS16_SET(c, 0x7F0000 + value10, value11);
        BUS16_SET(c, 0x7F0002 + value10, value11);
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
        BUS16_SET(c, 0x7F0004 + value10, value12);
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
        BUS16_SET(c, 0x7F0006 + value10, value13);
        uint8_t value14 = RAM8(0x0000 + sp0);
        uint16_t value15 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x1A));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x1A), (uint16_t)(value15 + 8));
        if ((uint16_t)(value15 + 8) < 0x2800) {
            a_hi_3b9d = (uint16_t)(value15 + 8) >> 8;
            x_3b9d = x_ret6;
            y_3b9d = value10;
            carry_3b9d = (uint16_t)(value15 + 8) >= 0x2800;
            overflow_3b9d = ((value15 ^ (uint16_t)(value15 + 8)) & ((uint16_t)(value15 + 8) ^ 8) & 0x8000) != 0;
            direct_page_3b9d = dp_ret;
            data_bank_3b9d = value14;
            goto shared_3B9D;
        }
        r->y = value10;
        r->c = (uint16_t)(value15 + 8) >= 0x2800;
        r->v = ((value15 ^ (uint16_t)(value15 + 8)) & ((uint16_t)(value15 + 8) ^ 8) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = value14;
        RETURN_RTS(c);
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 0x99), a_all3);
        uint16_t value16 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC5));
        r->a = value16;
        r->z = value16 == 0;
        r->n = value16 & 0x8000;
        r->mf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BB4, 0xC2300B); GUARD_JSR(c, sp_call, 0x3BB4); } /* draw_boss_frame_random_number */
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BB7, 0xC22A59); GUARD_JSR(c, sp_call, 0x3BB7); } /* derive_cosine_by_adding_quarter_turn */
        uint16_t a_all10 = r->a;
        uint16_t x_ret8 = r->x;
        BUS16_SET(c, (uint16_t)(dp_ret + 0x46), a_all10);
        BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), 0x02C0);
        r->a = 0x02C0;
        r->z = 0;
        r->n = 0;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BC1, 0xC22AC3); GUARD_JSR(c, sp_call, 0x3BC1); } /* multiply_unsigned_words_with_four_hardware_products */
        uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x95), value17);
        BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value17);
        uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value18);
        r->a = value18;
        r->z = value18 == 0;
        r->n = value18 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BCE, 0xC22AC3); GUARD_JSR(c, sp_call, 0x3BCE); } /* multiply_unsigned_words_with_four_hardware_products */
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x97), value19);
        uint16_t value20 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x95));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x46), value20);
        uint16_t value21 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x4E), value21);
        r->a = value21;
        r->z = value21 == 0;
        r->n = value21 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        { const uint16_t sp_call = r->sp; JSR(c, 0x3BDD, 0xC22AC3); GUARD_JSR(c, sp_call, 0x3BDD); } /* multiply_unsigned_words_with_four_hardware_products */
        uint16_t value22 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x57));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x99), value22);
        RAM8(0x0000 + sp0) = db_ret;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x1A));
        uint16_t value24 = BUS16_RDP(c, (uint16_t)(dp_ret + 0xC5));
        BUS16_SET(c, 0x7F0000 + value23, value24);
        BUS16_SET(c, 0x7F0002 + value23, value24);
        uint16_t value25 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x97));
        BUS16_SET(c, 0x7F0004 + value23, value25);
        uint16_t value26 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x99));
        BUS16_SET(c, 0x7F0006 + value23, value26);
        uint8_t value27 = RAM8(0x0000 + sp0);
        uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret + 0x1A));
        BUS16_SET(c, (uint16_t)(dp_ret + 0x1A), (uint16_t)(value28 + 8));
        if ((uint16_t)(value28 + 8) < 0x2800) {
            a_hi_3b9d = (uint16_t)(value28 + 8) >> 8;
            x_3b9d = x_ret8;
            y_3b9d = value23;
            carry_3b9d = (uint16_t)(value28 + 8) >= 0x2800;
            overflow_3b9d = ((value28 ^ (uint16_t)(value28 + 8)) & ((uint16_t)(value28 + 8) ^ 8) & 0x8000) != 0;
            direct_page_3b9d = dp_ret;
            data_bank_3b9d = value27;
            goto shared_3B9D;
        }
        r->y = value23;
        r->c = (uint16_t)(value28 + 8) >= 0x2800;
        r->v = ((value28 ^ (uint16_t)(value28 + 8)) & ((uint16_t)(value28 + 8) ^ 8) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        r->db = value27;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC23B98, SOM_RTS, "gen", initialize_256_native_death_particles, 0, L_Y | L_C | L_V, 2, 0, 0, 118, 54)

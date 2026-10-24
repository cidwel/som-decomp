#include "som_c.h"

/* C10404 calculate_actor_direction_codes   [class B, 207 bytes, 111 instructions]
 * Source: src/rom/calculate_actor_direction_codes.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCV.
 */
static void calculate_actor_direction_codes(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 0x11) + 0xC > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x000B + (uint16_t)(sp0 - 0x11), 0);
    uint16_t value = RAM16(0x0020 + x);
    uint16_t value2 = RAM16(0x0020 + y);
    uint8_t a1;
    uint8_t a_hi1;
    bool negative1;
    if (value >= value2) {
        a1 = (uint8_t)(value - value2);
        a_hi1 = (uint16_t)(value - value2) >> 8;
        negative1 = (uint16_t)(value - value2) & 0x8000;
    } else {
        RAM8(0x0000 + sp0 - 0x11) = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
        RAM8(0x0000 + sp0 - 0x12) = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
        RAM16_SET(0x000B + (uint16_t)(sp0 - 0x11), 3);
        a1 = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
        negative1 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) & 0x8000;
    }
    uint8_t a2;
    uint8_t a_hi2;
    bool zero1;
    bool negative2;
    if ((((a_hi1 << 8) | a1) & 0xFF00) == 0) {
        a2 = a1;
        a_hi2 = a_hi1;
        zero1 = (((a_hi1 << 8) | a1) & 0xFF00) == 0;
        negative2 = negative1;
    } else {
        RAM8(0x0000 + sp0 - 0x11) = (uint16_t)((((a_hi1 << 8) | a1 | 0xFF00) ^ 0xFFFF) + 1) >> 8;
        RAM8(0x0000 + sp0 - 0x12) = (uint8_t)((((a_hi1 << 8) | a1 | 0xFF00) ^ 0xFFFF) + 1);
        RAM16_SET(0x000B + (uint16_t)(sp0 - 0x11), RAM16(0x000B + (uint16_t)(sp0 - 0x11)) ^ 3);
        a2 = (uint8_t)((((a_hi1 << 8) | a1 | 0xFF00) ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)((((a_hi1 << 8) | a1 | 0xFF00) ^ 0xFFFF) + 1) >> 8;
        zero1 = (uint16_t)((((a_hi1 << 8) | a1 | 0xFF00) ^ 0xFFFF) + 1) == 0;
        negative2 = (uint16_t)((((a_hi1 << 8) | a1 | 0xFF00) ^ 0xFFFF) + 1) & 0x8000;
    }
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 0x11), (a_hi2 << 8) | a2);
    r->a = (a_hi2 << 8) | a2;
    r->c = value >= value2;
    r->z = zero1;
    r->n = negative2;
    r->v = ((value ^ value2) & (value ^ (uint16_t)(value - value2)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 0x11);
    r->sp -= 17;
    { const uint16_t sp_call = r->sp; JSR(c, 0x043E, 0xC1032E); GUARD_JSR(c, sp_call, 0x043E); } /* read_actor_y_minus_height_y */
    r->sp += 17;
    uint16_t dp_ret = r->dp;
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, (uint16_t)(dp_ret + 0x0D), (uint8_t)a_all);
        r->mf = 1;
        r->sp -= 17;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0443, 0xC10343); GUARD_JSR(c, sp_call, 0x0443); } /* read_actor_y_minus_height_x */
        r->sp += 17;
        uint16_t dp_ret2 = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x0D));
        uint8_t a3;
        uint8_t a_hi3;
        if (a_all2 >= value4) {
            a3 = (uint8_t)(a_all2 - value4);
            a_hi3 = (uint16_t)(a_all2 - value4) >> 8;
        } else {
            uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x0B));
            BUS16_SET(c, (uint16_t)(dp_ret2 + 0x0B), value5 | 0x0C);
            a3 = (uint8_t)(((uint16_t)(a_all2 - value4) ^ 0xFFFF) + 1);
            a_hi3 = (uint16_t)(((uint16_t)(a_all2 - value4) ^ 0xFFFF) + 1) >> 8;
        }
        uint8_t a4;
        uint8_t a_hi4;
        if ((((a_hi3 << 8) | a3) & 0xFF00) == 0) {
            a4 = a3;
            a_hi4 = a_hi3;
        } else {
            uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 0x0B));
            BUS16_SET(c, (uint16_t)(dp_ret2 + 0x0B), value6 ^ 0x0C);
            a4 = (uint8_t)((((a_hi3 << 8) | a3 | 0xFF00) ^ 0xFFFF) + 1);
            a_hi4 = (uint16_t)((((a_hi3 << 8) | a3 | 0xFF00) ^ 0xFFFF) + 1) >> 8;
        }
        uint16_t value7 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        if (((a_hi4 << 8) | a4) == value7) {
            BUS16_SET(c, (uint16_t)(dp_ret2 + 5), (a_hi4 << 8) | a4);
            uint16_t value8 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
            BUS16_SET(c, (uint16_t)(dp_ret2 + 3), value8);
            BUS16_SET(c, (uint16_t)(dp_ret2 + 9), 3);
            BUS16_SET(c, (uint16_t)(dp_ret2 + 7), 3);
        } else {
            if (((a_hi4 << 8) | a4) >= value7) {
                BUS16_SET(c, (uint16_t)(dp_ret2 + 3), (a_hi4 << 8) | a4);
                uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS16_SET(c, (uint16_t)(dp_ret2 + 5), value9);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 9), 0x0C);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 7), 0x0C);
            } else {
                BUS16_SET(c, (uint16_t)(dp_ret2 + 5), (a_hi4 << 8) | a4);
                uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS16_SET(c, (uint16_t)(dp_ret2 + 3), value10);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 9), 3);
                BUS16_SET(c, (uint16_t)(dp_ret2 + 7), 3);
            }
        }
        uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
        uint16_t value12 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
        BUS16_SET(c, (uint16_t)(dp_ret2 + 1), (uint16_t)(value11 - value12) >> 1);
        uint16_t value13 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        uint16_t value14 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 5));
        uint8_t a_hi5;
        if ((uint16_t)(((uint16_t)(value11 - value12) >> 2) + value13) >= value14) {
            a_hi5 = (uint16_t)(((uint16_t)(value11 - value12) >> 2) + value13) >> 8;
        } else {
            BUS16_SET(c, (uint16_t)(dp_ret2 + 9), 0x0F);
            a_hi5 = 0;
        }
        uint8_t value15 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x0B));
        uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 7));
        BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (value15 ^ 5) & value16);
        uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 5));
        uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x0B));
        uint8_t value20 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 9));
        BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (value19 ^ 5) & value20);
        uint8_t value21 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 0x0B));
        uint8_t value22 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        RAM16_SET(0x0000 + sp0 - 4, (((value17 & 0xF0) | value18) << 8) | ((uint8_t)((value21 ^ 5) << 4) | value22));
        uint8_t value23 = RAM8(0x0000 + sp0 - 4);
        uint8_t value24 = RAM8(0x0000 + sp0 - 3);
        uint8_t value25 = RAM8(0x0000 + sp0 - 2);
        uint8_t value26 = RAM8(0x0000 + sp0 - 1);
        uint8_t value27 = RAM8(0x0000 + sp0);
        r->a = (value24 << 8) | value23;
        r->c = value25 & 0x01;
        r->v = value25 & 0x40;
        r->mf = value25 & 0x20;
        r->xf = value25 & 0x10;
        r->dp = (value27 << 8) | value26;
        r->i = value25 & 0x04;
        r->d = value25 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 0x0D), a_all);
        r->mf = 0;
        r->sp -= 17;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0443, 0xC10343); GUARD_JSR(c, sp_call, 0x0443); } /* read_actor_y_minus_height_x */
        r->sp += 17;
        uint16_t dp_ret3 = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
        uint16_t value28 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x0D));
        uint8_t a5;
        uint8_t a_hi6;
        if (a_all3 >= value28) {
            a5 = (uint8_t)(a_all3 - value28);
            a_hi6 = (uint16_t)(a_all3 - value28) >> 8;
        } else {
            uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x0B));
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x0B), value29 | 0x0C);
            a5 = (uint8_t)(((uint16_t)(a_all3 - value28) ^ 0xFFFF) + 1);
            a_hi6 = (uint16_t)(((uint16_t)(a_all3 - value28) ^ 0xFFFF) + 1) >> 8;
        }
        uint8_t a6;
        uint8_t a_hi7;
        if ((((a_hi6 << 8) | a5) & 0xFF00) == 0) {
            a6 = a5;
            a_hi7 = a_hi6;
        } else {
            uint16_t value30 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 0x0B));
            BUS16_SET(c, (uint16_t)(dp_ret3 + 0x0B), value30 ^ 0x0C);
            a6 = (uint8_t)((((a_hi6 << 8) | a5 | 0xFF00) ^ 0xFFFF) + 1);
            a_hi7 = (uint16_t)((((a_hi6 << 8) | a5 | 0xFF00) ^ 0xFFFF) + 1) >> 8;
        }
        uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        if (((a_hi7 << 8) | a6) == value31) {
            BUS16_SET(c, (uint16_t)(dp_ret3 + 5), (a_hi7 << 8) | a6);
            uint16_t value32 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
            BUS16_SET(c, (uint16_t)(dp_ret3 + 3), value32);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 9), 3);
            BUS16_SET(c, (uint16_t)(dp_ret3 + 7), 3);
        } else {
            if (((a_hi7 << 8) | a6) >= value31) {
                BUS16_SET(c, (uint16_t)(dp_ret3 + 3), (a_hi7 << 8) | a6);
                uint16_t value33 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS16_SET(c, (uint16_t)(dp_ret3 + 5), value33);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 9), 0x0C);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 7), 0x0C);
            } else {
                BUS16_SET(c, (uint16_t)(dp_ret3 + 5), (a_hi7 << 8) | a6);
                uint16_t value34 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS16_SET(c, (uint16_t)(dp_ret3 + 3), value34);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 9), 3);
                BUS16_SET(c, (uint16_t)(dp_ret3 + 7), 3);
            }
        }
        uint16_t value35 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 3));
        uint16_t value36 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 5));
        BUS16_SET(c, (uint16_t)(dp_ret3 + 1), (uint16_t)(value35 - value36) >> 1);
        uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        uint16_t value38 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 5));
        uint8_t a_hi8;
        if ((uint16_t)(((uint16_t)(value35 - value36) >> 2) + value37) >= value38) {
            a_hi8 = (uint16_t)(((uint16_t)(value35 - value36) >> 2) + value37) >> 8;
        } else {
            BUS16_SET(c, (uint16_t)(dp_ret3 + 9), 0x0F);
            a_hi8 = 0;
        }
        uint8_t value39 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x0B));
        uint8_t value40 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 7));
        BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (value39 ^ 5) & value40);
        uint8_t value41 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 5));
        uint8_t value42 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
        uint8_t value43 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x0B));
        uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 9));
        BUS8_SET(c, (uint16_t)(dp_ret3 + 1), (value43 ^ 5) & value44);
        uint8_t value45 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 0x0B));
        uint8_t value46 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
        RAM16_SET(0x0000 + sp0 - 4, (((value41 & 0xF0) | value42) << 8) | ((uint8_t)((value45 ^ 5) << 4) | value46));
        uint8_t value47 = RAM8(0x0000 + sp0 - 4);
        uint8_t value48 = RAM8(0x0000 + sp0 - 3);
        uint8_t value49 = RAM8(0x0000 + sp0 - 2);
        uint8_t value50 = RAM8(0x0000 + sp0 - 1);
        uint8_t value51 = RAM8(0x0000 + sp0);
        r->a = (value48 << 8) | value47;
        r->c = value49 & 0x01;
        r->v = value49 & 0x40;
        r->mf = value49 & 0x20;
        r->xf = value49 & 0x10;
        r->dp = (value51 << 8) | value50;
        r->i = value49 & 0x04;
        r->d = value49 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC10404, SOM_RTS, "gen", calculate_actor_direction_codes, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 19, 1, 0, 207, 111)

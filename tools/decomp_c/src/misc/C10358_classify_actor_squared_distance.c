#include "som_c.h"

/* C10358 classify_actor_squared_distance   [class B, 172 bytes, 84 instructions]
 * Source: src/rom/classify_actor_squared_distance.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCV.
 */
static void classify_actor_squared_distance(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x4 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    uint16_t value = RAM16(0x0020 + x);
    uint16_t value2 = RAM16(0x0020 + y);
    uint8_t a2;
    uint8_t a_hi2;
    if ((uint16_t)(value - value2) == 0) {
        a2 = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
        a_hi2 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
    } else {
        uint8_t a1;
        uint8_t a_hi1;
        if (value >= value2) {
            a1 = (uint8_t)(value - value2);
            a_hi1 = (uint16_t)(value - value2) >> 8;
        } else {
            a1 = (uint8_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1);
            a_hi1 = (uint16_t)(((uint16_t)(value - value2) ^ 0xFFFF) + 1) >> 8;
        }
        a2 = a1;
        a_hi2 = a_hi1;
    }
    if ((((a_hi2 << 8) | a2) & 0xFF00) != 0) {
        RAM8(0x0000 + sp0 - 3) = 8;
        r->a = RAM8(0x0000 + sp0 - 3);
        RETURN_RTS(c);
    }
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), (a_hi2 << 8) | a2);
    uint8_t value7 = RAM8(0x0001 + (uint16_t)(sp0 - 7));
    BUS16_SET(c, 0x004202, (a2 << 8) | value7);
    RAM8(0x0000 + sp0 - 7) = a2;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)((a2 << 8) | value7);
    uint16_t value8 = BUS16(c, 0x004216);
    RAM16_SET(0x0003 + (uint16_t)(sp0 - 7), value8);
    r->a = value8;
    r->c = value >= value2;
    r->z = value8 == 0;
    r->n = value8 & 0x8000;
    r->v = ((value ^ value2) & (value ^ (uint16_t)(value - value2)) & 0x8000) != 0;
    r->mf = 0;
    r->dp = (uint16_t)(sp0 - 7);
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0x038E, 0xC1032E); GUARD_JSR(c, sp_call, 0x038E); } /* read_actor_y_minus_height_y */
    r->sp += 7;
    uint16_t dp_ret = r->dp;
    bool m_ret = r->mf;
    uint16_t a_all = r->a;
    if (m_ret) {
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)a_all);
        r->mf = 1;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0393, 0xC10343); GUARD_JSR(c, sp_call, 0x0393); } /* read_actor_y_minus_height_x */
        r->sp += 7;
        uint16_t dp_ret2 = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t a_all2 = r->a;
        uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
        uint8_t a4;
        uint8_t a_hi4;
        if ((uint16_t)(a_all2 - value9) == 0) {
            a4 = (uint8_t)(((uint16_t)(a_all2 - value9) ^ 0xFFFF) + 1);
            a_hi4 = (uint16_t)(((uint16_t)(a_all2 - value9) ^ 0xFFFF) + 1) >> 8;
        } else {
            uint8_t a3;
            uint8_t a_hi3;
            if (a_all2 >= value9) {
                a3 = (uint8_t)(a_all2 - value9);
                a_hi3 = (uint16_t)(a_all2 - value9) >> 8;
            } else {
                a3 = (uint8_t)(((uint16_t)(a_all2 - value9) ^ 0xFFFF) + 1);
                a_hi3 = (uint16_t)(((uint16_t)(a_all2 - value9) ^ 0xFFFF) + 1) >> 8;
            }
            a4 = a3;
            a_hi4 = a_hi3;
        }
        if ((((a_hi4 << 8) | a4) & 0xFF00) != 0) {
            RAM8(0x0000 + sp0 - 3) = 8;
            uint8_t value13 = RAM8(0x0000 + sp0 - 3);
            uint8_t value14 = RAM8(0x0000 + sp0 - 2);
            uint8_t value15 = RAM8(0x0000 + sp0 - 1);
            uint8_t value16 = RAM8(0x0000 + sp0);
            r->a = value13;
            r->c = value14 & 0x01;
            r->v = value14 & 0x40;
            r->mf = value14 & 0x20;
            r->xf = value14 & 0x10;
            r->dp = (value16 << 8) | value15;
            r->i = value14 & 0x04;
            r->d = value14 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        BUS16_SET(c, (uint16_t)(dp_ret2 + 1), (a_hi4 << 8) | a4);
        uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
        BUS16_SET(c, 0x004202, (a4 << 8) | value17);
        uint16_t value18 = BUS16(c, 0x004216);
        uint16_t value19 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 3));
        if ((uint16_t)(value18 + value19) != 0x2400) {
            if ((uint16_t)(value18 + value19) >= 0x2400) {
                RAM8(0x0000 + sp0 - 3) = 0x30;
                uint8_t value23 = RAM8(0x0000 + sp0 - 3);
                uint8_t value24 = RAM8(0x0000 + sp0 - 2);
                uint8_t value25 = RAM8(0x0000 + sp0 - 1);
                uint8_t value26 = RAM8(0x0000 + sp0);
                r->a = value23;
                r->c = value24 & 0x01;
                r->v = value24 & 0x40;
                r->mf = value24 & 0x20;
                r->xf = value24 & 0x10;
                r->dp = (value26 << 8) | value25;
                r->i = value24 & 0x04;
                r->d = value24 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(value18 + value19) != 0x1000) {
            if ((uint16_t)(value18 + value19) >= 0x1000) {
                RAM8(0x0000 + sp0 - 3) = 0x10;
                uint8_t value30 = RAM8(0x0000 + sp0 - 3);
                uint8_t value31 = RAM8(0x0000 + sp0 - 2);
                uint8_t value32 = RAM8(0x0000 + sp0 - 1);
                uint8_t value33 = RAM8(0x0000 + sp0);
                r->a = value30;
                r->c = value31 & 0x01;
                r->v = value31 & 0x40;
                r->mf = value31 & 0x20;
                r->xf = value31 & 0x10;
                r->dp = (value33 << 8) | value32;
                r->i = value31 & 0x04;
                r->d = value31 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(value18 + value19) != 0x0900) {
            if ((uint16_t)(value18 + value19) >= 0x0900) {
                RAM8(0x0000 + sp0 - 3) = 8;
                uint8_t value37 = RAM8(0x0000 + sp0 - 3);
                uint8_t value38 = RAM8(0x0000 + sp0 - 2);
                uint8_t value39 = RAM8(0x0000 + sp0 - 1);
                uint8_t value40 = RAM8(0x0000 + sp0);
                r->a = value37;
                r->c = value38 & 0x01;
                r->v = value38 & 0x40;
                r->mf = value38 & 0x20;
                r->xf = value38 & 0x10;
                r->dp = (value40 << 8) | value39;
                r->i = value38 & 0x04;
                r->d = value38 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(value18 + value19) != 0x0400) {
            if ((uint16_t)(value18 + value19) >= 0x0400) {
                RAM8(0x0000 + sp0 - 3) = 4;
                uint8_t value44 = RAM8(0x0000 + sp0 - 3);
                uint8_t value45 = RAM8(0x0000 + sp0 - 2);
                uint8_t value46 = RAM8(0x0000 + sp0 - 1);
                uint8_t value47 = RAM8(0x0000 + sp0);
                r->a = value44;
                r->c = value45 & 0x01;
                r->v = value45 & 0x40;
                r->mf = value45 & 0x20;
                r->xf = value45 & 0x10;
                r->dp = (value47 << 8) | value46;
                r->i = value45 & 0x04;
                r->d = value45 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(value18 + value19) == 0x0100) {
            RAM8(0x0000 + sp0 - 3) = 1;
            uint8_t value51 = RAM8(0x0000 + sp0 - 3);
            uint8_t value52 = RAM8(0x0000 + sp0 - 2);
            uint8_t value53 = RAM8(0x0000 + sp0 - 1);
            uint8_t value54 = RAM8(0x0000 + sp0);
            r->a = value51;
            r->c = value52 & 0x01;
            r->v = value52 & 0x40;
            r->mf = value52 & 0x20;
            r->xf = value52 & 0x10;
            r->dp = (value54 << 8) | value53;
            r->i = value52 & 0x04;
            r->d = value52 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        uint8_t a5;
        if ((uint16_t)(value18 + value19) >= 0x0100) {
            a5 = 2;
        } else {
            a5 = 1;
        }
        RAM8(0x0000 + sp0 - 3) = a5;
        uint8_t value58 = RAM8(0x0000 + sp0 - 3);
        uint8_t value59 = RAM8(0x0000 + sp0 - 2);
        uint8_t value60 = RAM8(0x0000 + sp0 - 1);
        uint8_t value61 = RAM8(0x0000 + sp0);
        r->a = value58;
        r->c = value59 & 0x01;
        r->v = value59 & 0x40;
        r->mf = value59 & 0x20;
        r->xf = value59 & 0x10;
        r->dp = (value61 << 8) | value60;
        r->i = value59 & 0x04;
        r->d = value59 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 1), a_all);
        r->mf = 0;
        r->sp -= 7;
        { const uint16_t sp_call = r->sp; JSR(c, 0x0393, 0xC10343); GUARD_JSR(c, sp_call, 0x0393); } /* read_actor_y_minus_height_x */
        r->sp += 7;
        uint16_t dp_ret3 = r->dp;
        if (r->mf != 0) { c->fail = 3; return; }
        uint16_t a_all3 = r->a;
        uint16_t value62 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
        uint8_t a7;
        uint8_t a_hi6;
        if ((uint16_t)(a_all3 - value62) == 0) {
            a7 = (uint8_t)(((uint16_t)(a_all3 - value62) ^ 0xFFFF) + 1);
            a_hi6 = (uint16_t)(((uint16_t)(a_all3 - value62) ^ 0xFFFF) + 1) >> 8;
        } else {
            uint8_t a6;
            uint8_t a_hi5;
            if (a_all3 >= value62) {
                a6 = (uint8_t)(a_all3 - value62);
                a_hi5 = (uint16_t)(a_all3 - value62) >> 8;
            } else {
                a6 = (uint8_t)(((uint16_t)(a_all3 - value62) ^ 0xFFFF) + 1);
                a_hi5 = (uint16_t)(((uint16_t)(a_all3 - value62) ^ 0xFFFF) + 1) >> 8;
            }
            a7 = a6;
            a_hi6 = a_hi5;
        }
        if ((((a_hi6 << 8) | a7) & 0xFF00) != 0) {
            RAM8(0x0000 + sp0 - 3) = 8;
            uint8_t value66 = RAM8(0x0000 + sp0 - 3);
            uint8_t value67 = RAM8(0x0000 + sp0 - 2);
            uint8_t value68 = RAM8(0x0000 + sp0 - 1);
            uint8_t value69 = RAM8(0x0000 + sp0);
            r->a = value66;
            r->c = value67 & 0x01;
            r->v = value67 & 0x40;
            r->mf = value67 & 0x20;
            r->xf = value67 & 0x10;
            r->dp = (value69 << 8) | value68;
            r->i = value67 & 0x04;
            r->d = value67 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        BUS16_SET(c, (uint16_t)(dp_ret3 + 1), (a_hi6 << 8) | a7);
        uint8_t value70 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
        BUS16_SET(c, 0x004202, (a7 << 8) | value70);
        uint16_t value71 = BUS16(c, 0x004216);
        uint16_t value72 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 3));
        if ((uint16_t)(value71 + value72) != 0x2400) {
            if ((uint16_t)(value71 + value72) >= 0x2400) {
                RAM8(0x0000 + sp0 - 3) = 0x30;
                uint8_t value76 = RAM8(0x0000 + sp0 - 3);
                uint8_t value77 = RAM8(0x0000 + sp0 - 2);
                uint8_t value78 = RAM8(0x0000 + sp0 - 1);
                uint8_t value79 = RAM8(0x0000 + sp0);
                r->a = value76;
                r->c = value77 & 0x01;
                r->v = value77 & 0x40;
                r->mf = value77 & 0x20;
                r->xf = value77 & 0x10;
                r->dp = (value79 << 8) | value78;
                r->i = value77 & 0x04;
                r->d = value77 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(value71 + value72) != 0x1000) {
            if ((uint16_t)(value71 + value72) >= 0x1000) {
                RAM8(0x0000 + sp0 - 3) = 0x10;
                uint8_t value83 = RAM8(0x0000 + sp0 - 3);
                uint8_t value84 = RAM8(0x0000 + sp0 - 2);
                uint8_t value85 = RAM8(0x0000 + sp0 - 1);
                uint8_t value86 = RAM8(0x0000 + sp0);
                r->a = value83;
                r->c = value84 & 0x01;
                r->v = value84 & 0x40;
                r->mf = value84 & 0x20;
                r->xf = value84 & 0x10;
                r->dp = (value86 << 8) | value85;
                r->i = value84 & 0x04;
                r->d = value84 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(value71 + value72) != 0x0900) {
            if ((uint16_t)(value71 + value72) >= 0x0900) {
                RAM8(0x0000 + sp0 - 3) = 8;
                uint8_t value90 = RAM8(0x0000 + sp0 - 3);
                uint8_t value91 = RAM8(0x0000 + sp0 - 2);
                uint8_t value92 = RAM8(0x0000 + sp0 - 1);
                uint8_t value93 = RAM8(0x0000 + sp0);
                r->a = value90;
                r->c = value91 & 0x01;
                r->v = value91 & 0x40;
                r->mf = value91 & 0x20;
                r->xf = value91 & 0x10;
                r->dp = (value93 << 8) | value92;
                r->i = value91 & 0x04;
                r->d = value91 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(value71 + value72) != 0x0400) {
            if ((uint16_t)(value71 + value72) >= 0x0400) {
                RAM8(0x0000 + sp0 - 3) = 4;
                uint8_t value97 = RAM8(0x0000 + sp0 - 3);
                uint8_t value98 = RAM8(0x0000 + sp0 - 2);
                uint8_t value99 = RAM8(0x0000 + sp0 - 1);
                uint8_t value100 = RAM8(0x0000 + sp0);
                r->a = value97;
                r->c = value98 & 0x01;
                r->v = value98 & 0x40;
                r->mf = value98 & 0x20;
                r->xf = value98 & 0x10;
                r->dp = (value100 << 8) | value99;
                r->i = value98 & 0x04;
                r->d = value98 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(value71 + value72) == 0x0100) {
            RAM8(0x0000 + sp0 - 3) = 1;
            uint8_t value104 = RAM8(0x0000 + sp0 - 3);
            uint8_t value105 = RAM8(0x0000 + sp0 - 2);
            uint8_t value106 = RAM8(0x0000 + sp0 - 1);
            uint8_t value107 = RAM8(0x0000 + sp0);
            r->a = value104;
            r->c = value105 & 0x01;
            r->v = value105 & 0x40;
            r->mf = value105 & 0x20;
            r->xf = value105 & 0x10;
            r->dp = (value107 << 8) | value106;
            r->i = value105 & 0x04;
            r->d = value105 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        uint8_t a8;
        if ((uint16_t)(value71 + value72) >= 0x0100) {
            a8 = 2;
        } else {
            a8 = 1;
        }
        RAM8(0x0000 + sp0 - 3) = a8;
        uint8_t value111 = RAM8(0x0000 + sp0 - 3);
        uint8_t value112 = RAM8(0x0000 + sp0 - 2);
        uint8_t value113 = RAM8(0x0000 + sp0 - 1);
        uint8_t value114 = RAM8(0x0000 + sp0);
        r->a = value111;
        r->c = value112 & 0x01;
        r->v = value112 & 0x40;
        r->mf = value112 & 0x20;
        r->xf = value112 & 0x10;
        r->dp = (value114 << 8) | value113;
        r->i = value112 & 0x04;
        r->d = value112 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC10358, SOM_RTS, "gen", classify_actor_squared_distance, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 9, 1, 0, 172, 84)

#include "som_c.h"

/* C11CB0 actor_script_controller_distance_gate   [class B, 79 bytes, 42 instructions]
 * Source: src/rom/actor_script_controller_distance_gate.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void actor_script_controller_distance_gate(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7E;
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 3;
    uint8_t a1 = 3;
    uint8_t a_hi1 = (uint16_t)(sp0 - 4) >> 8;
    uint16_t x1 = 0xE600;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool zero1 = 0;
    bool negative1 = 1;
    bool overflow1 = overflow;
    uint16_t direct_page = (uint16_t)(sp0 - 4);
    for (;;) {
        r->a = (a_hi1 << 8) | a1;
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->z = zero1;
        r->n = negative1;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = 0x7E;
        r->dp = direct_page;
        r->sp -= 4;
        { const uint16_t sp_call = r->sp; JSR(c, 0x1CC2, 0xC1058B); GUARD_JSR(c, sp_call, 0x1CC2); } /* reject_ineligible_or_nonmonster_actor */
        r->sp += 4;
        uint16_t dp_ret = r->dp;
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t x_ret = r->x;
        bool carry_ret = r->c;
        uint8_t a5;
        uint8_t a_hi5;
        uint16_t x5;
        uint16_t y3;
        uint16_t direct_page5;
        if (!carry_ret) {
            BUS8_SET(c, (uint16_t)(dp_ret + 1), 3);
            uint8_t a2 = 3;
            uint8_t a_hi2 = a_all >> 8;
            uint16_t x2 = x_ret;
            uint16_t y2 = y1;
            uint16_t direct_page2 = dp_ret;
            for (;;) {
                uint8_t value = BUS8_RDP(c, (uint16_t)(direct_page2 + 1));
                r->a = (a_hi2 << 8) | (uint8_t)(3 - value);
                r->x = x2;
                r->y = y2;
                r->c = value <= 3;
                r->z = (uint8_t)(3 - value) == 0;
                r->n = (uint8_t)(3 - value) & 0x80;
                r->v = ((value ^ 3) & ((uint8_t)(3 - value) ^ 3) & 0x80) != 0;
                r->mf = 1;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = direct_page2;
                r->sp -= 4;
                { const uint16_t sp_call = r->sp; JSR(c, 0x1CE0, 0xC104D3); GUARD_JSR(c, sp_call, 0x1CE0); } /* resolve_controller_hero_actor */
                r->sp += 4;
                uint16_t dp_ret2 = r->dp;
                if (r->mf != 1) { c->fail = 3; return; }
                if (r->xf != 0) { c->fail = 3; return; }
                uint16_t a_all2 = r->a;
                uint16_t x_ret2 = r->x;
                uint16_t y_ret = r->y;
                bool x_flag2;
                uint8_t a4;
                uint8_t a_hi4;
                uint16_t x4;
                uint16_t direct_page4;
                if (x_ret2 == 0) {
                    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value2 - 1));
                    if ((uint8_t)(value2 - 1) != 0) {
                        a2 = (uint8_t)a_all2;
                        a_hi2 = a_all2 >> 8;
                        x2 = x_ret2;
                        y2 = y_ret;
                        direct_page2 = dp_ret2;
                        continue;
                    }
                    r->c = x_ret2 >= 0;
                    r->z = (uint8_t)(value2 - 1) == 0;
                    r->n = (uint8_t)(value2 - 1) & 0x80;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1CF3, 0xC10285); GUARD_JSR(c, sp_call, 0x1CF3); } /* jump_actor_script_after_1_bytes */
                    r->sp += 4;
                    uint16_t dp_ret3 = r->dp;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret3 = r->xf;
                    uint16_t a_all3 = r->a;
                    uint16_t x_ret4 = r->x;
                    x_flag2 = x_ret3;
                    a4 = (uint8_t)a_all3;
                    a_hi4 = a_all3 >> 8;
                    x4 = x_ret4;
                    direct_page4 = dp_ret3;
                } else {
                    r->c = x_ret2 >= 0;
                    r->z = x_ret2 == 0;
                    r->n = x_ret2 & 0x8000;
                    r->sp -= 4;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x1CE8, 0xC10358); GUARD_JSR(c, sp_call, 0x1CE8); } /* classify_actor_squared_distance */
                    r->sp += 4;
                    if (r->mf != 1) { c->fail = 3; return; }
                    bool x_ret5 = r->xf;
                    uint16_t a_all4 = r->a;
                    bool x_flag;
                    uint8_t a3;
                    uint8_t a_hi3;
                    uint16_t x3;
                    uint16_t direct_page3;
                    if (((uint8_t)a_all4 & 0x20) != 0) {
                        r->z = ((uint8_t)a_all4 & 0x20) == 0;
                        r->sp -= 4;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x1CF8, 0xC10213); GUARD_JSR(c, sp_call, 0x1CF8); } /* skip_actor_script_after_1_bytes */
                        r->sp += 4;
                        uint16_t dp_ret4 = r->dp;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret6 = r->xf;
                        uint16_t a_all5 = r->a;
                        uint16_t x_ret7 = r->x;
                        x_flag = x_ret6;
                        a3 = (uint8_t)a_all5;
                        a_hi3 = a_all5 >> 8;
                        x3 = x_ret7;
                        direct_page3 = dp_ret4;
                    } else {
                        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                        BUS8_SET(c, (uint16_t)(dp_ret2 + 1), (uint8_t)(value3 - 1));
                        if ((uint8_t)(value3 - 1) != 0) {
                            if (x_ret5 != 0) { c->fail = 3; return; }
                            a2 = (uint8_t)a_all4;
                            a_hi2 = a_all4 >> 8;
                            x2 = x_ret2;
                            y2 = y_ret;
                            direct_page2 = dp_ret2;
                            continue;
                        }
                        r->z = (uint8_t)(value3 - 1) == 0;
                        r->n = (uint8_t)(value3 - 1) & 0x80;
                        r->xf = 0;
                        r->sp -= 4;
                        { const uint16_t sp_call = r->sp; JSR(c, 0x1CF3, 0xC10285); GUARD_JSR(c, sp_call, 0x1CF3); } /* jump_actor_script_after_1_bytes */
                        r->sp += 4;
                        uint16_t dp_ret5 = r->dp;
                        if (r->mf != 1) { c->fail = 3; return; }
                        bool x_ret8 = r->xf;
                        uint16_t a_all6 = r->a;
                        uint16_t x_ret9 = r->x;
                        x_flag = x_ret8;
                        a3 = (uint8_t)a_all6;
                        a_hi3 = a_all6 >> 8;
                        x3 = x_ret9;
                        direct_page3 = dp_ret5;
                    }
                    x_flag2 = x_flag;
                    a4 = a3;
                    a_hi4 = a_hi3;
                    x4 = x3;
                    direct_page4 = direct_page3;
                }
                a2 = a4;
                a_hi2 = a_hi4;
                x2 = x4;
                y2 = y_ret;
                direct_page2 = direct_page4;
                break;
            }
            a5 = a2;
            a_hi5 = a_hi2;
            x5 = x2;
            y3 = y2;
            direct_page5 = direct_page2;
        } else {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value4 - 1));
            if ((uint8_t)(value4 - 1) != 0) {
                a1 = (uint8_t)(x_ret + 0x0200);
                a_hi1 = (uint16_t)(x_ret + 0x0200) >> 8;
                x1 = (uint16_t)(x_ret + 0x0200);
                carry1 = x_ret + 0x0200 > 0xFFFF;
                zero1 = (uint8_t)(value4 - 1) == 0;
                negative1 = (uint8_t)(value4 - 1) & 0x80;
                overflow1 = ((x_ret ^ (uint16_t)(x_ret + 0x0200)) & ((uint16_t)(x_ret + 0x0200) ^ 0x0200) & 0x8000) != 0;
                direct_page = dp_ret;
                continue;
            }
            r->a = (uint16_t)(x_ret + 0x0200);
            r->x = (uint16_t)(x_ret + 0x0200);
            r->c = x_ret + 0x0200 > 0xFFFF;
            r->z = (uint8_t)(value4 - 1) == 0;
            r->n = (uint8_t)(value4 - 1) & 0x80;
            r->v = ((x_ret ^ (uint16_t)(x_ret + 0x0200)) & ((uint16_t)(x_ret + 0x0200) ^ 0x0200) & 0x8000) != 0;
            r->mf = 1;
            r->sp -= 4;
            { const uint16_t sp_call = r->sp; JSR(c, 0x1CF8, 0xC10213); GUARD_JSR(c, sp_call, 0x1CF8); } /* skip_actor_script_after_1_bytes */
            r->sp += 4;
            uint16_t dp_ret6 = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            uint16_t a_all7 = r->a;
            uint16_t x_ret11 = r->x;
            a5 = (uint8_t)a_all7;
            a_hi5 = a_all7 >> 8;
            x5 = x_ret11;
            y3 = y1;
            direct_page5 = dp_ret6;
        }
        a1 = a5;
        a_hi1 = a_hi5;
        x1 = x5;
        y1 = y3;
        direct_page = direct_page5;
        break;
    }
    RAM8(0x0000 + sp0 - 3) = a1;
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value5;
    r->x = x1;
    r->y = y1;
    r->c = value6 & 0x01;
    r->z = ((value8 << 8) | value7) == 0;
    r->n = ((value8 << 8) | value7) & 0x8000;
    r->v = value6 & 0x40;
    r->mf = value6 & 0x20;
    r->xf = value6 & 0x10;
    r->db = 0x7E;
    r->dp = (value8 << 8) | value7;
    r->i = value6 & 0x04;
    r->d = value6 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC11CB0, SOM_RTS, "gen", actor_script_controller_distance_gate, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 4, 1, 0, 79, 42)

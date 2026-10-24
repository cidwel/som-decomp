#include "som_c.h"

/* C12457 preempt_hero_program_for_controller_action   [class B, 128 bytes, 65 instructions]
 * Source: src/rom/preempt_hero_program_for_controller_action.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABYV.
 */
static void preempt_hero_program_for_controller_action(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), 3);
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0xE000;
    for (;;) {
        uint16_t value = RAM16(0x0190 + x1);
        if ((value & 0xC57B) != 0) {
            RAM8(0x014C + y) &= 0xFD;
            RAM8(0x0000 + sp0 - 3) = 0xFF;
            uint8_t value4 = RAM8(0x0000 + sp0 - 3);
            uint8_t value5 = RAM8(0x0000 + sp0 - 2);
            uint8_t value6 = RAM8(0x0000 + sp0 - 1);
            uint8_t value7 = RAM8(0x0000 + sp0);
            r->a = ((value & 0xC57B) >> 8 << 8) | value4;
            r->y = y;
            r->v = value5 & 0x40;
            r->mf = value5 & 0x20;
            r->xf = value5 & 0x10;
            r->dp = (value7 << 8) | value6;
            r->i = value5 & 0x04;
            r->d = value5 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
        RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), (uint16_t)(RAM16(0x0001 + (uint16_t)(sp0 - 5)) - 1));
        if (RAM16(0x0001 + (uint16_t)(sp0 - 5)) != 0) {
            uint8_t a_hi1_next = (uint16_t)(x1 + 0x0200) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + 0x0200);
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            continue;
        }
        RAM8(0x0001 + (uint16_t)(sp0 - 5)) = 3;
        uint8_t a_hi2 = (uint16_t)(x1 + 0x0200) >> 8;
        uint16_t x2 = (uint16_t)(x1 + 0x0200);
        uint16_t y1 = y;
        uint16_t direct_page = (uint16_t)(sp0 - 5);
        for (;;) {
            uint8_t value8 = BUS8_RDP(c, (uint16_t)(direct_page + 1));
            r->a = (a_hi2 << 8) | (uint8_t)(3 - value8);
            r->x = x2;
            r->y = y1;
            r->c = value8 <= 3;
            r->z = (uint8_t)(3 - value8) == 0;
            r->n = (uint8_t)(3 - value8) & 0x80;
            r->v = ((value8 ^ 3) & ((uint8_t)(3 - value8) ^ 3) & 0x80) != 0;
            r->mf = 1;
            r->xf = 0;
            r->db = 0x7E;
            r->dp = direct_page;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0x2485, 0xC104D3); GUARD_JSR(c, sp_call, 0x2485); } /* resolve_controller_hero_actor */
            r->sp += 5;
            uint16_t dp_ret = r->dp;
            if (r->mf != 1) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint16_t x_ret = r->x;
            uint16_t y_ret = r->y;
            if (x_ret == 0) {
                uint8_t value9 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value9 - 1));
                if ((uint8_t)(value9 - 1) != 0) {
                    a_hi2 = a_all >> 8;
                    x2 = x_ret;
                    y1 = y_ret;
                    direct_page = dp_ret;
                    continue;
                }
                RAM8(0x014C + y_ret) &= 0xFD;
                RAM8(0x0000 + sp0 - 3) = 0xFF;
                uint8_t value12 = RAM8(0x0000 + sp0 - 3);
                uint8_t value13 = RAM8(0x0000 + sp0 - 2);
                uint8_t value14 = RAM8(0x0000 + sp0 - 1);
                uint8_t value15 = RAM8(0x0000 + sp0);
                r->a = (a_all >> 8 << 8) | value12;
                r->v = value13 & 0x40;
                r->mf = value13 & 0x20;
                r->xf = value13 & 0x10;
                r->dp = (value15 << 8) | value14;
                r->i = value13 & 0x04;
                r->d = value13 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            if (RAM8(0x0011 + x_ret) != 2) {
                uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value17 - 1));
                if ((uint8_t)(value17 - 1) != 0) {
                    a_hi2 = a_all >> 8;
                    x2 = x_ret;
                    y1 = y_ret;
                    direct_page = dp_ret;
                    continue;
                }
                RAM8(0x014C + y_ret) &= 0xFD;
                RAM8(0x0000 + sp0 - 3) = 0xFF;
                uint8_t value20 = RAM8(0x0000 + sp0 - 3);
                uint8_t value21 = RAM8(0x0000 + sp0 - 2);
                uint8_t value22 = RAM8(0x0000 + sp0 - 1);
                uint8_t value23 = RAM8(0x0000 + sp0);
                r->a = (a_all >> 8 << 8) | value20;
                r->v = value21 & 0x40;
                r->mf = value21 & 0x20;
                r->xf = value21 & 0x10;
                r->dp = (value23 << 8) | value22;
                r->i = value21 & 0x04;
                r->d = value21 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            uint8_t value24 = RAM8(0x001C + x_ret);
            if (value24 != 0) {
                uint8_t value25 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value25 - 1));
                if ((uint8_t)(value25 - 1) != 0) {
                    a_hi2 = a_all >> 8;
                    x2 = x_ret;
                    y1 = y_ret;
                    direct_page = dp_ret;
                    continue;
                }
                RAM8(0x014C + y_ret) &= 0xFD;
                RAM8(0x0000 + sp0 - 3) = 0xFF;
                uint8_t value28 = RAM8(0x0000 + sp0 - 3);
                uint8_t value29 = RAM8(0x0000 + sp0 - 2);
                uint8_t value30 = RAM8(0x0000 + sp0 - 1);
                uint8_t value31 = RAM8(0x0000 + sp0);
                r->a = (a_all >> 8 << 8) | value28;
                r->v = value29 & 0x40;
                r->mf = value29 & 0x20;
                r->xf = value29 & 0x10;
                r->dp = (value31 << 8) | value30;
                r->i = value29 & 0x04;
                r->d = value29 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
            RAM8(0x0000 + sp0 - 5) = RAM8(0x014C + y_ret);
            uint8_t value33 = RAM8(0x0180 + y_ret);
            RAM8(0x0000 + sp0 - 6) = y_ret >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)y_ret;
            r->a = (a_all >> 8 << 8) | value33;
            r->x = y_ret;
            r->c = value24 >= 0;
            r->z = y_ret == 0;
            r->n = y_ret & 0x8000;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0x24B6, 0xC1263C); GUARD_JSR(c, sp_call, 0x24B6); } /* restart_actor_program */
            r->sp += 8;
            uint8_t db_ret = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret2 = r->xf;
            uint16_t a_all2 = r->a;
            if (x_ret2) {
                c->fail = 3;
                return;
            } else {
                uint8_t value42 = RAM8(0x0000 + sp0 - 7);
                uint8_t value43 = RAM8(0x0000 + sp0 - 6);
                uint8_t value44 = RAM8(0x0000 + sp0 - 5);
                uint8_t a2;
                if ((value44 & 2) == 0) {
                    a2 = 7;
                } else {
                    a2 = 1;
                }
                BUS8_SET(c, (db_ret << 0x10) + 0x0140 + ((value43 << 8) | value42), a2);
                uint8_t value45 = BUS8_RDP(c, (db_ret << 0x10) + 0x014C + ((value43 << 8) | value42));
                BUS8_SET(c, (db_ret << 0x10) + 0x014C + ((value43 << 8) | value42), value45 | 2);
                RAM8(0x0000 + sp0 - 3) = 0;
                uint8_t value47 = RAM8(0x0000 + sp0 - 3);
                uint8_t value48 = RAM8(0x0000 + sp0 - 2);
                uint8_t value49 = RAM8(0x0000 + sp0 - 1);
                uint8_t value50 = RAM8(0x0000 + sp0);
                r->a = (a_all2 >> 8 << 8) | value47;
                r->y = (value43 << 8) | value42;
                r->v = value48 & 0x40;
                r->mf = value48 & 0x20;
                r->xf = value48 & 0x10;
                r->dp = (value50 << 8) | value49;
                r->i = value48 & 0x04;
                r->d = value48 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0xC12457, SOM_RTS, "gen", preempt_hero_program_for_controller_action, 0, L_A | L_B | L_Y | L_V, 8, 1, 0, 128, 65)

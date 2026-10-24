#include "som_c.h"

/* 7EA3A5 release_controller_routes   [class B, 87 bytes, 54 instructions]
 * Source: src/boot/release_controller_routes.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: BXY.
 */
static void release_controller_routes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    r->a = (a_hi << 8) | a;
    r->z = (uint8_t)((a_hi << 8) | a) == 0;
    r->n = (uint8_t)((a_hi << 8) | a) & 0x80;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 7;
    { const uint16_t sp_call = r->sp; JSR(c, 0xA3BA, 0x7EACE9); GUARD_JSR(c, sp_call, 0xA3BA); } /* current_task_id */
    r->sp += 7;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)a_all);
    uint8_t value = RAM8(0x0000 + sp0 - 6);
    if (value >= 5) {
        BUS8_SET(c, (uint16_t)(dp_ret + 1), 5);
        if (x_ret) {
            uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x92);
            uint8_t a_hi1 = a_all >> 8;
            uint8_t x1 = value2;
            for (;;) {
                uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                uint8_t value4 = BUS8_RDP(c, (db_ret << 0x10) + 1 + x1);
                if (value3 != value4) {
                    uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value5 - 1));
                    if ((uint8_t)(value5 - 1) != 0) {
                        uint8_t a_hi1_next = x1 + 0x10 >> 8;
                        uint8_t x1_next = (uint8_t)(x1 + 0x10);
                        a_hi1 = a_hi1_next;
                        x1 = x1_next;
                        continue;
                    }
                    uint8_t a_hi1_next3 = x1 + 0x10 >> 8;
                    uint8_t x1_next3 = (uint8_t)(x1 + 0x10);
                    a_hi1 = a_hi1_next3;
                    x1 = x1_next3;
                    break;
                }
                BUS8_SET(c, (db_ret << 0x10) + 1 + x1, 0);
                uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value6 - 1));
                if ((uint8_t)(value6 - 1) != 0) {
                    uint8_t a_hi1_next2 = x1 + 0x10 >> 8;
                    uint8_t x1_next2 = (uint8_t)(x1 + 0x10);
                    a_hi1 = a_hi1_next2;
                    x1 = x1_next2;
                    continue;
                }
                uint8_t a_hi1_next4 = x1 + 0x10 >> 8;
                uint8_t x1_next4 = (uint8_t)(x1 + 0x10);
                a_hi1 = a_hi1_next4;
                x1 = x1_next4;
                break;
            }
            uint8_t value7 = RAM8(0x0000 + sp0 - 5);
            uint8_t value9 = RAM8(0x0000 + sp0 - 3);
            uint8_t value10 = RAM8(0x0000 + sp0 - 2);
            uint8_t value11 = RAM8(0x0000 + sp0 - 1);
            uint8_t value12 = RAM8(0x0000 + sp0);
            r->a = (a_hi1 << 8) | value9;
            r->x = x1;
            r->y = (uint8_t)y;
            r->mf = value10 & 0x20;
            r->xf = value10 & 0x10;
            r->db = value7;
            r->dp = (value12 << 8) | value11;
            r->i = value10 & 0x04;
            r->d = value10 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value13 = BUS16_RDP(c, (db_ret << 0x10) + 0x92);
            uint8_t a_hi2 = a_all >> 8;
            uint16_t x2 = value13;
            for (;;) {
                uint8_t value14 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                uint8_t value15 = BUS8_RDP(c, (db_ret << 0x10) + 1 + x2);
                if (value14 != value15) {
                    uint8_t value16 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value16 - 1));
                    if ((uint8_t)(value16 - 1) != 0) {
                        uint8_t a_hi2_next = (uint16_t)(x2 + 0x10) >> 8;
                        uint16_t x2_next = (uint16_t)(x2 + 0x10);
                        a_hi2 = a_hi2_next;
                        x2 = x2_next;
                        continue;
                    }
                    uint8_t a_hi2_next3 = (uint16_t)(x2 + 0x10) >> 8;
                    uint16_t x2_next3 = (uint16_t)(x2 + 0x10);
                    a_hi2 = a_hi2_next3;
                    x2 = x2_next3;
                    break;
                }
                BUS8_SET(c, (db_ret << 0x10) + 1 + x2, 0);
                uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
                BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value17 - 1));
                if ((uint8_t)(value17 - 1) != 0) {
                    uint8_t a_hi2_next2 = (uint16_t)(x2 + 0x10) >> 8;
                    uint16_t x2_next2 = (uint16_t)(x2 + 0x10);
                    a_hi2 = a_hi2_next2;
                    x2 = x2_next2;
                    continue;
                }
                uint8_t a_hi2_next4 = (uint16_t)(x2 + 0x10) >> 8;
                uint16_t x2_next4 = (uint16_t)(x2 + 0x10);
                a_hi2 = a_hi2_next4;
                x2 = x2_next4;
                break;
            }
            uint8_t value18 = RAM8(0x0000 + sp0 - 5);
            uint8_t value20 = RAM8(0x0000 + sp0 - 3);
            uint8_t value21 = RAM8(0x0000 + sp0 - 2);
            uint8_t value22 = RAM8(0x0000 + sp0 - 1);
            uint8_t value23 = RAM8(0x0000 + sp0);
            r->a = (a_hi2 << 8) | value20;
            r->x = x2;
            r->y = y;
            r->mf = value21 & 0x20;
            r->xf = value21 & 0x10;
            r->db = value18;
            r->dp = (value23 << 8) | value22;
            r->i = value21 & 0x04;
            r->d = value21 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    uint16_t value24 = BUS16_RDP(c, (db_ret << 0x10) + 0x92);
    if (x_ret) {
        BUS8_SET(c, (db_ret << 0x10) + 1 + (uint8_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value24), 0);
        uint8_t value25 = RAM8(0x0000 + sp0 - 5);
        uint8_t value27 = RAM8(0x0000 + sp0 - 3);
        uint8_t value28 = RAM8(0x0000 + sp0 - 2);
        uint8_t value29 = RAM8(0x0000 + sp0 - 1);
        uint8_t value30 = RAM8(0x0000 + sp0);
        r->a = ((uint16_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value24) >> 8 << 8) | value27;
        r->x = (uint8_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value24);
        r->y = (uint8_t)y;
        r->mf = value28 & 0x20;
        r->xf = value28 & 0x10;
        r->db = value25;
        r->dp = (value30 << 8) | value29;
        r->i = value28 & 0x04;
        r->d = value28 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        BUS8_SET(c, (db_ret << 0x10) + 1 + (uint16_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value24), 0);
        uint8_t value31 = RAM8(0x0000 + sp0 - 5);
        uint8_t value33 = RAM8(0x0000 + sp0 - 3);
        uint8_t value34 = RAM8(0x0000 + sp0 - 2);
        uint8_t value35 = RAM8(0x0000 + sp0 - 1);
        uint8_t value36 = RAM8(0x0000 + sp0);
        r->a = ((uint16_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value24) >> 8 << 8) | value33;
        r->x = (uint16_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value24);
        r->mf = value34 & 0x20;
        r->xf = value34 & 0x10;
        r->db = value31;
        r->dp = (value36 << 8) | value35;
        r->i = value34 & 0x04;
        r->d = value34 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EA3A5, SOM_RTS, "gen", release_controller_routes, 0, L_B | L_X | L_Y, 8, 1, 0, 87, 54)

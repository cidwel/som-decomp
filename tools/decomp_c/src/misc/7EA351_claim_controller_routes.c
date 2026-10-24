#include "som_c.h"

/* 7EA351 claim_controller_routes   [class B, 84 bytes, 53 instructions]
 * Source: src/boot/claim_controller_routes.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: BYCV.
 */
static void claim_controller_routes(SomCtx *c)
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
    { const uint16_t sp_call = r->sp; JSR(c, 0xA366, 0x7EACE9); GUARD_JSR(c, sp_call, 0xA366); } /* current_task_id */
    r->sp += 7;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    BUS8_SET(c, (uint16_t)(dp_ret + 2), (uint8_t)a_all);
    uint8_t value = RAM8(0x0000 + sp0 - 6);
    if (value < 5) {
        uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x92);
        if (x_ret) {
            uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
            BUS8_SET(c, (db_ret << 0x10) + 1 + (uint8_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value2), value3);
            uint8_t value4 = RAM8(0x0000 + sp0 - 5);
            uint8_t value6 = RAM8(0x0000 + sp0 - 3);
            uint8_t value7 = RAM8(0x0000 + sp0 - 2);
            uint8_t value8 = RAM8(0x0000 + sp0 - 1);
            uint8_t value9 = RAM8(0x0000 + sp0);
            r->a = ((uint16_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value2) >> 8 << 8) | value6;
            r->y = (uint8_t)y;
            r->c = value7 & 0x01;
            r->v = value7 & 0x40;
            r->mf = value7 & 0x20;
            r->xf = value7 & 0x10;
            r->db = value4;
            r->dp = (value9 << 8) | value8;
            r->i = value7 & 0x04;
            r->d = value7 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint8_t value10 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
            BUS8_SET(c, (db_ret << 0x10) + 1 + (uint16_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value2), value10);
            uint8_t value11 = RAM8(0x0000 + sp0 - 5);
            uint8_t value13 = RAM8(0x0000 + sp0 - 3);
            uint8_t value14 = RAM8(0x0000 + sp0 - 2);
            uint8_t value15 = RAM8(0x0000 + sp0 - 1);
            uint8_t value16 = RAM8(0x0000 + sp0);
            r->a = ((uint16_t)(((((a_all >> 8 << 8) | value) & 0xFF) << 1 << 1 << 1 << 1) + value2) >> 8 << 8) | value13;
            r->c = value14 & 0x01;
            r->v = value14 & 0x40;
            r->mf = value14 & 0x20;
            r->xf = value14 & 0x10;
            r->db = value11;
            r->dp = (value16 << 8) | value15;
            r->i = value14 & 0x04;
            r->d = value14 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
    BUS8_SET(c, (uint16_t)(dp_ret + 1), 5);
    if (x_ret) {
        uint8_t value17 = BUS8_RDP(c, (db_ret << 0x10) + 0x92);
        uint8_t a_hi1 = a_all >> 8;
        uint8_t x1 = value17;
        for (;;) {
            uint8_t value18 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
            BUS8_SET(c, (db_ret << 0x10) + 1 + x1, value18);
            uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value19 - 1));
            uint8_t a_hi1_next = x1 + 0x10 >> 8;
            uint8_t x1_next = (uint8_t)(x1 + 0x10);
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            if (!((uint8_t)(value19 - 1) != 0)) break;
        }
        uint8_t value20 = RAM8(0x0000 + sp0 - 5);
        uint8_t value22 = RAM8(0x0000 + sp0 - 3);
        uint8_t value23 = RAM8(0x0000 + sp0 - 2);
        uint8_t value24 = RAM8(0x0000 + sp0 - 1);
        uint8_t value25 = RAM8(0x0000 + sp0);
        r->a = (a_hi1 << 8) | value22;
        r->y = (uint8_t)y;
        r->c = value23 & 0x01;
        r->v = value23 & 0x40;
        r->mf = value23 & 0x20;
        r->xf = value23 & 0x10;
        r->db = value20;
        r->dp = (value25 << 8) | value24;
        r->i = value23 & 0x04;
        r->d = value23 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    } else {
        uint16_t value26 = BUS16_RDP(c, (db_ret << 0x10) + 0x92);
        uint8_t a_hi2 = a_all >> 8;
        uint16_t x2 = value26;
        for (;;) {
            uint8_t value27 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
            BUS8_SET(c, (db_ret << 0x10) + 1 + x2, value27);
            uint8_t value28 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value28 - 1));
            uint8_t a_hi2_next = (uint16_t)(x2 + 0x10) >> 8;
            uint16_t x2_next = (uint16_t)(x2 + 0x10);
            a_hi2 = a_hi2_next;
            x2 = x2_next;
            if (!((uint8_t)(value28 - 1) != 0)) break;
        }
        uint8_t value29 = RAM8(0x0000 + sp0 - 5);
        uint8_t value31 = RAM8(0x0000 + sp0 - 3);
        uint8_t value32 = RAM8(0x0000 + sp0 - 2);
        uint8_t value33 = RAM8(0x0000 + sp0 - 1);
        uint8_t value34 = RAM8(0x0000 + sp0);
        r->a = (a_hi2 << 8) | value31;
        r->y = y;
        r->c = value32 & 0x01;
        r->v = value32 & 0x40;
        r->mf = value32 & 0x20;
        r->xf = value32 & 0x10;
        r->db = value29;
        r->dp = (value34 << 8) | value33;
        r->i = value32 & 0x04;
        r->d = value32 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EA351, SOM_RTS, "gen", claim_controller_routes, 0, L_B | L_Y | L_C | L_V, 8, 1, 0, 84, 53)

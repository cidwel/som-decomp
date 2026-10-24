#include "som_c.h"

/* 7E83AD decode_three_component_lanes   [class B, 53 bytes, 32 instructions]
 * Source: src/boot/decode_three_component_lanes.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: XYCZNV.
 */
static void decode_three_component_lanes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = db;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    uint16_t value = RAM16(0x1001A);
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | 0xE8;
    r->y = value;
    r->z = 0;
    r->n = 1;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 6;
    { const uint16_t sp_call = r->sp; JSR(c, 0x83C4, 0x7E837E); GUARD_JSR(c, sp_call, 0x83C4); } /* decode_component_ramp */
    r->sp += 6;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    if (x_ret) {
        uint8_t value2 = BUS8_RDP(c, (db_ret << 0x10) + 0x1A);
        uint8_t value3 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        r->a = (a_all >> 8 << 8) | 0xE8;
        r->x = value3;
        r->y = (uint8_t)(value2 + 1);
        r->z = 0;
        r->n = 1;
        r->xf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x83CF, 0x7E837E); GUARD_JSR(c, sp_call, 0x83CF); } /* decode_component_ramp */
        r->sp += 6;
        uint16_t dp_ret2 = r->dp;
        uint8_t db_ret2 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret2 = r->xf;
        uint16_t a_all2 = r->a;
        if (x_ret2) {
            uint8_t value4 = BUS8_RDP(c, (db_ret2 << 0x10) + 0x1A);
            uint8_t value5 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
            r->a = (a_all2 >> 8 << 8) | 0xE8;
            r->x = value5;
            r->y = (uint8_t)(value4 + 2);
            r->z = 0;
            r->n = 1;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x83DB, 0x7E837E); GUARD_JSR(c, sp_call, 0x83DB); } /* decode_component_ramp */
            r->sp += 6;
            bool m_ret = r->mf;
            uint8_t value6 = RAM8(0x0000 + sp0 - 5);
            if (m_ret) {
                uint8_t value9 = RAM8(0x0000 + sp0 - 2);
                uint8_t value10 = RAM8(0x0000 + sp0 - 1);
                uint8_t value11 = RAM8(0x0000 + sp0);
                r->c = value9 & 0x01;
                r->z = ((value11 << 8) | value10) == 0;
                r->n = ((value11 << 8) | value10) & 0x8000;
                r->v = value9 & 0x40;
                r->mf = value9 & 0x20;
                r->xf = value9 & 0x10;
                r->db = value6;
                r->dp = (value11 << 8) | value10;
                r->i = value9 & 0x04;
                r->d = value9 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            uint16_t value17 = BUS16_RDP(c, (db_ret2 << 0x10) + 0x1A);
            uint16_t value18 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
            r->a = (a_all2 >> 8 << 8) | 0xE8;
            r->x = value18;
            r->y = (uint16_t)(value17 + 2);
            r->z = 0;
            r->n = 1;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x83DB, 0x7E837E); GUARD_JSR(c, sp_call, 0x83DB); } /* decode_component_ramp */
            r->sp += 6;
            bool m_ret2 = r->mf;
            uint8_t value19 = RAM8(0x0000 + sp0 - 5);
            if (m_ret2) {
                uint8_t value22 = RAM8(0x0000 + sp0 - 2);
                uint8_t value23 = RAM8(0x0000 + sp0 - 1);
                uint8_t value24 = RAM8(0x0000 + sp0);
                r->c = value22 & 0x01;
                r->z = ((value24 << 8) | value23) == 0;
                r->n = ((value24 << 8) | value23) & 0x8000;
                r->v = value22 & 0x40;
                r->mf = value22 & 0x20;
                r->xf = value22 & 0x10;
                r->db = value19;
                r->dp = (value24 << 8) | value23;
                r->i = value22 & 0x04;
                r->d = value22 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        }
    } else {
        uint16_t value30 = BUS16_RDP(c, (db_ret << 0x10) + 0x1A);
        uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        r->a = (a_all >> 8 << 8) | 0xE8;
        r->x = value31;
        r->y = (uint16_t)(value30 + 1);
        r->z = 0;
        r->n = 1;
        r->xf = 0;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0x83CF, 0x7E837E); GUARD_JSR(c, sp_call, 0x83CF); } /* decode_component_ramp */
        r->sp += 6;
        uint16_t dp_ret5 = r->dp;
        uint8_t db_ret5 = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret5 = r->xf;
        uint16_t a_all5 = r->a;
        if (x_ret5) {
            uint8_t value32 = BUS8_RDP(c, (db_ret5 << 0x10) + 0x1A);
            uint8_t value33 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 1));
            r->a = (a_all5 >> 8 << 8) | 0xE8;
            r->x = value33;
            r->y = (uint8_t)(value32 + 2);
            r->z = 0;
            r->n = 1;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x83DB, 0x7E837E); GUARD_JSR(c, sp_call, 0x83DB); } /* decode_component_ramp */
            r->sp += 6;
            bool m_ret3 = r->mf;
            uint8_t value34 = RAM8(0x0000 + sp0 - 5);
            if (m_ret3) {
                uint8_t value37 = RAM8(0x0000 + sp0 - 2);
                uint8_t value38 = RAM8(0x0000 + sp0 - 1);
                uint8_t value39 = RAM8(0x0000 + sp0);
                r->c = value37 & 0x01;
                r->z = ((value39 << 8) | value38) == 0;
                r->n = ((value39 << 8) | value38) & 0x8000;
                r->v = value37 & 0x40;
                r->mf = value37 & 0x20;
                r->xf = value37 & 0x10;
                r->db = value34;
                r->dp = (value39 << 8) | value38;
                r->i = value37 & 0x04;
                r->d = value37 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            uint16_t value45 = BUS16_RDP(c, (db_ret5 << 0x10) + 0x1A);
            uint16_t value46 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 1));
            r->a = (a_all5 >> 8 << 8) | 0xE8;
            r->x = value46;
            r->y = (uint16_t)(value45 + 2);
            r->z = 0;
            r->n = 1;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0x83DB, 0x7E837E); GUARD_JSR(c, sp_call, 0x83DB); } /* decode_component_ramp */
            r->sp += 6;
            bool m_ret4 = r->mf;
            uint8_t value47 = RAM8(0x0000 + sp0 - 5);
            if (m_ret4) {
                uint8_t value50 = RAM8(0x0000 + sp0 - 2);
                uint8_t value51 = RAM8(0x0000 + sp0 - 1);
                uint8_t value52 = RAM8(0x0000 + sp0);
                r->c = value50 & 0x01;
                r->z = ((value52 << 8) | value51) == 0;
                r->n = ((value52 << 8) | value51) & 0x8000;
                r->v = value50 & 0x40;
                r->mf = value50 & 0x20;
                r->xf = value50 & 0x10;
                r->db = value47;
                r->dp = (value52 << 8) | value51;
                r->i = value50 & 0x04;
                r->d = value50 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        }
    }
}
SOM_REGISTER(0x7E83AD, SOM_RTS, "gen", decode_three_component_lanes, 0, L_X | L_Y | L_C | L_Z | L_N | L_V, 7, 1, 0, 53, 32)

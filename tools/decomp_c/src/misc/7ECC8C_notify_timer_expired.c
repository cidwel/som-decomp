#include "som_c.h"

/* 7ECC8C notify_timer_expired   [class B, 43 bytes, 24 instructions]
 * Source: src/boot/notify_timer_expired.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: XY.
 */
static void notify_timer_expired(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint16_t value = RAM16(0x0001 + (uint16_t)(sp0 - 5));
    r->a = (uint16_t)(sp0 - 5);
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCC97, 0x7EB1A9); GUARD_JSR(c, sp_call, 0xCC97); } /* allocate_eight_byte_record */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    bool m_ret = r->mf;
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (m_ret) {
        uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (db_ret << 0x10) + 4 + x_ret2, value2);
        if (x_ret) {
            BUS8_SET(c, (db_ret << 0x10) + 2 + (uint8_t)x_ret2, 0xFF);
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + 1 + (uint8_t)((a_all >> 8 << 8) | value2));
            r->a = (a_all >> 8 << 8) | value3;
            r->x = (uint8_t)x_ret2;
            r->y = (uint8_t)((a_all >> 8 << 8) | value2);
            r->z = value3 == 0;
            r->n = value3 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCCAA, 0x7EB258); GUARD_JSR(c, sp_call, 0xCCAA); } /* append_pending_record */
            r->sp += 5;
            uint16_t dp_ret2 = r->dp;
            uint8_t db_ret2 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret3 = r->xf;
            uint16_t y_ret = r->y;
            if (x_ret3) {
                uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (db_ret2 << 0x10) + value4, 1);
                uint8_t value7 = RAM8(0x0000 + sp0 - 2);
                uint8_t value8 = RAM8(0x0000 + sp0 - 1);
                uint8_t value9 = RAM8(0x0000 + sp0);
                r->x = value4;
                r->y = (uint8_t)y_ret;
                r->mf = value7 & 0x20;
                r->xf = value7 & 0x10;
                r->dp = (value9 << 8) | value8;
                r->i = value7 & 0x04;
                r->d = value7 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret2 + 1));
                BUS8_SET(c, (db_ret2 << 0x10) + value10, 1);
                uint8_t value13 = RAM8(0x0000 + sp0 - 2);
                uint8_t value14 = RAM8(0x0000 + sp0 - 1);
                uint8_t value15 = RAM8(0x0000 + sp0);
                r->x = value10;
                r->mf = value13 & 0x20;
                r->xf = value13 & 0x10;
                r->dp = (value15 << 8) | value14;
                r->i = value13 & 0x04;
                r->d = value13 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret2, 0xFF);
            uint8_t value16 = BUS8_RDP(c, (db_ret << 0x10) + 1 + ((a_all >> 8 << 8) | value2));
            r->a = (a_all >> 8 << 8) | value16;
            r->y = (a_all >> 8 << 8) | value2;
            r->z = value16 == 0;
            r->n = value16 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCCAA, 0x7EB258); GUARD_JSR(c, sp_call, 0xCCAA); } /* append_pending_record */
            r->sp += 5;
            uint16_t dp_ret3 = r->dp;
            uint8_t db_ret3 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret5 = r->xf;
            uint16_t y_ret2 = r->y;
            if (x_ret5) {
                uint8_t value17 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (db_ret3 << 0x10) + value17, 1);
                uint8_t value20 = RAM8(0x0000 + sp0 - 2);
                uint8_t value21 = RAM8(0x0000 + sp0 - 1);
                uint8_t value22 = RAM8(0x0000 + sp0);
                r->x = value17;
                r->y = (uint8_t)y_ret2;
                r->mf = value20 & 0x20;
                r->xf = value20 & 0x10;
                r->dp = (value22 << 8) | value21;
                r->i = value20 & 0x04;
                r->d = value20 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value23 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
                BUS8_SET(c, (db_ret3 << 0x10) + value23, 1);
                uint8_t value26 = RAM8(0x0000 + sp0 - 2);
                uint8_t value27 = RAM8(0x0000 + sp0 - 1);
                uint8_t value28 = RAM8(0x0000 + sp0);
                r->x = value23;
                r->mf = value26 & 0x20;
                r->xf = value26 & 0x10;
                r->dp = (value28 << 8) | value27;
                r->i = value26 & 0x04;
                r->d = value26 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    } else {
        uint16_t value29 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
        BUS16_SET(c, (db_ret << 0x10) + 4 + x_ret2, value29);
        if (x_ret) {
            BUS8_SET(c, (db_ret << 0x10) + 2 + (uint8_t)x_ret2, 0xFF);
            uint8_t value30 = BUS8_RDP(c, (db_ret << 0x10) + 1 + (uint8_t)value29);
            r->a = (value29 >> 8 << 8) | value30;
            r->x = (uint8_t)x_ret2;
            r->y = (uint8_t)value29;
            r->z = value30 == 0;
            r->n = value30 & 0x80;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCCAA, 0x7EB258); GUARD_JSR(c, sp_call, 0xCCAA); } /* append_pending_record */
            r->sp += 5;
            uint16_t dp_ret4 = r->dp;
            uint8_t db_ret4 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret7 = r->xf;
            uint16_t y_ret3 = r->y;
            if (x_ret7) {
                uint8_t value31 = BUS8_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (db_ret4 << 0x10) + value31, 1);
                uint8_t value34 = RAM8(0x0000 + sp0 - 2);
                uint8_t value35 = RAM8(0x0000 + sp0 - 1);
                uint8_t value36 = RAM8(0x0000 + sp0);
                r->x = value31;
                r->y = (uint8_t)y_ret3;
                r->mf = value34 & 0x20;
                r->xf = value34 & 0x10;
                r->dp = (value36 << 8) | value35;
                r->i = value34 & 0x04;
                r->d = value34 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value37 = BUS16_RDP(c, (uint16_t)(dp_ret4 + 1));
                BUS8_SET(c, (db_ret4 << 0x10) + value37, 1);
                uint8_t value40 = RAM8(0x0000 + sp0 - 2);
                uint8_t value41 = RAM8(0x0000 + sp0 - 1);
                uint8_t value42 = RAM8(0x0000 + sp0);
                r->x = value37;
                r->mf = value40 & 0x20;
                r->xf = value40 & 0x10;
                r->dp = (value42 << 8) | value41;
                r->i = value40 & 0x04;
                r->d = value40 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        } else {
            BUS8_SET(c, (db_ret << 0x10) + 2 + x_ret2, 0xFF);
            uint8_t value43 = BUS8_RDP(c, (db_ret << 0x10) + 1 + value29);
            r->a = (value29 >> 8 << 8) | value43;
            r->y = value29;
            r->z = value43 == 0;
            r->n = value43 & 0x80;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 5;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCCAA, 0x7EB258); GUARD_JSR(c, sp_call, 0xCCAA); } /* append_pending_record */
            r->sp += 5;
            uint16_t dp_ret5 = r->dp;
            uint8_t db_ret5 = r->db;
            if (r->mf != 1) { c->fail = 3; return; }
            bool x_ret9 = r->xf;
            uint16_t y_ret4 = r->y;
            if (x_ret9) {
                uint8_t value44 = BUS8_RDP(c, (uint16_t)(dp_ret5 + 1));
                BUS8_SET(c, (db_ret5 << 0x10) + value44, 1);
                uint8_t value47 = RAM8(0x0000 + sp0 - 2);
                uint8_t value48 = RAM8(0x0000 + sp0 - 1);
                uint8_t value49 = RAM8(0x0000 + sp0);
                r->x = value44;
                r->y = (uint8_t)y_ret4;
                r->mf = value47 & 0x20;
                r->xf = value47 & 0x10;
                r->dp = (value49 << 8) | value48;
                r->i = value47 & 0x04;
                r->d = value47 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value50 = BUS16_RDP(c, (uint16_t)(dp_ret5 + 1));
                BUS8_SET(c, (db_ret5 << 0x10) + value50, 1);
                uint8_t value53 = RAM8(0x0000 + sp0 - 2);
                uint8_t value54 = RAM8(0x0000 + sp0 - 1);
                uint8_t value55 = RAM8(0x0000 + sp0);
                r->x = value50;
                r->mf = value53 & 0x20;
                r->xf = value53 & 0x10;
                r->dp = (value55 << 8) | value54;
                r->i = value53 & 0x04;
                r->d = value53 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
    }
}
SOM_REGISTER(0x7ECC8C, SOM_RTS, "gen", notify_timer_expired, 0, L_X | L_Y, 5, 0, 0, 43, 24)

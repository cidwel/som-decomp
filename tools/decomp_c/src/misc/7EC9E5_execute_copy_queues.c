#include "som_c.h"

/* 7EC9E5 execute_copy_queues   [class B, 92 bytes, 51 instructions]
 * Source: src/boot/execute_copy_queues.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: BXYCZNV.
 */
static void execute_copy_queues(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = x >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 6) = 0x7F;
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    uint8_t a_hi1 = (uint16_t)(sp0 - 6) >> 8;
    uint16_t x1 = 0x02FA;
    uint16_t y1 = y;
    for (;;) {
        uint16_t value = BUS16(c, 0x7F0000 + x1);
        if ((value & 0xFF) != 0) {
            uint16_t value2 = RAM16(0x102F6);
            RAM8(0x0000 + sp0 - 7) = (uint16_t)((value & 0xFF) + value2) >> 8;
            RAM8(0x0000 + sp0 - 8) = (uint8_t)((value & 0xFF) + value2);
            r->a = (uint16_t)((value & 0xFF) + value2);
            r->x = (uint16_t)((value & 0xFF) + value2);
            r->y = y1;
            r->c = (value & 0xFF) + value2 > 0xFFFF;
            r->z = (uint16_t)((value & 0xFF) + value2) == 0;
            r->n = (uint16_t)((value & 0xFF) + value2) & 0x8000;
            r->v = (((value & 0xFF) ^ (uint16_t)((value & 0xFF) + value2)) & (value2 ^ (uint16_t)((value & 0xFF) + value2)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = 0x7F;
            r->dp = (uint16_t)(sp0 - 6);
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCA09, 0x7EC985); GUARD_JSR(c, sp_call, 0xCA09); } /* execute_copy_queue_record */
            r->sp += 9;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint16_t y_ret = r->y;
            uint8_t value3 = RAM8(0x0000 + sp0 - 8);
            uint8_t value4 = RAM8(0x0000 + sp0 - 7);
            a_hi1 = a_all >> 8;
            x1 = (value4 << 8) | value3;
            y1 = y_ret;
            continue;
        }
        a_hi1 = 0;
        break;
    }
    uint16_t value5 = RAM16(0x10000 + 0x02FE);
    uint8_t a_hi3;
    uint16_t x3;
    uint16_t y3;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if ((value5 & 0xFF) == 0) {
        a_hi3 = 0;
        x3 = 0x02FE;
        y3 = y1;
        data_bank2 = 0x7F;
        direct_page2 = (uint16_t)(sp0 - 6);
    } else {
        uint8_t a1 = value5 & 0xFF;
        uint8_t a_hi2 = 0;
        uint16_t x2 = 0x02FE;
        uint16_t y2 = y1;
        uint8_t data_bank = 0x7F;
        uint16_t direct_page = (uint16_t)(sp0 - 6);
        for (;;) {
            uint16_t value6 = BUS16_RDP(c, (data_bank << 0x10) + 0x02F6);
            RAM8(0x0000 + sp0 - 7) = (uint16_t)(((a_hi2 << 8) | a1) + value6) >> 8;
            RAM8(0x0000 + sp0 - 8) = (uint8_t)(((a_hi2 << 8) | a1) + value6);
            r->a = (uint16_t)(((a_hi2 << 8) | a1) + value6);
            r->x = (uint16_t)(((a_hi2 << 8) | a1) + value6);
            r->y = y2;
            r->c = ((a_hi2 << 8) | a1) + value6 > 0xFFFF;
            r->z = (uint16_t)(((a_hi2 << 8) | a1) + value6) == 0;
            r->n = (uint16_t)(((a_hi2 << 8) | a1) + value6) & 0x8000;
            r->v = ((((a_hi2 << 8) | a1) ^ (uint16_t)(((a_hi2 << 8) | a1) + value6)) & (value6 ^ (uint16_t)(((a_hi2 << 8) | a1) + value6)) & 0x8000) != 0;
            r->mf = 0;
            r->xf = 0;
            r->db = data_bank;
            r->dp = direct_page;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCA20, 0x7EC985); GUARD_JSR(c, sp_call, 0xCA20); } /* execute_copy_queue_record */
            r->sp += 9;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t y_ret2 = r->y;
            uint8_t value7 = RAM8(0x0000 + sp0 - 8);
            uint8_t value8 = RAM8(0x0000 + sp0 - 7);
            uint16_t value9 = BUS16_RDP(c, (data_bank << 0x10) + ((value8 << 8) | value7));
            RAM8(0x0000 + sp0 - 7) = value9 >> 8;
            RAM8(0x0000 + sp0 - 8) = (uint8_t)value9;
            r->a = value9;
            r->x = (value8 << 8) | value7;
            r->z = value9 == 0;
            r->n = value9 & 0x8000;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0xCA28, 0x7EC93A); GUARD_JSR(c, sp_call, 0xCA28); } /* release_copy_queue_record */
            r->sp += 9;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            a1 = ((RAM8(0x0000 + sp0 - 7) << 8) | RAM8(0x0000 + sp0 - 8)) & 0xFF;
            a_hi2 = 0;
            x2 = (value8 << 8) | value7;
            y2 = y_ret2;
            data_bank = db_ret;
            direct_page = dp_ret;
            if (!(a1 != a_hi2)) break;
        }
        a_hi3 = a_hi2;
        x3 = x2;
        y3 = y2;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    BUS16_SET(c, (data_bank2 << 0x10) + 0x02FE, 0);
    BUS16_SET(c, (data_bank2 << 0x10) + 0x0300, 0x02FE);
    uint8_t value12 = RAM8(0x0000 + sp0 - 6);
    uint8_t value15 = RAM8(0x0000 + sp0 - 3);
    uint8_t value16 = RAM8(0x0000 + sp0 - 2);
    uint8_t value17 = RAM8(0x0000 + sp0 - 1);
    uint8_t value18 = RAM8(0x0000 + sp0);
    r->a = (2 << 8) | value15;
    r->x = x3;
    r->y = y3;
    r->c = value16 & 0x01;
    r->z = ((value18 << 8) | value17) == 0;
    r->n = ((value18 << 8) | value17) & 0x8000;
    r->v = value16 & 0x40;
    r->mf = value16 & 0x20;
    r->xf = value16 & 0x10;
    r->db = value12;
    r->dp = (value18 << 8) | value17;
    r->i = value16 & 0x04;
    r->d = value16 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EC9E5, SOM_RTS, "gen", execute_copy_queues, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 9, 1, 0, 92, 51)

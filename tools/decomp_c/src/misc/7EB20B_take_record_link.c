#include "som_c.h"

/* 7EB20B take_record_link   [class B, 47 bytes, 28 instructions]
 * Source: src/boot/take_record_link.s
 * Entry: M=16 bit X=16 bit DB=$7F D=$4200.  Callers read: ABXYCZNV.
 */
static void take_record_link(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint8_t a2;
    uint8_t a_hi2;
    uint16_t x2;
    uint8_t data_bank2;
    uint16_t direct_page2;
    if (x == 0) {
        a2 = (uint8_t)x;
        a_hi2 = x >> 8;
        x2 = x;
        data_bank2 = 0x7F;
        direct_page2 = 0x4200;
    } else {
        uint8_t a1;
        uint8_t a_hi1;
        uint16_t x1;
        uint8_t data_bank;
        uint16_t direct_page;
        if (x == 0xFFFF) {
            a1 = 0;
            a_hi1 = 0;
            x1 = 0;
            data_bank = 0x7F;
            direct_page = 0x4200;
        } else {
            uint16_t value = BUS16(c, 0x7F0000 + x);
            RAM8(0x0000 + sp0 - 4) = value >> 8;
            RAM8(0x0000 + sp0 - 5) = (uint8_t)value;
            RAM8(0x0000 + sp0 - 6) = x >> 8;
            RAM8(0x0000 + sp0 - 7) = (uint8_t)x;
            r->a = value;
            r->c = x >= 0xFFFF;
            r->z = value == 0;
            r->n = value & 0x8000;
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0xB227, 0x7EACE9); GUARD_JSR(c, sp_call, 0xB227); } /* current_task_id */
            r->sp += 8;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            if (r->mf != 0) { c->fail = 3; return; }
            if (r->xf != 0) { c->fail = 3; return; }
            uint16_t a_all = r->a;
            uint8_t value2 = RAM8(0x0000 + sp0 - 7);
            uint8_t value3 = RAM8(0x0000 + sp0 - 6);
            BUS16_SET(c, (db_ret << 0x10) + ((value3 << 8) | value2), a_all & 0xFF);
            uint8_t value4 = RAM8(0x0000 + sp0 - 5);
            uint8_t value5 = RAM8(0x0000 + sp0 - 4);
            a1 = (uint8_t)((value5 << 8) | value4);
            a_hi1 = value5;
            x1 = (value3 << 8) | value2;
            data_bank = db_ret;
            direct_page = dp_ret;
        }
        a2 = a1;
        a_hi2 = a_hi1;
        x2 = x1;
        data_bank2 = data_bank;
        direct_page2 = direct_page;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi2 << 8) | a2;
    r->x = x2;
    r->c = value7 & 0x01;
    r->z = ((value9 << 8) | value8) == 0;
    r->n = ((value9 << 8) | value8) & 0x8000;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = value6;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB20B, SOM_RTS, "gen", take_record_link, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 8, 0, 0, 47, 28)

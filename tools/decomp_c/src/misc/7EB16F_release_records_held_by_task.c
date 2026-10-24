#include "som_c.h"

/* 7EB16F release_records_held_by_task   [class B, 58 bytes, 37 instructions]
 * Source: src/boot/release_records_held_by_task.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: BCV.
 */
static void release_records_held_by_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)a;
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), a & 0xFF);
    uint16_t value = RAM16(0x102C4);
    uint8_t a_hi1 = 0;
    uint16_t x1 = value;
    uint16_t y1 = 0x0100;
    bool overflow1 = overflow;
    uint8_t data_bank = 0x7F;
    uint16_t direct_page = (uint16_t)(sp0 - 5);
    for (;;) {
        uint16_t value2 = BUS16_RDP(c, (data_bank << 0x10) + x1);
        uint16_t value3 = BUS16_RDP(c, (uint16_t)(direct_page + 1));
        if (value2 != value3) {
            if ((uint16_t)(y1 - 1) != 0) {
                uint8_t a_hi1_next = (uint16_t)(x1 + 8) >> 8;
                uint16_t x1_next = (uint16_t)(x1 + 8);
                uint16_t y1_next = (uint16_t)(y1 - 1);
                bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 8)) & ((uint16_t)(x1 + 8) ^ 8) & 0x8000) != 0;
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                y1 = y1_next;
                overflow1 = overflow1_next;
                continue;
            }
            uint8_t a_hi1_next3 = (uint16_t)(x1 + 8) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 + 8);
            uint16_t y1_next3 = (uint16_t)(y1 - 1);
            bool overflow1_next3 = ((x1 ^ (uint16_t)(x1 + 8)) & ((uint16_t)(x1 + 8) ^ 8) & 0x8000) != 0;
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            y1 = y1_next3;
            overflow1 = overflow1_next3;
            break;
        }
        r->a = value2;
        r->x = x1;
        r->y = y1;
        r->c = value2 >= value3;
        r->z = value2 == value3;
        r->n = (uint16_t)(value2 - value3) & 0x8000;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xB197, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xB197); } /* release_eight_byte_record */
        r->sp += 6;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        if ((uint16_t)(y1 - 1) != 0) {
            uint8_t a_hi1_next2 = (uint16_t)(x1 + 8) >> 8;
            uint16_t x1_next2 = (uint16_t)(x1 + 8);
            uint16_t y1_next2 = (uint16_t)(y1 - 1);
            bool overflow1_next2 = ((x1 ^ (uint16_t)(x1 + 8)) & ((uint16_t)(x1 + 8) ^ 8) & 0x8000) != 0;
            uint8_t data_bank_next = db_ret;
            uint16_t direct_page_next = dp_ret;
            a_hi1 = a_hi1_next2;
            x1 = x1_next2;
            y1 = y1_next2;
            overflow1 = overflow1_next2;
            data_bank = data_bank_next;
            direct_page = direct_page_next;
            continue;
        }
        uint8_t a_hi1_next4 = (uint16_t)(x1 + 8) >> 8;
        uint16_t x1_next4 = (uint16_t)(x1 + 8);
        uint16_t y1_next4 = (uint16_t)(y1 - 1);
        bool overflow1_next4 = ((x1 ^ (uint16_t)(x1 + 8)) & ((uint16_t)(x1 + 8) ^ 8) & 0x8000) != 0;
        uint8_t data_bank_next2 = db_ret;
        uint16_t direct_page_next2 = dp_ret;
        a_hi1 = a_hi1_next4;
        x1 = x1_next4;
        y1 = y1_next4;
        overflow1 = overflow1_next4;
        data_bank = data_bank_next2;
        direct_page = direct_page_next2;
        break;
    }
    uint8_t value4 = RAM8(0x0000 + sp0 - 5);
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value6;
    r->c = value7 & 0x01;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->db = value4;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EB16F, SOM_RTS, "gen", release_records_held_by_task, 0, L_B | L_C | L_V, 8, 0, 0, 58, 37)

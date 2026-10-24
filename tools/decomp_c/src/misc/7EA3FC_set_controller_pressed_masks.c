#include "som_c.h"

/* 7EA3FC set_controller_pressed_masks   [class B, 99 bytes, 58 instructions]
 * Source: src/boot/set_controller_pressed_masks.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: BY.
 */
static void set_controller_pressed_masks(SomCtx *c)
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
    if ((uint32_t)(uint16_t)(sp0 - 7) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)value;
    RAM8(0x0000 + sp0 - 9) = 0x7F;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 7), x);
    uint8_t a_hi3;
    uint16_t y2;
    uint8_t data_bank;
    uint16_t direct_page;
    if ((value & 0xFF) >= 5) {
        r->a = value & 0xFF;
        r->c = (value & 0xFF) >= 5;
        r->z = (value & 0xFF) == 5;
        r->n = (uint16_t)((value & 0xFF) - 5) & 0x8000;
        r->v = (((uint16_t)(sp0 - 5) ^ 2) & ((uint16_t)(sp0 - 5) ^ (uint16_t)(sp0 - 7)) & 0x8000) != 0;
        r->mf = 0;
        r->dp = (uint16_t)(sp0 - 7);
        r->sp -= 8;
        { const uint16_t sp_call = r->sp; JSR(c, 0xA431, 0x7EACE9); GUARD_JSR(c, sp_call, 0xA431); } /* current_task_id */
        r->sp += 8;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 0) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        BUS16_SET(c, (uint16_t)(dp_ret + 3), a_all & 0xFF);
        uint16_t value2 = BUS16_RDP(c, (db_ret << 0x10) + 0x92);
        uint8_t a_hi1 = 0;
        uint16_t x1 = value2;
        uint16_t y1 = 5;
        for (;;) {
            uint16_t value3 = BUS16_RDP(c, (db_ret << 0x10) + 1 + x1);
            uint16_t value4 = BUS16_RDP(c, (uint16_t)(dp_ret + 3));
            uint8_t a_hi2;
            if ((value3 & 0xFF) != value4) {
                a_hi2 = 0;
            } else {
                uint16_t value5 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                BUS16_SET(c, (db_ret << 0x10) + 8 + x1, value5);
                a_hi2 = value5 >> 8;
            }
            uint8_t a_hi1_next = (uint16_t)(x1 + 0x10) >> 8;
            uint16_t x1_next = (uint16_t)(x1 + 0x10);
            uint16_t y1_next = (uint16_t)(y1 - 1);
            a_hi1 = a_hi1_next;
            x1 = x1_next;
            y1 = y1_next;
            if (!(y1 != 0)) break;
        }
        a_hi3 = a_hi1;
        y2 = y1;
        data_bank = db_ret;
        direct_page = dp_ret;
    } else {
        uint16_t value6 = RAM16(0x10092);
        uint16_t value7 = RAM16(0x0001 + (uint16_t)(sp0 - 7));
        BUS16_SET(c, 0x7F0008 + (uint16_t)(((value & 0xFF) << 1 << 1 << 1 << 1) + value6), value7);
        a_hi3 = value7 >> 8;
        y2 = y;
        data_bank = 0x7F;
        direct_page = (uint16_t)(sp0 - 7);
    }
    uint8_t value8 = RAM8(0x0000 + sp0 - 7);
    uint8_t value12 = RAM8(0x0000 + sp0 - 3);
    uint8_t value13 = RAM8(0x0000 + sp0 - 2);
    uint8_t value14 = RAM8(0x0000 + sp0 - 1);
    uint8_t value15 = RAM8(0x0000 + sp0);
    r->a = (a_hi3 << 8) | value12;
    r->y = y2;
    r->mf = value13 & 0x20;
    r->xf = value13 & 0x10;
    r->db = value8;
    r->dp = (value15 << 8) | value14;
    r->i = value13 & 0x04;
    r->d = value13 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA3FC, SOM_RTS, "gen", set_controller_pressed_masks, 0, L_B | L_Y, 10, 1, 0, 99, 58)

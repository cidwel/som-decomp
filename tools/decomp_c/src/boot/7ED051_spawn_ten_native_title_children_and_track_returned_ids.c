#include "som_c.h"

/* 7ED051 spawn_ten_native_title_children_and_track_returned_ids   [class B, 48 bytes, 29 instructions]
 * Source: src/boot/spawn_ten_native_title_children_and_track_returned_ids.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABYCV.
 */
static void spawn_ten_native_title_children_and_track_returned_ids(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 4) + 0x1 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0;
    RAM8(0x0001 + (uint16_t)(sp0 - 4)) = 0x0A;
    uint8_t a_hi1 = (uint16_t)(sp0 - 4) >> 8;
    uint16_t x1 = 0x0318;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    uint8_t data_bank = 0;
    uint16_t direct_page = (uint16_t)(sp0 - 4);
    for (;;) {
        RAM8(0x0000 + sp0 - 4) = x1 >> 8;
        RAM8(0x0000 + sp0 - 5) = (uint8_t)x1;
        r->a = (a_hi1 << 8) | 0x7E;
        r->x = 0x5F1C;
        r->y = y1;
        r->c = carry1;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        r->db = data_bank;
        r->dp = direct_page;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xD069, 0x7EAB88); GUARD_JSR(c, sp_call, 0xD069); } /* create_and_enqueue_task */
        r->sp += 6;
        uint16_t dp_ret = r->dp;
        uint8_t db_ret = r->db;
        if (r->mf != 1) { c->fail = 3; return; }
        if (r->xf != 0) { c->fail = 3; return; }
        uint16_t a_all = r->a;
        uint16_t y_ret = r->y;
        bool carry_ret = r->c;
        bool overflow_ret = r->v;
        uint8_t value = RAM8(0x0000 + sp0 - 5);
        uint8_t value2 = RAM8(0x0000 + sp0 - 4);
        uint8_t a1 = a_all >> 8;
        uint8_t a_hi2 = (uint8_t)a_all;
        uint16_t x2 = (value2 << 8) | value;
        for (;;) {
            uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + x2);
            if (value3 != 0) {
                a1 = value3;
                x2 = (uint16_t)(x2 + 1);
                continue;
            }
            a1 = value3;
            break;
        }
        BUS8_SET(c, (db_ret << 0x10) + x2, a_hi2);
        uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
        BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value4 - 1));
        a_hi1 = a1;
        x1 = (uint16_t)(x2 + 1);
        y1 = y_ret;
        carry1 = carry_ret;
        overflow1 = overflow_ret;
        data_bank = db_ret;
        direct_page = dp_ret;
        if (!((uint8_t)(value4 - 1) != 0)) break;
    }
    uint8_t value5 = RAM8(0x0000 + sp0 - 3);
    uint8_t value6 = RAM8(0x0000 + sp0 - 2);
    uint8_t value7 = RAM8(0x0000 + sp0 - 1);
    uint8_t value8 = RAM8(0x0000 + sp0);
    r->a = (a_hi1 << 8) | value5;
    r->y = y1;
    r->c = value6 & 0x01;
    r->v = value6 & 0x40;
    r->mf = value6 & 0x20;
    r->xf = value6 & 0x10;
    r->db = data_bank;
    r->dp = (value8 << 8) | value7;
    r->i = value6 & 0x04;
    r->d = value6 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED051, SOM_RTS, "gen", spawn_ten_native_title_children_and_track_returned_ids, 0, L_A | L_B | L_Y | L_C | L_V, 6, 1, 0, 48, 29)

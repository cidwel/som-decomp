#include "som_c.h"

/* 7ED023 handle_parent_tracked_task_message   [class B, 46 bytes, 26 instructions]
 * Source: src/boot/handle_parent_tracked_task_message.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$02EE.  Callers read: ABYCV.
 */
static void handle_parent_tracked_task_message(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x02EE) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 5) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 2;
    RAM8(0x0000 + sp0 - 1) = 0xEE;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    uint8_t value = BUS8(c, 0x7F0002 + x);
    RAM8(0x0002 + (uint16_t)(sp0 - 5)) = value;
    r->a = ((uint16_t)(sp0 - 5) >> 8 << 8) | value;
    r->z = value == 0;
    r->n = value & 0x80;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xD033, 0x7EB1DD); GUARD_JSR(c, sp_call, 0xD033); } /* release_eight_byte_record */
    r->sp += 5;
    uint16_t dp_ret = r->dp;
    uint8_t db_ret = r->db;
    if (r->mf != 1) { c->fail = 3; return; }
    if (r->xf != 0) { c->fail = 3; return; }
    uint16_t a_all = r->a;
    BUS8_SET(c, (uint16_t)(dp_ret + 1), 0x14);
    uint8_t value2 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
    uint16_t x1 = 0x0318;
    for (;;) {
        uint8_t value3 = BUS8_RDP(c, (db_ret << 0x10) + x1);
        if (value2 == value3) {
            BUS8_SET(c, (db_ret << 0x10) + x1, 0);
        } else {
            uint8_t value4 = BUS8_RDP(c, (uint16_t)(dp_ret + 1));
            BUS8_SET(c, (uint16_t)(dp_ret + 1), (uint8_t)(value4 - 1));
            if ((uint8_t)(value4 - 1) != 0) {
                x1 = (uint16_t)(x1 + 1);
                continue;
            }
        }
        break;
    }
    uint8_t value6 = RAM8(0x0000 + sp0 - 3);
    uint8_t value7 = RAM8(0x0000 + sp0 - 2);
    uint8_t value8 = RAM8(0x0000 + sp0 - 1);
    uint8_t value9 = RAM8(0x0000 + sp0);
    r->a = (a_all >> 8 << 8) | value6;
    r->y = y;
    r->c = value7 & 0x01;
    r->v = value7 & 0x40;
    r->mf = value7 & 0x20;
    r->xf = value7 & 0x10;
    r->dp = (value9 << 8) | value8;
    r->i = value7 & 0x04;
    r->d = value7 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7ED023, SOM_RTS, "gen", handle_parent_tracked_task_message, 0, L_A | L_B | L_Y | L_C | L_V, 5, 1, 0, 46, 26)

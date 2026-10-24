#include "som_c.h"

/* 7E8F8F reserve_highest_free_hdma_channel   [class B, 56 bytes, 32 instructions]
 * Source: src/boot/reserve_highest_free_hdma_channel.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXY.
 */
static void reserve_highest_free_hdma_channel(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
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
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 5), x);
    uint8_t a_hi1 = (uint16_t)(sp0 - 5) >> 8;
    uint16_t x1 = 8;
    for (;;) {
        uint8_t value = BUS8_RDP(c, (db << 0x10) + 0x71 + x1);
        if (value == 0) {
            RAM8(0x0000 + sp0 - 5) = x1 >> 8;
            RAM8(0x0000 + sp0 - 6) = (uint8_t)x1;
            r->a = (a_hi1 << 8) | value;
            r->x = x1;
            r->y = y;
            r->c = carry;
            r->z = value == 0;
            r->n = value & 0x80;
            r->v = overflow;
            r->dp = (uint16_t)(sp0 - 5);
            r->sp -= 7;
            { const uint16_t sp_call = r->sp; JSR(c, 0x8FB2, 0x7EACE9); GUARD_JSR(c, sp_call, 0x8FB2); } /* current_task_id */
            r->sp += 7;
            uint16_t dp_ret = r->dp;
            uint8_t db_ret = r->db;
            bool m_ret = r->mf;
            bool x_ret = r->xf;
            uint16_t a_all = r->a;
            if (x_ret) {
                c->fail = 3;
                return;
            } else {
                uint8_t value15 = RAM8(0x0000 + sp0 - 6);
                uint8_t value16 = RAM8(0x0000 + sp0 - 5);
                if (m_ret) {
                    BUS8_SET(c, (db_ret << 0x10) + 0x71 + ((value16 << 8) | value15), (uint8_t)a_all);
                    r->a = (a_all >> 8 << 8) | (uint8_t)((uint8_t)((value16 << 8) | value15) - 1);
                    r->x = (value16 << 8) | value15;
                    r->z = (uint8_t)((uint8_t)((value16 << 8) | value15) - 1) == 0;
                    r->n = (uint8_t)((uint8_t)((value16 << 8) | value15) - 1) & 0x80;
                    r->mf = 1;
                    r->xf = 0;
                    r->sp -= 5;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x8FBB, 0x7EC34D); GUARD_JSR(c, sp_call, 0x8FBB); } /* derive_sixteen_bit_mask_from_low_nibble */
                    r->sp += 5;
                    uint16_t x_ret5 = r->x;
                    uint16_t value17 = BUS16_RDP(c, (uint16_t)(dp_ret + 1));
                    BUS8_SET(c, (db_ret << 0x10) + 9 + value17, (uint8_t)x_ret5);
                    uint8_t value20 = RAM8(0x0000 + sp0 - 2);
                    uint8_t value21 = RAM8(0x0000 + sp0 - 1);
                    uint8_t value22 = RAM8(0x0000 + sp0);
                    r->x = value17;
                    r->mf = value20 & 0x20;
                    r->xf = value20 & 0x10;
                    r->dp = (value22 << 8) | value21;
                    r->i = value20 & 0x04;
                    r->d = value20 & 0x08;
                    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                    RETURN_RTS(c);
                } else {
                    c->fail = 3;
                    return;
                }
            }
        }
        if ((uint16_t)(x1 - 1) != 0) {
            x1 = (uint16_t)(x1 - 1);
            continue;
        }
        BUS8_SET(c, (db << 0x10) + 0x0F + RAM16(0x0001 + (uint16_t)(sp0 - 5)), 0);
        uint8_t value31 = RAM8(0x0000 + sp0 - 3);
        uint8_t value32 = RAM8(0x0000 + sp0 - 2);
        uint8_t value33 = RAM8(0x0000 + sp0 - 1);
        uint8_t value34 = RAM8(0x0000 + sp0);
        r->a = (a_hi1 << 8) | value31;
        r->x = 0;
        r->y = y;
        r->mf = value32 & 0x20;
        r->xf = value32 & 0x10;
        r->dp = (value34 << 8) | value33;
        r->i = value32 & 0x04;
        r->d = value32 & 0x08;
        if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7E8F8F, SOM_RTS, "gen", reserve_highest_free_hdma_channel, 0, L_B | L_X | L_Y, 7, 1, 0, 56, 32)

#include "som_c.h"

/* 7EBF2A copy_and_submit_colour_tile   [class B, 68 bytes, 45 instructions]
 * Source: src/boot/copy_and_submit_colour_tile.s
 * Entry: M=8 bit X=16 bit DB=$00 D=$05BF.  Callers read: XY.
 */
static void copy_and_submit_colour_tile(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x05BF) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 5;
    RAM8(0x0000 + sp0 - 1) = 0xBF;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 3) = x >> 8;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)x;
    RAM8(0x0000 + sp0 - 5) = 0;
    RAM8(0x0000 + sp0 - 6) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 7) = 0x7F;
    RAM8(0x0000 + sp0 - 6) = 0;
    RAM8(0x0000 + sp0 - 7) = 0x40;
    RAM8(0x0000 + sp0 - 8) = (uint8_t)((a_hi << 8) | a);
    RAM8(0x0000 + sp0 - 9) = x >> 8;
    RAM8(0x0000 + sp0 - 0x0A) = (uint8_t)x;
    r->a = (a_hi << 8) | a;
    r->x = 0x40;
    r->y = 0x40;
    r->z = 0;
    r->n = 0;
    r->db = 0x7F;
    r->dp = (uint16_t)(sp0 - 5);
    r->sp -= 11;
    { const uint16_t sp_call = r->sp; JSR(c, 0xBF45, 0x7EB081); GUARD_JSR(c, sp_call, 0xBF45); } /* allocate_boot_heap_bytes_without_fill */
    r->sp += 11;
    uint16_t dp_ret = r->dp;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 1), x_ret2);
        RAM8(0x0000 + sp0 - 0x0B) = 0x7F;
        RAM8(0x0000 + sp0 - 0x0C) = x_ret2 >> 8;
        RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)x_ret2;
        r->a = (a_all >> 8 << 8) | 0x7F;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 14;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBF4E, 0x7EC44E); GUARD_JSR(c, sp_call, 0xBF4E); } /* copy_far_stack_arguments */
        r->sp += 14;
        uint16_t dp_ret3 = r->dp;
        r->a = ((uint16_t)((uint16_t)(sp0 - 0x0E) + 8) >> 8 << 8) | 0x43;
        r->c = (uint16_t)(sp0 - 0x0E) + 8 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)(sp0 - 0x0E) ^ (uint16_t)((uint16_t)(sp0 - 0x0E) + 8)) & ((uint16_t)((uint16_t)(sp0 - 0x0E) + 8) ^ 8) & 0x8000) != 0;
        r->mf = 1;
        r->sp -= 6;
        { const uint16_t sp_call = r->sp; JSR(c, 0xBF5D, 0x7E81D6); GUARD_JSR(c, sp_call, 0xBF5D); } /* allocate_graphics_workspace_block */
        r->sp += 6;
        if (r->mf != 1) { c->fail = 3; return; }
        bool x_ret13 = r->xf;
        uint16_t x_ret14 = r->x;
        if (x_ret13) {
            uint8_t value19 = BUS8_RDP(c, (uint16_t)(dp_ret3 + 1));
            r->a = 0xFF7F;
            r->x = (uint8_t)x_ret14;
            r->y = value19;
            r->z = value19 == 0;
            r->n = value19 & 0x80;
            r->xf = 1;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBF67, 0x7E82D4); GUARD_JSR(c, sp_call, 0xBF67); } /* queue_single_graphics_block */
            r->sp += 6;
            bool m_ret5 = r->mf;
            uint8_t value20 = RAM8(0x0000 + sp0 - 5);
            if (m_ret5) {
                uint8_t value23 = RAM8(0x0000 + sp0 - 2);
                uint8_t value24 = RAM8(0x0000 + sp0 - 1);
                uint8_t value25 = RAM8(0x0000 + sp0);
                r->mf = value23 & 0x20;
                r->xf = value23 & 0x10;
                r->db = value20;
                r->dp = (value25 << 8) | value24;
                r->i = value23 & 0x04;
                r->d = value23 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        } else {
            uint16_t value31 = BUS16_RDP(c, (uint16_t)(dp_ret3 + 1));
            r->a = 0xFF7F;
            r->y = value31;
            r->z = value31 == 0;
            r->n = value31 & 0x8000;
            r->xf = 0;
            r->sp -= 6;
            { const uint16_t sp_call = r->sp; JSR(c, 0xBF67, 0x7E82D4); GUARD_JSR(c, sp_call, 0xBF67); } /* queue_single_graphics_block */
            r->sp += 6;
            bool m_ret6 = r->mf;
            uint8_t value32 = RAM8(0x0000 + sp0 - 5);
            if (m_ret6) {
                uint8_t value35 = RAM8(0x0000 + sp0 - 2);
                uint8_t value36 = RAM8(0x0000 + sp0 - 1);
                uint8_t value37 = RAM8(0x0000 + sp0);
                r->mf = value35 & 0x20;
                r->xf = value35 & 0x10;
                r->db = value32;
                r->dp = (value37 << 8) | value36;
                r->i = value35 & 0x04;
                r->d = value35 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                c->fail = 3;
                return;
            }
        }
    }
}
SOM_REGISTER(0x7EBF2A, SOM_RTS, "gen", copy_and_submit_colour_tile, 0, L_X | L_Y, 14, 1, 0, 68, 45)

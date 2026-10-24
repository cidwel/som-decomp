#include "som_c.h"

/* 7E886E prepare_title_auxiliary_hdma   [class B, 97 bytes, 52 instructions]
 * Source: src/boot/prepare_title_auxiliary_hdma.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$06F1.  Callers read: BXYCV.
 */
static void prepare_title_auxiliary_hdma(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x06F1) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    if ((uint32_t)(uint16_t)(sp0 - 9) + 0x2 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0xF1;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM16_SET(0x0001 + (uint16_t)(sp0 - 9), x);
    RAM8(0x0000 + sp0 - 9) = 0;
    RAM8(0x0000 + sp0 - 0x0A) = 0x34;
    RAM8(0x0000 + sp0 - 0x0B) = 0x7E;
    RAM8(0x0000 + sp0 - 0x0C) = y >> 8;
    RAM8(0x0000 + sp0 - 0x0D) = (uint8_t)y;
    r->a = ((uint16_t)(sp0 - 9) >> 8 << 8) | 0x7E;
    r->x = 0x34;
    r->c = (uint16_t)(sp0 - 3) >= 6;
    r->z = 0;
    r->n = 0;
    r->v = (((uint16_t)(sp0 - 3) ^ 6) & ((uint16_t)(sp0 - 3) ^ (uint16_t)(sp0 - 9)) & 0x8000) != 0;
    r->dp = (uint16_t)(sp0 - 9);
    r->sp -= 14;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8887, 0x7EB081); GUARD_JSR(c, sp_call, 0x8887); } /* allocate_boot_heap_bytes_without_fill */
    r->sp += 14;
    uint16_t dp_ret = r->dp;
    if (r->mf != 1) { c->fail = 3; return; }
    bool x_ret = r->xf;
    uint16_t a_all = r->a;
    uint16_t x_ret2 = r->x;
    if (x_ret) {
        c->fail = 3;
        return;
    } else {
        BUS16_SET(c, (uint16_t)(dp_ret + 3), x_ret2);
        RAM8(0x0000 + sp0 - 0x0E) = 0x7F;
        RAM8(0x0000 + sp0 - 0x0F) = x_ret2 >> 8;
        RAM8(0x0000 + sp0 - 0x10) = (uint8_t)x_ret2;
        r->a = (a_all >> 8 << 8) | 0x7F;
        r->z = 0;
        r->n = 0;
        r->xf = 0;
        r->sp -= 17;
        { const uint16_t sp_call = r->sp; JSR(c, 0x8890, 0x7EC44E); GUARD_JSR(c, sp_call, 0x8890); } /* copy_far_stack_arguments */
        r->sp += 17;
        r->a = ((uint16_t)((uint16_t)(sp0 - 0x11) + 8) >> 8 << 8) | 5;
        r->c = (uint16_t)(sp0 - 0x11) + 8 > 0xFFFF;
        r->z = 0;
        r->n = 0;
        r->v = (((uint16_t)(sp0 - 0x11) ^ (uint16_t)((uint16_t)(sp0 - 0x11) + 8)) & ((uint16_t)((uint16_t)(sp0 - 0x11) + 8) ^ 8) & 0x8000) != 0;
        r->mf = 1;
        r->sp -= 9;
        { const uint16_t sp_call = r->sp; JSR(c, 0x889F, 0x7E8FC7); GUARD_JSR(c, sp_call, 0x889F); } /* allocate_transfer_descriptor */
        r->sp += 9;
        uint16_t dp_ret7 = r->dp;
        uint8_t db_ret5 = r->db;
        bool x_ret13 = r->xf;
        uint16_t x_ret14 = r->x;
        uint16_t value6 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 3));
        BUS16_SET(c, (db_ret5 << 0x10) + 2 + x_ret14, value6);
        if (x_ret13) {
            uint8_t value7 = BUS8_RDP(c, (uint16_t)(dp_ret7 + 1));
            BUS16_SET(c, (db_ret5 << 0x10) + value7, value6);
            BUS16_SET(c, (db_ret5 << 0x10) + 2 + value7, (uint8_t)x_ret14);
            BUS8_SET(c, (db_ret5 << 0x10) + 4 + (uint8_t)x_ret14, 0x7F);
            BUS8_SET(c, (db_ret5 << 0x10) + 1 + (uint8_t)x_ret14, 0x22);
            BUS8_SET(c, (db_ret5 << 0x10) + (uint8_t)x_ret14, 2);
            r->a = 2;
            r->x = (uint8_t)x_ret14;
            r->y = value7;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 1;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x88C3, 0x7E90DA); GUARD_JSR(c, sp_call, 0x88C3); } /* submit_transfer_or_program_hdma */
            r->sp += 9;
            uint8_t value8 = RAM8(0x0000 + sp0 - 2);
            uint8_t value9 = RAM8(0x0000 + sp0 - 1);
            uint8_t value10 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
            r->c = value8 & 0x01;
            r->v = value8 & 0x40;
            r->mf = value8 & 0x20;
            r->xf = value8 & 0x10;
            r->dp = (value10 << 8) | value9;
            r->i = value8 & 0x04;
            r->d = value8 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        } else {
            uint16_t value11 = BUS16_RDP(c, (uint16_t)(dp_ret7 + 1));
            BUS16_SET(c, (db_ret5 << 0x10) + value11, value6);
            BUS16_SET(c, (db_ret5 << 0x10) + 2 + value11, x_ret14);
            BUS8_SET(c, (db_ret5 << 0x10) + 4 + x_ret14, 0x7F);
            BUS8_SET(c, (db_ret5 << 0x10) + 1 + x_ret14, 0x22);
            BUS8_SET(c, (db_ret5 << 0x10) + x_ret14, 2);
            r->a = (x_ret14 >> 8 << 8) | 2;
            r->y = value11;
            r->z = 0;
            r->n = 0;
            r->mf = 1;
            r->xf = 0;
            r->sp -= 9;
            { const uint16_t sp_call = r->sp; JSR(c, 0x88C3, 0x7E90DA); GUARD_JSR(c, sp_call, 0x88C3); } /* submit_transfer_or_program_hdma */
            r->sp += 9;
            uint8_t value12 = RAM8(0x0000 + sp0 - 2);
            uint8_t value13 = RAM8(0x0000 + sp0 - 1);
            uint8_t value14 = RAM8(0x0000 + sp0);
            r->a = (uint16_t)((uint16_t)(sp0 - 9) + 6);
            r->c = value12 & 0x01;
            r->v = value12 & 0x40;
            r->mf = value12 & 0x20;
            r->xf = value12 & 0x10;
            r->dp = (value14 << 8) | value13;
            r->i = value12 & 0x04;
            r->d = value12 & 0x08;
            if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
            RETURN_RTS(c);
        }
    }
}
SOM_REGISTER(0x7E886E, SOM_RTS, "gen", prepare_title_auxiliary_hdma, 0, L_B | L_X | L_Y | L_C | L_V, 17, 1, 0, 97, 52)

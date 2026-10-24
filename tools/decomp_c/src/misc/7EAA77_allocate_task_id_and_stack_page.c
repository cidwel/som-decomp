#include "som_c.h"

/* 7EAA77 allocate_task_id_and_stack_page   [class B, 96 bytes, 53 instructions]
 * Source: src/boot/allocate_task_id_and_stack_page.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void allocate_task_id_and_stack_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    if ((uint32_t)(uint16_t)(sp0 - 8) + 0x5 > 0x1FFF) { c->fail = 3; return; }
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = a_hi;
    RAM8(0x0000 + sp0 - 4) = (uint8_t)((a_hi << 8) | a);
    uint16_t value = RAM16(0x0000 + sp0 - 4);
    RAM16_SET(0x0004 + (uint16_t)(sp0 - 8), y);
    RAM8(0x0001 + (uint16_t)(sp0 - 8)) = (uint8_t)value;
    RAM16_SET(0x0002 + (uint16_t)(sp0 - 8), x);
    uint8_t a_hi1 = value >> 8;
    uint16_t x1 = 0xAA;
    uint16_t y1 = 0x14;
    for (;;) {
        uint8_t value2 = BUS8_RDP(c, (db << 0x10) + x1);
        if (value2 == 0) {
            BUS8_SET(c, (db << 0x10) + x1, RAM8(0x0001 + (uint16_t)(sp0 - 8)));
            uint16_t value4 = RAM16(0x0002 + (uint16_t)(sp0 - 8));
            BUS8_SET(c, (db << 0x10) + 4 + value4, (uint8_t)((uint8_t)y1 - 0x17) ^ 0xFF);
            BUS16_SET(c, (db << 0x10) + 6 + value4, (uint16_t)((((uint8_t)(((uint8_t)((uint8_t)y1 - 0x17) ^ 0xFF) - 1) << 8) | 0) + 0x01F6));
            uint16_t value5 = RAM16(0x0004 + (uint16_t)(sp0 - 8));
            r->a = (uint16_t)((((uint8_t)(((uint8_t)((uint8_t)y1 - 0x17) ^ 0xFF) - 1) << 8) | 0) + 0x0100);
            r->x = (uint16_t)((((uint8_t)(((uint8_t)((uint8_t)y1 - 0x17) ^ 0xFF) - 1) << 8) | 0) + 0x0100);
            r->y = value5;
            r->c = (uint16_t)((((uint8_t)(((uint8_t)((uint8_t)y1 - 0x17) ^ 0xFF) - 1) << 8) | 0) + 0x01F6) >= 0xF6;
            r->z = value5 == 0;
            r->n = value5 & 0x8000;
            r->v = (((uint16_t)((((uint8_t)(((uint8_t)((uint8_t)y1 - 0x17) ^ 0xFF) - 1) << 8) | 0) + 0x01F6) ^ 0xF6) & ((uint16_t)((((uint8_t)(((uint8_t)((uint8_t)y1 - 0x17) ^ 0xFF) - 1) << 8) | 0) + 0x01F6) ^ (uint16_t)((((uint8_t)(((uint8_t)((uint8_t)y1 - 0x17) ^ 0xFF) - 1) << 8) | 0) + 0x0100)) & 0x8000) != 0;
            r->mf = 0;
            r->dp = (uint16_t)(sp0 - 8);
            r->sp -= 8;
            { const uint16_t sp_call = r->sp; JSR(c, 0xAAC7, 0x7EAA42); GUARD_JSR(c, sp_call, 0xAAC7); } /* prepare_initial_task_stack */
            r->sp += 8;
            uint16_t dp_ret = r->dp;
            bool x_ret = r->xf;
            if (x_ret) {
                uint8_t value6 = BUS8_RDP(c, (uint16_t)(dp_ret + 2));
                uint8_t value7 = RAM8(0x0000 + sp0 - 2);
                uint8_t value8 = RAM8(0x0000 + sp0 - 1);
                uint8_t value9 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value6;
                r->y = (uint8_t)value5;
                r->c = value7 & 0x01;
                r->v = value7 & 0x40;
                r->mf = value7 & 0x20;
                r->xf = value7 & 0x10;
                r->dp = (value9 << 8) | value8;
                r->i = value7 & 0x04;
                r->d = value7 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            } else {
                uint16_t value10 = BUS16_RDP(c, (uint16_t)(dp_ret + 2));
                uint8_t value11 = RAM8(0x0000 + sp0 - 2);
                uint8_t value12 = RAM8(0x0000 + sp0 - 1);
                uint8_t value13 = RAM8(0x0000 + sp0);
                r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
                r->x = value10;
                r->c = value11 & 0x01;
                r->v = value11 & 0x40;
                r->mf = value11 & 0x20;
                r->xf = value11 & 0x10;
                r->dp = (value13 << 8) | value12;
                r->i = value11 & 0x04;
                r->d = value11 & 0x08;
                if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
                RETURN_RTS(c);
            }
        }
        if ((uint16_t)(y1 - 1) != 0) {
            x1 = (uint16_t)(x1 + 1);
            y1 = (uint16_t)(y1 - 1);
            continue;
        }
        r->a = (uint16_t)((uint16_t)(sp0 - 8) + 5);
        r->x = 0;
        r->y = (uint16_t)(y1 - 1);
        r->c = carry;
        r->v = overflow;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0x7EAA77, SOM_RTS, "gen", allocate_task_id_and_stack_page, 0, L_B | L_X | L_Y | L_C | L_V, 8, 1, 0, 96, 53)

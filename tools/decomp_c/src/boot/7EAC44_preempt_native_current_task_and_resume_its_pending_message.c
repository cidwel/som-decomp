#include "som_c.h"

/* 7EAC44 preempt_native_current_task_and_resume_its_pending_message   [class A, 37 bytes, 22 instructions]
 * Source: src/boot/preempt_native_current_task_and_resume_its_pending_message.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: ABXYV.
 */
static void preempt_native_current_task_and_resume_its_pending_message(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0x42;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = ((overflow << 6) | (d_entry << 3)) | (i_entry << 2) | carry;
    uint16_t value = RAM16(0x1009E);
    uint16_t value2 = BUS16(c, 0x7F000A + value);
    uint8_t a1;
    uint8_t a_hi1;
    bool zero1;
    bool negative1;
    if (value2 != 0) {
        a1 = (uint8_t)value2;
        a_hi1 = value2 >> 8;
        zero1 = value2 == 0;
        negative1 = value2 & 0x8000;
    } else {
        BUS16_SET(c, 0x7F000A + value, 0xFFFF);
        a1 = 0xFF;
        a_hi1 = 0xFF;
        zero1 = 0;
        negative1 = 1;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = value;
    r->z = zero1;
    r->n = negative1;
    r->mf = 0;
    r->i = 1;
    r->sp -= 5;
    { const uint16_t sp_call = r->sp; JSR(c, 0xAC63, 0x7EA911); GUARD_JSR(c, sp_call, 0xAC63); } /* suspend_current_task */
    r->sp += 5;
    uint16_t x_ret2 = r->x;
    uint16_t y_ret = r->y;
    uint8_t value3 = RAM8(0x0000 + sp0 - 4);
    uint8_t value4 = RAM8(0x0000 + sp0 - 3);
    uint8_t value5 = RAM8(0x0000 + sp0 - 2);
    uint8_t value6 = RAM8(0x0000 + sp0 - 1);
    uint8_t value7 = RAM8(0x0000 + sp0);
    r->x = x_ret2 & 0xFFFF - ((value3 >> 4) & 1) * 0xFF00;
    r->y = y_ret & 0xFFFF - ((value3 >> 4) & 1) * 0xFF00;
    r->v = value5 & 0x40;
    r->mf = value5 & 0x20;
    r->xf = value5 & 0x10;
    r->db = value4;
    r->dp = (value7 << 8) | value6;
    r->i = value5 & 0x04;
    r->d = value5 & 0x08;
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAC44, SOM_RTS, "gen", preempt_native_current_task_and_resume_its_pending_message, 0, L_A | L_B | L_X | L_Y | L_V, 5, 1, 0, 37, 22)

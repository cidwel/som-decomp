#include "som_c.h"

/* 7E8DA0 stop_title_buffer_task   [class A, 12 bytes, 8 instructions]
 * Source: src/boot/stop_title_buffer_task.s
 * Entry: M=8 bit X=16 bit DB=$7F D=$0600.  Callers read: ABXYCZNV.
 */
static void stop_title_buffer_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x0600) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 6;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->sp -= 3;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8DA8, 0x7E8CA6); GUARD_JSR(c, sp_call, 0x8DA8); } /* cleanup_title_buffer_display */
    r->sp += 3;
    uint8_t value = RAM8(0x0000 + sp0 - 2);
    uint8_t value2 = RAM8(0x0000 + sp0 - 1);
    uint8_t value3 = RAM8(0x0000 + sp0);
    r->c = value & 0x01;
    r->z = ((value3 << 8) | value2) == 0;
    r->n = ((value3 << 8) | value2) & 0x8000;
    r->v = value & 0x40;
    r->mf = value & 0x20;
    r->xf = value & 0x10;
    r->dp = (value3 << 8) | value2;
    r->i = value & 0x04;
    r->d = value & 0x08;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E8DA0, SOM_RTS, "gen", stop_title_buffer_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 3, 1, 0, 12, 8)

#include "som_c.h"

/* 7EAD41 select_native_task_stack_page_as_direct_page   [class A, 10 bytes, 7 instructions]
 * Source: src/boot/select_native_task_stack_page_as_direct_page.s
 * Documented in docs/boot-native-title-particle-initialize.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCZNV.
 */
static void select_native_task_stack_page_as_direct_page(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = ((((negative << 7) | (overflow << 6) | 0x20) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    r->a = (r->a & 0x00FF) | ((((uint16_t)(sp0 - 1) & 0x1F00) >> 8) << 8);
    r->dp = (uint16_t)(sp0 - 1) & 0x1F00;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EAD41, SOM_RTS, "gen", select_native_task_stack_page_as_direct_page, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 10, 7)

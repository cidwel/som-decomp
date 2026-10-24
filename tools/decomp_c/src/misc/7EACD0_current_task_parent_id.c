#include "som_c.h"

/* 7EACD0 current_task_parent_id   [class A, 25 bytes, 16 instructions]
 * Source: src/boot/current_task_parent_id.s
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: ABXYCZNV.
 */
static void current_task_parent_id(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t dp = r->dp;
    const uint16_t a = r->a;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = dp >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)dp;
    RAM8(0x0000 + sp0 - 2) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 3) = 0x7F;
    RAM8(0x0000 + sp0 - 4) = 0x7F;
    uint16_t value = RAM16(0x1009E);
    uint8_t a1;
    if (value == 0) {
        a1 = 1;
    } else {
        uint8_t value2 = BUS8(c, 0x7F0005 + value);
        a1 = value2;
    }
    r->a = (a >> 8 << 8) | a1;
    r->x = value;
    r->z = dp == 0;
    r->n = dp & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EACD0, SOM_RTS, "gen", current_task_parent_id, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 5, 0, 0, 25, 16)

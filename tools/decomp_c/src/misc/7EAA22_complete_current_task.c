#include "som_c.h"

/* 7EAA22 complete_current_task   [class A, 32 bytes, 14 instructions]
 * Source: src/boot/complete_current_task.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: ABXYCZNV.
 */
static void complete_current_task(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t sp0 = r->sp;
    RAM8(0x0000 + sp0) = 0x7F;
    uint16_t value = RAM16(0x1009E);
    BUS8_SET(c, 0x7F0002 + value, 0x10);
    uint16_t value2 = RAM16(0x100A4);
    BUS16_SET(c, 0x7F0000 + value, value2);
    RAM16_SET(0x100A4, value);
    RAM16_SET(0x1009A, (uint16_t)(RAM16(0x1009A) - 1));
    r->a = value2;
    r->x = value;
    r->z = RAM16(0x1009A) == 0;
    r->n = RAM16(0x1009A) & 0x8000;
    r->mf = 0;
    r->db = 0x7F;
    r->i = 1;
    TAIL_CALL(c, 0x7EA948, SOM_RTL); /* select_next_task */
}
SOM_REGISTER(0x7EAA22, SOM_RTL, "gen", complete_current_task, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 32, 14)

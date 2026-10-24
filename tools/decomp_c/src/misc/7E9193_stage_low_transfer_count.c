#include "som_c.h"

/* 7E9193 stage_low_transfer_count   [class A, 15 bytes, 9 instructions]
 * Source: src/boot/stage_low_transfer_count.s
 * Documented in docs/boot.md
 * Entry: M=8 bit X=16 bit DB=$7F D=$4200.  Callers read: ABXY.
 */
static void stage_low_transfer_count(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 0)) return;
    if (r->dp != 0x4200) { c->fail = 3; return; }
    uint8_t value = RAM8(0x1006C);
    RAM8(0x1006E) = value;
    SET_A8(r, value);
    RETURN_RTS(c);
}
SOM_REGISTER(0x7E9193, SOM_RTS, "gen", stage_low_transfer_count, 0, L_A | L_B | L_X | L_Y, 3, 1, 0, 15, 9)

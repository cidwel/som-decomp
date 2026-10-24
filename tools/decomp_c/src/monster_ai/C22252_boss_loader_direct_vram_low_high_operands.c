#include "som_c.h"

/* C22252 boss_loader_direct_vram_low_high_operands   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/boss_loader_direct_vram_low_high_operands.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void boss_loader_direct_vram_low_high_operands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    uint8_t value;
    BUS8_OK(c, (RAM8(0x0032 + dp) << 0x10) + RAM16(0x0030 + dp), value);
    RAM8(0x0030 + dp)++;
    RAM8(0x0030 + dp)++;
    r->a = (a_hi << 8) | value;
    r->z = RAM8(0x0030 + dp) == 0;
    r->n = RAM8(0x0030 + dp) & 0x80;
    TAIL_CALL(c, 0xC22534, SOM_RTS); /* prepare_boss_resource_vram_word_expansion */
}
SOM_REGISTER(0xC22252, SOM_RTS, "hand", boss_loader_direct_vram_low_high_operands, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 4)

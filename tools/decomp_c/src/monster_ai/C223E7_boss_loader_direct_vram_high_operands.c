#include "som_c.h"

/* C223E7 boss_loader_direct_vram_high_operands   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/boss_loader_direct_vram_high_operands.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_loader_direct_vram_high_operands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = BUS8_RDL(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230), RAM8(0x0232));
    RAM8(0x0230)++;
    RAM8(0x0230)++;
    r->a = (a_hi << 8) | value;
    r->z = RAM8(0x0230) == 0;
    r->n = RAM8(0x0230) & 0x80;
    TAIL_CALL(c, 0xC225AD, SOM_RTS); /* prepare_boss_resource_vram_high_expansion */
}
SOM_REGISTER(0xC223E7, SOM_RTS, "gen", boss_loader_direct_vram_high_operands, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 4)

#include "som_c.h"

/* C2246D boss_loader_indirect_vram_high_operands   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/boss_loader_indirect_vram_high_operands.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void boss_loader_indirect_vram_high_operands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = BUS16(c, (RAM8(0x0232) << 0x10) + RAM16(0x0230));
    RAM16_SET(0x0230, (uint16_t)(RAM16(0x0230) + 1));
    RAM16_SET(0x0230, (uint16_t)(RAM16(0x0230) + 1));
    r->a = value;
    r->z = RAM16(0x0230) == 0;
    r->n = RAM16(0x0230) & 0x8000;
    TAIL_CALL(c, 0xC22660, SOM_RTS); /* decompress_boss_resource_to_vram_high */
}
SOM_REGISTER(0xC2246D, SOM_RTS, "gen", boss_loader_indirect_vram_high_operands, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 9, 4)

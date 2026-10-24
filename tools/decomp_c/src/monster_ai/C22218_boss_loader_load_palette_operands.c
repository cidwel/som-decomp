#include "som_c.h"
#include "som_hand_b.h"

/* C22218 boss_loader_load_palette_operands   [class A, 18 bytes, 10 instructions]
 * Source: src/rom/boss_loader_load_palette_operands.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void boss_loader_load_palette_operands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value; BUS16_OK(c, ((uint32_t)RAM8(0x0032 + dp) << 0x10) + RAM16(0x0030 + dp), value);
    RAM16_SET(0x0030 + dp, (uint16_t)(RAM16(0x0030 + dp) + 1));
    RAM16_SET(0x0030 + dp, (uint16_t)(RAM16(0x0030 + dp) + 1));
    uint16_t value2; BUS16_OK(c, ((uint32_t)RAM8(0x0032 + dp) << 0x10) + RAM16(0x0030 + dp), value2);
    RAM16_SET(0x0030 + dp, (uint16_t)(RAM16(0x0030 + dp) + 1));
    RAM16_SET(0x0030 + dp, (uint16_t)(RAM16(0x0030 + dp) + 1));
    r->a = value;
    r->x = value2;
    r->y = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    TAIL_CALL(c, 0xC226AC, SOM_RTS); /* load_boss_palette_through_wram_dma */
}
SOM_REGISTER(0xC22218, SOM_RTS, "hand", boss_loader_load_palette_operands, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 18, 10)

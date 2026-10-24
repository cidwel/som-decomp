#include "som_c.h"

/* C22249 boss_loader_ram_resource_operands   [class A, 9 bytes, 4 instructions]
 * Source: src/rom/boss_loader_ram_resource_operands.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void boss_loader_ram_resource_operands(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t value = BUS8_RDL(c, (RAM8(0x0332) << 0x10) + RAM16(0x0330), RAM8(0x0332));
    RAM8(0x0330)++;
    RAM8(0x0330)++;
    r->a = (a_hi << 8) | value;
    r->z = RAM8(0x0330) == 0;
    r->n = RAM8(0x0330) & 0x80;
    TAIL_CALL(c, 0xC224C3, SOM_RTS); /* prepare_boss_loader_resource_expansion */
}
SOM_REGISTER(0xC22249, SOM_RTS, "gen", boss_loader_ram_resource_operands, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 9, 4)

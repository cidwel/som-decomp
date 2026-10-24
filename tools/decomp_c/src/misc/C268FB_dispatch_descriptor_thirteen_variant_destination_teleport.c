#include "som_c.h"

/* C268FB dispatch_descriptor_thirteen_variant_destination_teleport   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_descriptor_thirteen_variant_destination_teleport.s
 * Documented in docs/boss-descriptor-thirteen-trajectory.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_descriptor_thirteen_variant_destination_teleport(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0042 + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC26907, SOM_RTS); /* teleport_descriptor_thirteen_variant_zero_to_destination_coordinates */
    case 0x0002: TAIL_CALL_DYN(c, 0xC26960, SOM_RTS); /* teleport_descriptor_thirteen_variant_one_to_destination_coordinates */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x6903 + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC268FB, SOM_RTS, "gen", dispatch_descriptor_thirteen_variant_destination_teleport, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)

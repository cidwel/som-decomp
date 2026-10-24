#include "som_c.h"

/* C267E5 dispatch_descriptor_thirteen_variant_destination_selection   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_descriptor_thirteen_variant_destination_selection.s
 * Documented in docs/boss-descriptor-thirteen-trajectory.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXYCV.
 */
static void dispatch_descriptor_thirteen_variant_destination_selection(SomCtx *c)
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
    case 0x0000: TAIL_CALL_DYN(c, 0xC267F1, SOM_RTS); /* select_descriptor_thirteen_variant_zero_destination_coordinates */
    case 0x0002: TAIL_CALL_DYN(c, 0xC26834, SOM_RTS); /* select_descriptor_thirteen_variant_one_destination_coordinates */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x67ED + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC267E5, SOM_RTS, "gen", dispatch_descriptor_thirteen_variant_destination_selection, SOM_UNWINDS, L_B | L_X | L_Y | L_C | L_V, 1, 0, 0, 8, 4)

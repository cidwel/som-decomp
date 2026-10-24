#include "som_c.h"

/* C26834 select_descriptor_thirteen_variant_one_destination_coordinates   [class B, 67 bytes, 30 instructions]
 * Source: src/rom/select_descriptor_thirteen_variant_one_destination_coordinates.s
 * Documented in docs/boss-descriptor-thirteen-trajectory.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void select_descriptor_thirteen_variant_one_destination_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x007E + value);
    if (value2 != 0) {
        if ((value2 & 0x20) != 0) {
            uint16_t value3 = BUS16(c, 0xDCE3D8 + ((value2 & 0x0F) << 1 << 1));
            RAM16_SET(0x029D, value3);
            uint16_t value4 = BUS16(c, 0xDCE3DA + ((value2 & 0x0F) << 1 << 1));
            RAM16_SET(0x02A1, value4);
            r->a = value4;
            r->x = value;
            r->c = (value2 & 0x0F) << 1 & 0x8000;
            r->z = value == 0;
            r->n = value & 0x8000;
            RETURN_RTS(c);
        }
        uint16_t value5 = BUS16(c, 0xDCE3B8 + ((value2 & 0x0F) << 1 << 1));
        RAM16_SET(0x029D, value5);
        uint16_t value6 = BUS16(c, 0xDCE3BA + ((value2 & 0x0F) << 1 << 1));
        RAM16_SET(0x02A1, value6);
        r->a = value6;
        r->x = value;
        r->c = (value2 & 0x0F) << 1 & 0x8000;
        r->z = value == 0;
        r->n = value & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value7 = BUS16(c, 0xDCE39C);
    RAM16_SET(0x029D, value7);
    uint16_t value8 = BUS16(c, 0xDCE39E);
    RAM16_SET(0x02A1, value8);
    r->a = value8;
    r->x = value;
    r->z = value8 == 0;
    r->n = value8 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26834, SOM_RTS, "gen", select_descriptor_thirteen_variant_one_destination_coordinates, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 67, 30)

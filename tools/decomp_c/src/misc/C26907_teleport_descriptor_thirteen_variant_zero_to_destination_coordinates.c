#include "som_c.h"

/* C26907 teleport_descriptor_thirteen_variant_zero_to_destination_coordinates   [class B, 89 bytes, 38 instructions]
 * Source: src/rom/teleport_descriptor_thirteen_variant_zero_to_destination_coordinates.s
 * Documented in docs/boss-descriptor-thirteen-trajectory.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void teleport_descriptor_thirteen_variant_zero_to_destination_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x007E + value);
    if (value2 != 0) {
        if ((value2 & 0x20) != 0) {
            uint16_t value3 = BUS16(c, 0xDCE3D0 + ((value2 & 0x0F) << 1 << 1));
            RAM16_SET(0x0295, value3);
            uint16_t value4 = BUS16(c, 0xDCE3D2 + ((value2 & 0x0F) << 1 << 1));
            RAM16_SET(0x0297, value4);
            RAM16_SET(0x002B + value, RAM16(0x0295));
            uint16_t value6 = RAM16(0x0297);
            RAM16_SET(0x0032 + value, value6);
            r->a = value6;
            r->x = value;
            r->c = (value2 & 0x0F) << 1 & 0x8000;
            r->z = value6 == 0;
            r->n = value6 & 0x8000;
            RETURN_RTS(c);
        }
        uint16_t value7 = BUS16(c, 0xDCE3A0 + ((value2 & 0x0F) << 1 << 1));
        RAM16_SET(0x0295, value7);
        uint16_t value8 = BUS16(c, 0xDCE3A2 + ((value2 & 0x0F) << 1 << 1));
        RAM16_SET(0x0297, value8);
        RAM16_SET(0x002B + value, RAM16(0x0295));
        uint16_t value10 = RAM16(0x0297);
        RAM16_SET(0x0032 + value, value10);
        r->a = value10;
        r->x = value;
        r->c = (value2 & 0x0F) << 1 & 0x8000;
        r->z = value10 == 0;
        r->n = value10 & 0x8000;
        RETURN_RTS(c);
    }
    uint16_t value11 = BUS16(c, 0xDCE398);
    RAM16_SET(0x002B + value, value11);
    uint16_t value12 = BUS16(c, 0xDCE39A);
    RAM16_SET(0x0032 + value, value12);
    r->a = value12;
    r->x = value;
    r->z = value12 == 0;
    r->n = value12 & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26907, SOM_RTS, "gen", teleport_descriptor_thirteen_variant_zero_to_destination_coordinates, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 89, 38)

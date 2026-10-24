#include "som_c.h"

/* C2AA60 configure_map_screen   [class D, 163 bytes, 67 instructions]
 * Source: src/rom/configure_map_screen.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void configure_map_screen(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0030);
    RAM16_SET(0x0000, value & 0x3F);
    uint16_t value2 = RAM16(0x0000);
    uint16_t value3 = BUS16(c, 0xC80100 + (uint16_t)(((value & 0x3F) << 1 << 1 << 1) + value2));
    RAM16_SET(0x0020, value3);
    uint16_t value4 = BUS16(c, 0xC80102 + (uint16_t)(((value & 0x3F) << 1 << 1 << 1) + value2));
    RAM16_SET(0x0022, value4);
    uint16_t value5 = BUS16(c, 0xC80104 + (uint16_t)(((value & 0x3F) << 1 << 1 << 1) + value2));
    RAM16_SET(0x0024, value5);
    uint16_t value6 = BUS16(c, 0xC80105 + (uint16_t)(((value & 0x3F) << 1 << 1 << 1) + value2));
    RAM16_SET(0x0025, value6);
    uint16_t value7 = BUS16(c, 0xC80107 + (uint16_t)(((value & 0x3F) << 1 << 1 << 1) + value2));
    RAM16_SET(0x0027, value7);
    RAM16_SET(0x0600, value7);
    RAM16_SET(0xDE00, value7);
    RAM16_SET(0x002C, 0);
    RAM16_SET(0x002E, 0);
    BUS16_SET(c, 0x004306, 0);
    BUS16_SET(c, 0x004316, 0);
    BUS16_SET(c, 0x004326, 0);
    BUS16_SET(c, 0x004336, 0);
    BUS16_SET(c, 0x004346, 0);
    BUS16_SET(c, 0x004356, 0);
    BUS16_SET(c, 0x004366, 0);
    BUS16_SET(c, 0x004376, 0);
    BUS8_SET(c, 0x002106, RAM8(0x0020));
    BUS8_SET(c, 0x002123, 0);
    BUS8_SET(c, 0x002124, 0);
    BUS8_SET(c, 0x002125, 0);
    BUS8_SET(c, 0x00212A, 0);
    BUS8_SET(c, 0x00212B, 0);
    BUS8_SET(c, 0x00212C, RAM8(0x0021));
    BUS8_SET(c, 0x00212D, RAM8(0x0022));
    BUS8_SET(c, 0x00212E, 0);
    BUS8_SET(c, 0x00212F, 0);
    BUS8_SET(c, 0x002130, 2);
    BUS8_SET(c, 0x002131, RAM8(0x0023));
    BUS8_SET(c, 0x002132, 0);
    BUS8_SET(c, 0x002126, 0);
    BUS8_SET(c, 0x002128, 0);
    BUS8_SET(c, 0x002127, 0xFF);
    BUS8_SET(c, 0x002129, 0xFF);
    RAM8(0x0091) = 0x63;
    BUS8_SET(c, 0x002101, 0x63);
    r->a = (value7 >> 8 << 8) | 0x63;
    r->x = (uint8_t)(((value & 0x3F) << 1 << 1 << 1) + value2);
    r->c = 0;
    r->v = ((((value & 0x3F) << 1 << 1 << 1) ^ (uint16_t)(((value & 0x3F) << 1 << 1 << 1) + value2)) & (value2 ^ (uint16_t)(((value & 0x3F) << 1 << 1 << 1) + value2)) & 0x8000) != 0;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2AA60, SOM_RTS, "gen", configure_map_screen, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 0, 1, 163, 67)

#include "som_c.h"

/* C269F7 terminate_descriptor_thirteen_trajectory_at_height_floor   [class B, 26 bytes, 12 instructions]
 * Source: src/rom/terminate_descriptor_thirteen_trajectory_at_height_floor.s
 * Documented in docs/boss-descriptor-thirteen-trajectory.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void terminate_descriptor_thirteen_trajectory_at_height_floor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x0066 + x);
    if (value & 0x8000) {
        RAM16_SET(0x0090 + x, 0);
        RAM16_SET(0x0064 + x, 0);
        RAM16_SET(0x0066 + x, 0x80);
        r->a = 0x80;
        r->c = 1;
        r->z = 0;
        r->n = 0;
        RETURN_RTS(c);
    }
    if (value >= 0x81) {
        r->a = value;
        r->c = 0;
        r->z = value == 0x81;
        r->n = (uint16_t)(value - 0x81) & 0x8000;
        RETURN_RTS(c);
    }
    RAM16_SET(0x0090 + x, 0);
    RAM16_SET(0x0064 + x, 0);
    RAM16_SET(0x0066 + x, 0x80);
    r->a = 0x80;
    r->c = 1;
    r->z = 0;
    r->n = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC269F7, SOM_RTS, "gen", terminate_descriptor_thirteen_trajectory_at_height_floor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 26, 12)

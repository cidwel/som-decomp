#include "som_c.h"

/* C2A7D5 set_map_layer_packed_parameters   [class B, 44 bytes, 26 instructions]
 * Source: src/rom/set_map_layer_packed_parameters.s
 * Documented in docs/maps.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void set_map_layer_packed_parameters(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    RAM8(0x0000 + sp0) = a >> 8;
    RAM8(0x0000 + sp0 - 1) = (uint8_t)a;
    BUS16_SET(c, 0x000A8A + y, (((a & 0x1F) << 8) | 0) >> 3);
    uint8_t value = RAM8(0x0000 + sp0 - 1);
    uint8_t value2 = RAM8(0x0000 + sp0);
    BUS8_SET(c, 0x000A8C + y, ((uint8_t)((value2 << 8) | value) >> 5) + 1);
    BUS16_SET(c, 0x000A8E + y, (((((uint8_t)((value2 << 8) | value) >> 5) + 1 << 8) | value2) & 0xFF) + 1);
    BUS16_SET(c, 0x000A86 + y, 0);
    r->a = 0;
    r->c = (uint8_t)((value2 << 8) | value) >> 4 & 0x01;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A7D5, SOM_RTS, "gen", set_map_layer_packed_parameters, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 2, -1, 0, 44, 26)

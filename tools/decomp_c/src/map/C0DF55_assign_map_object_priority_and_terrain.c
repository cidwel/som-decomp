#include "som_c.h"

/* C0DF55 assign_map_object_priority_and_terrain   [class B, 48 bytes, 24 instructions]
 * Source: src/rom/assign_map_object_priority_and_terrain.s
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void assign_map_object_priority_and_terrain(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0xE03C + x);
    if ((value & 7) >= 4) {
        RAM8(0x0000) = (((((value & 3) >> 2) | ((value & 1) << 7)) >> 1) | ((value & 3) >> 1 << 7)) >> 2;
        uint8_t value2 = RAM8(0xE08B + x);
        uint8_t value3 = RAM8(0x0000);
        RAM8(0xE08B + x) = (value2 & 0xCF) | value3;
        SET_A8(r, (value2 & 0xCF) | value3);
        r->c = (((((value & 3) >> 2) | ((value & 1) << 7)) >> 1) | ((value & 3) >> 1 << 7)) >> 1 & 0x01;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0xE08B + x);
    RAM8(0xE08B + x) = (value4 & 0xCF) | 0x20;
    r->a = (a >> 8 << 8) | ((value4 & 0xCF) | 0x20);
    r->c = (value & 7) >= 4;
    r->z = ((value4 & 0xCF) | 0x20) == 0;
    r->n = ((value4 & 0xCF) | 0x20) & 0x80;
    r->mf = 1;
    { const uint16_t sp_call = r->sp; JSL(c, 0xDF6F, 0x01DF22); GUARD_JSL(c, sp_call, 0xDF6F); } /* initialize_actor_tile_state_entry */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0DF55, SOM_RTS, "gen", assign_map_object_priority_and_terrain, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, -1, 0, 48, 24)

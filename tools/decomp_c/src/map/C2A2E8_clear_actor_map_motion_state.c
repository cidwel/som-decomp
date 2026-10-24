#include "som_c.h"

/* C2A2E8 clear_actor_map_motion_state   [class B, 120 bytes, 41 instructions]
 * Source: src/rom/clear_actor_map_motion_state.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: X.
 */
static void clear_actor_map_motion_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0xE006 + x, 0);
    RAM16_SET(0xE008 + x, 0);
    RAM16_SET(0xE00A + x, 0);
    RAM16_SET(0xE010 + x, 0);
    RAM16_SET(0xE012 + x, 0);
    RAM16_SET(0xE014 + x, 0);
    RAM16_SET(0xE016 + x, 0);
    RAM16_SET(0xE018 + x, 0);
    RAM16_SET(0xE01A + x, 0);
    RAM16_SET(0xE01C + x, 0);
    RAM16_SET(0xE01E + x, 0);
    RAM16_SET(0xE020 + x, 0);
    RAM16_SET(0xE022 + x, 0);
    RAM16_SET(0xE02C + x, 0);
    RAM16_SET(0xE02E + x, 0);
    RAM16_SET(0xE030 + x, 0);
    RAM16_SET(0xE036 + x, 0);
    RAM16_SET(0xE038 + x, 0);
    RAM16_SET(0xE040 + x, 0);
    RAM16_SET(0xE042 + x, 0);
    RAM16_SET(0xE044 + x, 0);
    RAM16_SET(0xE046 + x, 0);
    RAM16_SET(0xE048 + x, 0);
    RAM16_SET(0xE04A + x, 0);
    RAM16_SET(0xE04C + x, 0);
    RAM16_SET(0xE04E + x, 0);
    RAM16_SET(0xE050 + x, 0);
    RAM16_SET(0xE052 + x, 0);
    RAM16_SET(0xE054 + x, 0);
    RAM16_SET(0xE056 + x, 0);
    RAM16_SET(0xE058 + x, 0);
    RAM16_SET(0xE060 + x, 0);
    RAM16_SET(0xE083 + x, 0);
    RAM16_SET(0xE100 + x, 0);
    RAM16_SET(0xE104 + x, 0);
    RAM16_SET(0xE108 + x, 0);
    RAM16_SET(0xE030 + x, 0xFF);
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2A2E8, SOM_RTL, "gen", clear_actor_map_motion_state, 0, L_X, 1, 1, 0, 120, 41)

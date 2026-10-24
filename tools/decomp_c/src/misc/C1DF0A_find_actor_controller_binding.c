#include "som_c.h"

/* C1DF0A find_actor_controller_binding   [class A, 24 bytes, 14 instructions]
 * Source: src/rom/find_actor_controller_binding.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: ABXYCV.
 */
static void find_actor_controller_binding(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    uint8_t value = RAM8(0x00D9);
    if ((a & value) != 0) {
        SET_A8(r, 1);
        r->v = value & 0x40;
        RETURN_RTS(c);
    }
    uint8_t value2 = RAM8(0x00DA);
    if ((a & value2) != 0) {
        SET_A8(r, 2);
        r->v = value2 & 0x40;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x00DB);
    if ((a & value3) != 0) {
        SET_A8(r, 4);
        r->v = value3 & 0x40;
        RETURN_RTS(c);
    }
    SET_A8(r, 0);
    r->v = value3 & 0x40;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1DF0A, SOM_RTS, "gen", find_actor_controller_binding, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 24, 14)

#include "som_c.h"

/* C758FA restore_first_controller_binding_and_clear_other_two   [class A, 12 bytes, 6 instructions]
 * Source: src/rom/restore_first_controller_binding_and_clear_other_two.s
 * Entry: M=8 bit X=16 bit DB=any D=any.  Callers read: BXYCV.
 */
static void restore_first_controller_binding_and_clear_other_two(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint16_t x = r->x;
    uint8_t value = BUS8(c, 0x306000 + x);
    BUS8_SET(c, (uint16_t)(dp + 0xD9), value);
    BUS8_SET(c, (uint16_t)(dp + 0xDA), 0);
    BUS8_SET(c, (uint16_t)(dp + 0xDB), 0);
    r->x = (uint16_t)(x + 1);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC758FA, SOM_RTS, "gen", restore_first_controller_binding_and_clear_other_two, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 12, 6)

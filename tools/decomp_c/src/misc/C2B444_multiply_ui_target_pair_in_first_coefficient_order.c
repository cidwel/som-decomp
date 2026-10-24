#include "som_c.h"

/* C2B444 multiply_ui_target_pair_in_first_coefficient_order   [class A, 15 bytes, 7 instructions]
 * Source: src/rom/multiply_ui_target_pair_in_first_coefficient_order.s
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: Y.
 */
static void multiply_ui_target_pair_in_first_coefficient_order(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x0C));
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB448, 0xC2B453); GUARD_JSR(c, sp_call, 0xB448); } /* multiply_signed_ui_coordinate_using_two_native_byte_products */
    uint16_t x_ret = r->x;
    BUS16_SET(c, (uint16_t)(dp + 2), x_ret);
    uint16_t value2 = BUS16_RDP(c, (uint16_t)(dp + 0x0E));
    r->x = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 1;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0xB44F, 0xC2B453); GUARD_JSR(c, sp_call, 0xB44F); } /* multiply_signed_ui_coordinate_using_two_native_byte_products */
    uint16_t x_ret2 = r->x;
    BUS16_SET(c, (uint16_t)(dp + 6), x_ret2);
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2B444, SOM_RTS, "gen", multiply_ui_target_pair_in_first_coefficient_order, 0, L_Y, 1, 1, 0, 15, 7)

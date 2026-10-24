#include "som_c.h"

/* C26073 choose_descriptor_five_directional_distance_state   [class B, 58 bytes, 26 instructions]
 * Source: src/rom/choose_descriptor_five_directional_distance_state.s
 * Entry: M=16 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_five_directional_distance_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    const uint16_t dp = r->dp;
    uint16_t value = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    r->x = value;
    r->z = value == 0;
    r->n = value & 0x8000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x6077, 0xC23A52); GUARD_JSR(c, sp_call, 0x6077); } /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret = r->x;
    uint16_t value2 = RAM16(0x00A9 + x_ret);
    r->a = value2;
    r->z = value2 == 0;
    r->n = value2 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    { const uint16_t sp_call = r->sp; JSR(c, 0x607D, 0xC208D9); GUARD_JSR(c, sp_call, 0x607D); } /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    if (a_all2 >= 3) {
        if (a_all2 >= 4) {
            uint16_t value3 = RAM16(0x00AB + x_ret2);
            uint16_t value4 = BUS16(c, 0xDCE28A + (uint16_t)(value3 << 1));
            r->a = value4;
            r->x = (uint16_t)(value3 << 1);
            r->c = value3 & 0x8000;
            r->z = value4 == 0;
            r->n = value4 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value5 = RAM16(0x00AB + x_ret2);
        uint16_t value6 = BUS16(c, 0xDCE282 + (uint16_t)(value5 << 1));
        r->a = value6;
        r->x = (uint16_t)(value5 << 1);
        r->c = value5 & 0x8000;
        r->z = value6 == 0;
        r->n = value6 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value8 = BUS16(c, 0xDCE27A + (uint16_t)(RAM16(0x00AB + x_ret2) << 1));
    uint16_t value9 = BUS16_RDP(c, (uint16_t)(dp + 0x87));
    uint16_t value10 = RAM16(0x00B0 + value9);
    if (value8 == value10) {
        uint16_t value11 = RAM16(0x00AB + value9);
        uint16_t value12 = BUS16(c, 0xDCE282 + (uint16_t)(value11 << 1));
        r->a = value12;
        r->x = (uint16_t)(value11 << 1);
        r->c = value11 & 0x8000;
        r->z = value12 == 0;
        r->n = value12 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = value8;
    r->x = value9;
    r->c = value8 >= value10;
    r->z = value8 == value10;
    r->n = (uint16_t)(value8 - value10) & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26073, SOM_RTS, "gen", choose_descriptor_five_directional_distance_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 58, 26)

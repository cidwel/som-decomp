#include "som_c.h"

/* C28BCD choose_descriptor_eleven_distance_variant_state   [class B, 42 bytes, 18 instructions]
 * Source: src/rom/choose_descriptor_eleven_distance_variant_state.s
 * Documented in docs/boss-descriptor-eleven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_eleven_distance_variant_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x8BCF, 0xC23224); /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x00A9 + x_ret, a_all);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x8BD5, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    if (a_all2 < 5) {
        if (a_all2 < 2) {
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x8BEA, 0xC28BF7); /* update_descriptor_eleven_facing_phase_or_return_transition_abort */
            uint16_t a_all3 = r->a;
            bool carry_ret3 = r->c;
            bool zero_ret3 = r->z;
            bool negative_ret3 = r->n;
            uint8_t a1;
            uint8_t a_hi1;
            uint16_t x1;
            bool carry1;
            bool zero1;
            bool negative1;
            if (carry_ret3) {
                a1 = (uint8_t)a_all3;
                a_hi1 = a_all3 >> 8;
                x1 = x_ret2;
                carry1 = carry_ret3;
                zero1 = zero_ret3;
                negative1 = negative_ret3;
            } else {
                uint16_t value = RAM16(0x00AB + x_ret2);
                uint16_t value2 = BUS16(c, 0xDCE5B5 + (uint16_t)(value << 1));
                a1 = (uint8_t)value2;
                a_hi1 = value2 >> 8;
                x1 = (uint16_t)(value << 1);
                carry1 = value & 0x8000;
                zero1 = value2 == 0;
                negative1 = value2 & 0x8000;
            }
            r->a = (a_hi1 << 8) | a1;
            r->x = x1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xF038;
        r->c = a_all2 >= 2;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xF032;
    r->c = a_all2 >= 5;
    r->z = 0;
    r->n = 1;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28BCD, SOM_RTS, "gen", choose_descriptor_eleven_distance_variant_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 42, 18)

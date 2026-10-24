#include "som_c.h"

/* C28B85 choose_descriptor_eleven_horizontal_variant_state   [class B, 72 bytes, 35 instructions]
 * Source: src/rom/choose_descriptor_eleven_horizontal_variant_state.s
 * Documented in docs/boss-descriptor-eleven.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_eleven_horizontal_variant_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x8B87, 0xC23224); /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    uint16_t x_ret = r->x;
    RAM16_SET(0x00A9 + x_ret, a_all);
    uint16_t value = RAM16(0x002B + x_ret);
    uint16_t value2 = RAM16(0x0002 + (uint16_t)((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) + 0xE000));
    uint8_t a1;
    uint8_t a_hi1;
    if (!((uint16_t)(value - value2) & 0x8000)) {
        a1 = (uint8_t)(value - value2);
        a_hi1 = (uint16_t)(value - value2) >> 8;
    } else {
        uint16_t value3 = RAM16(0x02C7);
        a1 = (uint8_t)(((uint16_t)(value - value2) ^ value3) + 1);
        a_hi1 = (uint16_t)(((uint16_t)(value - value2) ^ value3) + 1) >> 8;
    }
    if (((a_hi1 << 8) | a1) < 0x50) {
        uint16_t value4 = RAM16(0x0032 + x_ret);
        uint16_t value5 = RAM16(0x0004 + (uint16_t)((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) + 0xE000));
        uint8_t a2;
        uint8_t a_hi2;
        if (!((uint16_t)(value4 - value5) & 0x8000)) {
            a2 = (uint8_t)(value4 - value5);
            a_hi2 = (uint16_t)(value4 - value5) >> 8;
        } else {
            uint16_t value6 = RAM16(0x02C7);
            a2 = (uint8_t)(((uint16_t)(value4 - value5) ^ value6) + 1);
            a_hi2 = (uint16_t)(((uint16_t)(value4 - value5) ^ value6) + 1) >> 8;
        }
        if (((a_hi2 << 8) | a2) < 0x20) {
            uint16_t value7 = RAM16(0x0287);
            r->a = (a_hi2 << 8) | a2;
            r->x = value7;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x8BC0, 0xC28BF7); /* update_descriptor_eleven_facing_phase_or_return_transition_abort */
            uint16_t a_all2 = r->a;
            bool carry_ret2 = r->c;
            bool zero_ret2 = r->z;
            bool negative_ret2 = r->n;
            uint8_t a3;
            uint8_t a_hi3;
            uint16_t x1;
            bool carry1;
            bool zero1;
            bool negative1;
            if (carry_ret2) {
                a3 = (uint8_t)a_all2;
                a_hi3 = a_all2 >> 8;
                x1 = value7;
                carry1 = carry_ret2;
                zero1 = zero_ret2;
                negative1 = negative_ret2;
            } else {
                uint16_t value8 = RAM16(0x00AB + value7);
                uint16_t value9 = BUS16(c, 0xDCE5B5 + (uint16_t)(value8 << 1));
                a3 = (uint8_t)value9;
                a_hi3 = value9 >> 8;
                x1 = (uint16_t)(value8 << 1);
                carry1 = value8 & 0x8000;
                zero1 = value9 == 0;
                negative1 = value9 & 0x8000;
            }
            r->a = (a_hi3 << 8) | a3;
            r->x = x1;
            r->c = carry1;
            r->z = zero1;
            r->n = negative1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xF036;
        r->y = (uint16_t)((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) + 0xE000);
        r->c = ((a_hi2 << 8) | a2) >= 0x20;
        r->z = 0;
        r->n = 1;
        r->v = ((value4 ^ value5) & (value4 ^ (uint16_t)(value4 - value5)) & 0x8000) != 0;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xF032;
    r->y = (uint16_t)((uint16_t)((((uint8_t)a_all << 8) | (a_all >> 8)) << 1) + 0xE000);
    r->c = ((a_hi1 << 8) | a1) >= 0x50;
    r->z = 0;
    r->n = 1;
    r->v = ((value ^ value2) & (value ^ (uint16_t)(value - value2)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28B85, SOM_RTS, "gen", choose_descriptor_eleven_horizontal_variant_state, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 72, 35)

#include "som_c.h"

/* C27661 choose_descriptor_ten_variant_distance_action   [class B, 112 bytes, 51 instructions]
 * Source: src/rom/choose_descriptor_ten_variant_distance_action.s
 * Documented in docs/boss-descriptor-ten.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_ten_variant_distance_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x7663, 0xC23224); /* select_nearest_active_living_party_actor */
    uint16_t a_all = r->a;
    RAM16_SET(0x00A9 + RAM16(0x0287), a_all);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x766B, 0xC2091D); /* derive_four_way_direction_to_low_byte_target */
    uint16_t value2 = RAM16(0x026A);
    uint16_t value3 = RAM16(0x0287);
    RAM16_SET(0x00AB + value3, value2);
    if (RAM16(0x0042 + value3) != 0) {
        r->a = RAM16(0x00A9 + value3);
        r->x = value3;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x76B2, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
        uint16_t a_all3 = r->a;
        uint16_t x_ret3 = r->x;
        if (a_all3 >= 3) {
            r->a = 2;
            r->c = a_all3 >= 3;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x76C8, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all4 = r->a;
            uint16_t value6 = BUS16(c, 0xDCE57F + (uint16_t)(a_all4 << 1));
            r->a = value6;
            r->x = (uint16_t)(a_all4 << 1);
            r->c = 0;
            r->z = value6 == 0;
            r->n = value6 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value7 = RAM16(0x00AB + x_ret3);
        uint16_t value8 = BUS16(c, 0xDCE58D + (uint16_t)(value7 << 1));
        r->a = value8;
        r->x = (uint16_t)(value7 << 1);
        r->c = 0;
        r->z = value8 == 0;
        r->n = value8 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = RAM16(0x00A9 + value3);
    r->x = value3;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x767D, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all5 = r->a;
    uint16_t x_ret5 = r->x;
    if (a_all5 >= 3) {
        if (a_all5 < 6) {
            uint16_t value11 = RAM16(0x00AB + RAM16(0x0287));
            uint16_t value12 = BUS16(c, 0xDCE577 + (uint16_t)(value11 << 1));
            r->a = value12;
            r->x = (uint16_t)(value11 << 1);
            r->c = 0;
            r->z = value12 == 0;
            r->n = value12 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 7;
        r->c = a_all5 >= 6;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x7698, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret6 = r->z;
        if (!zero_ret6) {
            uint16_t value14 = RAM16(0x00AB + RAM16(0x0287));
            uint16_t value15 = BUS16(c, 0xDCE577 + (uint16_t)(value14 << 1));
            r->a = value15;
            r->x = (uint16_t)(value14 << 1);
            r->c = 0;
            r->z = value15 == 0;
            r->n = value15 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xED63;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value16 = RAM16(0x00AB + x_ret5);
    uint16_t value17 = BUS16(c, 0xDCE585 + (uint16_t)(value16 << 1));
    r->a = value17;
    r->x = (uint16_t)(value16 << 1);
    r->c = 0;
    r->z = value17 == 0;
    r->n = value17 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC27661, SOM_RTS, "gen", choose_descriptor_ten_variant_distance_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 112, 51)

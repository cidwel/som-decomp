#include "som_c.h"

/* C2543D choose_descriptor_twelve_variant_zero_phase_control_action   [class B, 138 bytes, 60 instructions]
 * Source: src/rom/choose_descriptor_twelve_variant_zero_phase_control_action.s
 * Documented in docs/boss-descriptor-twelve.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_twelve_variant_zero_phase_control_action(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    if (RAM16(0x007E + value) != 0) {
        r->a = 2;
        r->x = value;
        JSR(c, 0x549C, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret = r->z;
        if (zero_ret) {
            uint16_t value3 = RAM16(0x0287);
            RAM16_SET(0x0034 + value3, RAM16(0x0034 + value3) & 0xFF0F);
            r->a = 0xDB29;
            r->x = value3;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value5 = RAM16(0x0287);
        uint16_t value6 = RAM16(0x0034 + value5);
        if ((value6 & 0x60) != 0) {
            RAM16_SET(0x0034 + value5, value6 & 0xFF0F);
            r->a = 0xDB29;
            r->x = value5;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 2;
        r->x = value5;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x54AE, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all2 = r->a;
        uint16_t value7 = BUS16(c, 0xDCE266 + (uint16_t)(a_all2 << 1));
        r->a = value7;
        r->x = (uint16_t)(a_all2 << 1);
        r->c = 0;
        r->z = value7 == 0;
        r->n = value7 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 3;
    r->x = value;
    JSR(c, 0x5449, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret3 = r->z;
    if (!zero_ret3) {
        uint16_t value8 = RAM16(0x0287);
        r->a = RAM16(0x00A9 + value8);
        r->x = value8;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x546C, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
        uint16_t a_all4 = r->a;
        if (a_all4 >= 3) {
            r->a = 1;
            r->c = a_all4 >= 3;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x548E, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all5 = r->a;
            uint16_t value10 = BUS16(c, 0xDCE25E + (uint16_t)(a_all5 << 1));
            r->a = value10;
            r->x = (uint16_t)(a_all5 << 1);
            r->c = 0;
            r->z = value10 == 0;
            r->n = value10 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = RAM16(0x00A9 + RAM16(0x0287));
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x5479, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
        uint16_t a_all6 = r->a;
        if (a_all6 < 3) {
            r->a = 0xDB26;
            r->c = 0;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        if (a_all6 < 7) {
            r->a = 1;
            r->c = a_all6 >= 7;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x548E, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all7 = r->a;
            uint16_t value13 = BUS16(c, 0xDCE25E + (uint16_t)(a_all7 << 1));
            r->a = value13;
            r->x = (uint16_t)(a_all7 << 1);
            r->c = 0;
            r->z = value13 == 0;
            r->n = value13 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xDB26;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value14 = RAM16(0x0287);
    RAM16_SET(0x0034 + value14, RAM16(0x0034 + value14) & 0xFF0F);
    r->a = 1;
    r->x = value14;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x545C, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all8 = r->a;
    uint16_t value16 = BUS16(c, 0xDCE262 + (uint16_t)(a_all8 << 1));
    r->a = value16;
    r->x = (uint16_t)(a_all8 << 1);
    r->c = 0;
    r->z = value16 == 0;
    r->n = value16 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2543D, SOM_RTS, "gen", choose_descriptor_twelve_variant_zero_phase_control_action, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 138, 60)

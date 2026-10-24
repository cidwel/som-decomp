#include "som_c.h"

/* C26B63 choose_descriptor_four_action_pointer   [class B, 73 bytes, 34 instructions]
 * Source: src/rom/choose_descriptor_four_action_pointer.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_four_action_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x6B65, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret = r->x;
    if (RAM16(0x007E + x_ret) != 0) {
        if (RAM16(0x0042 + x_ret) != 0) {
            r->a = 5;
            r->mf = 0;
            r->xf = 0;
            JSR(c, 0x6BA3, 0xC2300B); /* draw_boss_frame_random_number */
            uint16_t a_all2 = r->a;
            uint16_t value3 = BUS16(c, 0xDCE3F4 + (uint16_t)(a_all2 << 1));
            r->a = value3;
            r->x = (uint16_t)(a_all2 << 1);
            r->c = 0;
            r->z = value3 == 0;
            r->n = value3 & 0x8000;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 2;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x6B95, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all3 = r->a;
        uint16_t value4 = BUS16(c, 0xDCE3EE + (uint16_t)(a_all3 << 1));
        r->a = value4;
        r->x = (uint16_t)(a_all3 << 1);
        r->c = 0;
        r->z = value4 == 0;
        r->n = value4 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6B70, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all4 = r->a;
    uint16_t x_ret4 = r->x;
    if (a_all4 >= 4) {
        r->a = 0xE5F0;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value6 = RAM16(0x00AB + x_ret4);
    if (value6 == 3) {
        r->a = 0xE5F0;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value7 = BUS16(c, 0xDCE3E8 + (uint16_t)(value6 << 1));
    r->a = value7;
    r->x = (uint16_t)(value6 << 1);
    r->c = 0;
    r->z = value7 == 0;
    r->n = value7 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26B63, SOM_RTS, "gen", choose_descriptor_four_action_pointer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 73, 34)

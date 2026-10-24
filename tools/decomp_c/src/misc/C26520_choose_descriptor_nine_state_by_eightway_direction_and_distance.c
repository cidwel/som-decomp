#include "som_c.h"

/* C26520 choose_descriptor_nine_state_by_eightway_direction_and_distance   [class B, 43 bytes, 19 instructions]
 * Source: src/rom/choose_descriptor_nine_state_by_eightway_direction_and_distance.s
 * Documented in docs/boss-descriptor-nine.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_nine_state_by_eightway_direction_and_distance(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x6522, 0xC23A41); /* select_nearest_living_target_and_eight_way_direction */
    uint16_t x_ret = r->x;
    r->a = RAM16(0x00A9 + x_ret);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6528, 0xC208D9); /* derive_target_manhattan_distance_in_sixteen_pixel_units */
    uint16_t a_all2 = r->a;
    uint16_t x_ret2 = r->x;
    if (a_all2 >= 6) {
        if (a_all2 < 8) {
            r->a = 0xE146;
            r->c = a_all2 >= 8;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        uint16_t value2 = RAM16(0x00AB + x_ret2);
        uint16_t value3 = BUS16(c, 0xDCE31C + (uint16_t)(value2 << 1));
        r->a = value3;
        r->x = (uint16_t)(value2 << 1);
        r->c = value2 & 0x8000;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value4 = RAM16(0x00AB + x_ret2);
    uint16_t value5 = BUS16(c, 0xDCE314 + (uint16_t)(value4 << 1));
    r->a = value5;
    r->x = (uint16_t)(value4 << 1);
    r->c = value4 & 0x8000;
    r->z = value5 == 0;
    r->n = value5 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26520, SOM_RTS, "gen", choose_descriptor_nine_state_by_eightway_direction_and_distance, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 43, 19)

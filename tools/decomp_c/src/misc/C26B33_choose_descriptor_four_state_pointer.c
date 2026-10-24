#include "som_c.h"

/* C26B33 choose_descriptor_four_state_pointer   [class B, 48 bytes, 21 instructions]
 * Source: src/rom/choose_descriptor_four_state_pointer.s
 * Documented in docs/boss-descriptor-four.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_four_state_pointer(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x6B35, 0xC23A52); /* select_nearest_living_target_and_four_way_direction */
    uint16_t x_ret = r->x;
    if (RAM16(0x007E + x_ret) != 0) {
        r->a = 3;
        r->mf = 0;
        r->xf = 0;
        JSR(c, 0x6B58, 0xC2300B); /* draw_boss_frame_random_number */
        bool zero_ret2 = r->z;
        if (zero_ret2) {
            r->a = 0xE5D9;
            r->z = 0;
            r->n = 1;
            r->mf = 0;
            r->xf = 0;
            RETURN_RTS(c);
        }
        r->a = 0xE5DC;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x6B40, 0xC2300B); /* draw_boss_frame_random_number */
    bool zero_ret3 = r->z;
    if (zero_ret3) {
        r->a = 0xE5D6;
        r->z = 0;
        r->n = 1;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    uint16_t value3 = RAM16(0x00AB + RAM16(0x0287));
    uint16_t value4 = BUS16(c, 0xDCE3E0 + (uint16_t)(value3 << 1));
    r->a = value4;
    r->x = (uint16_t)(value3 << 1);
    r->c = value3 & 0x8000;
    r->z = value4 == 0;
    r->n = value4 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26B33, SOM_RTS, "gen", choose_descriptor_four_state_pointer, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 48, 21)

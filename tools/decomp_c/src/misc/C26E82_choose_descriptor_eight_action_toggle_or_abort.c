#include "som_c.h"

/* C26E82 choose_descriptor_eight_action_toggle_or_abort   [class B, 56 bytes, 27 instructions]
 * Source: src/rom/choose_descriptor_eight_action_toggle_or_abort.s
 * Documented in docs/boss-descriptor-eight.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_eight_action_toggle_or_abort(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(0x007E + x);
    if ((value & 1) != 0) {
        if ((value & 0x8000) != 0) {
            r->a = value;
            r->c = 1;
            r->z = (value & 0x8000) == 0;
            r->n = value & 0x8000;
            RETURN_RTS(c);
        }
        r->a = 0xE894;
        r->c = 0;
        r->z = 0;
        r->n = 1;
        RETURN_RTS(c);
    }
    RAM16_SET(0x007E + x, value ^ 0x8000);
    if ((value ^ 0x8000) & 0x8000) {
        r->a = 8;
        JSR(c, 0x6EA5, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all = r->a;
        uint16_t value2 = BUS16(c, 0xDCE497 + (uint16_t)(a_all << 1));
        r->a = value2;
        r->x = (uint16_t)(a_all << 1);
        r->c = 0;
        r->z = value2 == 0;
        r->n = value2 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 6;
    JSR(c, 0x6E97, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all2 = r->a;
    uint16_t value3 = BUS16(c, 0xDCE489 + (uint16_t)(a_all2 << 1));
    r->a = value3;
    r->x = (uint16_t)(a_all2 << 1);
    r->c = 0;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC26E82, SOM_RTS, "gen", choose_descriptor_eight_action_toggle_or_abort, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 56, 27)

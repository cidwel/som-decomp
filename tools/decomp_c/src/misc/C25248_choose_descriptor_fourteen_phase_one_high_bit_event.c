#include "som_c.h"

/* C25248 choose_descriptor_fourteen_phase_one_high_bit_event   [class A, 34 bytes, 15 instructions]
 * Source: src/rom/choose_descriptor_fourteen_phase_one_high_bit_event.s
 * Documented in docs/boss-descriptor-fourteen.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_descriptor_fourteen_phase_one_high_bit_event(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x007E + value);
    if ((value2 & 0x8000) == 0) {
        RAM16_SET(0x007E + value, value2 | 0x8000);
        r->a = 3;
        r->x = value;
        JSR(c, 0x5261, 0xC2300B); /* draw_boss_frame_random_number */
        uint16_t a_all = r->a;
        uint16_t value3 = BUS16(c, 0xC2DADE + (uint16_t)(a_all << 1));
        r->a = value3;
        r->x = (uint16_t)(a_all << 1);
        r->c = 0;
        r->z = value3 == 0;
        r->n = value3 & 0x8000;
        r->mf = 0;
        r->xf = 0;
        RETURN_RTS(c);
    }
    r->a = 0xD911;
    r->x = value;
    r->z = 0;
    r->n = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25248, SOM_RTS, "gen", choose_descriptor_fourteen_phase_one_high_bit_event, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 34, 15)

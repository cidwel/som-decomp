#include "som_c.h"

/* C261B1 choose_two_boss_velocity_words_from_random_pool   [class A, 31 bytes, 14 instructions]
 * Source: src/rom/choose_two_boss_velocity_words_from_random_pool.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void choose_two_boss_velocity_words_from_random_pool(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    r->a = 2;
    JSR(c, 0x61B6, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all = r->a;
    RAM16_SET(0x0295, (uint16_t)(a_all - 1));
    r->a = 2;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x61BF, 0xC2300B); /* draw_boss_frame_random_number */
    uint16_t a_all2 = r->a;
    RAM16_SET(0x0297, (uint16_t)(a_all2 - 1));
    uint16_t value = RAM16(0x0287);
    RAM16_SET(0x003C + value, RAM16(0x0295));
    uint16_t value3 = RAM16(0x0297);
    RAM16_SET(0x0040 + value, value3);
    r->a = value3;
    r->x = value;
    r->z = value3 == 0;
    r->n = value3 & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC261B1, SOM_RTS, "gen", choose_two_boss_velocity_words_from_random_pool, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 31, 14)

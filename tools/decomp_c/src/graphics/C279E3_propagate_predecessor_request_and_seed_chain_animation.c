#include "som_c.h"

/* C279E3 propagate_predecessor_request_and_seed_chain_animation   [class A, 38 bytes, 14 instructions]
 * Source: src/rom/propagate_predecessor_request_and_seed_chain_animation.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void propagate_predecessor_request_and_seed_chain_animation(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    RAM16_SET(0x0014 + value, RAM16(0x0082 + value));
    RAM16_SET(0x0082 + value, RAM16(0x0080 + value));
    RAM16_SET(0x0080 + value, RAM16(0x0082 + value2));
    uint16_t value6 = RAM16(0x0014 + value);
    if (value6 == 0xFFFF) {
        r->a = 0x013B;
        r->x = value;
        r->y = value2;
        r->c = value6 >= 0xFFFF;
        JSR(c, 0x7A07, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    }
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC279E3, SOM_RTS, "gen", propagate_predecessor_request_and_seed_chain_animation, 0, 0, 1, 0, 0, 38, 14)

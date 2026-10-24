#include "som_c.h"

/* C279B8 consume_primary_boss_request_into_chain_delay_queue   [class B, 43 bytes, 16 instructions]
 * Source: src/rom/consume_primary_boss_request_into_chain_delay_queue.s
 * Documented in docs/boss-descriptor-ten-children.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void consume_primary_boss_request_into_chain_delay_queue(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t value = RAM16(0x0287);
    uint16_t value2 = RAM16(0x00B0 + value);
    RAM16_SET(0x0014 + value, RAM16(0x0082 + value));
    RAM16_SET(0x0082 + value, RAM16(0x0080 + value));
    RAM16_SET(0x0080 + value, RAM16(0x00B4 + value2));
    RAM16_SET(0x00B4 + value2, RAM16(0x02C5));
    uint16_t value7 = RAM16(0x0014 + value);
    if (value7 == 0xFFFF) {
        r->a = 0x013B;
        r->x = value;
        r->y = value2;
        r->c = value7 >= 0xFFFF;
        JSR(c, 0x79E1, 0xC21394); /* select_boss_animation_and_reset_frame_cursor */
    }
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC279B8, SOM_RTS, "gen", consume_primary_boss_request_into_chain_delay_queue, 0, 0, 1, 0, 0, 43, 16)

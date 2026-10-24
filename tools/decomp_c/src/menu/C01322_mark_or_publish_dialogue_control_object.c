#include "som_c.h"

/* C01322 mark_or_publish_dialogue_control_object   [class A, 26 bytes, 11 instructions]
 * Source: src/rom/mark_or_publish_dialogue_control_object.s
 * Documented in docs/event-dialogue-line-completion.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void mark_or_publish_dialogue_control_object(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if (RAM8(0x1D13) == 0) {
        JSR(c, 0x133A, 0xC0133C); /* publish_eight_dialogue_control_object_sprite_records */
    } else {
        RAM8(0x0000 + RAM16(0x1D14)) = 1;
    }
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC01322, SOM_RTS, "gen", mark_or_publish_dialogue_control_object, 0, 0, 1, 1, 0, 26, 11)

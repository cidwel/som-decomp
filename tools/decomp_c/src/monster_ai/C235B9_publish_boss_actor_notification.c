#include "som_c.h"

/* C235B9 publish_boss_actor_notification   [class A, 6 bytes, 3 instructions]
 * Source: src/rom/publish_boss_actor_notification.s
 * Documented in docs/boss-actor-controller.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void publish_boss_actor_notification(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    RAM16_SET(0x0360, RAM16(0x0287));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC235B9, SOM_RTS, "gen", publish_boss_actor_notification, 0, 0, 1, 0, 0, 6, 3)

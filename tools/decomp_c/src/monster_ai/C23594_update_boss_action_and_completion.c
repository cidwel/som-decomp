#include "som_c.h"

/* C23594 update_boss_action_and_completion   [class B, 37 bytes, 16 instructions]
 * Source: src/rom/update_boss_action_and_completion.s
 * Documented in docs/boss-actor-controller.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void update_boss_action_and_completion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    uint16_t slot = RAM16(0x0287);
    uint16_t callback = RAM16(0x0048 + slot);
    r->a = callback;
    r->x = slot;
    r->z = callback == 0;
    r->n = callback & 0x8000;
    if (callback != 0)
        JSR(c, 0x359D, 0xC236B3); /* invoke_state_callback; it may leave the accumulator 8 bit */
    slot = r->xf ? RAM8(0x0287) : RAM16(0x0287); /* ldx $87 uses the index width the callback left */
    r->x = slot;
    JSR(c, 0x35A2, 0xC2362D); /* resolve_boss_hurt_death_timer_and_animation_completion */
    if (r->c) {
        slot = r->xf ? RAM8(0x0287) : RAM16(0x0287);
        r->x = slot;
        /* the next two accesses and the decrement use the accumulator width the callees left behind */
        const bool wide = !r->mf;
        uint16_t notified = wide ? RAM16(0x0080 + slot) : RAM8(0x0080 + slot);
        if (notified != 0) {
            JSR(c, 0x35AE, 0xC235B9); /* publish_boss_actor_notification */
            slot = r->xf ? RAM8(0x0287) : RAM16(0x0287);
            r->x = slot;
            if (wide) RAM16_SET(0x0080 + slot, 0);
            else RAM8(0x0080 + slot) = 0;
        }
        if (wide) RAM16_SET(OBJECT_PHASE + slot, (uint16_t)(RAM16(OBJECT_PHASE + slot) - 1));
        else RAM8(OBJECT_PHASE + slot)--;
    }
    r->c = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23594, SOM_RTS, "hand", update_boss_action_and_completion, 0, 0, 1, 0, 0, 37, 16)

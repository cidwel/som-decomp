#include "som_c.h"

/* C0939F poll_controllers_preserving_native_context   [class A, 20 bytes, 14 instructions]
 * Source: src/rom/poll_controllers_preserving_native_context.s
 * Documented in docs/game-controller-poll.md
 * Entry: M=any X=any DB=any D=$0000.  Callers read: ABXYCV.
 */
static void poll_controllers_preserving_native_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, -1, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t x_entry = r->xf;
    const uint8_t m_entry = r->mf;
    const bool carry = r->c;
    const bool overflow = r->v;
    const uint8_t db = r->db;
    r->a = 0;
    r->z = 1;
    r->n = 0;
    r->mf = 1;
    r->db = 0;
    r->sp -= 4;
    JSR(c, 0x93AE, 0xC093B9); /* poll_three_controller_words_and_publish_pressed_edges */
    r->sp += 4;
    r->c = carry;
    r->v = overflow;
    r->mf = m_entry;
    r->xf = x_entry;
    r->db = db;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0939F, SOM_RTS, "gen", poll_controllers_preserving_native_context, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 5, -1, -1, 20, 14)

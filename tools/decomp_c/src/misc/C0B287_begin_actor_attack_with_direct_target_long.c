#include "som_c.h"

/* C0B287 begin_actor_attack_with_direct_target_long   [class A, 14 bytes, 9 instructions]
 * Source: src/rom/begin_actor_attack_with_direct_target_long.s
 * Documented in docs/actor-attack-entry.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void begin_actor_attack_with_direct_target_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x0000) = 0xFF;
    r->a = (a_hi << 8) | 0;
    r->db = 0;
    r->sp -= 1;
    JSR(c, 0xB292, 0xC0B24A); /* begin_actor_attack_unless_movement_or_attack_busy */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0B287, SOM_RTL, "gen", begin_actor_attack_with_direct_target_long, 0, L_X | L_Y | L_C | L_V, 2, 1, 0, 14, 9)

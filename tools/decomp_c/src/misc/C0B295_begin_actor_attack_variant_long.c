#include "som_c.h"

/* C0B295 begin_actor_attack_variant_long   [class A, 10 bytes, 7 instructions]
 * Source: src/rom/begin_actor_attack_variant_long.s
 * Documented in docs/actor-attack-entry.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: XYCV.
 */
static void begin_actor_attack_variant_long(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    r->a = (a_hi << 8) | 0;
    r->db = 0;
    r->sp -= 1;
    JSR(c, 0xB29C, 0xC0B2A7); /* begin_actor_attack_variant_and_update_party_gauge */
    r->sp += 1;
    r->mf = 1;
    r->xf = 0;
    r->db = 0x7E;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0B295, SOM_RTL, "gen", begin_actor_attack_variant_long, 0, L_X | L_Y | L_C | L_V, 2, 1, 0, 10, 7)

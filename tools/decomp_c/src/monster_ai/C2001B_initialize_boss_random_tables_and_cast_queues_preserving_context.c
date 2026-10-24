#include "som_c.h"

/* C2001B initialize_boss_random_tables_and_cast_queues_preserving_context   [class C, 37 bytes, 23 instructions]
 * Source: src/rom/initialize_boss_random_tables_and_cast_queues_preserving_context.s
 * Documented in docs/boss-public-initialize.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void initialize_boss_random_tables_and_cast_queues_preserving_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    r->db = 0x7E;
    r->dp = 0x0200;
    r->sp -= 6;
    JSR(c, 0x002F, 0xC23057); /* initialize_boss_random_seed_pool_and_two_separated_indices */
    r->sp += 6;
    RAM16_SET(0x02C5, 0);
    RAM16_SET(0x02C7, 0xFFFF);
    r->a = a;
    r->z = a == 0;
    r->n = a & 0x8000;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 4;
    JSL(c, 0x003B, 0xC00045); /* public_cast_queue_initializer_jump */
    r->sp += 4;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2001B, SOM_RTL, "gen", initialize_boss_random_tables_and_cast_queues_preserving_context, 0, L_X | L_Y, 7, 0, 0, 37, 23)

#include "som_c.h"

/* C23197 dispatch_death_explosion_animation_lifetime   [class C, 8 bytes, 4 instructions]
 * Source: src/rom/dispatch_death_explosion_animation_lifetime.s
 * Documented in docs/boss-native-linked-death-effects.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: ABXYCZNV.
 */
static void dispatch_death_explosion_animation_lifetime(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    uint16_t value = RAM16(OBJECT_PHASE + x);
    r->a = (uint16_t)(value << 1);
    r->x = (uint16_t)(value << 1);
    r->c = value & 0x8000;
    r->z = (uint16_t)(value << 1) == 0;
    r->n = (uint16_t)(value << 1) & 0x8000;
    switch ((uint16_t)(value << 1)) {
    case 0x0000: TAIL_CALL_DYN(c, 0xC231A3, SOM_RTS); /* initialize_boss_death_explosion_then_check_animation */
    case 0x0002: TAIL_CALL_DYN(c, 0xC231C9, SOM_RTS); /* terminate_boss_death_explosion_when_animation_timer_zero */
    default: TAIL_CALL_DYN(c, 0xC20000 | BUS16(c, 0xC20000 + (uint16_t)(0x319F + ((uint16_t)(value << 1)))), SOM_RTS);
    }
}
SOM_REGISTER(0xC23197, SOM_RTS, "gen", dispatch_death_explosion_animation_lifetime, SOM_UNWINDS, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 8, 4)

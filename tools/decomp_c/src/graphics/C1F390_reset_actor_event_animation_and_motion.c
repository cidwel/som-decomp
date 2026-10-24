#include "som_c.h"

/* C1F390 reset_actor_event_animation_and_motion   [class B, 57 bytes, 25 instructions]
 * Source: src/rom/reset_actor_event_animation_and_motion.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: ABYCV.
 */
static void reset_actor_event_animation_and_motion(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x0A50 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0);
    RAM16_SET(0x0A52 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0);
    RAM16_SET(0x0A53 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0);
    RAM16_SET(0xE01A + x, 0);
    RAM16_SET(0x0A56 + (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3), 0x2817);
    RAM8(0xE041 + x) = 0;
    RAM8(0xE01C + x) = 0;
    RAM8(0xE01D + x) = 0;
    RAM8(0xE011 + x) = 0;
    RAM8(0xE013 + x) = 0;
    RAM8(0xE030 + x) = 0xFF;
    RAM8(0xE063 + x) = 0;
    r->a = 0x28FF;
    r->y = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 3);
    r->c = (uint16_t)((((uint8_t)x << 8) | (x >> 8)) << 2) & 0x8000;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F390, SOM_RTS, "gen", reset_actor_event_animation_and_motion, 0, L_A | L_B | L_Y | L_C | L_V, 1, 0, 0, 57, 25)

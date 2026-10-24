#include "som_c.h"

/* C76CA7 commit_native_hero_personality_and_reinitialize_actor_program   [class B, 68 bytes, 32 instructions]
 * Source: src/rom/commit_native_hero_personality_and_reinitialize_actor_program.s
 * Documented in docs/ui-native-personality-callbacks.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: nothing.
 */
static void commit_native_hero_personality_and_reinitialize_actor_program(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint8_t value = RAM8(0xA22B);
    uint8_t value2 = RAM8(0xA136);
    RAM8(0xA257 + value) = value2;
    uint8_t value3 = BUS8(c, 0xC76D8B + value2);
    RAM8(0xA173) = value3;
    RAM8(0xCC73 + value) = (RAM8(0xCC73 + value) & 0x80) | RAM8(0xA173);
    uint8_t value6 = BUS8(c, 0xC76D9B + value2);
    RAM8(0xCC7A + value) = value6;
    RAM8(0xCC7D + value) = RAM8(0xA211);
    r->a = (uint8_t)(value + 0x80);
    r->x = (uint16_t)((uint16_t)(((value << 8) | 0) << 1) + 0xE000);
    r->y = value;
    r->c = value + 0x80 > 0xFF;
    r->z = (uint8_t)(value + 0x80) == 0;
    r->n = (uint8_t)(value + 0x80) & 0x80;
    r->v = ((value ^ (uint8_t)(value + 0x80)) & ((uint8_t)(value + 0x80) ^ 0x80) & 0x80) != 0;
    JSL(c, 0x6CE9, 0xC10020); /* set_actor_program_long */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC76CA7, SOM_RTL, "gen", commit_native_hero_personality_and_reinitialize_actor_program, 0, 0, 2, 1, 0, 68, 32)

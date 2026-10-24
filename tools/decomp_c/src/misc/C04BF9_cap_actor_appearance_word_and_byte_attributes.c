#include "som_c.h"

/* C04BF9 cap_actor_appearance_word_and_byte_attributes   [class B, 47 bytes, 19 instructions]
 * Source: src/rom/cap_actor_appearance_word_and_byte_attributes.s
 * Documented in docs/monster-ai-opcodes.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXY.
 */
static void cap_actor_appearance_word_and_byte_attributes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t x = r->x;
    if (RAM16(ACTOR_MAGIC_DEFENSE + x) > 0x03E7) {
        RAM16_SET(ACTOR_MAGIC_DEFENSE + x, 0x03E7);
    }
    if (RAM16(ACTOR_DEFENSE + x) > 0x03E7) {
        RAM16_SET(ACTOR_DEFENSE + x, 0x03E7);
    }
    if (RAM8(ACTOR_EVADE + x) > 0x63) {
        RAM8(ACTOR_EVADE + x) = 0x63;
    }
    if (RAM8(ACTOR_MAGIC_EVADE + x) > 0x63) {
        RAM8(ACTOR_MAGIC_EVADE + x) = 0x63;
    }
    r->a = 0x0363;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC04BF9, SOM_RTS, "gen", cap_actor_appearance_word_and_byte_attributes, 0, L_A | L_B | L_X | L_Y, 1, 1, 0, 47, 19)

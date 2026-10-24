#include "som_c.h"

/* C290E4 publish_native7f_actor_mask_to_party_and_collision_byte   [class B, 42 bytes, 17 instructions]
 * Source: src/rom/publish_native7f_actor_mask_to_party_and_collision_byte.s
 * Documented in docs/boss-native7f-motion-collapse.md
 * Entry: M=any X=16 bit DB=$7E D=$0300.  Callers read: BYCV.
 */
static void publish_native7f_actor_mask_to_party_and_collision_byte(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint8_t value2 = BUS8(c, 0xC205F0 + RAM16(0x038B));
    RAM8(0x0395) = value2;
    RAM8(HERO_HIT_MASK) = value2 | RAM8(HERO_HIT_MASK);
    uint8_t value3 = RAM8(0x0395);
    RAM8(0xE259) = value3 | RAM8(0xE259);
    RAM8(0xE459) = value3 | RAM8(0xE459);
    RAM8(0x005A + RAM16(BATTLE_DEFENCE_WORK)) = 7;
    r->mf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC290E4, SOM_RTS, "gen", publish_native7f_actor_mask_to_party_and_collision_byte, 0, L_B | L_Y | L_C | L_V, 1, -1, 0, 42, 17)

#include "som_c.h"

/* C03962 prepare_cast_actor_context   [class A, 39 bytes, 22 instructions]
 * Source: src/rom/prepare_cast_actor_context.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=any X=16 bit DB=$7E D=any.  Callers read: BXYCZNV.
 */
static void prepare_cast_actor_context(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM16_SET(BATTLE_ATTACKER_PTR, x & 0x1FFF);
    RAM16_SET(BATTLE_DEFENDER_PTR, y & 0x1FFF);
    RAM8(BATTLE_ATTACKER_SLOT) = RAM8(0x0384) >> 1;
    uint8_t value2 = RAM8(0x0386);
    RAM8(0x0381) = value2 >> 1;
    uint16_t battle_defender_ptr = RAM16(BATTLE_DEFENDER_PTR);
    uint16_t battle_attacker_ptr = RAM16(BATTLE_ATTACKER_PTR);
    r->a = (r->a & 0x00FF) | (((y & 0x1FFF) >> 8) << 8);
    r->x = battle_defender_ptr;
    r->y = battle_attacker_ptr;
    r->c = value2 & 0x01;
    r->z = battle_attacker_ptr == 0;
    r->n = battle_attacker_ptr & 0x8000;
    r->mf = 1;
    r->dp = 0x0300;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC03962, SOM_RTS, "gen", prepare_cast_actor_context, 0, L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, -1, 0, 39, 22)

#include "som_c.h"
#include "som_hand.h"

/* C04177 actor_death_public_context_and_reward_cleanup_wrapper   [class B, 37 bytes, 19 instructions]
 * Source: src/rom/actor_death_public_context_and_reward_cleanup_wrapper.s
 * Documented in docs/boss-native-linked-public-death.md
 * Entry: M=16 bit X=16 bit DB=any D=any.  Callers read: YV.
 */
static void actor_death_public_context_and_reward_cleanup_wrapper(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, 0, 0)) return;
    const uint16_t sp0 = r->sp; /* the prologue pushes are real stack bytes */
    RAM8(sp0 - 0) = r->dp >> 8;
    RAM8(sp0 - 1) = (uint8_t)r->dp;
    RAM8(sp0 - 2) = r->db;
    RAM8(sp0 - 3) = (r->n << 7) | (r->v << 6) | (r->mf << 5) | (r->xf << 4) | (r->d << 3) | (r->i << 2) | (r->z << 1) | r->c;
    const uint16_t x = r->x;
    r->y = x;
    r->sp -= 4;
    JSR(c, 0x417F, 0xC03962); /* prepare_cast_actor_context */
    r->sp += 4;
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    JSL(c, 0x4183, 0xC05D46); /* clear_map_entry_party_effects */
    r->sp += 4;
    r->x = RAM16(0x0085 + r->dp); /* the callees may have changed D */
    r->mf = 1;
    r->xf = 0;
    r->sp -= 4;
    JSR(c, 0x4188, 0xC04247); /* external */
    r->sp += 4;
    RAM8(0x0080 + r->dp) &= 0x7F;
    BUS8_SET(c, ((uint32_t)r->db << 16) + 0xE059, 0);
    BUS8_SET(c, ((uint32_t)r->db << 16) + 0xE259, 0);
    BUS8_SET(c, ((uint32_t)r->db << 16) + 0xE459, 0);
    som_pull_p(c, sp0 - 3); /* PLP */
    r->db = RAM8(sp0 - 2); /* PLB */
    r->dp = RAM8(sp0 - 1) | (RAM8(sp0) << 8); /* PLD */
    r->z = r->dp == 0;
    r->n = r->dp & 0x8000;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC04177, SOM_RTL, "hand", actor_death_public_context_and_reward_cleanup_wrapper, 0, L_Y | L_V, 4, 0, 0, 37, 19)

#include "som_c.h"

/* C054E7 prepare_native_consumable_effect_actor_context_and_dispatch   [class C, 53 bytes, 30 instructions]
 * Source: src/rom/prepare_native_consumable_effect_actor_context_and_dispatch.s
 * Documented in docs/event-menu-consumable-effects.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: BXYV.
 */
static void prepare_native_consumable_effect_actor_context_and_dispatch(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint8_t d_entry = r->d;
    const uint8_t i_entry = r->i;
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    const bool carry = r->c;
    const bool zero = r->z;
    const bool negative = r->n;
    const bool overflow = r->v;
    RAM8(0x0000 + sp0) = 0;
    RAM8(0x0000 + sp0 - 1) = 0;
    RAM8(0x0000 + sp0 - 2) = 0;
    RAM8(0x0000 + sp0 - 3) = ((((negative << 7) | (overflow << 6)) | (d_entry << 3)) | (i_entry << 2)) | (zero << 1) | carry;
    RAM8(0x0000 + sp0 - 4) = a >> 8;
    RAM8(0x0000 + sp0 - 5) = (uint8_t)a;
    RAM16_SET(BATTLE_TEMP_AC, a & 0x0F);
    RAM8(0x0000 + sp0 - 4) = 0x7E;
    RAM8(0xE1F8 + x) = 0x10;
    RAM8(0x0380) |= 0x40;
    uint8_t battle_temp_ac = RAM8(BATTLE_TEMP_AC);
    RAM8(ACTOR_PENDING_HP_DAMAGE + x) = 0;
    RAM8(0xE1F2 + x) = 0;
    RAM8(HERO_HIT_MASK + x) = 0;
    r->a = (uint8_t)(battle_temp_ac << 4);
    r->x = (uint8_t)(battle_temp_ac << 1);
    r->y = x;
    r->c = (uint8_t)(battle_temp_ac << 3) & 0x80;
    r->z = (uint8_t)(battle_temp_ac << 4) == 0;
    r->n = (uint8_t)(battle_temp_ac << 4) & 0x80;
    r->mf = 1;
    r->db = 0x7E;
    r->dp = 0x0300;
    switch ((uint8_t)(battle_temp_ac << 1)) {
    case 0x0000: TAIL_CALL_FRAME(c, 0xC05536, SOM_RTL, 4); /* apply_native_consumable_effects_and_restore_original_cpu_context */
    case 0x0002: TAIL_CALL_FRAME(c, 0xC05536, SOM_RTL, 4); /* apply_native_consumable_effects_and_restore_original_cpu_context */
    default: TAIL_CALL_FRAME(c, 0xC00000 | BUS16(c, 0xC00000 + (uint16_t)(0x551C + ((uint8_t)(battle_temp_ac << 1)))), SOM_RTL, 4);
    }
}
SOM_REGISTER(0xC054E7, SOM_RTL, "gen", prepare_native_consumable_effect_actor_context_and_dispatch, 0, L_B | L_X | L_Y | L_V, 6, 0, 0, 53, 30)

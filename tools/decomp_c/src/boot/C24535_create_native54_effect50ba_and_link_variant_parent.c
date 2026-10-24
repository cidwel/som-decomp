#include "som_c.h"

/* C24535 create_native54_effect50ba_and_link_variant_parent   [class A, 25 bytes, 10 instructions]
 * Source: src/rom/create_native54_effect50ba_and_link_variant_parent.s
 * Documented in docs/boss-native54-setup.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void create_native54_effect50ba_and_link_variant_parent(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    uint8_t value = RAM8(0x0042 + x);
    RAM8(0x0395) = value;
    r->a = (a_hi << 8) | value;
    r->x = 0x50BA;
    r->y = 0x2000;
    { const uint16_t sp_call = r->sp; JSR(c, 0x4542, 0xC20D53); GUARD_JSR(c, sp_call, 0x4542); } /* allocate_boss_object_pool_slot */
    uint16_t x_ret = r->x;
    RAM16_SET(0x0042 + x_ret, RAM16(0x0395));
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    RAM16_SET(0x00B4 + x_ret, battle_defence_work);
    r->a = battle_defence_work;
    r->z = battle_defence_work == 0;
    r->n = battle_defence_work & 0x8000;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC24535, SOM_RTS, "gen", create_native54_effect50ba_and_link_variant_parent, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 25, 10)

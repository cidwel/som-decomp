#include "som_c.h"

/* C28597 move_native59_one_step_toward_farthest_party_target   [class B, 52 bytes, 23 instructions]
 * Source: src/rom/move_native59_one_step_toward_farthest_party_target.s
 * Documented in docs/boss-native59-setup.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: nothing.
 */
static void move_native59_one_step_toward_farthest_party_target(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    JSR(c, 0x8599, 0xC2325A); /* select_farthest_active_living_party_actor_last_tie */
    uint16_t a_all = r->a;
    RAM16_SET(0x00A9 + RAM16(0x0287), a_all);
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0x85A1, 0xC20941); /* derive_eight_way_direction_to_low_byte_target */
    uint16_t a_all2 = r->a;
    RAM16_SET(0x00AB + RAM16(0x0287), a_all2);
    uint16_t value3 = BUS16(c, 0xC285CB + (uint16_t)(a_all2 << 2));
    RAM16_SET(0x0295, value3);
    uint16_t value4 = BUS16(c, 0xC285CD + (uint16_t)(a_all2 << 2));
    RAM16_SET(0x0297, value4);
    uint16_t value5 = RAM16(0x0287);
    RAM16_SET(0x002B + value5, (uint16_t)(RAM16(0x0295) + RAM16(0x002B + value5)));
    RAM16_SET(0x0032 + value5, (uint16_t)(RAM16(0x0297) + RAM16(0x0032 + value5)));
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC28597, SOM_RTS, "gen", move_native59_one_step_toward_farthest_party_target, 0, 0, 1, 0, 0, 52, 23)

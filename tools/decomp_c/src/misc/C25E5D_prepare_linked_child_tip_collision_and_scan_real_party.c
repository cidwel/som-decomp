#include "som_c.h"

/* C25E5D prepare_linked_child_tip_collision_and_scan_real_party   [class A, 30 bytes, 12 instructions]
 * Source: src/rom/prepare_linked_child_tip_collision_and_scan_real_party.s
 * Documented in docs/boss-native-linked-motion.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXV.
 */
static void prepare_linked_child_tip_collision_and_scan_real_party(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint16_t value = RAM16(0x0287);
    RAM8(0x00C0 + value) = RAM8(0x00B9 + value);
    RAM8(0x00C1 + value) = RAM8(0x00BB + value);
    RAM8(0x00C2 + value) = 0x10;
    RAM8(0x00C3 + value) = 0x10;
    r->a = (a >> 8 << 8) | 0x10;
    r->x = value;
    JSR(c, 0x5E79, 0xC23CE8); /* scan_projectile_collision_and_mark_parent_target_contacts */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC25E5D, SOM_RTS, "gen", prepare_linked_child_tip_collision_and_scan_real_party, 0, L_B | L_X | L_V, 1, 0, 0, 30, 12)

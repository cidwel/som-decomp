#include "som_c.h"

/* C2B49C publish_queued_native_motion_and_saved_restore_state   [class B, 123 bytes, 43 instructions]
 * Source: src/rom/publish_queued_native_motion_and_saved_restore_state.s
 * Documented in docs/actor-queued-effect-requests.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void publish_queued_native_motion_and_saved_restore_state(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t value = BUS8(c, 0xD04157 + x);
    RAM8(0xE04F + y) = value;
    RAM8(0xE060 + y) = 0xC0;
    RAM8(0xE128 + y) = RAM8(0xE01C + y);
    RAM8(0xE129 + y) = RAM8(0xE05D + y);
    RAM8(0xE01C + y) = 0x40;
    RAM8(0xE114 + y) = 0;
    RAM8(0xE05D + y) = 0;
    RAM8(0xE012 + y) = 0;
    RAM8(0xE00C + y) = 0;
    RAM8(0xE025 + y) = 0;
    RAM8(0xE084 + y) = 0;
    RAM16_SET(0xE12E + y, RAM16(0xE104 + y));
    RAM16_SET(0xE124 + y, RAM16(0xE106 + y));
    RAM16_SET(0xE12A + y, RAM16(0xE05E + y));
    RAM16_SET(0xE134 + y, RAM16(0xE006 + y));
    RAM16_SET(0xE122 + y, RAM16(0xE008 + y));
    uint16_t value9 = BUS16(c, 0xD0415C + x);
    RAM16_SET(0xE0FC + y, value9);
    uint16_t value10 = BUS16(c, 0xD0415A + x);
    RAM16_SET(0xE06A + y, value10);
    RAM16_SET(0xE104 + y, 0);
    RAM16_SET(0xE006 + y, 0);
    RAM16_SET(0xE008 + y, 0);
    RAM16_SET(0xE11A + y, 0);
    RAM16_SET(0xE11C + y, 0);
    RAM16_SET(0xE11E + y, 0);
    RAM16_SET(0xE118 + y, 1);
    r->a = 1;
    r->mf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC2B49C, SOM_RTL, "gen", publish_queued_native_motion_and_saved_restore_state, 0, L_B | L_Y | L_C | L_V, 1, 1, 0, 123, 43)

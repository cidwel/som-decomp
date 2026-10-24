#include "som_c.h"

/* C0E00C retire_and_rescan_cached_map_object_slot   [class A, 40 bytes, 17 instructions]
 * Source: src/rom/retire_and_rescan_cached_map_object_slot.s
 * Documented in docs/event-vm-object-refresh.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: Y.
 */
static void retire_and_rescan_cached_map_object_slot(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const bool carry = r->c;
    uint8_t value = RAM8(0xE000 + x);
    uint8_t a_hi1;
    bool carry1;
    if (value == 0) {
        a_hi1 = a_hi;
        carry1 = carry;
    } else {
        RAM8(0xE000 + x) = 0;
        JSR(c, 0xE018, 0xC0E2E1); /* release_map_object_to_position_cache */
        uint16_t a_all = r->a;
        bool carry_ret = r->c;
        a_hi1 = a_all >> 8;
        carry1 = carry_ret;
    }
    RAM8(0xE043 + x) = 0;
    RAM8(0x000C) = RAM8(0x00BC);
    RAM16_SET(0x0004, 0);
    RAM16_SET(0x0006, 0);
    RAM16_SET(0x0008, 0xFFFF);
    r->a = 0xFFFF;
    r->y = 0;
    r->c = carry1;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xE032, 0xC0DDBE); /* scan_map_object_cache_for_creation */
    r->xf = 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC0E00C, SOM_RTL, "gen", retire_and_rescan_cached_map_object_slot, 0, L_Y, 1, 1, 0, 40, 17)

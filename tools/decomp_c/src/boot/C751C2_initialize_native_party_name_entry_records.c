#include "som_c.h"

/* C751C2 initialize_native_party_name_entry_records   [class B, 85 bytes, 37 instructions]
 * Source: src/rom/initialize_native_party_name_entry_records.s
 * Documented in docs/event-menu-name-helpers.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BV.
 */
static void initialize_native_party_name_entry_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    uint16_t x1 = 0;
    uint16_t y1 = 0x0180;
    for (;;) {
        RAM8(0xE180 + x1) = 0;
        RAM8(0xE380 + x1) = 0;
        RAM8(0xE580 + x1) = 0;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 - 1);
        if (!(y1 != 0)) break;
    }
    RAM8(0xE180) = 0x80;
    RAM8(0xE1E7) = 0x80;
    RAM8(0xE380) = 0x81;
    RAM8(0xE3E7) = 0x81;
    RAM8(0xE580) = 0x82;
    RAM8(0xE5E7) = 0x82;
    RAM8(INVENTORY_GOLD) = 0;
    RAM8(0xCC6B) = 0;
    RAM8(0xCC6C) = 0;
    RAM8(0xCC70) = 0;
    RAM8(0xA25A) = 0x75;
    RAM8(0xA25B) = 0;
    RAM8(0xA257) = 0x0F;
    RAM8(0xA258) = 0x0F;
    RAM8(0xA259) = 0x0F;
    RAM8(0x00EE) = 0;
    RAM8(0x00EF) = 0;
    RAM8(0x00F0) = 0;
    r->a = (a_hi << 8) | 0x0F;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC751C2, SOM_RTS, "gen", initialize_native_party_name_entry_records, 0, L_B | L_V, 2, 1, 0, 85, 37)

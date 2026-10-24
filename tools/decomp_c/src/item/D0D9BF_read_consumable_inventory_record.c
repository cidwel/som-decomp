#include "som_c.h"

/* D0D9BF read_consumable_inventory_record   [class A, 15 bytes, 7 instructions]
 * Source: src/rom/read_consumable_inventory_record.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABY.
 */
static void read_consumable_inventory_record(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    r->a = ((a >> 8 << 8) | RAM8(INVENTORY_CONSUMABLES + (uint8_t)(a >> 8 << 8 | ((uint8_t)a & 0x0F)))) & 0xFF;
    r->y = (uint8_t)y;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D9BF, SOM_RTS, "gen", read_consumable_inventory_record, 0, L_A | L_B | L_Y, 1, 0, 0, 15, 7)

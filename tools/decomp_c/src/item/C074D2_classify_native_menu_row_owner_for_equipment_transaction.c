#include "som_c.h"

/* C074D2 classify_native_menu_row_owner_for_equipment_transaction   [class A, 18 bytes, 11 instructions]
 * Source: src/rom/classify_native_menu_row_owner_for_equipment_transaction.s
 * Documented in docs/event-menu-equipment-dispatch.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABV.
 */
static void classify_native_menu_row_owner_for_equipment_transaction(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t a2;
    if ((a & 0x80) != 0) {
        a2 = a;
    } else {
        uint8_t ring_owner = RAM8(RING_OWNER);
        uint8_t a1;
        if ((uint8_t)((a_hi << 8) | a) == ring_owner) {
            a1 = 0;
        } else {
            a1 = 1;
        }
        a2 = a1;
    }
    SET_A8(r, (uint8_t)(a2 + 2));
    RETURN_RTS(c);
}
SOM_REGISTER(0xC074D2, SOM_RTS, "gen", classify_native_menu_row_owner_for_equipment_transaction, 0, L_A | L_B | L_V, 1, 1, 1, 18, 11)

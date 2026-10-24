#include "som_c.h"

/* D0C800 locate_menu_category_inventory_and_equipment_spans   [class B, 63 bytes, 28 instructions]
 * Source: src/rom/locate_menu_category_inventory_and_equipment_spans.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYV.
 */
static void locate_menu_category_inventory_and_equipment_spans(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t ring_category = RAM16(RING_CATEGORY);
    if ((uint16_t)((ring_category & 0xFF) - 4) == 0) {
        r->a = 0;
        r->x = 0x24;
        r->y = 0x60;
        r->v = (((ring_category & 0xFF) ^ 4) & ((ring_category & 0xFF) ^ (uint16_t)((ring_category & 0xFF) - 4)) & 0x8000) != 0;
        RETURN_RTL(c);
    }
    if ((uint16_t)((ring_category & 0xFF) - 5) == 0) {
        r->a = 0x15;
        r->x = 0x30;
        r->y = 0x61;
        r->v = (((ring_category & 0xFF) ^ 4) & ((ring_category & 0xFF) ^ (uint16_t)((ring_category & 0xFF) - 4)) & 0x8000) != 0;
        RETURN_RTL(c);
    }
    if ((uint16_t)((ring_category & 0xFF) - 6) == 0) {
        r->a = 0x2A;
        r->x = 0x3C;
        r->y = 0x62;
        r->v = (((ring_category & 0xFF) ^ 4) & ((ring_category & 0xFF) ^ (uint16_t)((ring_category & 0xFF) - 4)) & 0x8000) != 0;
        RETURN_RTL(c);
    }
    if ((uint16_t)((ring_category & 0xFF) - 7) == 0) {
        r->a = 0x15;
        r->x = 0x30;
        r->y = 0x61;
        r->v = (((ring_category & 0xFF) ^ 4) & ((ring_category & 0xFF) ^ (uint16_t)((ring_category & 0xFF) - 4)) & 0x8000) != 0;
        RETURN_RTL(c);
    }
    r->a = 0;
    r->x = 0x54;
    r->y = 0x63;
    r->v = (((ring_category & 0xFF) ^ 4) & ((ring_category & 0xFF) ^ (uint16_t)((ring_category & 0xFF) - 4)) & 0x8000) != 0;
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0C800, SOM_RTL, "gen", locate_menu_category_inventory_and_equipment_spans, 0, L_A | L_B | L_X | L_Y | L_V, 1, 0, 0, 63, 28)

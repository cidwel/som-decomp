#include "som_c.h"

/* D0D5F3 dispatch_native_menu_second_line_description   [class C, 35 bytes, 16 instructions]
 * Source: src/rom/dispatch_native_menu_second_line_description.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: YCV.
 */
static void dispatch_native_menu_second_line_description(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    if (RAM8(0x1847) == 0) {
        uint8_t value2 = RAM8(0x1803);
        if ((value2 & 0x20) != 0) {
            r->y = (uint8_t)y;
            r->v = value2 & 0x40;
            r->mf = 1;
            r->xf = 1;
            RETURN_RTS(c);
        }
        uint8_t value3 = RAM8(0x19D3);
        if (value3 != 0x9B) {
            uint8_t ring_category = RAM8(RING_CATEGORY);
            r->a = (a >> 8 << 8) | (uint8_t)(ring_category << 1);
            r->x = (uint8_t)((a >> 8 << 8) | (uint8_t)(ring_category << 1));
            r->y = (uint8_t)y;
            r->c = ring_category & 0x80;
            r->z = (uint8_t)((a >> 8 << 8) | (uint8_t)(ring_category << 1)) == 0;
            r->n = (uint8_t)((a >> 8 << 8) | (uint8_t)(ring_category << 1)) & 0x80;
            r->v = value2 & 0x40;
            switch ((uint8_t)((a >> 8 << 8) | (uint8_t)(ring_category << 1))) {
            case 0x0000: TAIL_CALL_DYN(c, 0xD0D624, SOM_RTS); /* format_consumable_inventory_quantity_description */
            case 0x0002: TAIL_CALL_DYN(c, 0xD0D66F, SOM_RTS); /* format_selected_equipment_current_and_candidate_stat */
            default: TAIL_CALL_DYN(c, 0xD00000 | BUS16(c, 0xD00000 + (uint16_t)(0xD616 + ((uint8_t)((a >> 8 << 8) | (uint8_t)(ring_category << 1))))), SOM_RTS);
            }
        }
        r->y = (uint8_t)y;
        r->c = value3 >= 0x9B;
        r->v = value2 & 0x40;
        r->mf = 1;
        r->xf = 1;
        RETURN_RTS(c);
    }
    r->y = (uint8_t)y;
    r->mf = 1;
    r->xf = 1;
    TAIL_CALL(c, 0xD0D822, SOM_RTS); /* render_complete_menu_price_or_armor_selection_description */
}
SOM_REGISTER(0xD0D5F3, SOM_RTS, "gen", dispatch_native_menu_second_line_description, SOM_UNWINDS, L_Y | L_C | L_V, 1, 0, 0, 35, 16)

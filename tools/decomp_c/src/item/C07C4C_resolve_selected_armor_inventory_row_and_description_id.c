#include "som_c.h"

/* C07C4C resolve_selected_armor_inventory_row_and_description_id   [class B, 47 bytes, 23 instructions]
 * Source: src/rom/resolve_selected_armor_inventory_row_and_description_id.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=any X=16 bit DB=any D=any.  Callers read: BXYV.
 */
static void resolve_selected_armor_inventory_row_and_description_id(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, -1, -1, 0)) return;
    const uint8_t db = r->db;
    JSL(c, 0x7C4F, 0xC06BE2); /* calculate_wrapped_native_menu_row_index */
    uint16_t a_all = r->a;
    uint8_t a1 = a_all & 0xFF;
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0x54;
    uint16_t y1 = a_all & 0xFF;
    for (;;) {
        uint8_t value = RAM8(0xCC00 + x1);
        if (value == 0xFF) {
            a1 = value;
            x1 = (uint16_t)(x1 + 1);
            continue;
        }
        a1 = value;
        x1 = (uint16_t)(x1 + 1);
        y1 = (uint16_t)(y1 - 1);
        if (!(!(y1 & 0x8000))) break;
    }
    BUS16_SET(c, (db << 0x10) + 0x183E, (uint16_t)(x1 - 1));
    BUS8_SET(c, (db << 0x10) + 0x1842, a1 & 0x3F);
    BUS8_SET(c, (db << 0x10) + 0x1843, (uint8_t)((a_hi1 << 8) | (uint8_t)(x1 - 0x55)));
    r->a = (a_hi1 << 8) | (uint8_t)(x1 - 0x55);
    r->x = (uint8_t)((a_hi1 << 8) | (uint8_t)(x1 - 0x55));
    r->y = (uint8_t)y1;
    r->v = (((uint8_t)(x1 - 1) ^ 0x54) & ((uint8_t)(x1 - 1) ^ (uint8_t)(x1 - 0x55)) & 0x80) != 0;
    r->mf = 1;
    r->xf = 1;
    RETURN_RTL(c);
}
SOM_REGISTER(0xC07C4C, SOM_RTL, "gen", resolve_selected_armor_inventory_row_and_description_id, 0, L_B | L_X | L_Y | L_V, 1, -1, 0, 47, 23)

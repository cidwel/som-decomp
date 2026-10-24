#include "som_c.h"

/* C06D1C project_and_publish_all_native_menu_ring_rows   [class A, 27 bytes, 15 instructions]
 * Source: src/rom/project_and_publish_all_native_menu_ring_rows.s
 * Documented in docs/event-menu-ring-rows.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: BXYCV.
 */
static void project_and_publish_all_native_menu_ring_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint8_t a1 = RAM16(RING_ENTRY_COUNT) & 0xFF;
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0x18C0;
    uint16_t y1 = y;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        r->x = x1;
        r->y = y1;
        r->c = carry1;
        r->mf = 0;
        r->xf = 0;
        r->db = 0;
        r->dp = 0;
        r->sp -= 4;
        JSR(c, 0x6D2B, 0xC06D74); /* update_native_menu_ring_row_angle_project_coordinates_and_publish_oam */
        r->sp += 4;
        uint16_t y_ret = r->y;
        bool again = (uint16_t)(((a_hi1 << 8) | a1) - 1) != 0;
        uint8_t a1_next = (uint8_t)(((a_hi1 << 8) | a1) - 1);
        uint8_t a_hi1_next = (uint16_t)(((a_hi1 << 8) | a1) - 1) >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 0x10);
        uint16_t y1_next = y_ret;
        bool carry1_next = x1 + 0x10 > 0xFFFF;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x10)) & ((uint16_t)(x1 + 0x10) ^ 0x10) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!again) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06D1C, SOM_RTS, "gen", project_and_publish_all_native_menu_ring_rows, 0, L_B | L_X | L_Y | L_C | L_V, 4, 1, 1, 27, 15)

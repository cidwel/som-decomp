#include "som_c.h"

/* C069F0 restore_menu_actor_and_controller_selection_from_coordinates   [class B, 107 bytes, 55 instructions]
 * Source: src/rom/restore_menu_actor_and_controller_selection_from_coordinates.s
 * Documented in docs/event-menu-actor-cycle.md
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void restore_menu_actor_and_controller_selection_from_coordinates(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t value = RAM16(0x183E);
    uint16_t value2 = RAM16(0x1840);
    r->a = ((uint8_t)value2 << 8) | (value2 >> 8);
    r->x = ((uint8_t)value << 8) | (value >> 8);
    r->y = ((uint8_t)value2 << 8) | (value2 >> 8);
    JSR(c, 0x69FE, 0xC06A5B); /* update_event_menu_primary_mode_flag */
    r->mf = 1; /* sep */
    r->xf = 1;
    r->x &= 0xFF;
    r->y &= 0xFF;
    uint16_t a_all = r->a;
    uint8_t x_ret = r->x;
    const uint8_t y_ret = (uint8_t)r->y; /* CPY compares Y as the callee left it */
    uint8_t a2;
    if (x_ret == 0) {
        a2 = 0;
    } else {
        uint8_t a1;
        if (x_ret == 2) {
            a1 = 1;
        } else {
            a1 = 2;
        }
        a2 = a1;
    }
    RAM8(RING_OWNER) = a2;
    uint8_t a4;
    uint8_t x2;
    if (y_ret == 0) {
        a4 = 1;
        x2 = 0;
    } else {
        uint8_t a3;
        uint8_t x1;
        if (y_ret == 2) {
            a3 = 2;
            x1 = 1;
        } else {
            a3 = 4;
            x1 = 2;
        }
        a4 = a3;
        x2 = x1;
    }
    RAM8(0x1805) = x2;
    r->a = (a_all >> 8 << 8) | a4;
    r->mf = 1;
    r->xf = 1;
    r->sp -= 1;
    JSR(c, 0x6A28, 0xC06ADE); /* choose_other_available_menu_actor */
    r->sp += 1;
    uint16_t a_all2 = r->a;
    r->a = (a_all2 >> 8 << 8) | a4;
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x6A2C, 0xC06A73); /* bind_event_menu_controller_to_party_actor */
    r->mf = 0; /* rep */
    r->xf = 0;
    RAM8(RING_CATEGORY) = RAM8(0x0000 + (RAM16(RING_OWNER) & 0xFF) + 0x1870);
    uint16_t ring_owner2 = RAM16(RING_OWNER);
    RAM16_SET(0x1844, (uint16_t)((uint16_t)((((ring_owner2 & 0xFF) << 8) | 0) << 1) + 0xE180));
    uint16_t value4 = RAM16(0x0010 + (uint16_t)((uint16_t)((((ring_owner2 & 0xFF) << 8) | 0) << 1) + 0xE180));
    r->a = value4 & 0x8000;
    r->x = (uint16_t)((uint16_t)((((ring_owner2 & 0xFF) << 8) | 0) << 1) + 0xE180);
    r->c = (uint16_t)((((ring_owner2 & 0xFF) << 8) | 0) << 1) + 0xE180 > 0xFFFF;
    r->z = (value4 & 0x8000) == 0;
    r->n = value4 & 0x8000 & 0x8000;
    r->v = (((uint16_t)((((ring_owner2 & 0xFF) << 8) | 0) << 1) ^ (uint16_t)((uint16_t)((((ring_owner2 & 0xFF) << 8) | 0) << 1) + 0xE180)) & ((uint16_t)((uint16_t)((((ring_owner2 & 0xFF) << 8) | 0) << 1) + 0xE180) ^ 0xE180) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC069F0, SOM_RTS, "hand", restore_menu_actor_and_controller_selection_from_coordinates, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 107, 55)

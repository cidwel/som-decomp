#include "som_c.h"

/* C06AA5 initialize_event_menu_controller_and_descriptor   [class B, 57 bytes, 26 instructions]
 * Source: src/rom/initialize_event_menu_controller_and_descriptor.s
 * Documented in docs/event-menu-actor-selection.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void initialize_event_menu_controller_and_descriptor(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    RAM8(RING_CATEGORY) = 0;
    r->x = (uint8_t)x;
    r->y = (uint8_t)y;
    r->xf = 1;
    JSR(c, 0x6AAC, 0xC06A5B); /* update_event_menu_primary_mode_flag */
    uint16_t a_all = r->a;
    uint8_t value = RAM8(0x00D9);
    uint8_t a2;
    if (value & 0x80) {
        a2 = value;
    } else {
        uint8_t value2 = RAM8(0x00DA);
        uint8_t a1;
        if (value2 & 0x80) {
            a1 = value2;
        } else {
            a1 = RAM8(0x00DB);
        }
        a2 = a1;
    }
    RAM8(RING_OWNER) = (a2 & 7) >> 1;
    RAM8(0x1805) = (a2 & 7) >> 1;
    uint8_t a3;
    if ((a2 & 7) >> 1 << 1 != 0) {
        a3 = (a2 & 7) >> 1 << 1;
    } else {
        a3 = ((a2 & 7) >> 1 << 1) + 1;
    }
    r->a = (a_all >> 8 << 8) | a3;
    r->mf = 1;
    r->xf = 1;
    JSR(c, 0x6AC6, 0xC06A73); /* bind_event_menu_controller_to_party_actor */
    uint16_t value4 = RAM16(0x1840);
    uint16_t value5 = BUS16(c, 0xD8FB80);
    uint16_t value6 = BUS16(c, 0xD80000 + (uint16_t)(((value4 & 0xFF) << 1) + value5));
    RAM16_SET(0x183C, value6);
    r->a = value6;
    r->x = (uint16_t)(((value4 & 0xFF) << 1) + value5);
    r->c = ((value4 & 0xFF) << 1) + value5 > 0xFFFF;
    r->z = value6 == 0;
    r->n = value6 & 0x8000;
    r->v = ((((value4 & 0xFF) << 1) ^ (uint16_t)(((value4 & 0xFF) << 1) + value5)) & (value5 ^ (uint16_t)(((value4 & 0xFF) << 1) + value5)) & 0x8000) != 0;
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC06AA5, SOM_RTS, "gen", initialize_event_menu_controller_and_descriptor, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 57, 26)

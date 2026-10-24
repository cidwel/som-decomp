#include "som_c.h"

/* D0D9CE rebuild_selected_hero_attributes_for_menu_description   [class A, 16 bytes, 8 instructions]
 * Source: src/rom/rebuild_selected_hero_attributes_for_menu_description.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=any X=16 bit DB=$00 D=$0000.  Callers read: YV.
 */
static void rebuild_selected_hero_attributes_for_menu_description(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t ring_owner = RAM16(RING_OWNER);
    r->a = (((uint8_t)(ring_owner << 1) << 8) | ((uint16_t)(ring_owner << 1) >> 8)) & 0x0600;
    r->x = (((uint8_t)(ring_owner << 1) << 8) | ((uint16_t)(ring_owner << 1) >> 8)) & 0x0600;
    r->c = ring_owner & 0x8000;
    r->z = ((((uint8_t)(ring_owner << 1) << 8) | ((uint16_t)(ring_owner << 1) >> 8)) & 0x0600) == 0;
    r->n = (((uint8_t)(ring_owner << 1) << 8) | ((uint16_t)(ring_owner << 1) >> 8)) & 0x0600 & 0x8000;
    r->mf = 0;
    JSL(c, 0xD9DC, 0xC00036); /* rebuild_actor_stats_public_jump */
    r->mf = 0;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xD0D9CE, SOM_RTS, "gen", rebuild_selected_hero_attributes_for_menu_description, 0, L_Y | L_V, 1, -1, 0, 16, 8)

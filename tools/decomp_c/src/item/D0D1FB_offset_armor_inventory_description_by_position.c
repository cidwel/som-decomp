#include "som_c.h"
#include "som_hand_b.h"

/* D0D1FB offset_armor_inventory_description_by_position   [class B, 52 bytes, 32 instructions]
 * Source: src/rom/offset_armor_inventory_description_by_position.s
 * Documented in docs/event-menu-text-tick.md
 * Entry: M=any X=any DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void offset_armor_inventory_description_by_position(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, -1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    i_php(c);
    r->mf = 0; /* REP #$30 */
    r->xf = 0;
    r->a &= 0x003F;
    i_phx(c);
    i_pha(c);
    if ((RAM16(0x1809) & 0x00FF) == 3) {
        uint8_t offset = (uint8_t)(r->x - 0x54); /* position of the armor row inside the armor page */
        uint16_t stacked = RAM16(r->sp + 1);
        uint8_t nine = (uint8_t)((uint8_t)(offset << 3) + offset);
        RAM16_SET(r->sp + 1, (uint16_t)(nine + stacked));
    }
    i_pla(c);
    i_plx(c);
    hand_plp(c);
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0D1FB, SOM_RTL, "hand", offset_armor_inventory_description_by_position, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 6, -1, -1, 52, 32)

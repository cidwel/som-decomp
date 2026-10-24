#include "som_c.h"
#include "som_hand_b.h"

/* C2A043 copy_map_tile_attribute_entries   [class A, 38 bytes, 20 instructions]
 * Source: src/rom/copy_map_tile_attribute_entries.s
 * Documented in docs/maps.md
 * Entry: M=16 bit X=16 bit DB=$7F D=$0000.  Callers read: BX.
 */
static void copy_map_tile_attribute_entries(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    uint16_t y = 0;
    uint16_t value = 0;
    uint16_t sprite = 0;
    do {
        value = BUS16(c, 0xCB0400 + r->x) & 0x00FF;
        r->x++;
        uint16_t entry = (uint16_t)(value << 2);
        i_phx(c); /* the saved X lives on the real stack: a store through ($14),Y can reach it near the end of the bank */
        r->x = entry;
        sprite = BUS16(c, 0xCB0000 + entry);
        uint32_t dest = (uint32_t)(0x7F0000 + RAM16(0x0014));
        bus16_set_once(c, dest + y, sprite);
        y += 2;
        value = BUS16(c, 0xCB0002 + entry);
        dest = (uint32_t)(0x7F0000 + RAM16(0x0014));
        bus16_set_once(c, dest + y, value);
        y += 2;
        i_plx(c);
    } while (y < 0x0300);
    r->a = value;
    r->y = y;
    hand_cmp16(r, y, 0x0300);
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2A043, SOM_RTS, "hand", copy_map_tile_attribute_entries, 0, L_B | L_X, 2, 0, 0, 38, 20)

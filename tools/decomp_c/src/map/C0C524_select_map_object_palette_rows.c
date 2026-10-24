#include "som_c.h"

/* C0C524 select_map_object_palette_rows   [class B, 68 bytes, 32 instructions]
 * Source: src/rom/select_map_object_palette_rows.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XY.
 */
static void select_map_object_palette_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    RAM8(0x00ED) = (a >= 0xFF) << 7;
    uint16_t value = BUS16(c, 0xC82E00 + ((((a_hi << 8) | a) & 0x7F) << 1 << 1));
    r->a = value;
    r->x = (((a_hi << 8) | a) & 0x7F) << 1 << 1;
    r->y = 0x82;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->sp -= 1;
    JSR(c, 0xC547, 0xC0C568); /* copy_map_object_palette_row */
    r->sp += 1;
    uint16_t x_ret = r->x;
    uint16_t value2 = BUS16(c, 0xC82E01 + x_ret);
    r->a = value2;
    r->y = 0xA2;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xC551, 0xC0C568); /* copy_map_object_palette_row */
    r->sp += 1;
    uint16_t x_ret2 = r->x;
    uint16_t value3 = BUS16(c, 0xC82E02 + x_ret2);
    r->a = value3;
    r->y = 0xC2;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xC55B, 0xC0C568); /* copy_map_object_palette_row */
    r->sp += 1;
    uint16_t x_ret3 = r->x;
    uint16_t value4 = BUS16(c, 0xC82E03 + x_ret3);
    r->a = value4;
    r->y = 0xE2;
    r->mf = 0;
    r->xf = 0;
    r->sp -= 1;
    JSR(c, 0xC565, 0xC0C568); /* copy_map_object_palette_row */
    r->sp += 1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0C524, SOM_RTS, "gen", select_map_object_palette_rows, 0, L_X | L_Y, 3, 1, 1, 68, 32)

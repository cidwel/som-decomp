#include "som_c.h"

/* C1B6BF rotate_map_graphics_wave_plane   [class B, 42 bytes, 22 instructions]
 * Source: src/rom/rotate_map_graphics_wave_plane.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$7F D=$0000.  Callers read: B.
 */
static void rotate_map_graphics_wave_plane(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint8_t x = r->x;
    uint8_t a_hi1 = a_hi;
    uint8_t x1 = x;
    uint8_t y1 = 0;
    for (;;) {
        uint8_t value = BUS8(c, RAM16(0x0006) + 0x7F0000 + y1);
        r->a = (a_hi1 << 8) | value;
        r->x = x1;
        r->y = y1;
        r->mf = 1;
        r->xf = 1;
        r->db = 0x7F;
        r->dp = 0;
        JSR(c, 0xB6C5, 0xC1B6E9); /* rotate_map_graphics_byte_by_wave_phase */
        uint16_t a_all = r->a;
        BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + y1, (uint8_t)a_all);
        uint8_t value2 = BUS8(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 1));
        r->a = (a_all >> 8 << 8) | value2;
        r->y = (uint8_t)(y1 + 1);
        r->mf = 1;
        r->xf = 1;
        JSR(c, 0xB6CD, 0xC1B6E9); /* rotate_map_graphics_byte_by_wave_phase */
        uint16_t a_all2 = r->a;
        BUS8_SET(c, RAM16(0x0006) + 0x7F0000 + (uint8_t)(y1 + 1), (uint8_t)a_all2);
        uint8_t x2;
        if ((uint8_t)(x1 + 1) < 0x10) {
            x2 = (uint8_t)(x1 + 1);
        } else {
            x2 = 0;
        }
        a_hi1 = a_all2 >> 8;
        x1 = x2;
        y1 = (uint8_t)(y1 + 2);
        if (!(y1 < 0x10)) break;
    }
    uint16_t value3 = RAM16(0x0006);
    RAM16_SET(0x0006, (uint16_t)(value3 + 0x10));
    r->a = (uint16_t)(value3 + 0x10);
    r->mf = 1;
    r->xf = 1;
    r->db = 0x7F;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1B6BF, SOM_RTS, "gen", rotate_map_graphics_wave_plane, 0, L_B, 1, 1, 1, 42, 22)

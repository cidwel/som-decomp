#include "som_c.h"

/* C1FD52 configure_map_backgrounds   [class D, 102 bytes, 49 instructions]
 * Source: src/rom/configure_map_backgrounds.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYCV.
 */
static void configure_map_backgrounds(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x0029) = 9;
    BUS8_SET(c, 0x002105, 9);
    BUS8_SET(c, 0x002107, 0x51);
    BUS8_SET(c, 0x002108, 0x39);
    uint8_t value = RAM8(0x00E8);
    uint8_t a1;
    if (!(value & 0x01)) {
        a1 = 0x58;
    } else {
        a1 = 0x5C;
    }
    BUS8_SET(c, 0x002109, a1);
    BUS8_SET(c, 0x00210A, 0);
    RAM8(0x0002) = 0;
    BUS8_SET(c, 0x00210B, RAM8(0x0002));
    BUS8_SET(c, 0x00210C, 4);
    uint8_t value3 = RAM8(0x00B8);
    if ((value3 & 0xF8) == 0xF8) {
        RAM8(0x0029) = 7;
        BUS8_SET(c, 0x002105, 7);
        BUS8_SET(c, 0x00211B, 0);
        BUS8_SET(c, 0x00211B, 1);
        BUS8_SET(c, 0x00211C, 0);
        BUS8_SET(c, 0x00211C, 0);
        BUS8_SET(c, 0x00211D, 0);
        BUS8_SET(c, 0x00211D, 0);
        BUS8_SET(c, 0x00211E, 0);
        BUS8_SET(c, 0x00211E, 1);
        SET_A8(r, 1);
        r->c = (value3 & 0xF8) >= 0xF8;
        r->i = 0;
        RETURN_RTS(c);
    }
    SET_A8(r, value3 & 0xF8);
    r->c = (value3 & 0xF8) >= 0xF8;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FD52, SOM_RTS, "gen", configure_map_backgrounds, 0, L_A | L_B | L_X | L_Y | L_C | L_V, 1, 1, 1, 102, 49)

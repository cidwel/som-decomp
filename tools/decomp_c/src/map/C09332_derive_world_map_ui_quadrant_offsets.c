#include "som_c.h"

/* C09332 derive_world_map_ui_quadrant_offsets   [class A, 54 bytes, 29 instructions]
 * Source: src/rom/derive_world_map_ui_quadrant_offsets.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: ABXYC.
 */
static void derive_world_map_ui_quadrant_offsets(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if ((RAM8(0x0001) & 2) == 0) {
        uint8_t value2 = RAM8(0x0001);
        RAM8(0x0001) >>= 1;
        if (value2 & 0x01) {
            RAM8(0x004C) = 0xC0;
            RAM8(0x004D) = 0x80;
            SET_A8(r, 0x80);
            r->c = value2 & 0x01;
            r->mf = 1;
            RETURN_RTS(c);
        }
        RAM8(0x004C) = 0x40;
        RAM8(0x004D) = 0;
        SET_A8(r, 0);
        r->c = value2 & 0x01;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value3 = RAM8(0x0001);
    RAM8(0x0001) >>= 1;
    if (!(value3 & 0x01)) {
        RAM8(0x004C) = 0x80;
        RAM8(0x004D) = 0xC0;
        SET_A8(r, 0xC0);
        r->c = value3 & 0x01;
        r->mf = 1;
        RETURN_RTS(c);
    }
    if (value3 & 0x01) {
        RAM8(0x004C) = 0;
        RAM8(0x004D) = 0x40;
        SET_A8(r, 0x40);
        r->c = value3 & 0x01;
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value4 = RAM8(0x0001);
    RAM8(0x0001) >>= 1;
    if (value4 & 0x01) {
        RAM8(0x004C) = 0xC0;
        RAM8(0x004D) = 0x80;
        SET_A8(r, 0x80);
        r->c = value4 & 0x01;
        r->mf = 1;
        RETURN_RTS(c);
    }
    RAM8(0x004C) = 0x40;
    RAM8(0x004D) = 0;
    SET_A8(r, 0);
    r->c = value4 & 0x01;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC09332, SOM_RTS, "gen", derive_world_map_ui_quadrant_offsets, 0, L_A | L_B | L_X | L_Y | L_C, 1, 0, 1, 54, 29)

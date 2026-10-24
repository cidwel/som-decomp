#include "som_c.h"

/* C0A691 publish_world_map_picker_matrix_when_rows_are_complete   [class D, 67 bytes, 31 instructions]
 * Source: src/rom/publish_world_map_picker_matrix_when_rows_are_complete.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=any X=8 bit DB=$00 D=$0000.  Callers read: CV.
 */
static void publish_world_map_picker_matrix_when_rows_are_complete(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, -1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    if (RAM8(0x000E) == 0) {
        if (RAM8(0x000D) == 0) {
            r->mf = 1;
            RETURN_RTS(c);
        }
        if (RAM8(0x001E) != 0) {
            r->mf = 1;
            RETURN_RTS(c);
        }
        RAM8(0x001F) = 0;
        uint8_t value4 = RAM8(0x0036);
        BUS8_SET(c, 0x00211B, value4);
        uint8_t value5 = RAM8(0x0037);
        BUS8_SET(c, 0x00211B, value5);
        BUS8_SET(c, 0x00211E, value4);
        BUS8_SET(c, 0x00211E, value5);
        uint8_t value6 = RAM8(0x0038);
        BUS8_SET(c, 0x00211C, value6);
        uint8_t value7 = RAM8(0x0039);
        BUS8_SET(c, 0x00211C, value7);
        BUS8_SET(c, 0x00211D, (uint8_t)((value6 ^ 0xFF) + 1));
        BUS8_SET(c, 0x00211D, (uint8_t)((value7 ^ 0xFF) + ((value6 ^ 0xFF) + 1 > 0xFF)));
        r->c = (value7 ^ 0xFF) + ((value6 ^ 0xFF) + 1 > 0xFF) > 0xFF;
        r->v = ((value7 ^ 0xFF ^ (uint8_t)((value7 ^ 0xFF) + ((value6 ^ 0xFF) + 1 > 0xFF))) & (uint8_t)((value7 ^ 0xFF) + ((value6 ^ 0xFF) + 1 > 0xFF)) & 0x80) != 0;
        r->mf = 1;
        RETURN_RTS(c);
    }
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0A691, SOM_RTS, "gen", publish_world_map_picker_matrix_when_rows_are_complete, 0, L_C | L_V, 1, -1, 1, 67, 31)

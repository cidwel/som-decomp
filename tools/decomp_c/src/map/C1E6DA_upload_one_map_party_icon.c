#include "som_c.h"

/* C1E6DA upload_one_map_party_icon   [class D, 73 bytes, 32 instructions]
 * Source: src/rom/upload_one_map_party_icon.s
 * Documented in docs/maps.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void upload_one_map_party_icon(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a = r->a & 0xFF;
    const uint8_t a_hi = r->a >> 8;
    uint8_t a1;
    if (a >= 0xEC) {
        a1 = (uint8_t)(a - 0xE9);
    } else {
        a1 = a & 3;
    }
    BUS16_SET(c, 0x002116, RAM16(0x0000));
    uint16_t value2 = BUS16(c, 0xD2C600 + ((((a_hi << 8) | a1) & 0xFF) << 1 << 1 << 1));
    r->a = value2;
    r->x = (((a_hi << 8) | a1) & 0xFF) << 1 << 1 << 1;
    r->mf = 0;
    JSR(c, 0xE6F9, 0xC1E723); /* upload_map_party_icon_tile */
    uint16_t value3 = BUS16(c, 0xD2C602 + ((((a_hi << 8) | a1) & 0xFF) << 1 << 1 << 1));
    r->a = value3;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xE700, 0xC1E723); /* upload_map_party_icon_tile */
    BUS16_SET(c, 0x002116, (uint16_t)(RAM16(0x0000) + 0x0100));
    uint16_t value5 = BUS16(c, 0xD2C604 + ((((a_hi << 8) | a1) & 0xFF) << 1 << 1 << 1));
    r->a = value5;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xE710, 0xC1E723); /* upload_map_party_icon_tile */
    uint16_t value6 = BUS16(c, 0xD2C606 + ((((a_hi << 8) | a1) & 0xFF) << 1 << 1 << 1));
    r->a = value6;
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xE717, 0xC1E723); /* upload_map_party_icon_tile */
    uint16_t value7 = RAM16(0x0000);
    RAM16_SET(0x0000, (uint16_t)(value7 + 0x20));
    r->a = (uint16_t)(value7 + 0x20);
    r->c = value7 + 0x20 > 0xFFFF;
    r->z = (uint16_t)(value7 + 0x20) == 0;
    r->n = (uint16_t)(value7 + 0x20) & 0x8000;
    r->v = ((value7 ^ (uint16_t)(value7 + 0x20)) & ((uint16_t)(value7 + 0x20) ^ 0x20) & 0x8000) != 0;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1E6DA, SOM_RTS, "gen", upload_one_map_party_icon, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 1, 0, 73, 32)

#include "som_c.h"

/* C1FB79 decode_upload_and_advance_party_scene_frame   [class B, 99 bytes, 46 instructions]
 * Source: src/rom/decode_upload_and_advance_party_scene_frame.s
 * Documented in docs/ui-native-scene-constructor.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void decode_upload_and_advance_party_scene_frame(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t x = r->x;
    RAM8(0xE06F + x) = 0x0E;
    RAM8(0xE08E + x) = 0;
    RAM8(0x0002) = 0xD1;
    uint8_t value = RAM8(0xE040 + x);
    RAM16_SET(0x0000, (uint16_t)(((((a >> 8 << 8) | value) & 0xFF) << 1) + RAM16(0xE02A + x) + ((((a >> 8 << 8) | value) & 0xFF) >> 0x0F)));
    uint16_t value3;
    BUS16_OK(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value3);
    RAM16_SET(0x0000, ((((uint8_t)value3 << 8) | (value3 >> 8)) & 0xFF) << 1);
    RAM8(0xE088 + x) = (uint8_t)value3 & 0xC0;
    uint8_t value4 = RAM8(0xE033 + x);
    RAM8(0x0002) = value4;
    RAM8(0x0012) = value4;
    RAM16_SET(0x0000, (uint16_t)(RAM16(0xE072 + x) + RAM16(0x0000)));
    uint16_t value7;
    BUS16_OK(c, (RAM8(0x0002) << 0x10) + RAM16(0x0000), value7);
    RAM16_SET(0x0014, x);
    r->a = value7;
    r->mf = 0;
    JSL(c, 0xFBBF, 0xC0EB02); /* decode_actor_frame_tiles_and_geometry_long */
    r->mf = 0;
    r->xf = 0;
    JSR(c, 0xFBC2, 0xC1FBDC); /* upload_two_rows_of_eight_character_tiles */
    uint16_t value8 = RAM16(0x0014);
    RAM8(0xE040 + value8)++;
    uint8_t value9 = RAM8(0xE08A + value8);
    uint8_t a1;
    bool carry1;
    bool overflow1;
    if (((uint8_t)(value9 + 0x28) & 0x10) == 0) {
        a1 = (uint8_t)(value9 + 0x28);
        carry1 = value9 + 0x28 > 0xFF;
        overflow1 = ((value9 ^ (uint8_t)(value9 + 0x28)) & ((uint8_t)(value9 + 0x28) ^ 0x28) & 0x80) != 0;
    } else {
        a1 = (uint8_t)((uint8_t)(value9 + 0x28) + 0x10 + (value9 + 0x28 > 0xFF));
        carry1 = (uint8_t)(value9 + 0x28) + 0x10 + (value9 + 0x28 > 0xFF) > 0xFF;
        overflow1 = (((uint8_t)(value9 + 0x28) ^ (uint8_t)((uint8_t)(value9 + 0x28) + 0x10 + (value9 + 0x28 > 0xFF))) & ((uint8_t)((uint8_t)(value9 + 0x28) + 0x10 + (value9 + 0x28 > 0xFF)) ^ 0x10) & 0x80) != 0;
    }
    RAM8(0xE08A + value8) = a1;
    r->c = carry1;
    r->v = overflow1;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1FB79, SOM_RTS, "hand", decode_upload_and_advance_party_scene_frame, 0, L_B | L_Y | L_C | L_V, 2, -1, 0, 99, 46)

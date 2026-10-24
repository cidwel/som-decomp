#include "som_c.h"

/* C0A841 initialize_world_map_picker_background_and_hdma_records   [class D, 233 bytes, 102 instructions]
 * Source: src/rom/initialize_world_map_picker_background_and_hdma_records.s
 * Documented in docs/ui-native-world-map-picker-scene.md
 * Entry: M=8 bit X=8 bit DB=$00 D=$0000.  Callers read: XYCV.
 */
static void initialize_world_map_picker_background_and_hdma_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const bool overflow = r->v;
    BUS8_SET(c, 0x00211B, 0);
    BUS8_SET(c, 0x00211B, 6);
    BUS8_SET(c, 0x00211C, 0);
    BUS8_SET(c, 0x00211C, 0);
    BUS8_SET(c, 0x00211D, 0);
    BUS8_SET(c, 0x00211D, 0);
    BUS8_SET(c, 0x00211E, 0);
    BUS8_SET(c, 0x00211E, 8);
    BUS8_SET(c, 0x00211A, 0x80);
    BUS8_SET(c, 0x002130, 1);
    BUS8_SET(c, 0x00212C, 0x11);
    BUS8_SET(c, 0x002115, 0x80);
    BUS8_SET(c, 0x002116, 0);
    BUS8_SET(c, 0x002117, 0);
    uint8_t x1 = 0xCE;
    for (;;) {
        RAM8(0x0000 + x1) = 0;
        x1 = (uint8_t)(x1 - 1);
        if (!(x1 != 0)) break;
    }
    uint8_t a_hi1 = a_hi;
    uint8_t x2 = x1;
    for (;;) {
        uint8_t value = BUS8(c, 0xC64780 + x2);
        uint8_t y1 = 0x40;
        for (;;) {
            BUS8_SET(c, 0x002119, value);
            y1 = (uint8_t)(y1 - 1);
            if (!(y1 != 0)) break;
        }
        x2 = (uint8_t)(x2 + 1);
        if (!(x2 < 0xC0)) break;
    }
    uint8_t y2 = 0x40;
    for (;;) {
        BUS8_SET(c, 0x002119, 0);
        y2 = (uint8_t)(y2 - 1);
        if (!(y2 != 0)) break;
    }
    BUS8_SET(c, 0x002121, 0xF1);
    BUS8_SET(c, 0x002122, 0xFF);
    BUS8_SET(c, 0x002122, 0xFF);
    BUS8_SET(c, 0x002121, 0);
    BUS8_SET(c, 0x002122, 0);
    BUS8_SET(c, 0x002122, 0);
    BUS8_SET(c, 0x00211F, 0);
    BUS8_SET(c, 0x00211F, 2);
    BUS8_SET(c, 0x002120, 0);
    BUS8_SET(c, 0x002120, 2);
    BUS8_SET(c, 0x002105, 7);
    BUS8_SET(c, 0x002131, 0);
    BUS8_SET(c, 0x00210D, 0x80);
    BUS8_SET(c, 0x00210D, 1);
    BUS8_SET(c, 0x00210E, 0x90);
    BUS8_SET(c, 0x00210E, 1);
    uint8_t a_hi2 = a_hi1;
    uint8_t x3 = 0;
    uint8_t y3 = 0x7E;
    for (;;) {
        uint16_t value2 = BUS16(c, 0x00A961 + x3);
        RAM16_SET(0x1180 + x3, (uint16_t)(value2 << 3));
        RAM16_SET(0x1100 + y3, (uint16_t)(value2 << 3));
        a_hi2 = (uint16_t)(value2 << 3) >> 8;
        x3 = (uint8_t)(x3 + 2);
        y3 = (uint8_t)(y3 - 2);
        if (!(x3 < 0x80)) break;
    }
    uint8_t a_hi3 = a_hi2;
    uint8_t x4 = 0;
    for (;;) {
        uint16_t value3 = BUS16(c, 0x00A932 + x4);
        RAM16_SET(0x1080 + x4, value3);
        uint16_t value4 = BUS16(c, 0x00A93F + x4);
        RAM16_SET(0x1200 + x4, value4);
        a_hi3 = value4 >> 8;
        x4 = (uint8_t)(x4 + 1);
        if (!(x4 < 0x30)) break;
    }
    uint8_t a_hi4 = a_hi3;
    uint8_t x5 = 0;
    bool carry1 = 0;
    for (;;) {
        uint16_t value5 = BUS16(c, 0x00A92A + x5);
        BUS16_SET(c, 0x004340 + x5, value5);
        uint8_t a_hi4_next = value5 >> 8;
        uint8_t x5_next = (uint8_t)(x5 + 2);
        bool carry1_next = (uint8_t)(x5 + 2) >= 8;
        a_hi4 = a_hi4_next;
        x5 = x5_next;
        carry1 = carry1_next;
        if (!(x5 < 8)) break;
    }
    BUS8_SET(c, 0x002121, 0xB0);
    BUS8_SET(c, 0x002122, 0);
    BUS8_SET(c, 0x002122, 0x70);
    r->x = x5;
    r->y = y3;
    r->c = carry1;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC0A841, SOM_RTS, "gen", initialize_world_map_picker_background_and_hdma_records, 0, L_X | L_Y | L_C | L_V, 1, 1, 1, 233, 102)

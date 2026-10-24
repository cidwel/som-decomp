#include "som_c.h"

/* C2B247 publish_clipped_ui_marker_sprite_records   [class B, 64 bytes, 35 instructions]
 * Source: src/rom/publish_clipped_ui_marker_sprite_records.s
 * Documented in docs/ui-native-ui-frame-projection.md
 * Entry: M=8 bit X=16 bit DB=$00 D=$0000.  Callers read: Y.
 */
static void publish_clipped_ui_marker_sprite_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    const uint16_t x = r->x;
    const uint16_t y = r->y;
    uint8_t a_b256 = 0;
    uint8_t a_hi_b256 = 0;
    uint16_t x_b256 = 0;
    uint16_t y_b256 = 0;
    uint8_t a_hi_b27e = 0;
    uint16_t x_b27e = 0;
    uint16_t y_b27e = 0;
    uint8_t a_b25b = 0;
    uint8_t a_hi_b25b = 0;
    uint16_t x_b25b = 0;
    uint16_t y_b25b = 0;
    uint8_t a_b269 = 0;
    uint8_t a_hi_b269 = 0;
    uint16_t x_b269 = 0;
    uint16_t y_b269 = 0;
    uint8_t a_b26e = 0;
    uint8_t a_hi_b26e = 0;
    uint16_t x_b26e = 0;
    uint16_t y_b26e = 0;
    uint8_t a_hi_b27e2 = 0;
    uint16_t x_b27e2 = 0;
    uint16_t y_b27e2 = 0;
    uint8_t value = BUS8(c, 0xC20000 + x);
    if (!(value & 0x80)) {
        a_b256 = value;
        a_hi_b256 = a_hi;
        x_b256 = x;
        y_b256 = y;
        goto shared_B256;
    }
    uint8_t value2 = RAM8(0x0009);
    if (value + value2 <= 0xFF) {
        a_hi_b27e = a_hi;
        x_b27e = x;
        y_b27e = y;
        goto shared_B27E;
    }
    if (value + value2 > 0xFF) {
        a_b25b = (uint8_t)(value + value2);
        a_hi_b25b = a_hi;
        x_b25b = x;
        y_b25b = y;
        goto shared_B25B;
    }
    a_b256 = (uint8_t)(value + value2);
    a_hi_b256 = a_hi;
    x_b256 = x;
    y_b256 = y;
    shared_B256:;
    uint8_t value3 = RAM8(0x0009);
    if (a_b256 + value3 > 0xFF) {
        a_hi_b27e = a_hi_b256;
        x_b27e = x_b256;
        y_b27e = y_b256;
        goto shared_B27E;
    }
    a_b25b = (uint8_t)(a_b256 + value3);
    a_hi_b25b = a_hi_b256;
    x_b25b = x_b256;
    y_b25b = y_b256;
    goto shared_B25B;
    shared_B27E:;
    RAM8(0x0002)--;
    if (RAM8(0x0002) != 0) {
        uint8_t value4 = BUS8(c, 0xC20000 + (uint16_t)(x_b27e + 4));
        if (!(value4 & 0x80)) {
            a_b256 = value4;
            a_hi_b256 = a_hi_b27e;
            x_b256 = (uint16_t)(x_b27e + 4);
            y_b256 = y_b27e;
            goto shared_B256;
        }
        uint8_t value5 = RAM8(0x0009);
        if (value4 + value5 <= 0xFF) {
            x_b27e = (uint16_t)(x_b27e + 4);
            goto shared_B27E;
        }
        if (value4 + value5 > 0xFF) {
            a_b25b = (uint8_t)(value4 + value5);
            a_hi_b25b = a_hi_b27e;
            x_b25b = (uint16_t)(x_b27e + 4);
            y_b25b = y_b27e;
            goto shared_B25B;
        }
        a_b256 = (uint8_t)(value4 + value5);
        a_hi_b256 = a_hi_b27e;
        x_b256 = (uint16_t)(x_b27e + 4);
        y_b256 = y_b27e;
        goto shared_B256;
    }
    r->y = y_b27e;
    r->mf = 1;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
    shared_B25B:;
    uint8_t value6 = BUS8(c, 0xC20001 + x_b25b);
    if (!(value6 & 0x80)) {
        a_b269 = value6;
        a_hi_b269 = a_b25b;
        x_b269 = x_b25b;
        y_b269 = y_b25b;
        goto shared_B269;
    }
    uint8_t value7 = RAM8(0x0008);
    if (value6 + value7 <= 0xFF) {
        a_hi_b27e = a_b25b;
        x_b27e = x_b25b;
        y_b27e = y_b25b;
        goto shared_B27E;
    }
    if (value6 + value7 > 0xFF) {
        a_b26e = (uint8_t)(value6 + value7);
        a_hi_b26e = a_b25b;
        x_b26e = x_b25b;
        y_b26e = y_b25b;
        goto shared_B26E;
    }
    a_b269 = (uint8_t)(value6 + value7);
    a_hi_b269 = a_b25b;
    x_b269 = x_b25b;
    y_b269 = y_b25b;
    goto shared_B269;
    shared_B269:;
    uint8_t value8 = RAM8(0x0008);
    if (a_b269 + value8 > 0xFF) {
        a_hi_b27e = a_hi_b269;
        x_b27e = x_b269;
        y_b27e = y_b269;
        goto shared_B27E;
    }
    a_b26e = (uint8_t)(a_b269 + value8);
    a_hi_b26e = a_hi_b269;
    x_b26e = x_b269;
    y_b26e = y_b269;
    goto shared_B26E;
    shared_B26E:;
    BUS16_SET(c, 0x000800 + y_b26e, (a_hi_b26e << 8) | a_b26e);
    uint16_t value9 = BUS16(c, 0xC20002 + x_b26e);
    BUS16_SET(c, 0x000802 + y_b26e, value9);
    a_hi_b27e2 = value9 >> 8;
    x_b27e2 = x_b26e;
    y_b27e2 = (uint16_t)(y_b26e + 4);
    goto shared_B27E_1;
    shared_B27E_1:;
    RAM16_SET(0x0002, (uint16_t)(RAM16(0x0002) - 1));
    if (RAM16(0x0002) != 0) {
        uint8_t value10 = BUS8(c, 0xC20000 + (uint16_t)(x_b27e2 + 4));
        if (!(value10 & 0x80)) {
            a_b256 = value10;
            a_hi_b256 = a_hi_b27e2;
            x_b256 = (uint16_t)(x_b27e2 + 4);
            y_b256 = y_b27e2;
            goto shared_B256;
        }
        uint8_t value11 = RAM8(0x0009);
        if (value10 + value11 <= 0xFF) {
            a_hi_b27e = a_hi_b27e2;
            x_b27e = (uint16_t)(x_b27e2 + 4);
            y_b27e = y_b27e2;
            goto shared_B27E;
        }
        if (value10 + value11 > 0xFF) {
            a_b25b = (uint8_t)(value10 + value11);
            a_hi_b25b = a_hi_b27e2;
            x_b25b = (uint16_t)(x_b27e2 + 4);
            y_b25b = y_b27e2;
            goto shared_B25B;
        }
        a_b256 = (uint8_t)(value10 + value11);
        a_hi_b256 = a_hi_b27e2;
        x_b256 = (uint16_t)(x_b27e2 + 4);
        y_b256 = y_b27e2;
        goto shared_B256;
    }
    r->y = y_b27e2;
    r->mf = 0;
    r->xf = 0;
    r->db = 0;
    r->dp = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2B247, SOM_RTS, "gen", publish_clipped_ui_marker_sprite_records, 0, L_Y, 1, 1, 0, 64, 35)

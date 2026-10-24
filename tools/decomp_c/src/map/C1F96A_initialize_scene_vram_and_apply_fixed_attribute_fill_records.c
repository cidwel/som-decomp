#include "som_c.h"

/* C1F96A initialize_scene_vram_and_apply_fixed_attribute_fill_records   [class D, 119 bytes, 46 instructions]
 * Source: src/rom/initialize_scene_vram_and_apply_fixed_attribute_fill_records.s
 * Documented in docs/ui-native-vram-initialization.md
 * Entry: M=16 bit X=8 bit DB=$00 D=$0000.  Callers read: BYCV.
 */
static void initialize_scene_vram_and_apply_fixed_attribute_fill_records(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS8_SET(c, 0x002115, 0x80);
    BUS8_SET(c, 0x004374, 0);
    BUS16_SET(c, 0x004372, 0);
    BUS16_SET(c, 0x004370, 0x1809);
    RAM16_SET(0x0000, 0);
    BUS16_SET(c, 0x002116, 0x5000);
    BUS16_SET(c, 0x004375, 0x1000);
    BUS8_SET(c, 0x00420B, 0x80);
    BUS16_SET(c, 0x004370, 0x1908);
    uint8_t a_hi1 = 0x19;
    uint8_t x1 = 0;
    bool carry1 = carry;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value = BUS16(c, 0x01F9F2 + x1);
        RAM16_SET(0x0000, value);
        uint16_t value2 = BUS16(c, 0x01F9F3 + x1);
        BUS16_SET(c, 0x002116, value2);
        uint16_t value3 = BUS16(c, 0x01F9F5 + x1);
        BUS16_SET(c, 0x004375, value3);
        BUS8_SET(c, 0x00420B, 0x80);
        uint8_t a_hi1_next = x1 + 5 >> 8;
        uint8_t x1_next = (uint8_t)(x1 + 5);
        bool carry1_next = (uint8_t)(x1 + 5) >= 0x1E;
        bool overflow1_next = ((x1 ^ x1 + 5) & (x1 + 5 ^ 5) & 0x8000) != 0;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        carry1 = carry1_next;
        overflow1 = overflow1_next;
        if (!(x1 < 0x1E)) break;
    }
    BUS8_SET(c, 0x002115, 0x80);
    BUS8_SET(c, 0x004374, 0xC6);
    BUS16_SET(c, 0x002116, 0x4000);
    r->a = 0x1801;
    r->x = 0x2000;
    r->y = 0x1000;
    r->c = carry1;
    r->v = overflow1;
    r->xf = 0;
    JSR(c, 0xF9DF, 0xC1F9E1); /* configure_and_trigger_dma_seven_from_word_arguments */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1F96A, SOM_RTS, "gen", initialize_scene_vram_and_apply_fixed_attribute_fill_records, 0, L_B | L_Y | L_C | L_V, 1, 0, 1, 119, 46)

#include "som_c.h"

/* D0CD6D restore_saved_menu_palette_and_request_upload   [class A, 33 bytes, 13 instructions]
 * Source: src/rom/restore_saved_menu_palette_and_request_upload.s
 * Entry: M=16 bit X=16 bit DB=$00 D=$0000.  Callers read: ABXYCZNV.
 */
static void restore_saved_menu_palette_and_request_upload(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x00, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x8000 + 0);
    RAM16_SET(0x0600 + 0, value);
    uint8_t a1 = (uint8_t)value;
    uint8_t a_hi1 = value >> 8;
    uint16_t x1 = 0x20;
    bool carry1 = carry;
    bool zero1 = 0;
    bool negative1 = 0;
    for (;;) {
        uint16_t value2 = RAM16(0x8000 + x1);
        BUS16_SET(c, 0x000600 + x1, value2);
        uint8_t a1_next = (uint8_t)value2;
        uint8_t a_hi1_next = value2 >> 8;
        uint16_t x1_next = (uint16_t)(x1 + 2);
        bool carry1_next = (uint16_t)(x1 + 2) >= 0x0100;
        bool zero1_next = (uint16_t)(x1 + 2) == 0x0100;
        bool negative1_next = (uint16_t)((uint16_t)(x1 + 2) - 0x0100) & 0x8000;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        carry1 = carry1_next;
        zero1 = zero1_next;
        negative1 = negative1_next;
        if (!(x1 < 0x0100)) break;
    }
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y;
    r->c = carry1;
    r->z = zero1;
    r->n = negative1;
    r->v = overflow;
    { const uint16_t sp_call = r->sp; JSR(c, 0xCD8C, 0xD0CDA9); GUARD_JSR(c, sp_call, 0xCD8C); } /* request_menu_palette_upload */
    if (r->xf) { r->x &= 0xFF; r->y &= 0xFF; }
    RETURN_RTL(c);
}
SOM_REGISTER(0xD0CD6D, SOM_RTL, "gen", restore_saved_menu_palette_and_request_upload, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 1, 0, 0, 33, 13)

#include "som_c.h"

/* C7553F construct_nine_native_save_confirmation_tile_rows   [class B, 59 bytes, 30 instructions]
 * Source: src/rom/construct_nine_native_save_confirmation_tile_rows.s
 * Documented in docs/ui-native-saved-game-menu-request.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0000.  Callers read: BYCV.
 */
static void construct_nine_native_save_confirmation_tile_rows(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const bool carry = r->c;
    const bool overflow = r->v;
    RAM16_SET(0xA171, 9);
    uint8_t a1 = 9;
    uint8_t a_hi1 = 0;
    uint16_t x1 = 0x8E;
    uint16_t y1 = 0x2218;
    bool carry1 = carry;
    bool zero1 = 0;
    bool overflow1 = overflow;
    do {
        RAM16_SET(0xA173, 0x0C);
        uint8_t a2 = (uint8_t)y1;
        uint8_t a_hi2 = y1 >> 8;
        uint16_t x2 = x1;
        do {
            RAM16_SET(0x9000 + x2, (a_hi2 << 8) | a2);
            RAM16_SET(0x9040 + x2, (uint16_t)(((a_hi2 << 8) | a2) + 2));
            RAM16_SET(0xA173, (uint16_t)(RAM16(0xA173) - 1));
            uint8_t a2_next = (uint8_t)(((a_hi2 << 8) | a2) + 4);
            uint8_t a_hi2_next = (uint16_t)(((a_hi2 << 8) | a2) + 4) >> 8;
            uint16_t x2_next = (uint16_t)(x2 + 2);
            a2 = a2_next;
            a_hi2 = a_hi2_next;
            x2 = x2_next;
        } while (RAM16(0xA173) != 0);
        RAM16_SET(0xA171, (uint16_t)(RAM16(0xA171) - 1));
        uint8_t a1_next = (uint8_t)((a_hi2 << 8) | a2);
        uint8_t a_hi1_next = a_hi2;
        uint16_t x1_next = (uint16_t)(x1 + 0x80);
        uint16_t y1_next = (a_hi2 << 8) | a2;
        bool carry1_next = x1 + 0x80 > 0xFFFF;
        bool zero1_next = RAM16(0xA171) == 0;
        bool overflow1_next = ((x1 ^ (uint16_t)(x1 + 0x80)) & ((uint16_t)(x1 + 0x80) ^ 0x80) & 0x8000) != 0;
        a1 = a1_next;
        a_hi1 = a_hi1_next;
        x1 = x1_next;
        y1 = y1_next;
        carry1 = carry1_next;
        zero1 = zero1_next;
        overflow1 = overflow1_next;
    } while (RAM16(0xA171) != 0);
    r->a = (a_hi1 << 8) | a1;
    r->x = x1;
    r->y = y1;
    r->c = carry1;
    r->z = zero1;
    r->v = overflow1;
    JSL(c, 0x5578, 0xC02AD7); /* native_menu_tile_workspace_upload_long_wrapper */
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC7553F, SOM_RTS, "gen", construct_nine_native_save_confirmation_tile_rows, 0, L_B | L_Y | L_C | L_V, 2, 1, 0, 59, 30)

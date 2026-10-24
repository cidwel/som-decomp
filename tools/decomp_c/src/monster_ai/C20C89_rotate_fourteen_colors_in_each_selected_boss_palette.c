#include "som_c.h"

/* C20C89 rotate_fourteen_colors_in_each_selected_boss_palette   [class B, 87 bytes, 47 instructions]
 * Source: src/rom/rotate_fourteen_colors_in_each_selected_boss_palette.s
 * Documented in docs/boss-native-linked-death-dependencies.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BYV.
 */
static void rotate_fourteen_colors_in_each_selected_boss_palette(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t a = r->a;
    const uint16_t y = r->y;
    const bool overflow = r->v;
    uint16_t value = RAM16(0x0287);
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = value;
    uint16_t y1 = y;
    bool overflow1 = overflow;
    for (;;) {
        uint16_t value2 = RAM16(0x0018 + x1);
        if ((value2 & 0xFF) != 0) {
            RAM16_SET(0x021A, (((value2 & 0xFF) << 8) | 0) >> 3);
            RAM16_SET(0x020C, ((((value2 & 0xFF) << 8) | 0) >> 3) + 0x061E + (((((value2 & 0xFF) << 8) | 0) >> 3) + 0x1E > 0xFFFF));
            uint16_t value3 = RAM16(0x021A);
            RAM16_SET(0x020F, (uint16_t)((uint16_t)(value3 + 4) + 0x0600 + (value3 + 4 > 0xFFFF)));
            uint16_t value4 = BUS16(c, RAM16(0x020C) + 0x7E0000);
            RAM16_SET(0x0295, value4);
            RAM16_SET(0x021A, (uint16_t)(value3 + 4));
            uint8_t a_hi2 = (uint16_t)(value3 + 4) >> 8;
            uint16_t x2 = (uint16_t)(value3 + 0x1C);
            uint16_t y2 = (uint16_t)(value3 + 0x1E);
            for (;;) {
                uint16_t value5 = RAM16(0x0600 + x2);
                RAM16_SET(0x0600 + y2, value5);
                uint16_t value6 = RAM16(0x021A);
                uint8_t a_hi2_next = value5 >> 8;
                uint16_t x2_next = (uint16_t)(x2 - 2);
                uint16_t y2_next = x2;
                a_hi2 = a_hi2_next;
                x2 = x2_next;
                y2 = y2_next;
                if (!(y2 != value6)) break;
            }
            uint16_t value7 = RAM16(0x0295);
            BUS16_SET(c, RAM16(0x020F) + 0x7E0000, value7);
            a_hi1 = value7 >> 8;
            x1 = (uint16_t)(x1 + 1);
            y1 = y2;
            overflow1 = ((value3 ^ (uint16_t)(value3 + 4)) & ((uint16_t)(value3 + 4) ^ 4) & 0x8000) != 0;
            continue;
        }
        a_hi1 = 0;
        break;
    }
    r->a = (a_hi1 << 8) | (uint8_t)a;
    r->y = y1;
    r->v = overflow1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC20C89, SOM_RTS, "gen", rotate_fourteen_colors_in_each_selected_boss_palette, 0, L_B | L_Y | L_V, 2, 0, 0, 87, 47)

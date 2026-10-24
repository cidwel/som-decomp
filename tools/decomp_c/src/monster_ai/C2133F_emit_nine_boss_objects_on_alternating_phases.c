#include "som_c.h"

/* C2133F emit_nine_boss_objects_on_alternating_phases   [class B, 85 bytes, 40 instructions]
 * Source: src/rom/emit_nine_boss_objects_on_alternating_phases.s
 * Documented in docs/graphics.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0200.  Callers read: BXY.
 */
static void emit_nine_boss_objects_on_alternating_phases(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0200) { c->fail = 3; return; }
    const uint16_t x = r->x;
    RAM16_SET(0x027F, RAM16(0x007C) >> 2);
    RAM16_SET(0x0281, RAM16(0x0059));
    RAM16_SET(0x0283, 0x80);
    uint8_t a_hi1 = 0;
    uint16_t x1 = x;
    uint16_t y1 = 0;
    for (;;) {
        RAM16_SET(0x0287, (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600));
        uint16_t value3 = RAM16(0x008C + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600));
        uint8_t a_hi4;
        uint16_t x4;
        if (value3 == 0) {
            a_hi4 = value3 >> 8;
            x4 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600);
        } else {
            uint16_t value4 = RAM16(0x00ED);
            uint8_t a_hi3;
            uint16_t x3;
            if ((value4 & 0x40) != 0) {
                r->a = value4;
                r->x = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600);
                r->y = y1;
                r->v = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600) ^ 0xE600) & 0x8000) != 0;
                r->mf = 0;
                r->xf = 0;
                r->db = 0x7E;
                r->dp = 0x0200;
                RAM8(r->sp) = y1 >> 8; /* PHY */
                RAM8((uint16_t)(r->sp - 1)) = (uint8_t)y1;
                r->sp -= 2;
                JSR(c, 0x137B, 0xC211F4); /* integrate_boss_height_and_dispatch_enabled_motion_callback */
                r->mf = 0;
                r->xf = 0;
                JSR(c, 0x137E, 0xC21F80); /* emit_boss_sprite_piece_list */
                y1 = RAM16((uint16_t)(r->sp + 1)); /* PLY reads the real stack: a callee can leave it unbalanced */
                r->sp += 2;
                uint16_t a_all2 = r->a;
                uint16_t x_ret2 = r->x;
                a_hi3 = a_all2 >> 8;
                x3 = x_ret2;
            } else {
                RAM16_SET(0x008C + (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600), value3 ^ 2);
                uint8_t a_hi2;
                uint16_t x2;
                if (((value3 ^ 2) & 2) == 0) {
                    a_hi2 = (value3 ^ 2) >> 8;
                    x2 = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600);
                } else {
                    r->a = value3 ^ 2;
                    r->x = (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600);
                    r->y = y1;
                    r->v = (((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) ^ (uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600)) & ((uint16_t)((uint16_t)((((uint8_t)y1 << 8) | (y1 >> 8)) << 1) + 0xE600) ^ 0xE600) & 0x8000) != 0;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0x7E;
                    r->dp = 0x0200;
                    RAM8(r->sp) = y1 >> 8; /* PHY */
                    RAM8((uint16_t)(r->sp - 1)) = (uint8_t)y1;
                    r->sp -= 2;
                    JSR(c, 0x137B, 0xC211F4); /* integrate_boss_height_and_dispatch_enabled_motion_callback */
                    r->mf = 0;
                    r->xf = 0;
                    JSR(c, 0x137E, 0xC21F80); /* emit_boss_sprite_piece_list */
                    y1 = RAM16((uint16_t)(r->sp + 1)); /* PLY reads the real stack: a callee can leave it unbalanced */
                    r->sp += 2;
                    uint16_t a_all4 = r->a;
                    uint16_t x_ret4 = r->x;
                    a_hi2 = a_all4 >> 8;
                    x2 = x_ret4;
                }
                a_hi3 = a_hi2;
                x3 = x2;
            }
            a_hi4 = a_hi3;
            x4 = x3;
        }
        a_hi1 = a_hi4;
        x1 = x4;
        y1 = (uint16_t)(y1 + 1);
        if (!(y1 != 9)) break;
    }
    RAM16_SET(0x007C, (uint16_t)(RAM16(0x027F) << 2));
    RAM16_SET(0x0FAC, 1);
    r->a = 1;
    r->x = x1;
    r->y = y1;
    r->mf = 0;
    r->xf = 0;
    r->db = 0x7E;
    r->dp = 0x0200;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC2133F, SOM_RTS, "hand", emit_nine_boss_objects_on_alternating_phases, 0, L_B | L_X | L_Y, 2, 0, 0, 85, 40)

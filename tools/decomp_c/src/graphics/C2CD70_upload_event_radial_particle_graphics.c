#include "som_c.h"
/* SOM_POLL_HOOK */

/* C2CD70 upload_event_radial_particle_graphics   [class D, 161 bytes, 67 instructions]
 * Source: src/rom/upload_event_radial_particle_graphics.s
 * Documented in docs/event-menu-effect-graphics.md
 * Entry: M=8 bit X=16 bit DB=$7E D=any.  Callers read: ABXYCZNV.
 */
static void upload_event_radial_particle_graphics(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    const uint16_t dp = r->dp;
    const uint8_t a_hi = r->a >> 8;
    RAM16_SET(0x0014 + dp, 0x0200);
    RAM8(0xE04F + 0x0200) = 0x83;
    r->a = (a_hi << 8) | 0x83;
    r->y = 0x0200;
    { const uint16_t sp_call = r->sp; JSL(c, 0xCD7F, 0xC1864D); GUARD_JSL(c, sp_call, 0xCD7F); } /* load_actor_secondary_graphics_and_palette_long */
    uint8_t db_ret = r->db;
    bool x_ret = r->xf;
    uint16_t x_ret2 = r->x;
    bool carry_ret = r->c;
    bool overflow_ret = r->v;
    uint16_t value = BUS16(c, (db_ret << 0x10) + 0x078C);
    BUS16_SET(c, (db_ret << 0x10) + 0xBF8C, value);
    uint16_t value2 = BUS16(c, (db_ret << 0x10) + 0x078E);
    BUS16_SET(c, (db_ret << 0x10) + 0xBF8E, value2);
    uint16_t value3 = BUS16(c, (db_ret << 0x10) + 0x0790);
    BUS16_SET(c, (db_ret << 0x10) + 0xBF90, value3);
    uint16_t value4 = BUS16(c, (db_ret << 0x10) + 0x0792);
    BUS16_SET(c, (db_ret << 0x10) + 0xBF92, value4);
    uint16_t value5 = BUS16(c, (db_ret << 0x10) + 0x0794);
    BUS16_SET(c, (db_ret << 0x10) + 0xBF94, value5);
    if (x_ret) {
        c->fail = 3; /* operand size does not fit the register width on this path */
        return;
    } else {
        BUS16_SET(c, 0x004370, 0x1801);
        BUS16_SET(c, 0x004360, 0x1801);
        BUS8_SET(c, 0x004374, 0x7E);
        BUS8_SET(c, 0x004364, 0x7E);
        RAM8(0x00EC + dp) = 2;
        bool overflow1 = overflow_ret;
        for (;;) {
            uint8_t value6 = RAM8(0x00EC + dp);
            overflow1 = value6 & 0x40;
            if (!((value6 & 2) != 0)) break;
        }
        BUS16_SET(c, 0x004372, 0x39E0);
        BUS8_SET(c, 0x002115, 0x80);
        BUS16_SET(c, 0x002116, 0x7200);
        uint8_t a1 = 4;
        uint8_t a_hi1 = value5 >> 8;
        for (;;) {
            BUS16_SET(c, 0x004375, 0x20);
            BUS16_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x00420B, 0x80);
            BUS16_SET(c, 0x004362, 0xCB00);
            BUS8_SET(c, 0x00420B, 0x40);
            a1 = (uint8_t)(a1 - 1);
            if (!(a1 != 0)) break;
        }
        BUS16_SET(c, 0x002116, 0x7300);
        uint8_t a2 = 8;
        uint8_t a_hi2 = a_hi1;
        uint16_t y1 = 0x7300;
        bool zero1 = 0;
        bool negative1 = 0;
        for (;;) {
            BUS16_SET(c, 0x004362, 0xCB00);
            BUS16_SET(c, 0x004365, 0x20);
            BUS8_SET(c, 0x00420B, 0x40);
            uint8_t a2_next = (uint8_t)(a2 - 1);
            uint16_t y1_next = 0x20;
            bool zero1_next = (uint8_t)(a2 - 1) == 0;
            bool negative1_next = (uint8_t)(a2 - 1) & 0x80;
            a2 = a2_next;
            y1 = y1_next;
            zero1 = zero1_next;
            negative1 = negative1_next;
            if (!(a2 != 0)) break;
        }
        r->a = (a_hi2 << 8) | a2;
        r->x = x_ret2;
        r->y = y1;
        r->c = carry_ret;
        r->z = db_ret == 0;
        r->n = db_ret & 0x80;
        r->v = overflow1;
        r->mf = 1;
        r->xf = 0;
        RETURN_RTS(c);
    }
}
SOM_REGISTER(0xC2CD70, SOM_RTS, "gen", upload_event_radial_particle_graphics, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 1, 0, 161, 67)

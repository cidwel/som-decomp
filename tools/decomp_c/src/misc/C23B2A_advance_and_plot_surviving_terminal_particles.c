#include "som_c.h"

/* C23B2A advance_and_plot_surviving_terminal_particles   [class B, 110 bytes, 55 instructions]
 * Source: src/rom/advance_and_plot_surviving_terminal_particles.s
 * Documented in docs/boss-native-death-particles.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0300.  Callers read: ABXYCZNV.
 */
static void advance_and_plot_surviving_terminal_particles(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    const uint16_t sp0 = r->sp;
    const uint16_t y = r->y;
    uint16_t battle_defence_work = RAM16(BATTLE_DEFENCE_WORK);
    uint16_t value = RAM16(OBJECT_AGE + battle_defence_work);
    if (value < 0x4B) {
        RAM16_SET(0x031C, (uint16_t)(value << 3));
        RAM16_SET(0x031C, (uint16_t)((uint16_t)(value << 4) + RAM16(0x031C)));
        uint16_t value3 = RAM16(0x031C);
        RAM16_SET(0x031C, (uint16_t)(0x2800 - value3));
        RAM8(0x0000 + sp0) = 0x7E;
        RAM8(0x0000 + sp0 - 1) = 0x7F;
        RAM16_SET(0x031A, 0x2000);
        uint8_t a_hi1 = 0x20;
        uint16_t y1 = y;
        bool overflow1 = ((value3 ^ 0x2800) & ((uint16_t)(0x2800 - value3) ^ 0x2800) & 0x8000) != 0;
        for (;;) {
            uint16_t value4 = RAM16(0x031A);
            uint16_t value5 = BUS16(c, 0x7F0004 + value4);
            uint16_t value6 = BUS16(c, 0x7F0000 + value4);
            uint8_t a_hi3;
            uint16_t y3;
            if ((uint16_t)(value5 + value6) >= 0x8000) {
                a_hi3 = (uint16_t)(value5 + value6) >> 8;
                y3 = value4;
            } else {
                BUS16_SET(c, 0x7F0000 + value4, (uint16_t)(value5 + value6));
                uint16_t value7 = BUS16(c, 0x7F0006 + value4);
                uint16_t value8 = BUS16(c, 0x7F0002 + value4);
                uint8_t a_hi2;
                uint16_t y2;
                if ((uint16_t)(value7 + value8) >= 0x4000) {
                    a_hi2 = (uint16_t)(value7 + value8) >> 8;
                    y2 = value4;
                } else {
                    BUS16_SET(c, 0x7F0002 + value4, (uint16_t)(value7 + value8));
                    uint8_t value9 = BUS8(c, 0x7F0001 + value4);
                    r->a = ((uint16_t)(value7 + value8) >> 8 << 8) | value9;
                    r->mf = 0;
                    r->xf = 0;
                    r->db = 0x7F;
                    r->dp = 0x0300;
                    r->sp -= 1;
                    { const uint16_t sp_call = r->sp; JSR(c, 0x3B80, 0xC23C0E); GUARD_JSR(c, sp_call, 0x3B80); } /* plot_terminal_particle_bitplanes */
                    r->sp += 1;
                    uint16_t a_all = r->a;
                    uint16_t y_ret = r->y;
                    a_hi2 = a_all >> 8;
                    y2 = y_ret;
                }
                a_hi3 = a_hi2;
                y3 = y2;
            }
            uint16_t value10 = RAM16(0x031A);
            RAM16_SET(0x031A, (uint16_t)(value10 + 8));
            uint16_t value11 = RAM16(0x031C);
            a_hi1 = (uint16_t)(value10 + 8) >> 8;
            y1 = y3;
            overflow1 = ((value10 ^ (uint16_t)(value10 + 8)) & ((uint16_t)(value10 + 8) ^ 8) & 0x8000) != 0;
            if (!((uint16_t)(value10 + 8) < value11)) break;
        }
        uint8_t value12 = RAM8(0x0000 + sp0);
        uint16_t battle_defence_work2 = RAM16(BATTLE_DEFENCE_WORK);
        BUS16_SET(c, (value12 << 0x10) + 0x0351, 1);
        r->a = 1;
        r->x = battle_defence_work2;
        r->y = y1;
        r->c = 0;
        r->z = 0;
        r->n = 0;
        r->v = overflow1;
        r->mf = 0;
        r->xf = 0;
        r->db = value12;
        r->dp = 0x0300;
        RETURN_RTS(c);
    }
    r->a = value;
    r->x = battle_defence_work;
    r->c = 1;
    r->z = value == 0x4B;
    r->n = (uint16_t)(value - 0x4B) & 0x8000;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC23B2A, SOM_RTS, "gen", advance_and_plot_surviving_terminal_particles, 0, L_A | L_B | L_X | L_Y | L_C | L_Z | L_N | L_V, 2, 0, 0, 110, 55)

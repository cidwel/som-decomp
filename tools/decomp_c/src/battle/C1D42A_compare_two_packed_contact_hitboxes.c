#include "som_c.h"

/* C1D42A compare_two_packed_contact_hitboxes   [class B, 99 bytes, 58 instructions]
 * Source: src/rom/compare_two_packed_contact_hitboxes.s
 * Documented in docs/actor-party-map-contacts.md
 * Entry: M=any X=16 bit DB=$7E D=$0000.  Callers read: BXYC.
 */
static void compare_two_packed_contact_hitboxes(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, -1, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    RAM8(0x0012) = (uint8_t)(RAM8(0x0012) + RAM8(0x0016)) >> 1;
    RAM8(0x0013) = (uint8_t)(RAM8(0x0013) + RAM8(0x0017)) >> 1;
    uint8_t value5 = RAM8(0x0006);
    uint8_t a1;
    bool negative1;
    if (value5 & 0x80) {
        uint8_t value6 = RAM8(0x0014);
        uint8_t value7 = RAM8(0x0010);
        a1 = (uint8_t)((value6 ^ 0xFF) + value7 + 1);
        negative1 = (uint8_t)((value6 ^ 0xFF) + value7 + 1) & 0x80;
    } else {
        uint8_t value8 = RAM8(0x0010);
        uint8_t value9 = RAM8(0x0014);
        a1 = (uint8_t)((value8 ^ 0xFF) + value9 + 1);
        negative1 = (uint8_t)((value8 ^ 0xFF) + value9 + 1) & 0x80;
    }
    if (negative1) {
        uint8_t value10 = RAM8(0x000A);
        uint8_t a2;
        if (!((uint8_t)(a1 + value10) & 0x80)) {
            a2 = (uint8_t)(a1 + value10);
        } else {
            a2 = (uint8_t)(((uint8_t)(a1 + value10) ^ 0xFF) + 1);
        }
        uint8_t value11 = RAM8(0x0012);
        if (a2 >= value11) {
            r->c = a2 >= value11;
            r->mf = 1;
            RETURN_RTS(c);
        }
        uint8_t value12 = RAM8(0x0007);
        uint8_t a3;
        bool negative2;
        if (value12 & 0x80) {
            uint8_t value13 = RAM8(0x0015);
            uint8_t value14 = RAM8(0x0011);
            a3 = (uint8_t)((value13 ^ 0xFF) + value14 + 1);
            negative2 = (uint8_t)((value13 ^ 0xFF) + value14 + 1) & 0x80;
        } else {
            uint8_t value15 = RAM8(0x0011);
            uint8_t value16 = RAM8(0x0015);
            a3 = (uint8_t)((value15 ^ 0xFF) + value16 + 1);
            negative2 = (uint8_t)((value15 ^ 0xFF) + value16 + 1) & 0x80;
        }
        if (negative2) {
            uint8_t value17 = RAM8(0x000B);
            uint8_t a4;
            if (!((uint8_t)(a3 + value17) & 0x80)) {
                a4 = (uint8_t)(a3 + value17);
            } else {
                a4 = (uint8_t)(((uint8_t)(a3 + value17) ^ 0xFF) + 1);
            }
            r->c = a4 >= RAM8(0x0013);
            r->mf = 1;
            RETURN_RTS(c);
        }
        r->c = (uint8_t)(a3 + RAM8(0x000B)) >= RAM8(0x0013);
        r->mf = 1;
        RETURN_RTS(c);
    }
    uint8_t value21 = RAM8(0x000A);
    uint8_t value22 = RAM8(0x0012);
    if ((uint8_t)(a1 + value21) < value22) {
        uint8_t value23 = RAM8(0x0007);
        uint8_t a5;
        bool negative3;
        if (value23 & 0x80) {
            uint8_t value24 = RAM8(0x0015);
            uint8_t value25 = RAM8(0x0011);
            a5 = (uint8_t)((value24 ^ 0xFF) + value25 + 1);
            negative3 = (uint8_t)((value24 ^ 0xFF) + value25 + 1) & 0x80;
        } else {
            uint8_t value26 = RAM8(0x0011);
            uint8_t value27 = RAM8(0x0015);
            a5 = (uint8_t)((value26 ^ 0xFF) + value27 + 1);
            negative3 = (uint8_t)((value26 ^ 0xFF) + value27 + 1) & 0x80;
        }
        if (negative3) {
            uint8_t value28 = RAM8(0x000B);
            uint8_t a6;
            if (!((uint8_t)(a5 + value28) & 0x80)) {
                a6 = (uint8_t)(a5 + value28);
            } else {
                a6 = (uint8_t)(((uint8_t)(a5 + value28) ^ 0xFF) + 1);
            }
            r->c = a6 >= RAM8(0x0013);
            r->mf = 1;
            RETURN_RTS(c);
        }
        r->c = (uint8_t)(a5 + RAM8(0x000B)) >= RAM8(0x0013);
        r->mf = 1;
        RETURN_RTS(c);
    }
    r->c = (uint8_t)(a1 + value21) >= value22;
    r->mf = 1;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC1D42A, SOM_RTS, "gen", compare_two_packed_contact_hitboxes, 0, L_B | L_X | L_Y | L_C, 1, -1, 0, 99, 58)

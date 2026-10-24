#include "som_c.h"

/* C2B053 freeze_party_motion_when_all_heroes_ready   [class B, 62 bytes, 28 instructions]
 * Source: src/rom/freeze_party_motion_when_all_heroes_ready.s
 * Documented in docs/event-vm-control.md
 * Entry: M=16 bit X=16 bit DB=$7E D=$0000.  Callers read: C.
 */
static void freeze_party_motion_when_all_heroes_ready_m16x16(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 0, 0)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint16_t a = r->a;
    uint8_t a_hi1 = a >> 8;
    uint16_t x1 = 0x0400;
    for (;;) {
        uint8_t value = RAM8(0xE000 + x1);
        if (value == 0) {
            if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
                uint8_t a_hi1_next = (uint16_t)(x1 - 0x0200) >> 8;
                uint16_t x1_next = (uint16_t)(x1 - 0x0200);
                a_hi1 = a_hi1_next;
                x1 = x1_next;
                continue;
            }
            RAM16_SET(0xE006, 0);
            RAM16_SET(0xE206, 0);
            RAM16_SET(0xE406, 0);
            RAM16_SET(0xE008, 0);
            RAM16_SET(0xE208, 0);
            RAM16_SET(0xE408, 0);
            RAM8(0xE01D) = 0;
            RAM8(0xE21D) = 0;
            RAM8(0xE41D) = 0;
            r->c = 0;
            r->mf = 1;
            RETURN_RTL(c);
        }
        if (value & 0x80) {
            if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
                uint8_t a_hi1_next2 = (uint16_t)(x1 - 0x0200) >> 8;
                uint16_t x1_next2 = (uint16_t)(x1 - 0x0200);
                a_hi1 = a_hi1_next2;
                x1 = x1_next2;
                continue;
            }
            RAM16_SET(0xE006, 0);
            RAM16_SET(0xE206, 0);
            RAM16_SET(0xE406, 0);
            RAM16_SET(0xE008, 0);
            RAM16_SET(0xE208, 0);
            RAM16_SET(0xE408, 0);
            RAM8(0xE01D) = 0;
            RAM8(0xE21D) = 0;
            RAM8(0xE41D) = 0;
            r->c = 0;
            r->mf = 1;
            RETURN_RTL(c);
        }
        if (RAM8(0xE060 + x1) != 0) {
            r->c = 1;
            r->mf = 1;
            RETURN_RTL(c);
        }
        if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
            uint8_t a_hi1_next3 = (uint16_t)(x1 - 0x0200) >> 8;
            uint16_t x1_next3 = (uint16_t)(x1 - 0x0200);
            a_hi1 = a_hi1_next3;
            x1 = x1_next3;
            continue;
        }
        RAM16_SET(0xE006, 0);
        RAM16_SET(0xE206, 0);
        RAM16_SET(0xE406, 0);
        RAM16_SET(0xE008, 0);
        RAM16_SET(0xE208, 0);
        RAM16_SET(0xE408, 0);
        RAM8(0xE01D) = 0;
        RAM8(0xE21D) = 0;
        RAM8(0xE41D) = 0;
        r->c = 0;
        r->mf = 1;
        RETURN_RTL(c);
    }
}

/* C2B053 freeze_party_motion_when_all_heroes_ready   [class B, 62 bytes, 28 instructions]
 * Source: src/rom/freeze_party_motion_when_all_heroes_ready.s
 * Documented in docs/event-vm-control.md
 * Entry: M=8 bit X=8 bit DB=$7E D=$0000.  Callers read: C.
 */
static void freeze_party_motion_when_all_heroes_ready_m8x8(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 1)) return;
    if (r->dp != 0x0000) { c->fail = 3; return; }
    const uint8_t a_hi = r->a >> 8;
    uint8_t a_hi1 = a_hi;
    uint16_t x1 = 0x0400;
    bool first_pass = true;
    for (;;) {
        if (first_pass) {
            uint8_t value = RAM8(0xE000 + x1);
            if (value == 0) {
                if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
                    uint8_t a_hi1_next = (uint16_t)(x1 - 0x0200) >> 8;
                    uint16_t x1_next = (uint16_t)(x1 - 0x0200);
                    a_hi1 = a_hi1_next;
                    x1 = x1_next;
                    first_pass = false;
                    continue;
                }
                RAM16_SET(0xE006, 0);
                RAM16_SET(0xE206, 0);
                RAM16_SET(0xE406, 0);
                RAM16_SET(0xE008, 0);
                RAM16_SET(0xE208, 0);
                RAM16_SET(0xE408, 0);
                RAM8(0xE01D) = 0;
                RAM8(0xE21D) = 0;
                RAM8(0xE41D) = 0;
                r->c = 0;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (value & 0x80) {
                if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
                    uint8_t a_hi1_next2 = (uint16_t)(x1 - 0x0200) >> 8;
                    uint16_t x1_next2 = (uint16_t)(x1 - 0x0200);
                    a_hi1 = a_hi1_next2;
                    x1 = x1_next2;
                    first_pass = false;
                    continue;
                }
                RAM16_SET(0xE006, 0);
                RAM16_SET(0xE206, 0);
                RAM16_SET(0xE406, 0);
                RAM16_SET(0xE008, 0);
                RAM16_SET(0xE208, 0);
                RAM16_SET(0xE408, 0);
                RAM8(0xE01D) = 0;
                RAM8(0xE21D) = 0;
                RAM8(0xE41D) = 0;
                r->c = 0;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (RAM8(0xE060 + x1) != 0) {
                r->c = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
                uint8_t a_hi1_next3 = (uint16_t)(x1 - 0x0200) >> 8;
                uint16_t x1_next3 = (uint16_t)(x1 - 0x0200);
                a_hi1 = a_hi1_next3;
                x1 = x1_next3;
                first_pass = false;
                continue;
            }
            RAM16_SET(0xE006, 0);
            RAM16_SET(0xE206, 0);
            RAM16_SET(0xE406, 0);
            RAM16_SET(0xE008, 0);
            RAM16_SET(0xE208, 0);
            RAM16_SET(0xE408, 0);
            RAM8(0xE01D) = 0;
            RAM8(0xE21D) = 0;
            RAM8(0xE41D) = 0;
            r->c = 0;
            r->xf = 0;
            RETURN_RTL(c);
        } else {
            uint8_t value3 = RAM8(0xE000 + x1);
            if (value3 == 0) {
                if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
                    uint8_t a_hi1_next4 = (uint16_t)(x1 - 0x0200) >> 8;
                    uint16_t x1_next4 = (uint16_t)(x1 - 0x0200);
                    a_hi1 = a_hi1_next4;
                    x1 = x1_next4;
                    continue;
                }
                RAM16_SET(0xE006, 0);
                RAM16_SET(0xE206, 0);
                RAM16_SET(0xE406, 0);
                RAM16_SET(0xE008, 0);
                RAM16_SET(0xE208, 0);
                RAM16_SET(0xE408, 0);
                RAM8(0xE01D) = 0;
                RAM8(0xE21D) = 0;
                RAM8(0xE41D) = 0;
                r->c = 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (value3 & 0x80) {
                if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
                    uint8_t a_hi1_next5 = (uint16_t)(x1 - 0x0200) >> 8;
                    uint16_t x1_next5 = (uint16_t)(x1 - 0x0200);
                    a_hi1 = a_hi1_next5;
                    x1 = x1_next5;
                    continue;
                }
                RAM16_SET(0xE006, 0);
                RAM16_SET(0xE206, 0);
                RAM16_SET(0xE406, 0);
                RAM16_SET(0xE008, 0);
                RAM16_SET(0xE208, 0);
                RAM16_SET(0xE408, 0);
                RAM8(0xE01D) = 0;
                RAM8(0xE21D) = 0;
                RAM8(0xE41D) = 0;
                r->c = 0;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (RAM8(0xE060 + x1) != 0) {
                r->c = 1;
                r->mf = 1;
                r->xf = 0;
                RETURN_RTL(c);
            }
            if (!((uint16_t)(x1 - 0x0200) & 0x8000)) {
                uint8_t a_hi1_next6 = (uint16_t)(x1 - 0x0200) >> 8;
                uint16_t x1_next6 = (uint16_t)(x1 - 0x0200);
                a_hi1 = a_hi1_next6;
                x1 = x1_next6;
                continue;
            }
            RAM16_SET(0xE006, 0);
            RAM16_SET(0xE206, 0);
            RAM16_SET(0xE406, 0);
            RAM16_SET(0xE008, 0);
            RAM16_SET(0xE208, 0);
            RAM16_SET(0xE408, 0);
            RAM8(0xE01D) = 0;
            RAM8(0xE21D) = 0;
            RAM8(0xE41D) = 0;
            r->c = 0;
            r->mf = 1;
            r->xf = 0;
            RETURN_RTL(c);
        }
    }
}

/* Entered with M16/X16, M8/X8 accumulator/index widths: one body per width pair. */
static void freeze_party_motion_when_all_heroes_ready(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (r->mf == 0 && r->xf == 0) { freeze_party_motion_when_all_heroes_ready_m16x16(c); return; }
    if (r->mf == 1 && r->xf == 1) { freeze_party_motion_when_all_heroes_ready_m8x8(c); return; }
    c->fail = 3;
}
SOM_REGISTER(0xC2B053, SOM_RTL, "gen", freeze_party_motion_when_all_heroes_ready, 0, L_C, 1, -1, -1, 62, 28)

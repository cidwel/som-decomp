#include "som_c.h"

/* 7EA1E2 publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank   [class D, 95 bytes, 39 instructions]
 * Source: src/boot/publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank.s
 * Documented in docs/boot-native-scheduler-irq-setup.md
 * Entry: M=16 bit X=16 bit DB=$7F D=any.  Callers read: YCV.
 */
static void publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7F, 0, 0)) return;
    const uint16_t y = r->y;
    const bool carry = r->c;
    const bool overflow = r->v;
    BUS16_SET(c, 0x004209, 0xC0);
    RAM8(0x0104) = 0x5C;
    RAM8(0x0105) = 0x66;
    RAM8(0x0106) = 0xA2;
    RAM8(0x0107) = 0x7E;
    RAM8(0x0100) = 0x40;
    RAM8(0x1008C)++;
    uint8_t value = BUS8(c, 0x004211);
    uint8_t value2 = BUS8(c, 0x004210);
    uint8_t a_hi1 = 0;
    for (;;) {
        uint8_t value3 = BUS8(c, 0x004212);
        if (!((value3 & 0x80) != 0)) break;
    }
    uint8_t a_hi2 = a_hi1;
    for (;;) {
        uint8_t value4 = BUS8(c, 0x004212);
        if (!((value4 & 0x80) == 0)) break;
    }
    uint8_t value5 = RAM8(0x10090);
    RAM8(0x10090) = value5 | 0x20;
    BUS8_SET(c, 0x004200, value5 | 0x20);
    r->y = y;
    r->c = carry;
    r->v = overflow;
    RETURN_RTS(c);
}
SOM_REGISTER(0x7EA1E2, SOM_RTS, "gen", publish_native_scheduler_irq_vector_and_enable_vertical_irq_after_vblank, 0, L_Y | L_C | L_V, 5, 0, 0, 95, 39)

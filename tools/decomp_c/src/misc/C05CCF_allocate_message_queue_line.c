#include "som_c.h"

/* C05CCF allocate_message_queue_line   [class B, 57 bytes, 27 instructions]
 * Source: src/rom/allocate_message_queue_line.s
 * Documented in docs/spells-non-damage.md
 * Entry: M=8 bit X=16 bit DB=$7E D=$0300.  Callers read: BXYCV.
 */
static void allocate_message_queue_line(SomCtx *c)
{
    Cpu *r = &c->cpu;
    uint8_t *ram = c->wram;
    if (!hand_require(c, 0x7E, 1, 0)) return;
    if (r->dp != 0x0300) { c->fail = 3; return; }
    uint8_t value = RAM8(0x039F);
    BUS8_SET(c, 0x004202, RAM8(0x03A1));
    BUS8_SET(c, 0x004203, 0x1E);
    uint16_t value3 = BUS16(c, 0x004216);
    r->y = value3;
    r->c = value >= 0x0C;
    r->mf = 0;
    JSR(c, 0x5CF0, 0xC05D33); /* clear_message_queue_line */
    uint16_t y_ret = r->y;
    RAM8(0xFE00 + y_ret) = 0x60;
    RAM8(0x039F)++;
    RAM8(0x03A1)++;
    uint8_t value4 = RAM8(0x03A1);
    if (value4 == 0x0C) {
        RAM8(0x03A1) = 0;
    }
    r->y = (uint16_t)(y_ret + 1);
    r->c = value4 >= 0x0C;
    r->mf = 1;
    r->xf = 0;
    RETURN_RTS(c);
}
SOM_REGISTER(0xC05CCF, SOM_RTS, "gen", allocate_message_queue_line, 0, L_B | L_X | L_Y | L_C | L_V, 1, 1, 0, 57, 27)

#include "som_c.h"

/* C08260 enter_native_map_from_selected_ui_target_index   [class A, 6 bytes, 2 instructions]
 * Source: src/rom/enter_native_map_from_selected_ui_target_index.s
 * Entry: M=any X=any DB=$7E D=any.  Callers read: Y.
 */
static void enter_native_map_from_selected_ui_target_index(SomCtx *c)
{
    Cpu *r = &c->cpu;
    if (!hand_require(c, 0x7E, -1, -1)) return;
    { const uint16_t sp_call = r->sp; JSR(c, 0x8262, 0xC08223); GUARD_JSR(c, sp_call, 0x8262); } /* external */
    TAIL_CALL(c, 0xC0B03F, SOM_RTS); /* initialize_main_map_loop_before_native_nmi_wait */
}
SOM_REGISTER(0xC08260, SOM_RTS, "gen", enter_native_map_from_selected_ui_target_index, 0, L_Y, 1, -1, -1, 6, 2)

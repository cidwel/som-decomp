; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-vblank.md.
.setcpu "65816"
.smart
.a8
.i16

wait_menu_vblank_through_native_long_wrapper = $C0693F

.segment "CODE"
.org $D572
await_menu_vblank_then_fall_through_to_text_transition:
    jsl f:wait_menu_vblank_through_native_long_wrapper

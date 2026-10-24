; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-map-entry-prefix.md.
.setcpu "65816"
.smart
.a8
.i16

initialize_main_map_loop_before_native_nmi_wait = $B03F

.segment "CODE"
.org $8255
reset_native_stack_and_jump_from_ui_to_main_map_loop:
    rep #$10
    .i16
    ldx #$01FF
    txs
    sep #$20
    jmp initialize_main_map_loop_before_native_nmi_wait

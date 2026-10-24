; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-input-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $2BA5
dispatch_native_menu_idle_callback_when_selected_pad_is_empty:
    phx
    lda $42,X
    ora $43,X
    bne dispatch_native_menu_idle_callback_when_selected_pad_is_empty_c02bb8
    .a8
    lda #$00
    xba
    lda f:$7EA202
    asl
    tax
    jsr ($339F,X)
dispatch_native_menu_idle_callback_when_selected_pad_is_empty_c02bb8:
    plx
    rts

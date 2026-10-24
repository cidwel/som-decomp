; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

render_native_saved_slot_text_rows_with_real_vblank = $5D9A

.segment "CODE"
.org $5369
render_nine_native_save_confirmation_description_rows:
    phx
    .i16
    ldx #$70C0
    stx a:$A18C
    .i16
    ldx #$0300
    stx a:$A191
    .i16
    ldx #$0180
    stx a:$A199
    .a8
    lda #$09
    sta a:$A171
    plx
    jsr render_native_saved_slot_text_rows_with_real_vblank
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

render_native_saved_slot_text_rows_with_real_vblank = $5D9A

.segment "CODE"
.org $5D68
configure_and_render_two_native_saved_slot_text_rows:
    rep #$20
    phx
    lda a:$A162
    .a16
    and #$00FF
    asl
    tax
    lda f:$C75F87,X
    clc
    adc a:$A199
    sta a:$A18C
    sep #$20
    .i16
    ldx #$0380
    stx a:$A191
    .i16
    ldx #$01C0
    stx a:$A199
    .a8
    lda #$02
    sta a:$A171
    plx
    jsr render_native_saved_slot_text_rows_with_real_vblank
    rts

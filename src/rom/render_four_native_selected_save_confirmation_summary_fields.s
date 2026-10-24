; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-saved-game-menu-request.md.
.setcpu "65816"
.smart
.a8
.i16

render_native_saved_slot_text_rows_with_real_vblank = $5D9A

.segment "CODE"
.org $541E
render_four_native_selected_save_confirmation_summary_fields:
    .i16
    ldx #$0000
    .i16
    ldy #$0008
    .a8
    lda #$7F
render_four_native_selected_save_confirmation_summary_fields_c75426:
    sta a:$9C00,X
    inx
    dey
    bne render_four_native_selected_save_confirmation_summary_fields_c75426
    stz a:$A17A
    stz a:$A17B
render_four_native_selected_save_confirmation_summary_fields_c75433:
    ldx a:$A17A
    phx
    jsr ($5F8F,X)
    txy
    plx
    rep #$20
    lda f:$C75F97,X
    sta a:$A18C
    lda f:$C75F9F,X
    sta a:$A191
    tyx
    sep #$20
    .a8
    lda #$01
    sta a:$A171
    jsr render_native_saved_slot_text_rows_with_real_vblank
    lda a:$A17A
    inc
    inc
    sta a:$A17A
    .a8
    cmp #$08
    bne render_four_native_selected_save_confirmation_summary_fields_c75433
    rts

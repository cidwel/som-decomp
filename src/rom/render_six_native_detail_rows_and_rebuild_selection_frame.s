; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-detail.md.
.setcpu "65816"
.smart
.a8
.i16

highlight_native_saved_slot_rectangle_and_request_publication = $C757DC
render_native_saved_slot_text_rows_with_real_vblank = $5D9A
reset_and_rebuild_native_menu_frame_without_heading = $C02AE3

.segment "CODE"
.org $6512
render_six_native_detail_rows_and_rebuild_selection_frame:
    phx
    .i16
    ldx #$6500
    stx a:$A18C
    .i16
    ldx #$03C0
    stx a:$A191
    .i16
    ldx #$01E0
    stx a:$A199
    .a8
    lda #$06
    sta a:$A171
    plx
    jsr render_native_saved_slot_text_rows_with_real_vblank
    jsl f:reset_and_rebuild_native_menu_frame_without_heading
    lda a:$A202
    pha
    .a8
    lda #$06
    sta a:$A202
    jsl f:highlight_native_saved_slot_rectangle_and_request_publication
    pla
    sta a:$A202
    .a8
    lda #$40
    tsb a:$A20A
    rts

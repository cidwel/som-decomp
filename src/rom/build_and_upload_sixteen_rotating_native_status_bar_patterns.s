; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-party-status-art.md.
.setcpu "65816"
.smart
.a8
.i16

repeat_native_status_bar_plane_byte_eight_times = $6B96
upload_native_saved_slot_text_rows_wrapper = $C02ADF

.segment "CODE"
.org $6B55
build_and_upload_sixteen_rotating_native_status_bar_patterns:
    .a8
    lda #$10
    sta a:$A175
    .i16
    ldx #$0000
    .i16
    ldy #$0080
    sty a:$A1C7
build_and_upload_sixteen_rotating_native_status_bar_patterns_c76b63:
    lda a:$A1C7
    jsr repeat_native_status_bar_plane_byte_eight_times
    .a8
    lda #$00
    jsr repeat_native_status_bar_plane_byte_eight_times
    lda a:$A1C8
    jsr repeat_native_status_bar_plane_byte_eight_times
    .a8
    lda #$00
    jsr repeat_native_status_bar_plane_byte_eight_times
    sec
    ror a:$A1C7
    ror a:$A1C8
    dec a:$A175
    bne build_and_upload_sixteen_rotating_native_status_bar_patterns_c76b63
    .i16
    ldx #$0200
    stx a:$A191
    .i16
    ldx #$6180
    stx a:$A18C
    jsl f:upload_native_saved_slot_text_rows_wrapper
    rts

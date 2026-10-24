; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AE55
initialize_complete_picker_cursor_object_buffer:
    rep #$30
    .i16
    ldx #$0000
    .a16
    lda #$E0FF
initialize_complete_picker_cursor_object_buffer_c2ae5d:
    sta a:$0800,X
    inx
    inx
    inx
    inx
    .i16
    cpx #$0200
    bcc initialize_complete_picker_cursor_object_buffer_c2ae5d
initialize_complete_picker_cursor_object_buffer_c2ae69:
    stz a:$0800,X
    inx
    .i16
    cpx #$0220
    bcc initialize_complete_picker_cursor_object_buffer_c2ae69
    .a16
    lda #$00AA
    sta a:$0A00
    .a16
    lda #$3FE0
    sta a:$0802
    .a16
    lda #$7FE0
    sta a:$0806
    .a16
    lda #$BFE0
    sta a:$080A
    .a16
    lda #$FFE0
    sta a:$080E
    sep #$30
    .a8
    lda #$03
    sta a:$2101
    .a8
    lda #$81
    sta a:$2121
    .a8
    lda #$FF
    sta a:$2122
    sta a:$2122
    rts

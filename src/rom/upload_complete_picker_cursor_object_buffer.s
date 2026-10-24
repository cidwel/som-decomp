; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-world-map-picker-scene.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $AEA5
upload_complete_picker_cursor_object_buffer:
    rep #$20
    .a16
    lda #$0000
    sta a:$2102
    .a16
    lda #$0800
    sta a:$4372
    .a16
    lda #$0400
    sta a:$4370
    .a16
    lda #$0220
    sta a:$4375
    sep #$20
    .i8
    ldx #$00
    stx a:$4374
    .i8
    ldx #$80
    stx a:$420B
    rts

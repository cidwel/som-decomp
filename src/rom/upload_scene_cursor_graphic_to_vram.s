; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $FDB8
upload_scene_cursor_graphic_to_vram:
    sep #$20
    rep #$10
    .a8
    lda #$80
    sta a:$2115
    .i16
    ldx #$7000
    stx a:$2116
    .i16
    ldx #$1801
    stx a:$4370
    .i16
    ldx #$FB00
    stx a:$4372
    .a8
    lda #$C7
    sta a:$4374
    .i16
    ldx #$00A0
    stx a:$4375
    .a8
    lda #$80
    sta a:$420B
    rtl

; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-interrupts.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $984D
publish_pending_ui_scene_tile_column:
    sep #$10
    rep #$20
    ldx $2F
    bmi publish_pending_ui_scene_tile_column_c09856
    rts
publish_pending_ui_scene_tile_column_c09856:
    .i8
    ldx #$00
    stx $2F
    .i8
    ldx #$03
    stx a:$2115
    .a16
    lda #$1800
    sta a:$4370
    .i8
    ldx #$00
    stx a:$4374
    .a16
    lda #$0B80
    sta a:$4372
    lda $78
    sta a:$2116
    .a16
    lda #$0080
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    rts

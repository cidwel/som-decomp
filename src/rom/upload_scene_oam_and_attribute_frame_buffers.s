; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-interrupts.md.
.setcpu "65816"
.smart
.a8
.i16

publish_changed_scene_attribute_window_rows = $8890

.segment "CODE"
.org $882B
upload_scene_oam_and_attribute_frame_buffers:
    sep #$10
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
    .i8
    ldx #$00
    stx a:$4374
    .a16
    lda #$0220
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    stx a:$2115
    .a16
    lda #$1900
    sta a:$4370
    lda $A2
    sta a:$4372
    .i8
    ldx #$7E
    stx a:$4374
    lda $A4
    sta a:$2116
    .a16
    lda #$0080
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B
    lda $E3
    .a16
    and #$0006
    beq publish_changed_scene_attribute_window_rows
    lda $92
    sta a:$4372
    lda $94
    sta a:$2116
    .a16
    lda #$0040
    sta a:$4375
    .i8
    ldx #$80
    stx a:$420B

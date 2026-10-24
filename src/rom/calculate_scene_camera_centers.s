; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $83C8
calculate_scene_camera_centers:
    rep #$20
    sep #$10
    lda $3E
    sta $3A
    lda $FA
    .a16
    and #$03FF
    sec
    .a16
    sbc #$0080
    sta $3E
    lda $FC
    .a16
    and #$03FF
    sec
    .a16
    sbc #$0070
    sta $40
    rts

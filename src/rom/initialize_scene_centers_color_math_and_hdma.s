; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_scene_camera_centers = $83C8
routine_02adaa = $2ADAA

.segment "CODE"
.org $8366
initialize_scene_centers_color_math_and_hdma:
    sep #$10
    rep #$20
    lda $FA
    .a16
    and #$FFF8
    sta $70
    lda $FC
    .a16
    and #$FFF8
    sta $72
    jsr calculate_scene_camera_centers
    .i8
    ldx #$02
    stx a:$2130
    .i8
    ldx #$21
    stx a:$2131
    stx $2A
    .i8
    ldx #$E0
    stx a:$2132
    .i8
    ldx #$02
    stx a:$212D
    jsl f:routine_02adaa
    .a16
    lda #$0000
    sta a:$1100
    sta a:$1200
    .a16
    lda #$7F00
    sta a:$1000
    sta a:$1400
    rts

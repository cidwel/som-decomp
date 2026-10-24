; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $900A
compute_bounded_scene_target_angle_with_hardware_division:
    rep #$20
    lda $84
    sta $00
    lda $F7
    lsr
    lda $88
    bcc compute_bounded_scene_target_angle_with_hardware_division_c0901b
    sta $00
    lda $84
compute_bounded_scene_target_angle_with_hardware_division_c0901b:
    sta $02
    stz $04
compute_bounded_scene_target_angle_with_hardware_division_c0901f:
    lda $00
    .a16
    cmp #$0100
    bcs compute_bounded_scene_target_angle_with_hardware_division_c0902d
    lda $02
    .a16
    cmp #$0100
    bcc compute_bounded_scene_target_angle_with_hardware_division_c09033
compute_bounded_scene_target_angle_with_hardware_division_c0902d:
    lsr $00
    lsr $02
    bra compute_bounded_scene_target_angle_with_hardware_division_c0901f
compute_bounded_scene_target_angle_with_hardware_division_c09033:
    lda $00
    cmp $02
    bcc compute_bounded_scene_target_angle_with_hardware_division_c09043
    pha
    lda $02
    sta $00
    pla
    sta $02
    dec $04
compute_bounded_scene_target_angle_with_hardware_division_c09043:
    lda $00
    asl
    asl
    asl
    asl
    sta a:$4204
    sep #$20
    lda $02
    sta a:$4206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda a:$4214
    .a8
    cmp #$11
    bcc compute_bounded_scene_target_angle_with_hardware_division_c09064
    .a8
    lda #$10
compute_bounded_scene_target_angle_with_hardware_division_c09064:
    sep #$10
    tax
    lda f:$00907A,X
    bit $04
    bpl compute_bounded_scene_target_angle_with_hardware_division_c09071
    .a8
    eor #$FF
compute_bounded_scene_target_angle_with_hardware_division_c09071:
    sta $96
    sta $F6
    lda $F7
    sta $97
    rts

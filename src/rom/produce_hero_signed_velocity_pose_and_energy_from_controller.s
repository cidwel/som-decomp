; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-motion.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $B710
produce_hero_signed_velocity_pose_and_energy_from_controller:
    .i8
    ldx #$00
    txy
    lda $10
    .a8
    and #$03
    beq produce_hero_signed_velocity_pose_and_energy_from_controller_c0b721
    .i8
    ldx #$02
    .a8
    and #$01
    bne produce_hero_signed_velocity_pose_and_energy_from_controller_c0b721
    .i8
    ldx #$82
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b721:
    lda $10
    .a8
    and #$0C
    beq produce_hero_signed_velocity_pose_and_energy_from_controller_c0b72f
    .i8
    ldy #$02
    .a8
    and #$04
    bne produce_hero_signed_velocity_pose_and_energy_from_controller_c0b72f
    .i8
    ldy #$82
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b72f:
    bit $10
    bmi produce_hero_signed_velocity_pose_and_energy_from_controller_c0b737
    .a8
    lda #$30
    trb $12
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b737:
    tya
    xba
    txa
    rep #$10
    lsr $11
    bcs produce_hero_signed_velocity_pose_and_energy_from_controller_c0b74e
    lsr $11
    bcs produce_hero_signed_velocity_pose_and_energy_from_controller_c0b749
    .i16
    ldx #$0400
    bra produce_hero_signed_velocity_pose_and_energy_from_controller_c0b751
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b749:
    .i16
    ldx #$0200
    bra produce_hero_signed_velocity_pose_and_energy_from_controller_c0b751
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b74e:
    .i16
    ldx #$0000
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b751:
    tay
    stz a:$E067,X
    lda a:$E01C,X
    ora a:$E060,X
    ora a:$E00A,X
    beq produce_hero_signed_velocity_pose_and_energy_from_controller_c0b761
    rts
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b761:
    lda $12
    bpl produce_hero_signed_velocity_pose_and_energy_from_controller_c0b77b
    sta a:$E01D,X
    lda a:$E011,X
    .a8
    cmp #$02
    beq produce_hero_signed_velocity_pose_and_energy_from_controller_c0b798
    .a8
    lda #$80
    trb $12
    lda a:$E063,X
    lsr
    bcc produce_hero_signed_velocity_pose_and_energy_from_controller_c0b78d
    bcs produce_hero_signed_velocity_pose_and_energy_from_controller_c0b780
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b77b:
    bit a:$E01D,X
    bpl produce_hero_signed_velocity_pose_and_energy_from_controller_c0b78f
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b780:
    .a8
    lda #$64
    sec
    sbc a:$E189,X
    lsr
    clc
    .a8
    adc #$32
    sta a:$E1ED,X
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b78d:
    lda $12
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b78f:
    sta a:$E01D,X
    rep #$20
    tya
    sta a:$E006,X
produce_hero_signed_velocity_pose_and_energy_from_controller_c0b798:
    rts

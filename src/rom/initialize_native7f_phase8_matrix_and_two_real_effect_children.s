; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-setup.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
set_boss_animation_bank_low_byte_c7 = $0CE0

.segment "CODE"
.org $8F7B
initialize_native7f_phase8_matrix_and_two_real_effect_children:
    ldx $87
    jsr set_boss_animation_bank_low_byte_c7
    .a16
    lda #$0001
    sta a:$0000,X
    .a16
    lda #$0008
    sta a:$0094,X
    .a16
    lda #$0002
    sta a:$000B,X
    sep #$20
    .a8
    lda #$C0
    sta f:$00211A
    rep #$20
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    .i16
    ldx #$986D
    .i16
    ldy #$3921
    jsr allocate_boss_object_pool_slot
    .i16
    ldx #$3D34
    .i16
    ldy #$2A20
    jsr allocate_boss_object_pool_slot
    clc
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-motion-collapse.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F
publish_native7f_actor_mask_to_party_and_collision_byte = $90E4

.segment "CODE"
.org $90AC
shrink_native7f_while_rotating_then_attack_and_mask_party:
    ldx $87
    lda a:$00B2,X
    clc
    .a16
    adc #$0080
    sta a:$00B2,X
    lda a:$00B0,X
    sec
    .a16
    sbc #$0018
    sta a:$00B0,X
    .a16
    cmp #$0010
    bcs shrink_native7f_while_rotating_then_attack_and_mask_party_c290df
    .a16
    lda #$0009
    sta a:$0094,X
    stz a:$0096,X
    stz a:$00B0,X
    .a16
    lda #$0072
    jsl f:boss_attack_row_public_jump
    ldx $87
    jsr publish_native7f_actor_mask_to_party_and_collision_byte
shrink_native7f_while_rotating_then_attack_and_mask_party_c290df:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts

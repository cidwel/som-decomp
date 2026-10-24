; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-motion-collapse.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
derive_isotropic_native7f_mode7_matrix_from_scale_and_angle = $979F

.segment "CODE"
.org $91A4
release_native7f_party_mask_once_and_wait_for_left_boundary:
    ldx $87
    lda a:$00B4,X
    bne release_native7f_party_mask_once_and_wait_for_left_boundary_c291d4
    lda a:$002B,X
    .a16
    cmp #$0128
    bcs release_native7f_party_mask_once_and_wait_for_left_boundary_c291d4
    lda $C7
    sta a:$00B4,X
    sep #$20
    .a8
    lda #$01
    sta a:$E059
    .a8
    lda #$01
    sta a:$E259
    .a8
    lda #$01
    sta a:$E459
    rep #$20
    .a16
    lda #$006F
    jsl f:boss_attack_row_public_jump
    ldx $87
release_native7f_party_mask_once_and_wait_for_left_boundary_c291d4:
    .a16
    lda #$0028
    cmp a:$002B,X
    bcc release_native7f_party_mask_once_and_wait_for_left_boundary_c291ee
    stz a:$0096,X
    .a16
    lda #$0011
    sta a:$0094,X
    stz a:$0090,X
    .a16
    lda #$0080
    sta a:$00B0,X
release_native7f_party_mask_once_and_wait_for_left_boundary_c291ee:
    jsr derive_isotropic_native7f_mode7_matrix_from_scale_and_angle
    clc
    rts

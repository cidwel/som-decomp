; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-motion.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_object_pool_slot = $0D53
boss_attack_row_public_jump = $C0006C
request_boss_sound_with_parameter_word = $30E3
test_native54_negative_status_or_begin_hurt_shift = $4965

.segment "CODE"
.org $46ED
complete_native54_attack_animation_and_create_projectile:
    ldx $87
    jsr test_native54_negative_status_or_begin_hurt_shift
    bcs complete_native54_attack_animation_and_create_projectile_c24717
    lda a:$009E,X
    bne complete_native54_attack_animation_and_create_projectile_c2473a
    lda a:$00BE,X
    beq complete_native54_attack_animation_and_create_projectile_c24719
    .a16
    lda #$000C
    sta a:$0094,X
    sep #$20
    .a8
    lda #$C1
    sta a:$F812,Y
    .a8
    lda #$DE
    sta a:$F80E,Y
    .a8
    lda #$40
    sta a:$F813,Y
    rep #$20
complete_native54_attack_animation_and_create_projectile_c24717:
    clc
    rts
complete_native54_attack_animation_and_create_projectile_c24719:
    .a16
    lda #$000C
    sta a:$0094,X
    sep #$20
    lda a:$0076,X
    beq complete_native54_attack_animation_and_create_projectile_c24729
    inc a:$0094,X
complete_native54_attack_animation_and_create_projectile_c24729:
    .a8
    lda #$C1
    sta a:$F812,Y
    .a8
    lda #$DE
    sta a:$F80E,Y
    .a8
    lda #$40
    sta a:$F813,Y
    rep #$20
complete_native54_attack_animation_and_create_projectile_c2473a:
    lda a:$0096,X
    .a16
    cmp #$0003
    bne complete_native54_attack_animation_and_create_projectile_c2478d
    ldx $87
    .a16
    lda #$001C
    clc
    adc a:$0042,X
    jsl f:boss_attack_row_public_jump
    ldx $87
    lda a:$00A9,X
    sta $9B
    stz a:$00B8,X
    lda a:$002B,X
    sta $95
    lda a:$0032,X
    sta $97
    stx $99
    .i16
    ldy #$A801
    .i16
    ldx #$4F7D
    jsr allocate_boss_object_pool_slot
    bcs complete_native54_attack_animation_and_create_projectile_c2478d
    lda $95
    sta a:$002B,X
    lda $97
    sta a:$0032,X
    lda $99
    sta a:$00B0,X
    lda $9B
    sta a:$00A9,X
    .a16
    lda #$003D
    .i16
    ldx #$000F
    jsr request_boss_sound_with_parameter_word
complete_native54_attack_animation_and_create_projectile_c2478d:
    clc
    rts

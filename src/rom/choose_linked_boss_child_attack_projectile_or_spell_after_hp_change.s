; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-attack-selection.md.
.setcpu "65816"
.smart
.a8
.i16

boss_attack_row_public_jump = $C0006C
derive_target_manhattan_distance_in_sixteen_pixel_units = $08D9
draw_boss_frame_random_number = $300B
prepare_boss_attack_row_and_create_selected_projectile = $58EF
prepare_boss_spell_if_enabled_otherwise_unwind_caller = $5906

.segment "CODE"
.org $581D
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change:
    ldx $87
    lda a:$002D,X
    cmp a:$00AD,X
    bcc choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c25828
    rts
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c25828:
    stz a:$00AD,X
    lda a:$00A9,X
    jsr derive_target_manhattan_distance_in_sixteen_pixel_units
    ldx $87
    .a16
    cmp #$0008
    bcs choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c2588f
    .a16
    lda #$0007
    jsr draw_boss_frame_random_number
    ldx $87
    .a16
    cmp #$0000
    beq choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c2588f
    .a16
    lda #$0008
    sta a:$00B8,X
    .a16
    lda #$0003
    jsr draw_boss_frame_random_number
    clc
    .a16
    adc #$0060
    ldx $87
    jsl f:boss_attack_row_public_jump
    ldx $87
    lda a:$00A9,X
    asl
    xba
    clc
    .a16
    adc #$E000
    tay
    lda a:$0002,Y
    cmp a:$002B,X
    bcc choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c2587f
    ldy a:$00B2,X
    .a16
    lda #$0003
    sta a:$0081,Y
    lda a:$00A9,X
    sta a:$00A9,Y
    rts
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c2587f:
    ldy a:$00B0,X
    .a16
    lda #$0003
    sta a:$0081,Y
    lda a:$00A9,X
    sta a:$00A9,Y
    rts
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c2588f:
    .a16
    lda #$0020
    sta a:$00B8,X
    ldy a:$00B0,X
    .a16
    lda #$0005
    sta a:$0081,Y
    ldy a:$00B2,X
    sta a:$0081,Y
    .a16
    lda #$0002
    jsr draw_boss_frame_random_number
    sta $00
    ldx $87
    .a16
    cmp #$0000
    beq choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258d7
    .a16
    lda #$0004
    sta a:$00A9,X
    lda a:$0042,X
    bne choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258c5
    .a16
    lda #$0009
    jsr prepare_boss_attack_row_and_create_selected_projectile
    rts
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258c5:
    dec $00
    lda $00
    beq choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258d0
    .a16
    lda #$0000
    bra choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258d3
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258d0:
    .a16
    lda #$001B
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258d3:
    jsr prepare_boss_attack_row_and_create_selected_projectile
    rts
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258d7:
    lda a:$0184,X
    lsr
    lsr
    cmp a:$0182,X
    bcs choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258e8
    .a16
    lda #$0107
    jsr prepare_boss_spell_if_enabled_otherwise_unwind_caller
    rts
choose_linked_boss_child_attack_projectile_or_spell_after_hp_change_c258e8:
    .a16
    lda #$020B
    jsr prepare_boss_spell_if_enabled_otherwise_unwind_caller
    rts

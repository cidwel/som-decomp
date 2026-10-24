; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

enqueue_actor_weapon_level_up_notice = $5B40
rebuild_actor_attributes_native = $C04530
send_combat_sound_with_fixed_parameter_fifteen = $398D
store_selected_actor_weapon_experience_byte = $444A

.segment "CODE"
.org $43B7
advance_actor_weapon_experience_and_level:
    lda a:$E000,Y
    .a8
    cmp #$01
    beq advance_actor_weapon_experience_and_level_c043bf
    rts
advance_actor_weapon_experience_and_level_c043bf:
    lda a:$E191,Y
    bpl advance_actor_weapon_experience_and_level_c043c5
    rts
advance_actor_weapon_experience_and_level_c043c5:
    rep #$20
    lda a:$E19C,Y
    .a16
    and #$00FF
    tax
    sep #$20
    lda f:$C043AC,X
    sta $D8
    lda a:$E1E4,Y
    tax
    lda a:$CFB0,X
    inc
    sta $B0
    sty $CC
    sty $D4
    lda a:$E19C,Y
    cmp $B0
    bne advance_actor_weapon_experience_and_level_c043f0
    stz $D0
    jmp store_selected_actor_weapon_experience_byte
advance_actor_weapon_experience_and_level_c043f0:
    lda a:$E1E4,Y
    sta $D4
    ldy $D4
    lda a:$E1D0,Y
    clc
    adc $A6
    sta $D0
    ldy $CC
    lda $D0
    cmp $D8
    bcc store_selected_actor_weapon_experience_byte
    lda a:$E19C,Y
    .a8
    cmp #$08
    bne advance_actor_weapon_experience_and_level_c04414
    lda $D8
    sta $D0
    bra store_selected_actor_weapon_experience_byte
advance_actor_weapon_experience_and_level_c04414:
    stz $D0
    lda a:$E1E4,Y
    sta $D8
    lsr
    sta $D4
    ldy $D4
    lda $D8
    .a8
    bit #$01
    bne advance_actor_weapon_experience_and_level_c04431
    lda a:$E1C0,Y
    clc
    .a8
    adc #$10
    sta a:$E1C0,Y
    bra advance_actor_weapon_experience_and_level_c04438
advance_actor_weapon_experience_and_level_c04431:
    lda a:$E1C0,Y
    inc
    sta a:$E1C0,Y
advance_actor_weapon_experience_and_level_c04438:
    jsr store_selected_actor_weapon_experience_byte
    ldx $CC
    jsl f:rebuild_actor_attributes_native
    jsr enqueue_actor_weapon_level_up_notice
    .a8
    lda #$CE
    jsr send_combat_sound_with_fixed_parameter_fifteen
    rts

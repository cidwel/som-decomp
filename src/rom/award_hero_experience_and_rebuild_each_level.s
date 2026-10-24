; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

cap_combat_24bit_value_at_9999999 = $39A4
enqueue_actor_level_up_notice = $5B20
rebuild_actor_attributes_native = $C04530
send_combat_sound_with_fixed_parameter_fifteen = $398D

.segment "CODE"
.org $445B
award_hero_experience_and_rebuild_each_level:
    .a8
    lda #$04
    sta $84
award_hero_experience_and_rebuild_each_level_c0445f:
    ldx $83
    lda a:$E000,X
    .a8
    cmp #$01
    bne award_hero_experience_and_rebuild_each_level_c0446f
    ldy a:$E182,X
    beq award_hero_experience_and_rebuild_each_level_c0446f
    bra award_hero_experience_and_rebuild_each_level_c04476
award_hero_experience_and_rebuild_each_level_c0446f:
    dec $84
    dec $84
    bpl award_hero_experience_and_rebuild_each_level_c0445f
    rts
award_hero_experience_and_rebuild_each_level_c04476:
    ldy $85
    rep #$20
    lda a:$E18D,Y
    clc
    adc a:$E18D,X
    sta $D0
    sep #$20
    .a8
    lda #$00
    adc a:$E18F,X
    sta $D2
    jsr cap_combat_24bit_value_at_9999999
    rep #$20
    lda $D0
    sta a:$E18D,X
    sep #$20
    lda $D2
    sta a:$E18F,X
award_hero_experience_and_rebuild_each_level_c0449d:
    lda a:$E181,X
    .a8
    cmp #$62
    beq award_hero_experience_and_rebuild_each_level_c044e4
    lda a:$E17F,X
    cmp a:$E18F,X
    beq award_hero_experience_and_rebuild_each_level_c044ae
    bcs award_hero_experience_and_rebuild_each_level_c044e4
award_hero_experience_and_rebuild_each_level_c044ae:
    bcc award_hero_experience_and_rebuild_each_level_c044bc
    rep #$20
    lda a:$E17D,X
    cmp a:$E18D,X
    beq award_hero_experience_and_rebuild_each_level_c044bc
    bcs award_hero_experience_and_rebuild_each_level_c044e4
award_hero_experience_and_rebuild_each_level_c044bc:
    sep #$20
    lda a:$E181,X
    inc
    sta a:$E181,X
    jsl f:rebuild_actor_attributes_native
    jsr enqueue_actor_level_up_notice
    .a8
    lda #$AF
    jsr send_combat_sound_with_fixed_parameter_fifteen
    rep #$20
    lda a:$E184,X
    sta a:$E182,X
    sep #$20
    lda $80
    .a8
    ora #$40
    sta $80
    jmp award_hero_experience_and_rebuild_each_level_c0449d
award_hero_experience_and_rebuild_each_level_c044e4:
    sep #$20
    dec $84
    dec $84
    bmi award_hero_experience_and_rebuild_each_level_c044ef
    jmp award_hero_experience_and_rebuild_each_level_c0445f
award_hero_experience_and_rebuild_each_level_c044ef:
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_boss_palette_transition_object = $272D
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
select_native7f_nearest_target_and_primary_spell_gate = $93CB

.segment "CODE"
.org $9381
advance_native7f_timed_spell_state_or_enter_death_palette_phase:
    ldx $87
    lda a:$0190,X
    bmi advance_native7f_timed_spell_state_or_enter_death_palette_phase_c293a8
    lda a:$00AD,X
    cmp a:$002D,X
    bcc advance_native7f_timed_spell_state_or_enter_death_palette_phase_c29399
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    stz a:$00AD,X
    jsr select_native7f_nearest_target_and_primary_spell_gate
advance_native7f_timed_spell_state_or_enter_death_palette_phase_c29399:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$00F0
    bcc advance_native7f_timed_spell_state_or_enter_death_palette_phase_c293a6
    inc a:$0094,X
advance_native7f_timed_spell_state_or_enter_death_palette_phase_c293a6:
    clc
    rts
advance_native7f_timed_spell_state_or_enter_death_palette_phase_c293a8:
    .a16
    lda #$0012
    sta a:$0094,X
    stz a:$0096,X
    .i16
    ldx #$0084
    .i16
    ldy #$000D
    .a16
    lda #$0078
    jsr allocate_boss_palette_transition_object
    .i16
    ldx #$0085
    .i16
    ldy #$000E
    .a16
    lda #$0078
    jsr allocate_boss_palette_transition_object
    clc
    rts

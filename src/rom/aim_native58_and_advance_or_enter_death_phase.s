; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-action-helpers.md.
.setcpu "65816"
.smart
.a8
.i16

derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
derive_fine_direction_to_low_byte_target = $0965
select_nearest_active_living_party_actor = $3224

.segment "CODE"
.org $7BC0
aim_native58_and_advance_or_enter_death_phase:
    sep #$20
    lda a:$0380
    .a8
    and #$7F
    sta a:$0380
    rep #$20
    ldx $87
    lda a:$0190,X
    bmi aim_native58_and_advance_or_enter_death_phase_c27bfe
    lda a:$00A9,X
    jsr derive_fine_direction_to_low_byte_target
    ldx $87
    sta a:$00AB,X
    lda a:$00AD,X
    cmp a:$002D,X
    bcc aim_native58_and_advance_or_enter_death_phase_c27bfc
    inc a:$0094,X
    stz a:$00AD,X
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    lda a:$00B6,X
    bne aim_native58_and_advance_or_enter_death_phase_c27bf4
aim_native58_and_advance_or_enter_death_phase_c27bf4:
    jsr select_nearest_active_living_party_actor
    ldx $87
    sta a:$00A9,X
aim_native58_and_advance_or_enter_death_phase_c27bfc:
    clc
    rts
aim_native58_and_advance_or_enter_death_phase_c27bfe:
    .a16
    lda #$0004
    sta a:$0094,X
    stz a:$003E,X
    stz a:$0040,X
    clc
    rts

; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
routine_c8e9fc = $E9FC
routine_c8ea69 = $EA69



.segment "CODE"
.org $EB9F
resolve_remedy_spell:
    ldx $85
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    jsr routine_c8ea69
    jsr routine_c8e9fc
    jsl f:$C03F28
    rts

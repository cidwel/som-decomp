; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
routine_c8e88e = $E88E
select_spell_element_multiplier = $E8A0



.segment "CODE"
.org $EBF4
resolve_status_only_spell:
    ldx $85
    jsr select_spell_element_multiplier
    jsr calculate_spell_attack_roll
    jsr routine_c8e88e
    rts

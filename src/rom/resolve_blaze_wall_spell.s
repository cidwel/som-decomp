; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
queue_spell_damage_with_minimum_one = $E9DF
routine_c8e88e = $E88E
select_spell_element_multiplier = $E8A0



.segment "CODE"
.org $EBE5
resolve_blaze_wall_spell:
    ldx $85
    jsr select_spell_element_multiplier
    jsr calculate_spell_attack_roll
    jsr queue_spell_damage_with_minimum_one
    jsr routine_c8e88e
    rts

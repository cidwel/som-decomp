; Recovered Secret of Mana USA boot routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
queue_spell_damage_with_minimum_one = $E9DF
select_spell_element_multiplier = $E8A0



.segment "CODE"
.org $EA8B
resolve_standard_damage_spell:
    ldx $85
    jsr select_spell_element_multiplier
    jsr calculate_spell_attack_roll
    jsr queue_spell_damage_with_minimum_one
    rts

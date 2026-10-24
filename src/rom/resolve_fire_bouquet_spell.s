; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0
queue_spell_damage_with_minimum_one = $E9DF
select_spell_element_multiplier = $E8A0

object_buff_flags = $E1B0
object_attack_buff_timer = $E1B7

.segment "CODE"
.org $EBCA
resolve_fire_bouquet_spell:
    ldx $85
    jsr select_spell_element_multiplier
    jsr calculate_spell_attack_roll
    jsr queue_spell_damage_with_minimum_one
    lda a:object_buff_flags,X
    .a8
    and #$3F
    .a8
    ora #$80
    sta a:object_buff_flags,X
    lda $9C
    sta a:object_attack_buff_timer,X
    rts

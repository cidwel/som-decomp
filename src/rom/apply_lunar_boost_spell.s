; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0

object_buff_flags = $E1B0
object_evasion_buff_timer = $E1BB
object_attack_buff_timer = $E1B7

.segment "CODE"
.org $ECB5
apply_lunar_boost_spell:
    ldx $85
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    lda a:object_buff_flags,X
    .a8
    and #$33
    .a8
    ora #$48
    sta a:object_buff_flags,X
    lda $9C
    sta a:object_attack_buff_timer,X
    sta a:object_evasion_buff_timer,X
    rts

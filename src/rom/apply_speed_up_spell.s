; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0

object_buff_flags = $E1B0
object_evasion_buff_timer = $E1BB
object_accuracy_buff_timer = $E1BA

.segment "CODE"
.org $EB04
apply_speed_up_spell:
    ldx $85
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    lda a:object_buff_flags,X
    .a8
    and #$C3
    .a8
    ora #$14
    sta a:object_buff_flags,X
    lda $9C
    sta a:object_evasion_buff_timer,X
    sta a:object_accuracy_buff_timer,X
    rts

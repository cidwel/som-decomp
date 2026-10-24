; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

calculate_spell_attack_roll = $E8C0

object_buff_flags = $E1B0
object_defence_buff_timer = $E1BC

.segment "CODE"
.org $EB20
apply_defender_spell:
    ldx $85
    .a8
    lda #$04
    sta $8F
    jsr calculate_spell_attack_roll
    lda a:object_buff_flags,X
    .a8
    and #$FC
    .a8
    ora #$01
    sta a:object_buff_flags,X
    lda $9C
    sta a:object_defence_buff_timer,X
    rts

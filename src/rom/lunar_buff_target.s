; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_buff_flags = $E1B0
object_evasion_buff_timer = $E1BB
object_accuracy_buff_timer = $E1BA
object_defence_buff_timer = $E1BC
object_attack_buff_timer = $E1B7

.segment "CODE"
.org $EF48
lunar_buff_target:
    ldx $85
    lda $9C
    sta a:object_attack_buff_timer,X
    sta a:object_accuracy_buff_timer,X
    sta a:object_evasion_buff_timer,X
    sta a:object_defence_buff_timer,X
    .a8
    lda #$55
    sta a:object_buff_flags,X
    rts

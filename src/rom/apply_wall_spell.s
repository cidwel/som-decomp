; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c8ea69 = $EA69

object_secondary_buff_flags = $E1B1
object_wall_hits = $E1B8

.segment "CODE"
.org $ED53
apply_wall_spell:
    ldx $85
    jsr routine_c8ea69
    lda a:object_secondary_buff_flags,X
    .a8
    ora #$40
    sta a:object_secondary_buff_flags,X
    lda $9D
    inc
    inc
    sta a:object_wall_hits,X
    rts

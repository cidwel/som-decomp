; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_actor_kind = $E1FB
object_cast_element_index = $E177
object_element_spell_progress = $E1D8
object_packed_spell_levels = $E1C4

.segment "CODE"
.org $4E6E
read_actor_element_spell_level:
    lda a:object_actor_kind,Y
    bmi read_actor_element_spell_level_d04e7e
    lda a:object_packed_spell_levels,Y
    sta $9D
    lda a:object_element_spell_progress,Y
    sta $9E
    rts
read_actor_element_spell_level_d04e7e:
    ldy $83
    sty $CC
    lda a:object_cast_element_index,Y
    sta $CC
    ldy $CC
    lda a:object_element_spell_progress,Y
    sta $9E
    lsr $CC
    php
    ldy $CC
    lda a:object_packed_spell_levels,Y
    sta $D0
    plp
    bcs read_actor_element_spell_level_d04ea3
    lsr $D0
    lsr $D0
    lsr $D0
    lsr $D0
read_actor_element_spell_level_d04ea3:
    lda $D0
    .a8
    and #$0F
    sta $9D
    ldy $83
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_spell_target_count = $E176

.segment "CODE"
.org $EA69
divide_spell_level_by_target_count:
    .a8
    lda #$00
    sta f:$004205
    lda $9D
    sta f:$004204
    lda a:object_spell_target_count,Y
    sta f:$004206
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    lda f:$004214
    sta $9D
    rts

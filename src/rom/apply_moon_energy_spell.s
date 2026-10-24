; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c8ea69 = $EA69

object_critical_and_saber_level = $E1AE

.segment "CODE"
.org $ECD1
apply_moon_energy_spell:
    ldx $85
    jsr routine_c8ea69
    lda $9D
    inc
    asl
    asl
    asl
    asl
    sta $A4
    lda a:object_critical_and_saber_level,X
    .a8
    and #$0F
    ora $A4
    sta a:object_critical_and_saber_level,X
    rts

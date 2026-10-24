; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16


object_maximum_mp = $E187

.segment "CODE"
.org $EFE6
lunar_halve_caster_maximum_mp:
    ldy $83
    lda a:object_maximum_mp,Y
    lsr
    sta a:object_maximum_mp,Y
    rts

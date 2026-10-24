; Recovered Secret of Mana USA spell routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16




.segment "CODE"
.org $EABC
moon_saber_entry:
    .a8
    lda #$40
    pha

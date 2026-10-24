; Recovered Secret of Mana USA routine; behaviour documented in docs/spells-non-damage.md.
.setcpu "65816"
.smart
.a8
.i16




.segment "CODE"
.org $E88E
apply_spell_row_status:
    rep #$20
    .i16
    ldy #$2ADD
    lda [$DC],Y
    ldy $83
    sta $9A
    sep #$20
    jsl f:$C8E301
    rts

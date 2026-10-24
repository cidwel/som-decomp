; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c29445 = $9445

.segment "CODE"
.org $942E
cast_native7f_spell_021c:
    .a16
    lda #$021C
    bra routine_c29445

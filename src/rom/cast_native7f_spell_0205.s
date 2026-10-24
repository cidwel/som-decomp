; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c29445 = $9445

.segment "CODE"
.org $9429
cast_native7f_spell_0205:
    .a16
    lda #$0205
    bra routine_c29445

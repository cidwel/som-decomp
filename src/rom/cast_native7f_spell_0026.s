; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c29445 = $9445

.segment "CODE"
.org $943D
cast_native7f_spell_0026:
    .a16
    lda #$0026
    bra routine_c29445

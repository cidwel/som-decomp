; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-spells.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c29445 = $9445

.segment "CODE"
.org $9424
cast_native7f_spell_0222:
    .a16
    lda #$0222
    bra routine_c29445

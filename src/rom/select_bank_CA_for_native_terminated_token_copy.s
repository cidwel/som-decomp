; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-detail.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c76ac3 = $6AC3

.segment "CODE"
.org $6AB7
select_bank_CA_for_native_terminated_token_copy:
    phb
    .a8
    lda #$CA
    pha
    plb
    bra routine_c76ac3

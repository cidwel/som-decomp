; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-spell-item-detail.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $6ABE
select_bank_C7_and_copy_native_terminated_tokens:
    phb
    .a8
    lda #$C7
    pha
    plb
select_bank_C7_and_copy_native_terminated_tokens_c76ac3:
    lda a:$0000,Y
    beq select_bank_C7_and_copy_native_terminated_tokens_c76ad0
    sta f:$7E9C00,X
    inx
    iny
    bra select_bank_C7_and_copy_native_terminated_tokens_c76ac3
select_bank_C7_and_copy_native_terminated_tokens_c76ad0:
    plb
    rts

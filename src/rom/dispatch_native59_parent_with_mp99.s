; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-header.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8455
dispatch_native59_parent_with_mp99:
    .a16
    lda #$6363
    sta a:$0186,X
    lda a:$0094,X
    asl
    tax
    jmp ($8463,X)

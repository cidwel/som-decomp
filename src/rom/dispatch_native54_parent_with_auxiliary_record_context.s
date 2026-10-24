; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-header.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $44A8
dispatch_native54_parent_with_auxiliary_record_context:
    lda $89
    sec
    .a16
    sbc #$F800
    tay
    lda a:$0094,X
    asl
    tax
    jmp ($44B7,X)

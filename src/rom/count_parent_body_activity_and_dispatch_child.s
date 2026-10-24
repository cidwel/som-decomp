; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native54-body.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4AFB
count_parent_body_activity_and_dispatch_child:
    lda a:$00B0,X
    tax
    inc a:$00BA,X
    lda $89
    sec
    .a16
    sbc #$F800
    tay
    ldx $87
    lda a:$0094,X
    asl
    tax
    jmp ($4B13,X)

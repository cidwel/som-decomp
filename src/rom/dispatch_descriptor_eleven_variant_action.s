; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-eleven.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8C20
dispatch_descriptor_eleven_variant_action:
    lda a:$0042,X
    asl
    tax
    jmp ($8C28,X)

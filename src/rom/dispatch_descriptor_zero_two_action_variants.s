; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-zero.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3D8C
dispatch_descriptor_zero_two_action_variants:
    lda a:$0042,X
    asl
    tax
    jmp ($3D94,X)

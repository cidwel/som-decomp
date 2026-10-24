; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $604B
dispatch_descriptor_five_state_choice:
    lda a:$007E,X
    asl
    tax
    jmp ($6053,X)

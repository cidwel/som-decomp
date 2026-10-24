; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $60BB
dispatch_descriptor_five_action_choice:
    lda a:$007E,X
    asl
    tax
    jmp ($60C3,X)

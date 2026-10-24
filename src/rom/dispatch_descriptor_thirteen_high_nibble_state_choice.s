; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-thirteen.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $66D9
dispatch_descriptor_thirteen_high_nibble_state_choice:
    lda a:$007E,X
    lsr
    lsr
    lsr
    lsr
    asl
    tax
    jmp ($66E5,X)

; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $77BF
dispatch_descriptor_ten_chain_end_eight_states:
    lda a:$0094,X
    asl
    tax
    jmp ($77C7,X)

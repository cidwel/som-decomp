; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-ten-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $77A7
dispatch_descriptor_ten_chain_link_eight_states:
    lda a:$0094,X
    asl
    tax
    jmp ($77AF,X)

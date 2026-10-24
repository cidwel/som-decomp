; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-fourteen.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $5193
dispatch_descriptor_fourteen_low_byte_state_phase:
    lda a:$007E,X
    .a16
    and #$00FF
    asl
    tax
    jmp ($519E,X)

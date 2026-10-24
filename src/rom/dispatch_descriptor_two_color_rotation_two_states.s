; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-two-palette.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $415D
dispatch_descriptor_two_color_rotation_two_states:
    lda a:$0094,X
    asl
    tax
    jmp ($4165,X)

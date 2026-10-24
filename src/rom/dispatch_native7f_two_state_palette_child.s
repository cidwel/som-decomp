; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native7f-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $986D
dispatch_native7f_two_state_palette_child:
    lda a:$0094,X
    asl
    tax
    jmp ($9875,X)

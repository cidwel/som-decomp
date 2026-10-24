; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8A91
dispatch_native59_palette_cycle:
    lda a:$0094,X
    asl
    tax
    jmp ($8A99,X)

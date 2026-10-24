; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8999
dispatch_native59_child_radius_convergence:
    lda a:$0042,X
    asl
    tax
    jmp ($89A1,X)

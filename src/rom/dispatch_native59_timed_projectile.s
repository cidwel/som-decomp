; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-children.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $89D1
dispatch_native59_timed_projectile:
    lda a:$0094,X
    asl
    tax
    jmp ($89D9,X)

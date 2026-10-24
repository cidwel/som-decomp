; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-grandchildren.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $821B
dispatch_native58_right_attack_child:
    lda a:$0094,X
    asl
    tax
    jmp ($8223,X)

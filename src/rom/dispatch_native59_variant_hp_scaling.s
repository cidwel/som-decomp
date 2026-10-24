; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native59-setup.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $876C
dispatch_native59_variant_hp_scaling:
    lda a:$0042,X
    asl
    tax
    jmp ($8774,X)

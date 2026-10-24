; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-grandchildren.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $8295
dispatch_right_attack_by_variant_and_order:
    asl
    sta $95
    lda a:$0042,X
    asl
    asl
    clc
    adc $95
    tax
    jmp ($EFDC,X)

; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-parent-actions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7C9D
dispatch_native58_variant_action:
    ldx $87
    lda a:$0042,X
    asl
    tax
    jmp ($7CA7,X)

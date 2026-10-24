; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native58-parent-actions.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $7C5F
dispatch_native58_body_part_order:
    lda a:$00B0,X
    asl
    tax
    jmp ($7C67,X)

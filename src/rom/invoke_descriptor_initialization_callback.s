; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $35BF
invoke_descriptor_initialization_callback:
    ldx $87
    lda a:$00B4,X
    beq invoke_descriptor_initialization_callback_c235cb
    sta $0C
    jmp ($020C)
invoke_descriptor_initialization_callback_c235cb:
    rts

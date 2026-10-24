; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $360C
invoke_descriptor_chooser_callback:
    lda a:$00B6,X
    beq invoke_descriptor_chooser_callback_c23616
    sta $0C
    jmp ($020C)
invoke_descriptor_chooser_callback_c23616:
    rts

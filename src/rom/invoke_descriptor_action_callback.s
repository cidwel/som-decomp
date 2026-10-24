; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3617
invoke_descriptor_action_callback:
    lda a:$00B8,X
    beq invoke_descriptor_action_callback_c23621
    sta $0C
    jmp ($020C)
invoke_descriptor_action_callback_c23621:
    rts

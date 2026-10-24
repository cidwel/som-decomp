; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $3622
invoke_descriptor_hurt_callback:
    lda a:$00BA,X
    beq invoke_descriptor_hurt_callback_c2362c
    sta $0C
    jmp ($020C)
invoke_descriptor_hurt_callback_c2362c:
    rts

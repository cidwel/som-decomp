; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-descriptor-five-terminal.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $600F
advance_descriptor_five_terminal_visibility_and_disable_linked_effect_after_tick24:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0018
    bcc advance_descriptor_five_terminal_visibility_and_disable_linked_effect_after_tick24_c2602b
    stz a:$0096,X
    inc a:$0094,X
    lda a:$0070,X
    .a16
    ora #$0004
    sta a:$0070,X
    stz a:$00A7,X
advance_descriptor_five_terminal_visibility_and_disable_linked_effect_after_tick24_c2602b:
    clc
    rts

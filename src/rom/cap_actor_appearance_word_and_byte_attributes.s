; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16


.segment "CODE"
.org $4BF9
cap_actor_appearance_word_and_byte_attributes:
    rep #$20
    .a16
    lda #$03E7
    cmp a:$E1A8,X
    bcs cap_actor_appearance_word_and_byte_attributes_c04c06
    sta a:$E1A8,X
cap_actor_appearance_word_and_byte_attributes_c04c06:
    .a16
    lda #$03E7
    cmp a:$E1A5,X
    bcs cap_actor_appearance_word_and_byte_attributes_c04c11
    sta a:$E1A5,X
cap_actor_appearance_word_and_byte_attributes_c04c11:
    sep #$20
    .a8
    lda #$63
    cmp a:$E1A4,X
    bcs cap_actor_appearance_word_and_byte_attributes_c04c1d
    sta a:$E1A4,X
cap_actor_appearance_word_and_byte_attributes_c04c1d:
    .a8
    lda #$63
    cmp a:$E1A7,X
    bcs cap_actor_appearance_word_and_byte_attributes_c04c27
    sta a:$E1A7,X
cap_actor_appearance_word_and_byte_attributes_c04c27:
    rts

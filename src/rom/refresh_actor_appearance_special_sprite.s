; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

cap_actor_appearance_word_and_byte_attributes = $4BF9
classify_actor_appearance_from_sprite = $47DD
load_actor_base_attributes_for_appearance = $474F
prepare_actor_appearance_table_pointers = $4860
reduce_and_clamp_actor_appearance_attributes = $4BBE
reorder_actor_attribute_bit_pairs = $4A53

.segment "CODE"
.org $45E6
refresh_actor_appearance_special_sprite:
    jsr classify_actor_appearance_from_sprite
    jsr load_actor_base_attributes_for_appearance
    jsr prepare_actor_appearance_table_pointers
    jsr reduce_and_clamp_actor_appearance_attributes
    jsr reorder_actor_attribute_bit_pairs
    lda a:$E1AB,X
    .a8
    ora #$12
    sta a:$E1AB,X
    txy
    lda a:$E1E3,X
    sta f:$004202
    .a8
    lda #$07
    sta f:$004203
    nop
    nop
    nop
    rep #$20
    lda f:$004216
    tax
    lda f:$D0BDC5,X
    sta a:$E199,Y
    lda f:$D0BDC1,X
    sta a:$E194,Y
    sep #$20
    lda f:$D0BDC3,X
    sta a:$E197,Y
    lda f:$D0BDC4,X
    clc
    adc a:$E188,Y
    sta a:$E198,Y
    lda f:$D0BDC7,X
    sta a:$E1F7,Y
    lda a:$E1C0,Y
    sta a:$E19C,Y
    sta a:$E19B,Y
    tyx
    jsr cap_actor_appearance_word_and_byte_attributes
    plp
    plb
    pld
    rtl

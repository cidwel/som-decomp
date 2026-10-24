; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-remaining.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_actor_name_message_token = $5C06
append_rom_message_text = $5C2A

.segment "CODE"
.org $5921
enqueue_new_spell_buff_notices:
    lda a:$E1E7,X
    .a8
    cmp #$83
    bcc enqueue_new_spell_buff_notices_c05929
    rtl
enqueue_new_spell_buff_notices_c05929:
    sty $CC
    .a8
    lda #$07
    sta $AA
    stz $AB
enqueue_new_spell_buff_notices_c05931:
    clc
    rol $CC
    bcs enqueue_new_spell_buff_notices_c0593b
enqueue_new_spell_buff_notices_c05936:
    dec $AA
    bpl enqueue_new_spell_buff_notices_c05931
    rtl
enqueue_new_spell_buff_notices_c0593b:
    rep #$20
    lda $AA
    asl
    tax
    lda f:$C05E49,X
    pha
    sep #$20
    jsr allocate_message_queue_line
    dey
    lda a:$FE00,Y
    lsr
    sta a:$FE00,Y
    iny
    ldx $85
    jsr append_actor_name_message_token
    plx
    jsr append_rom_message_text
    bra enqueue_new_spell_buff_notices_c05936

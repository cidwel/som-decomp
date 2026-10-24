; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-spell-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_actor_name_message_token = $5C06
append_rom_message_text = $5C2A
routine_c05b34 = $5B34

.segment "CODE"
.org $5B75
enqueue_spell_element_level_up_notice:
    stx $B4
    jsr allocate_message_queue_line
    jsr append_actor_name_message_token
    .i16
    ldx #$6279
    jsr append_rom_message_text
    jsr allocate_message_queue_line
    .a8
    lda #$56
    sta a:$FE00,Y
    iny
    ldx $B4
    lda a:$E177,X
    clc
    .a8
    adc #$2A
    sta a:$FE00,Y
    iny
    .i16
    ldx #$6256
    jsr append_rom_message_text
    lda $9D
    jsr routine_c05b34
    rtl

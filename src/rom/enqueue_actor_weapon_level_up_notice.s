; Recovered Secret of Mana USA routine; behaviour documented in docs/rom-combat.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_message_queue_line = $5CCF
append_actor_name_message_token = $5C06
append_rom_message_text = $5C2A
routine_c05b34 = $5B34

.segment "CODE"
.org $5B40
enqueue_actor_weapon_level_up_notice:
    stx $B4
    jsr allocate_message_queue_line
    jsr append_actor_name_message_token
    .i16
    ldx #$6265
    jsr append_rom_message_text
    jsr allocate_message_queue_line
    ldx $B4
    lda a:$E19C,X
    pha
    lda a:$E1E4,X
    rep #$20
    .a16
    and #$0007
    asl
    tax
    lda f:$C05DFB,X
    tax
    sep #$20
    jsr append_rom_message_text
    .i16
    ldx #$6256
    jsr append_rom_message_text
    pla
    jmp routine_c05b34

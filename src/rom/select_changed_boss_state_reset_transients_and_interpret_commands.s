; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-state-engine-vm.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_boss_state_byte_command_through_original_twenty_two_word_table = $37C7

.segment "CODE"
.org $377A
select_changed_boss_state_reset_transients_and_interpret_commands:
    cmp a:$007A,X
    beq select_changed_boss_state_reset_transients_and_interpret_commands_c237c6
    sta a:$007A,X
    asl
    tay
    .a16
    lda #$C200
    sta $31
    lda a:$0076,X
    sta $30
    lda [$30],Y
    sta $30
    stz a:$0090,X
    stz a:$003A,X
    stz a:$003C,X
    stz a:$003E,X
    stz a:$0040,X
    stz a:$00C4,X
    stz a:$00C6,X
    stz a:$0014,X
    stz a:$0048,X
    stz a:$004A,X
    stz a:$007C,X
    .i16
    ldy #$0000
select_changed_boss_state_reset_transients_and_interpret_commands_c237b6:
    lda [$30],Y
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq select_changed_boss_state_reset_transients_and_interpret_commands_c237c6
    iny
    jsr dispatch_boss_state_byte_command_through_original_twenty_two_word_table
    bra select_changed_boss_state_reset_transients_and_interpret_commands_c237b6
select_changed_boss_state_reset_transients_and_interpret_commands_c237c6:
    rts

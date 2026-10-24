; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16

choose_next_boss_script_list = $3551
select_changed_boss_state_reset_transients_and_interpret_commands = $377A
update_boss_action_and_completion = $3594

.segment "CODE"
.org $3561
consume_boss_state_list_and_bootstrap_vm:
    ldx $87
    .a16
    lda #$C200
    sta $31
    lda a:$00B0,X
    sta $30
    ldy a:$00B2,X
    lda [$30],Y
    .a16
    and #$00FF
    .a16
    cmp #$00FF
    beq consume_boss_state_list_and_bootstrap_vm_c2358e
    iny
    sty $36
    jsr select_changed_boss_state_reset_transients_and_interpret_commands
    lda $36
    sta a:$00B2,X
    stz a:$0096,X
    inc a:$0094,X
    jmp update_boss_action_and_completion
consume_boss_state_list_and_bootstrap_vm_c2358e:
    dec a:$0094,X
    jmp choose_next_boss_script_list

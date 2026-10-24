; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16

begin_boss_death_initialization_when_control_and_lock_clear = $0AFD
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
invoke_descriptor_action_callback = $3617
invoke_descriptor_chooser_callback = $360C
test_boss_negative_status_word = $34B0

.segment "CODE"
.org $35CC
choose_script_with_hp_action_and_nonlocal_death_gate:
    lda a:$0082,X
    .a16
    cmp #$0002
    bne choose_script_with_hp_action_and_nonlocal_death_gate_c235e3
    jsr test_boss_negative_status_word
    bcc choose_script_with_hp_action_and_nonlocal_death_gate_c235e3
    .a16
    lda #$0004
    sta a:$0094,X
    pla
    jmp begin_boss_death_initialization_when_control_and_lock_clear
choose_script_with_hp_action_and_nonlocal_death_gate_c235e3:
    ldx $87
    lda a:$0082,X
    bne choose_script_with_hp_action_and_nonlocal_death_gate_c235f0
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    stz a:$00AD,X
choose_script_with_hp_action_and_nonlocal_death_gate_c235f0:
    lda a:$00AD,X
    cmp a:$002D,X
    bcc choose_script_with_hp_action_and_nonlocal_death_gate_c23602
    stz a:$0082,X
    jsr invoke_descriptor_action_callback
    bcc choose_script_with_hp_action_and_nonlocal_death_gate_c2360b
    ldx $87
choose_script_with_hp_action_and_nonlocal_death_gate_c23602:
    .a16
    lda #$0001
    sta a:$0082,X
    jmp invoke_descriptor_chooser_callback
choose_script_with_hp_action_and_nonlocal_death_gate_c2360b:
    rts

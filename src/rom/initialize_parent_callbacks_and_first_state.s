; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-actor-controller.md.
.setcpu "65816"
.smart
.a8
.i16

allocate_parent_linked_boss_effect_and_copy_coordinates = $3385
consume_boss_state_list_and_bootstrap_vm = $3561
derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction = $3372
invoke_descriptor_initialization_callback = $35BF

.segment "CODE"
.org $3512
initialize_parent_callbacks_and_first_state:
    ldx $87
    jsr derive_boss_hp_gate_from_byte_189_with_wrapped_subtraction
    stz a:$00AD,X
    .a16
    lda #$00FF
    sta a:$007A,X
    lda a:$00A7,X
    beq initialize_parent_callbacks_and_first_state_c23528
    jsr allocate_parent_linked_boss_effect_and_copy_coordinates
initialize_parent_callbacks_and_first_state_c23528:
    jsr invoke_descriptor_initialization_callback
    ldx $87
    lda a:$00BC,X
    sta a:$00B0,X
    stz a:$00B2,X
    .a16
    lda #$0002
    sta a:$0094,X
    stz a:$0080,X
    stz a:$0014,X
    stz a:$0048,X
    stz a:$004A,X
    .a16
    lda #$0001
    sta a:$0082,X
    jmp consume_boss_state_list_and_bootstrap_vm

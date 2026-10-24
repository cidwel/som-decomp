; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-alternate-death.md.
.setcpu "65816"
.smart
.a8
.i16

create_boss_terminal_visual_effect_pair = $3A9A
mark_controller_and_request_numeric_boss_death_event = $0C11
rotate_fourteen_colors_in_each_selected_boss_palette = $0C89
tail_call_selected_alternate_death_callback = $0BC9

.segment "CODE"
.org $0BCE
advance_alternate_boss_death_callback_effects_and_event_gates:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0080
    bcs advance_alternate_boss_death_callback_effects_and_event_gates_c20bed
    .a16
    cmp #$0008
    bne advance_alternate_boss_death_callback_effects_and_event_gates_c20be8
    lda a:$0078,X
    beq advance_alternate_boss_death_callback_effects_and_event_gates_c20be5
    jsr tail_call_selected_alternate_death_callback
advance_alternate_boss_death_callback_effects_and_event_gates_c20be5:
    jsr create_boss_terminal_visual_effect_pair
advance_alternate_boss_death_callback_effects_and_event_gates_c20be8:
    jsr rotate_fourteen_colors_in_each_selected_boss_palette
    clc
    rts
advance_alternate_boss_death_callback_effects_and_event_gates_c20bed:
    lda a:$00D9
    ora a:$00DA
    ora a:$00DB
    .a16
    bit #$0080
    bne advance_alternate_boss_death_callback_effects_and_event_gates_c20c0f
    lda a:$1D04
    .a16
    bit #$0020
    bne advance_alternate_boss_death_callback_effects_and_event_gates_c20c0f
    ldx $87
    lda a:$0072,X
    beq advance_alternate_boss_death_callback_effects_and_event_gates_c20c0d
    jsr mark_controller_and_request_numeric_boss_death_event
advance_alternate_boss_death_callback_effects_and_event_gates_c20c0d:
    sec
    rts
advance_alternate_boss_death_callback_effects_and_event_gates_c20c0f:
    clc
    rts

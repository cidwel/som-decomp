; Recovered Secret of Mana USA routine; behaviour documented in docs/boss-native-linked-death-phases.md.
.setcpu "65816"
.smart
.a8
.i16

create_boss_terminal_visual_effect_pair = $3A9A
mark_controller_and_request_numeric_boss_death_event = $0C11
rotate_fourteen_colors_in_each_selected_boss_palette = $0C89

.segment "CODE"
.org $0B50
wait_for_boss_death_controller_event_gates:
    ldx $87
    lda a:$0096,X
    .a16
    cmp #$0080
    bcs wait_for_boss_death_controller_event_gates_c20b67
    .a16
    cmp #$0008
    bne wait_for_boss_death_controller_event_gates_c20b62
    jsr create_boss_terminal_visual_effect_pair
wait_for_boss_death_controller_event_gates_c20b62:
    jsr rotate_fourteen_colors_in_each_selected_boss_palette
    clc
    rts
wait_for_boss_death_controller_event_gates_c20b67:
    lda a:$00D9
    ora a:$00DA
    ora a:$00DB
    .a16
    bit #$0080
    bne wait_for_boss_death_controller_event_gates_c20b89
    lda a:$1D04
    .a16
    bit #$0020
    bne wait_for_boss_death_controller_event_gates_c20b89
    ldx $87
    lda a:$0072,X
    beq wait_for_boss_death_controller_event_gates_c20b87
    jsr mark_controller_and_request_numeric_boss_death_event
wait_for_boss_death_controller_event_gates_c20b87:
    sec
    rts
wait_for_boss_death_controller_event_gates_c20b89:
    clc
    rts

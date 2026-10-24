; Recovered Secret of Mana USA routine; behaviour documented in docs/hero-controller-schedule.md.
.setcpu "65816"
.smart
.a8
.i16

advance_hero_charge_input_and_restore_byte_accumulator = $B32A
advance_selected_hero_charge_timing_and_publish_native_gauge = $B330
consume_controller_selected_deferred_attack_or_begin_attack = $B21C
routine_02b665 = $2B665
scan_controller_actor_contacts_and_dispatch_interaction_or_attack = $B851

.segment "CODE"
.org $B799
schedule_controller_interaction_charge_and_deferred_attacks:
    jsl f:routine_02b665
    lda $F1
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b7a2
    rts
schedule_controller_interaction_charge_and_deferred_attacks_c0b7a2:
    sep #$30
    lda $D9
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b7c9
    bmi schedule_controller_interaction_charge_and_deferred_attacks_c0b7c9
    .a8
    lda #$08
    trb $CC
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b7b7
    lda $D9
    jsr scan_controller_actor_contacts_and_dispatch_interaction_or_attack
    bra schedule_controller_interaction_charge_and_deferred_attacks_c0b7c9
schedule_controller_interaction_charge_and_deferred_attacks_c0b7b7:
    bit $ED
    bpl schedule_controller_interaction_charge_and_deferred_attacks_c0b7c9
    lda $D9
    bit $43
    bpl schedule_controller_interaction_charge_and_deferred_attacks_c0b7c6
    jsr advance_selected_hero_charge_timing_and_publish_native_gauge
    bra schedule_controller_interaction_charge_and_deferred_attacks_c0b7c9
schedule_controller_interaction_charge_and_deferred_attacks_c0b7c6:
    jsr consume_controller_selected_deferred_attack_or_begin_attack
schedule_controller_interaction_charge_and_deferred_attacks_c0b7c9:
    sep #$30
    lda $DA
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b7f0
    bmi schedule_controller_interaction_charge_and_deferred_attacks_c0b7f0
    .a8
    lda #$08
    trb $CD
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b7de
    lda $DA
    jsr scan_controller_actor_contacts_and_dispatch_interaction_or_attack
    bra schedule_controller_interaction_charge_and_deferred_attacks_c0b7f0
schedule_controller_interaction_charge_and_deferred_attacks_c0b7de:
    bit $ED
    bpl schedule_controller_interaction_charge_and_deferred_attacks_c0b7f0
    lda $DA
    bit $45
    bpl schedule_controller_interaction_charge_and_deferred_attacks_c0b7ed
    jsr advance_selected_hero_charge_timing_and_publish_native_gauge
    bra schedule_controller_interaction_charge_and_deferred_attacks_c0b7f0
schedule_controller_interaction_charge_and_deferred_attacks_c0b7ed:
    jsr consume_controller_selected_deferred_attack_or_begin_attack
schedule_controller_interaction_charge_and_deferred_attacks_c0b7f0:
    sep #$30
    lda $DB
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b817
    bmi schedule_controller_interaction_charge_and_deferred_attacks_c0b817
    .a8
    lda #$08
    trb $CE
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b805
    lda $DB
    jsr scan_controller_actor_contacts_and_dispatch_interaction_or_attack
    bra schedule_controller_interaction_charge_and_deferred_attacks_c0b817
schedule_controller_interaction_charge_and_deferred_attacks_c0b805:
    bit $ED
    bpl schedule_controller_interaction_charge_and_deferred_attacks_c0b817
    lda $DB
    bit $47
    bpl schedule_controller_interaction_charge_and_deferred_attacks_c0b814
    jsr advance_selected_hero_charge_timing_and_publish_native_gauge
    bra schedule_controller_interaction_charge_and_deferred_attacks_c0b817
schedule_controller_interaction_charge_and_deferred_attacks_c0b814:
    jsr consume_controller_selected_deferred_attack_or_begin_attack
schedule_controller_interaction_charge_and_deferred_attacks_c0b817:
    sep #$20
    bit $ED
    bpl schedule_controller_interaction_charge_and_deferred_attacks_c0b850
    lda f:$7EE02C
    bne schedule_controller_interaction_charge_and_deferred_attacks_c0b82e
    lda f:$7EE085
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b82e
    .a8
    lda #$01
    jsr advance_hero_charge_input_and_restore_byte_accumulator
schedule_controller_interaction_charge_and_deferred_attacks_c0b82e:
    lda f:$7EE22C
    bne schedule_controller_interaction_charge_and_deferred_attacks_c0b83f
    lda f:$7EE285
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b83f
    .a8
    lda #$02
    jsr advance_hero_charge_input_and_restore_byte_accumulator
schedule_controller_interaction_charge_and_deferred_attacks_c0b83f:
    lda f:$7EE42C
    bne schedule_controller_interaction_charge_and_deferred_attacks_c0b850
    lda f:$7EE485
    beq schedule_controller_interaction_charge_and_deferred_attacks_c0b850
    .a8
    lda #$04
    jsr advance_hero_charge_input_and_restore_byte_accumulator
schedule_controller_interaction_charge_and_deferred_attacks_c0b850:
    rts

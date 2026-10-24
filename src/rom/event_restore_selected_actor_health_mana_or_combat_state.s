; Recovered Secret of Mana USA routine; behaviour documented in docs/event-vm-actor-recovery.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_event_opcode_or_wait_state = $E8D3
event_initialize_actor_combat_state = $EE83

.segment "CODE"
.org $EDEF
event_restore_selected_actor_health_mana_or_combat_state:
    rep #$10
    ldy $D1
    iny
    iny
    sty $D1
    ldx $D4
    lda $05
    bmi event_restore_selected_actor_health_mana_or_combat_state_c1ee2f
    .a8
    cmp #$40
    bcs event_restore_selected_actor_health_mana_or_combat_state_c1ee5a
    .a8
    and #$3F
    beq event_restore_selected_actor_health_mana_or_combat_state_c1ee0f
    .a8
    cmp #$04
    bcs event_restore_selected_actor_health_mana_or_combat_state_c1ee19
    dec
    asl
    xba
    .a8
    lda #$00
    tax
event_restore_selected_actor_health_mana_or_combat_state_c1ee0f:
    rep #$20
    lda a:$E184,X
    sta a:$E182,X
    bra event_restore_selected_actor_health_mana_or_combat_state_c1ee57
event_restore_selected_actor_health_mana_or_combat_state_c1ee19:
    rep #$20
    lda a:$E184
    sta a:$E182
    lda a:$E384
    sta a:$E382
    lda a:$E584
    sta a:$E582
    bra event_restore_selected_actor_health_mana_or_combat_state_c1ee57
event_restore_selected_actor_health_mana_or_combat_state_c1ee2f:
    .a8
    and #$7F
    beq event_restore_selected_actor_health_mana_or_combat_state_c1ee3d
    .a8
    cmp #$04
    bcs event_restore_selected_actor_health_mana_or_combat_state_c1ee45
    dec
    asl
    xba
    .a8
    lda #$00
    tax
event_restore_selected_actor_health_mana_or_combat_state_c1ee3d:
    lda a:$E187,X
    sta a:$E186,X
    bra event_restore_selected_actor_health_mana_or_combat_state_c1ee57
event_restore_selected_actor_health_mana_or_combat_state_c1ee45:
    lda a:$E187
    sta a:$E186
    lda a:$E387
    sta a:$E386
    lda a:$E587
    sta a:$E586
event_restore_selected_actor_health_mana_or_combat_state_c1ee57:
    brl dispatch_native_event_opcode_or_wait_state
event_restore_selected_actor_health_mana_or_combat_state_c1ee5a:
    .a8
    and #$3F
    beq event_restore_selected_actor_health_mana_or_combat_state_c1ee68
    .a8
    cmp #$04
    bcs event_restore_selected_actor_health_mana_or_combat_state_c1ee6e
    dec
    asl
    xba
    .a8
    lda #$00
    tax
event_restore_selected_actor_health_mana_or_combat_state_c1ee68:
    jsr event_initialize_actor_combat_state
    brl dispatch_native_event_opcode_or_wait_state
event_restore_selected_actor_health_mana_or_combat_state_c1ee6e:
    .i16
    ldx #$0000
    jsr event_initialize_actor_combat_state
    .i16
    ldx #$0200
    jsr event_initialize_actor_combat_state
    .i16
    ldx #$0400
    jsr event_initialize_actor_combat_state
    brl dispatch_native_event_opcode_or_wait_state

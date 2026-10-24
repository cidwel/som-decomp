; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-cast-restore.md.
.setcpu "65816"
.smart
.a8
.i16

prepare_cast_actor_context_long = $C0395E
rebuild_actor_attributes_native = $C04530
restore_combat_context_and_return_long = $4000
routine_018000 = $18000
select_actor_status_attack_row_long = $C8E5FB

.segment "CODE"
.org $3F94
finish_previous_cast_and_request_followup_event:
    phd
    phb
    php
    jsl f:prepare_cast_actor_context_long
    .a8
    lda #$00
    sta a:$E1F8,X
    sta a:$E1F8,Y
    lda a:$E1FB,Y
    .a8
    bit #$10
    beq finish_previous_cast_and_request_followup_event_c03fbe
    lda a:$E170,X
    sta a:$E181,Y
    rep #$20
    lda a:$E03E,Y
    .a16
    and #$0FFF
    jsl f:routine_018000
    bra restore_combat_context_and_return_long
finish_previous_cast_and_request_followup_event_c03fbe:
    ldx $85
    lda a:$E170,X
    .a8
    cmp #$20
    beq finish_previous_cast_and_request_followup_event_c03fcd
    .a8
    cmp #$23
    beq finish_previous_cast_and_request_followup_event_c03fcd
    bra restore_combat_context_and_return_long
finish_previous_cast_and_request_followup_event_c03fcd:
    lda a:$CC79
    bne finish_previous_cast_and_request_followup_event_c03fd4
    bra restore_combat_context_and_return_long
finish_previous_cast_and_request_followup_event_c03fd4:
    lda a:$CC78
    bne finish_previous_cast_and_request_followup_event_c03fdb
    bra restore_combat_context_and_return_long
finish_previous_cast_and_request_followup_event_c03fdb:
    .i16
    ldx #$0000
    lda a:$E1E8
    .a8
    cmp #$11
    beq finish_previous_cast_and_request_followup_event_c03fea
    sta a:$CC77
    .a8
    lda #$11
finish_previous_cast_and_request_followup_event_c03fea:
    sta a:$E1E8
    jsl f:select_actor_status_attack_row_long
    jsl f:rebuild_actor_attributes_native
    rep #$20
    .a16
    lda #$0008
    jsl f:routine_018000
    bra restore_combat_context_and_return_long

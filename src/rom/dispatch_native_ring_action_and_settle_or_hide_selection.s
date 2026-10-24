; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-selection-normal.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_seven_category_ring_action_and_mark_equipment_pair = $71A2
hide_native_menu_icon_oam_objects = $D0C83F
poll_and_update_native_ring_until_confirm_and_cancel_are_released = $6896
routine_c06875 = $6875

.segment "CODE"
.org $68A7
dispatch_native_ring_action_and_settle_or_hide_selection:
    jsr dispatch_native_seven_category_ring_action_and_mark_equipment_pair
    sep #$30
    lda a:$1826
    bne dispatch_native_ring_action_and_settle_or_hide_selection_c068b6
    jsl f:hide_native_menu_icon_oam_objects
    rts
dispatch_native_ring_action_and_settle_or_hide_selection_c068b6:
    .a8
    lda #$40
    bit a:$1804
    bne dispatch_native_ring_action_and_settle_or_hide_selection_c068e0
    .a8
    lda #$10
    bit a:$1804
    bne dispatch_native_ring_action_and_settle_or_hide_selection_c068d4
    lda a:$1803
    .a8
    bit #$40
    bne dispatch_native_ring_action_and_settle_or_hide_selection_c068d4
    .a8
    bit #$02
    beq routine_c06875
    jsr poll_and_update_native_ring_until_confirm_and_cancel_are_released
    bra dispatch_native_ring_action_and_settle_or_hide_selection_c068e0
dispatch_native_ring_action_and_settle_or_hide_selection_c068d4:
    sep #$20
    lda a:$19F0
    .a8
    cmp #$C0
    beq dispatch_native_ring_action_and_settle_or_hide_selection_c068e0
    jsr poll_and_update_native_ring_until_confirm_and_cancel_are_released
dispatch_native_ring_action_and_settle_or_hide_selection_c068e0:
    sep #$20
    .a8
    lda #$02
    trb a:$1803
    rep #$30
    rts

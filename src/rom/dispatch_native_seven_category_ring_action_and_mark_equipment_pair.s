; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-ring-action-dispatch.md.
.setcpu "65816"
.smart
.a8
.i16

dispatch_native_shop_action_to_buy_sell_or_weapon_upgrade = $7AB5
mark_selected_native_ring_row_and_return_owner_or_special_descriptor = $794A
reject_native_menu_row_and_clear_original_blink_records = $7594
request_native_menu_audio_0e = $D0CF08

.segment "CODE"
.org $71A2
dispatch_native_seven_category_ring_action_and_mark_equipment_pair:
    sep #$30
    .a8
    lda #$02
    trb a:$1803
    .a8
    lda #$F0
    trb a:$1804
    lda a:$1847
    beq dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071b6
    jmp dispatch_native_shop_action_to_buy_sell_or_weapon_upgrade
dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071b6:
    sep #$30
    lda a:$180A
    asl
    tax
    rep #$30
    lda a:$18A0,X
    .a16
    and #$4000
    bne dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071eb
    sep #$20
    lda a:$1809
    .a8
    cmp #$03
    bcc dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071ee
    jsl f:request_native_menu_audio_0e
    .a8
    lda #$40
    bit a:$1803
    bne dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071ee
    tsb a:$1803
    lda a:$180A
    sta a:$185C
    jsr mark_selected_native_ring_row_and_return_owner_or_special_descriptor
    sta a:$185D
    rts
dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071eb:
    jmp reject_native_menu_row_and_clear_original_blink_records
dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071ee:
    sep #$30
    stz a:$1826
    lda a:$1809
    .a8
    cmp #$04
    bcs dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071fd
    sta a:$19F0
dispatch_native_seven_category_ring_action_and_mark_equipment_pair_c071fd:
    asl
    tax
    rep #$30
    jmp ($7204,X)

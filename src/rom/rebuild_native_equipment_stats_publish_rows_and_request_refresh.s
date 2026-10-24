; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-transaction.md.
.setcpu "65816"
.smart
.a8
.i16

publish_native_menu_transaction_result_with_real_vblank_and_ring_phase = $761A
rebuild_native_equipped_actor_stats_and_cap_persistent_mana = $7A28
routine_c0760d = $760D

.segment "CODE"
.org $75E4
rebuild_native_equipment_stats_publish_rows_and_request_refresh:
    rep #$30
    lda a:$1808
    asl
    xba
    .a16
    and #$FF00
    tax
    jsr rebuild_native_equipped_actor_stats_and_cap_persistent_mana
    jsr publish_native_menu_transaction_result_with_real_vblank_and_ring_phase
    sep #$20
    lda a:$1808
    asl
    bne rebuild_native_equipment_stats_publish_rows_and_request_refresh_c075fe
    inc
rebuild_native_equipment_stats_publish_rows_and_request_refresh_c075fe:
    sta a:$19F2
    sep #$20
    lda a:$19F0
    .a8
    cmp #$02
    beq routine_c0760d

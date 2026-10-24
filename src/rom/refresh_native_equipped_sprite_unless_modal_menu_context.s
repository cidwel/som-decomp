; Recovered Secret of Mana USA routine; behaviour documented in docs/event-menu-equipment-transaction.md.
.setcpu "65816"
.smart
.a8
.i16

rebuild_native_equipment_stats_publish_rows_and_request_refresh = $75E4
refresh_native_equipped_sprite_id_and_clear_pose_offsets = $7699

.segment "CODE"
.org $759E
refresh_native_equipped_sprite_unless_modal_menu_context:
    lda a:$19F0
    bmi rebuild_native_equipment_stats_publish_rows_and_request_refresh
    lda a:$1808
    sta a:$19F2
    jsr refresh_native_equipped_sprite_id_and_clear_pose_offsets
    bra rebuild_native_equipment_stats_publish_rows_and_request_refresh

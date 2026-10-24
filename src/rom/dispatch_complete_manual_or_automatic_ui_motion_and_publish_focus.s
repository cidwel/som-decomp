; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-ui-frame-motion-chain.md.
.setcpu "65816"
.smart
.a8
.i16

advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition = $8C78
calculate_scene_camera_centers = $83C8
consume_ui_scene_buttons_and_restart_after_world_map_picker = $8779
routine_c083e7 = $83E7
routine_c08598 = $8598
routine_c08638 = $8638

.segment "CODE"
.org $83A8
dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus:
    sep #$30
    lda $8C
    beq dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus_c083b3
    jsr advance_automatic_ui_countdown_and_dispatch_radial_or_music_transition
    bra calculate_scene_camera_centers
dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus_c083b3:
    .a8
    lda #$C0
    and $FE
    ora $BF
    beq dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus_c083bc
    rts
dispatch_complete_manual_or_automatic_ui_motion_and_publish_focus_c083bc:
    jsr routine_c08598
    jsr routine_c083e7
    jsr routine_c08638
    jsr consume_ui_scene_buttons_and_restart_after_world_map_picker

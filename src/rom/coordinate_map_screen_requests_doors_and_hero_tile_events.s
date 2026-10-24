; Recovered Secret of Mana USA routine; behaviour documented in docs/map-control-frame.md.
.setcpu "65816"
.smart
.a8
.i16

audio_command_sender_public_jump = $C30004
blank_display_disable_interrupts_and_clear_windows_for_map_entry = $87C4
dispatch_selected_hero_door_action_before_diagonal_continuation = $B9C5
initialize_main_map_loop_before_native_nmi_wait = $B03F
initialize_ui_scene_and_await_two_complete_vblank_transitions = $8038
move_scene_camera_entry = $D1F9
prepare_destination_fade = $8B09
preserve_direct_page_and_run_complete_mode_seven_transition = $C64000
request_saved_map_return = $BBD1
routine_02cfb8 = $2CFB8
scan_three_hero_tile_triggers_and_request_complete_event_format = $B630
wait_for_selected_hero_door_action_to_complete = $B9B6

.segment "CODE"
.org $B4FE
coordinate_map_screen_requests_doors_and_hero_tile_events:
    sep #$30
    lda $2B
    .a8
    cmp #$27
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b518
    bit $ED
    bpl coordinate_map_screen_requests_doors_and_hero_tile_events_c0b516
    lda $42
    .a8
    eor #$10
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b518
    jsl f:routine_02cfb8
    sep #$20
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b516:
    stz $2B
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b518:
    stz $5E
    stz $5F
    lda $49
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b565
    bpl coordinate_map_screen_requests_doors_and_hero_tile_events_c0b53d
    .a8
    bit #$40
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b52d
    lda $F4
    .a8
    and #$01
    asl
    sta $5F
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b52d:
    .a8
    lda #$20
    bit $49
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b556
    lda $F4
    .a8
    and #$01
    asl
    asl
    tsb $5F
    bra coordinate_map_screen_requests_doors_and_hero_tile_events_c0b556
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b53d:
    .a8
    bit #$40
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b548
    lda $F4
    .a8
    and #$01
    asl
    sta $5E
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b548:
    .a8
    lda #$20
    bit $49
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b556
    lda $F4
    .a8
    and #$01
    asl
    asl
    tsb $5E
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b556:
    lda $49
    .a8
    bit #$1F
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b565
    dec
    sta $49
    .a8
    and #$1F
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b565
    stz $49
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b565:
    lda $95
    bpl coordinate_map_screen_requests_doors_and_hero_tile_events_c0b58a
    lda $F4
    .a8
    and #$03
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b58a
    lda $95
    .a8
    and #$7F
    sta $95
    sta a:$1E01
    .a8
    lda #$02
    sta a:$1E00
    stz a:$1E02
    lda a:$0119
    sta a:$1E03
    jsl f:audio_command_sender_public_jump
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b58a:
    sep #$20
    .a8
    lda #$04
    bit $E8
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5c1
    lda $F4
    bpl coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5c0
    .a8
    cmp #$80
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b59d
    jsr prepare_destination_fade
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b59d:
    sep #$20
    .a8
    lda #$88
    sta $86
    stz $84
    jsr move_scene_camera_entry
    sep #$20
    lda $E2
    .a8
    and #$01
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5c0
    jsr blank_display_disable_interrupts_and_clear_windows_for_map_entry
    jsl f:preserve_direct_page_and_run_complete_mode_seven_transition
    sep #$20
    .a8
    lda #$83
    sta $E8
    brl initialize_main_map_loop_before_native_nmi_wait
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5c0:
    rts
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5c1:
    bit $FF
    bpl coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5e6
    lda $E2
    .a8
    and #$01
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5c0
    sta $E2
    sta a:$4200
    lda $FF
    lsr
    bcc coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5d9
    .a8
    lda #$80
    bra coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5db
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5d9:
    .a8
    lda #$7F
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5db:
    sta $FE
    stz $FF
    .a8
    lda #$44
    sta $F8
    jmp initialize_ui_scene_and_await_two_complete_vblank_transitions
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5e6:
    bit $FF
    bvc coordinate_map_screen_requests_doors_and_hero_tile_events_c0b605
    lda $E0
    .a8
    and #$1F
    .a8
    cmp #$1F
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5f5
    brl dispatch_selected_hero_door_action_before_diagonal_continuation
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5f5:
    lda $E2
    .a8
    and #$01
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b5c0
    sta $E2
    sta a:$4200
    stz $FF
    brl initialize_main_map_loop_before_native_nmi_wait
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b605:
    lda $FF
    .a8
    bit #$20
    beq coordinate_map_screen_requests_doors_and_hero_tile_events_c0b60e
    brl wait_for_selected_hero_door_action_to_complete
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b60e:
    rep #$10
    .i16
    ldx #$0000
    lda f:$7EE04A
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b62d
    .i16
    ldx #$0200
    lda f:$7EE24A
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b62d
    .i16
    ldx #$0400
    lda f:$7EE44A
    bne coordinate_map_screen_requests_doors_and_hero_tile_events_c0b62d
    beq scan_three_hero_tile_triggers_and_request_complete_event_format
coordinate_map_screen_requests_doors_and_hero_tile_events_c0b62d:
    brl request_saved_map_return

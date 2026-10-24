; Recovered Secret of Mana USA routine; behaviour documented in docs/actor-queued-effect-requests.md.
.setcpu "65816"
.smart
.a8
.i16

consume_queued_guarded_cast_request = $DC38
consume_queued_motion_or_map_scroll_request = $DBC6
refresh_mask_selected_idle_hero_weapon_graphics = $DBAE
restore_event_screen_and_reenable_frame_interrupts = $FF3A

.segment "CODE"
.org $DB6B
dispatch_queued_actor_weapon_cast_or_motion_request:
    sep #$20
    lda a:$19F0
    bpl dispatch_queued_actor_weapon_cast_or_motion_request_c1db7d
    .a8
    cmp #$C0
    bne dispatch_queued_actor_weapon_cast_or_motion_request_c1db7c
    stz a:$1D04
    jmp restore_event_screen_and_reenable_frame_interrupts
dispatch_queued_actor_weapon_cast_or_motion_request_c1db7c:
    rts
dispatch_queued_actor_weapon_cast_or_motion_request_c1db7d:
    bne dispatch_queued_actor_weapon_cast_or_motion_request_c1db81
    bra consume_queued_motion_or_map_scroll_request
dispatch_queued_actor_weapon_cast_or_motion_request_c1db81:
    .a8
    cmp #$01
    bne dispatch_queued_actor_weapon_cast_or_motion_request_c1db88
    brl consume_queued_guarded_cast_request
dispatch_queued_actor_weapon_cast_or_motion_request_c1db88:
    .a8
    cmp #$02
    beq dispatch_queued_actor_weapon_cast_or_motion_request_c1db8d
    rts
dispatch_queued_actor_weapon_cast_or_motion_request_c1db8d:
    lda a:$19F2
    lsr
    bcc dispatch_queued_actor_weapon_cast_or_motion_request_c1db98
    .a8
    lda #$00
    jsr refresh_mask_selected_idle_hero_weapon_graphics
dispatch_queued_actor_weapon_cast_or_motion_request_c1db98:
    sep #$20
    lda a:$19F2
    .a8
    and #$02
    beq dispatch_queued_actor_weapon_cast_or_motion_request_c1dba4
    jsr refresh_mask_selected_idle_hero_weapon_graphics
dispatch_queued_actor_weapon_cast_or_motion_request_c1dba4:
    sep #$20
    lda a:$19F2
    .a8
    and #$04
    bne refresh_mask_selected_idle_hero_weapon_graphics
    rts

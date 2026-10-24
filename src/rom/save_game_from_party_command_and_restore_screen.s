; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-save-restart.md.
.setcpu "65816"
.smart
.a8
.i16

public_saved_game_menu_request_alias = $C0000C
restore_event_screen_and_reenable_frame_interrupts = $FF3A
transfer_party_command_to_cold_reset = $EBC3

.segment "CODE"
.org $EBB2
save_game_from_party_command_and_restore_screen:
    .a8
    cmp #$06
    bne transfer_party_command_to_cold_reset
    rep #$20
    lda a:$010E
    jsl f:public_saved_game_menu_request_alias
    jsr restore_event_screen_and_reenable_frame_interrupts
    rts

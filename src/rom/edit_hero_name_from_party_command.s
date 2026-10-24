; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-name-command.md.
.setcpu "65816"
.smart
.a8
.i16

jump_public_native_name_menu = $C0000F
restore_event_screen_and_reenable_frame_interrupts = $FF3A

.segment "CODE"
.org $EB71
edit_hero_name_from_party_command:
    tax
    .a8
    lda #$00
    jsl f:jump_public_native_name_menu
    jsr restore_event_screen_and_reenable_frame_interrupts
    rts

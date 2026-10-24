; Recovered Secret of Mana USA routine; behaviour documented in docs/event-gold-hud-commands.md.
.setcpu "65816"
.smart
.a8
.i16

wait_for_native_nmi_and_refresh_party_hud_numbers = $E326

.segment "CODE"
.org $EFDF
advance_event_cursor_wait_for_nmi_and_publish_party_hud:
    rep #$20
    inc $D1
    jsr wait_for_native_nmi_and_refresh_party_hud_numbers
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/event-party-hud-restore.md.
.setcpu "65816"
.smart
.a8
.i16

clear_party_hud_tilemap = $E2E5
place_party_hud_frames = $E113
request_frame_upload_and_wait_for_native_nmi = $E0F9
reset_party_hud_workspace = $E2FE
upload_map_party_icons = $E6B6
write_party_hud_numbers = $E339

.segment "CODE"
.org $E0DB
restore_party_hud_across_two_native_frames:
    jsr reset_party_hud_workspace
    sep #$20
    phb
    .a8
    lda #$00
    pha
    plb
    jsr request_frame_upload_and_wait_for_native_nmi
    jsr clear_party_hud_tilemap
    jsr place_party_hud_frames
    jsr request_frame_upload_and_wait_for_native_nmi
    jsr write_party_hud_numbers
    jsr upload_map_party_icons
    plb
    rts

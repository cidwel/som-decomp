; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

clear_party_hud_tilemap = $E2E5
place_party_hud_frames = $E113
reset_party_hud_workspace = $E2FE
upload_map_party_icons = $E6B6
write_party_hud_numbers = $E339

.segment "CODE"
.org $E104
initialize_party_hud:
    jsr reset_party_hud_workspace
    jsr clear_party_hud_tilemap
    jsr place_party_hud_frames
    jsr write_party_hud_numbers
    jmp upload_map_party_icons

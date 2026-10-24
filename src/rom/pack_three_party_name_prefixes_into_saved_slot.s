; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-write.md.
.setcpu "65816"
.smart
.a8
.i16

pack_six_party_name_bytes_into_two_slot_copies = $57B1

.segment "CODE"
.org $571E
pack_three_party_name_prefixes_into_saved_slot:
    .i16
    ldy #$E000
    jsr pack_six_party_name_bytes_into_two_slot_copies
    .i16
    ldy #$E200
    jsr pack_six_party_name_bytes_into_two_slot_copies
    .i16
    ldy #$E400
    jsr pack_six_party_name_bytes_into_two_slot_copies
    rts

; Recovered Secret of Mana USA routine; behaviour documented in docs/monster-ai-opcodes.md.
.setcpu "65816"
.smart
.a8
.i16

refresh_controller_status_bits_from_party = $3F2C

.segment "CODE"
.org $3F28
refresh_controller_status_public_call:
    jsr refresh_controller_status_bits_from_party
    rtl

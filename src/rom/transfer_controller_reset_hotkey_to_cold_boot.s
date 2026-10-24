; Recovered Secret of Mana USA routine; behaviour documented in docs/game-controller-poll.md.
.setcpu "65816"
.smart
.a8
.i16

jump_to_cold_boot = $C10010

.segment "CODE"
.org $93B3
transfer_controller_reset_hotkey_to_cold_boot:
    clc
    jsl f:jump_to_cold_boot
    rts

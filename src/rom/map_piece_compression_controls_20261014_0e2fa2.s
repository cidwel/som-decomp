.setcpu "65816"
.segment "CODE"
.org $2FA2
map_control_0e2fa2:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

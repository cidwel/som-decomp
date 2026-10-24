.setcpu "65816"
.segment "CODE"
.org $B2FA
map_control_0eb2fa:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

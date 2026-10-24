.setcpu "65816"
.segment "CODE"
.org $2FA6
map_control_0e2fa6:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

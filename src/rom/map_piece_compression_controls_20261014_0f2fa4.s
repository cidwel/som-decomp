.setcpu "65816"
.segment "CODE"
.org $2FA4
map_control_0f2fa4:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count

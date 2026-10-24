.setcpu "65816"
.segment "CODE"
.org $9DB9
map_control_0e9db9:
    .byte $E8 ; backreference distance high bits
    .byte $95 ; distance low bit/count

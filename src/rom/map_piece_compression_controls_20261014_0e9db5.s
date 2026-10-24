.setcpu "65816"
.segment "CODE"
.org $9DB5
map_control_0e9db5:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count

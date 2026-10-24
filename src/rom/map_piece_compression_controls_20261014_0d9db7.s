.setcpu "65816"
.segment "CODE"
.org $9DB7
map_control_0d9db7:
    .byte $E8 ; backreference distance high bits
    .byte $93 ; distance low bit/count

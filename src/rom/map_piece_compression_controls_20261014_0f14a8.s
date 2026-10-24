.setcpu "65816"
.segment "CODE"
.org $14A8
map_control_0f14a8:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count

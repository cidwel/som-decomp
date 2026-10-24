.setcpu "65816"
.segment "CODE"
.org $54C9
map_control_0f54c9:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count

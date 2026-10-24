.setcpu "65816"
.segment "CODE"
.org $0907
map_control_0f0907:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count

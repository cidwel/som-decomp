.setcpu "65816"
.segment "CODE"
.org $E051
map_control_0fe051:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

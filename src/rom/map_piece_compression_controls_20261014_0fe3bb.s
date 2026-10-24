.setcpu "65816"
.segment "CODE"
.org $E3BB
map_control_0fe3bb:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

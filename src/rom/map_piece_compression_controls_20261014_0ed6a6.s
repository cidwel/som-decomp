.setcpu "65816"
.segment "CODE"
.org $D6A6
map_control_0ed6a6:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

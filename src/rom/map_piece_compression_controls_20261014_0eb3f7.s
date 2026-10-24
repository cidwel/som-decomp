.setcpu "65816"
.segment "CODE"
.org $B3F7
map_control_0eb3f7:
    .byte $E8 ; backreference distance high bits
    .byte $9D ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $B822
map_control_0eb822:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

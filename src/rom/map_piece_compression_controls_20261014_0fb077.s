.setcpu "65816"
.segment "CODE"
.org $B077
map_control_0fb077:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count

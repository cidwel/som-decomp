.setcpu "65816"
.segment "CODE"
.org $6CA8
map_control_0d6ca8:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

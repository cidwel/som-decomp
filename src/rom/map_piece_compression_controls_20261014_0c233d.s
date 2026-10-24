.setcpu "65816"
.segment "CODE"
.org $233D
map_control_0c233d:
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count

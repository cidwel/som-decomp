.setcpu "65816"
.segment "CODE"
.org $91BE
map_control_0e91be:
    .byte $E8 ; backreference distance high bits
    .byte $59 ; distance low bit/count

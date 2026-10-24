.setcpu "65816"
.segment "CODE"
.org $CFD8
map_control_0ecfd8:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $CFE3
map_control_0ecfe3:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $DA92
map_control_0eda92:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count

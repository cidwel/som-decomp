.setcpu "65816"
.segment "CODE"
.org $F646
map_control_0cf646:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

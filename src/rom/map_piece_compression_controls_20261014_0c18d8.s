.setcpu "65816"
.segment "CODE"
.org $18D8
map_control_0c18d8:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

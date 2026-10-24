.setcpu "65816"
.segment "CODE"
.org $8107
map_control_0e8107:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

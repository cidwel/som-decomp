.setcpu "65816"
.segment "CODE"
.org $7117
map_control_0d7117:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

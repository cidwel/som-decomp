.setcpu "65816"
.segment "CODE"
.org $7981
map_control_0f7981:
    .byte $EC ; backreference distance high bits
    .byte $82 ; distance low bit/count

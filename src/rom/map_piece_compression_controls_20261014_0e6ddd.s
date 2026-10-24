.setcpu "65816"
.segment "CODE"
.org $6DDD
map_control_0e6ddd:
    .byte $EC ; backreference distance high bits
    .byte $87 ; distance low bit/count

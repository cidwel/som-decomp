.setcpu "65816"
.segment "CODE"
.org $2DDD
map_control_0f2ddd:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

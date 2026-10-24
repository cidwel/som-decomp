.setcpu "65816"
.segment "CODE"
.org $3DDD
map_control_0d3ddd:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count

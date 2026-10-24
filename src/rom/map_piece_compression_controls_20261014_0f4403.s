.setcpu "65816"
.segment "CODE"
.org $4403
map_control_0f4403:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

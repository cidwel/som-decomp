.setcpu "65816"
.segment "CODE"
.org $7160
map_control_0f7160:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

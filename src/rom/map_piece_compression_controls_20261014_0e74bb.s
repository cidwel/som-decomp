.setcpu "65816"
.segment "CODE"
.org $74BB
map_control_0e74bb:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count

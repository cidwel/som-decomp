.setcpu "65816"
.segment "CODE"
.org $8227
map_control_0c8227:
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count

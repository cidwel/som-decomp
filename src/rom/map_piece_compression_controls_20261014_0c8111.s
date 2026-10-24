.setcpu "65816"
.segment "CODE"
.org $8111
map_control_0c8111:
    .byte $E9 ; backreference distance high bits
    .byte $8B ; distance low bit/count

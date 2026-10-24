.setcpu "65816"
.segment "CODE"
.org $CF5F
map_control_0ecf5f:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count

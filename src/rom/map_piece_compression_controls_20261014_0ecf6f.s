.setcpu "65816"
.segment "CODE"
.org $CF6F
map_control_0ecf6f:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count

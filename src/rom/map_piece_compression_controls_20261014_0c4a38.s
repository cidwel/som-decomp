.setcpu "65816"
.segment "CODE"
.org $4A38
map_control_0c4a38:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count

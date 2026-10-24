.setcpu "65816"
.segment "CODE"
.org $4AA4
map_control_0c4aa4:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count

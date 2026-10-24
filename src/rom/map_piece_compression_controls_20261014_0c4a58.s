.setcpu "65816"
.segment "CODE"
.org $4A58
map_control_0c4a58:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count

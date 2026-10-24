.setcpu "65816"
.segment "CODE"
.org $3161
map_control_0d3161:
    .byte $E8 ; backreference distance high bits
    .byte $1B ; distance low bit/count

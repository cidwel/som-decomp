.setcpu "65816"
.segment "CODE"
.org $5915
map_control_0c5915:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $7915
map_control_0c7915:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

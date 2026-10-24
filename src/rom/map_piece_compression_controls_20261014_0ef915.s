.setcpu "65816"
.segment "CODE"
.org $F915
map_control_0ef915:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count

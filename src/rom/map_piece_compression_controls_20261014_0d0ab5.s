.setcpu "65816"
.segment "CODE"
.org $0AB5
map_control_0d0ab5:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count

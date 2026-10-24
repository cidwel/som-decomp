.setcpu "65816"
.segment "CODE"
.org $0AB0
map_control_0d0ab0:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count

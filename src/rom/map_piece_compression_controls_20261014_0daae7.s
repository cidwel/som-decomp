.setcpu "65816"
.segment "CODE"
.org $AAE7
map_control_0daae7:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

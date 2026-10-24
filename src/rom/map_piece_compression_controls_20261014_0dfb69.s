.setcpu "65816"
.segment "CODE"
.org $FB69
map_control_0dfb69:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

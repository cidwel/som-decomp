.setcpu "65816"
.segment "CODE"
.org $EC56
map_control_0eec56:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

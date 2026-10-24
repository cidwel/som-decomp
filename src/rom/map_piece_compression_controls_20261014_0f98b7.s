.setcpu "65816"
.segment "CODE"
.org $98B7
map_control_0f98b7:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

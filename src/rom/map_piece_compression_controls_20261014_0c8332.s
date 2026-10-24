.setcpu "65816"
.segment "CODE"
.org $8332
map_control_0c8332:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

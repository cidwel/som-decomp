.setcpu "65816"
.segment "CODE"
.org $9E31
map_control_0d9e31:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

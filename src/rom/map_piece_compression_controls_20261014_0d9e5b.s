.setcpu "65816"
.segment "CODE"
.org $9E5B
map_control_0d9e5b:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

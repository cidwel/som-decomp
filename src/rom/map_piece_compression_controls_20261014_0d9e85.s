.setcpu "65816"
.segment "CODE"
.org $9E85
map_control_0d9e85:
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count

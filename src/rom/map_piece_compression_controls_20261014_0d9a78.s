.setcpu "65816"
.segment "CODE"
.org $9A78
map_control_0d9a78:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

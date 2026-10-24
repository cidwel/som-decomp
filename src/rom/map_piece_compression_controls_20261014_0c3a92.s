.setcpu "65816"
.segment "CODE"
.org $3A92
map_control_0c3a92:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count

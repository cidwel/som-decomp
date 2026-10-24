.setcpu "65816"
.segment "CODE"
.org $9F36
map_control_0e9f36:
    .byte $E8 ; backreference distance high bits
    .byte $2D ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $8063
map_control_0d8063:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count

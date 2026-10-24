.setcpu "65816"
.segment "CODE"
.org $4B40
map_control_0c4b40:
    .byte $E8 ; backreference distance high bits
    .byte $26 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $D003
map_control_0ed003:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

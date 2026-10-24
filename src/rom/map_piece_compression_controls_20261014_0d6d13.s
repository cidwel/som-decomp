.setcpu "65816"
.segment "CODE"
.org $6D13
map_control_0d6d13:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

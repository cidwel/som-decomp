.setcpu "65816"
.segment "CODE"
.org $26C9
map_control_0c26c9:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count

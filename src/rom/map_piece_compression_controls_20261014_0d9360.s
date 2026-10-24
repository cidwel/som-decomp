.setcpu "65816"
.segment "CODE"
.org $9360
map_control_0d9360:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $2BA2
map_control_0d2ba2:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count

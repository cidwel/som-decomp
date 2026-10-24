.setcpu "65816"
.segment "CODE"
.org $1C0C
map_control_0d1c0c:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count

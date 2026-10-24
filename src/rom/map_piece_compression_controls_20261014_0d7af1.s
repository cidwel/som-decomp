.setcpu "65816"
.segment "CODE"
.org $7AF1
map_control_0d7af1:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count

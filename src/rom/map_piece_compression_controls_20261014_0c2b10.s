.setcpu "65816"
.segment "CODE"
.org $2B10
map_control_0c2b10:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $D4B2
map_control_0fd4b2:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

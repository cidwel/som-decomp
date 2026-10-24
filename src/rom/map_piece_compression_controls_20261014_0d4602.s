.setcpu "65816"
.segment "CODE"
.org $4602
map_control_0d4602:
    .byte $E8 ; backreference distance high bits
    .byte $8A ; distance low bit/count

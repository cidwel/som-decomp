.setcpu "65816"
.segment "CODE"
.org $22DC
map_control_0f22dc:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count

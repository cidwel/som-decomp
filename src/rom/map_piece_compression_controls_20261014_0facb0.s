.setcpu "65816"
.segment "CODE"
.org $ACB0
map_control_0facb0:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $BAA0
map_control_0ebaa0:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count

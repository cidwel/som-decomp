.setcpu "65816"
.segment "CODE"
.org $B7E1
map_control_0eb7e1:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count

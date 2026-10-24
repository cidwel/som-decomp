.setcpu "65816"
.segment "CODE"
.org $BFC0
map_control_0ebfc0:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count

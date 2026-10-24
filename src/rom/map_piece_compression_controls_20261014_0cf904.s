.setcpu "65816"
.segment "CODE"
.org $F904
map_control_0cf904:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count

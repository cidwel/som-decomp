.setcpu "65816"
.segment "CODE"
.org $15DF
map_control_0d15df:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count

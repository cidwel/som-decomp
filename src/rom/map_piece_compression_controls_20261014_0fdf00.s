.setcpu "65816"
.segment "CODE"
.org $DF00
map_control_0fdf00:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count

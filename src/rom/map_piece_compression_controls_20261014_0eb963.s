.setcpu "65816"
.segment "CODE"
.org $B963
map_control_0eb963:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

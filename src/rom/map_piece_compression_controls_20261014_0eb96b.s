.setcpu "65816"
.segment "CODE"
.org $B96B
map_control_0eb96b:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $2752
map_control_0c2752:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count

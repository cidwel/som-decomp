.setcpu "65816"
.segment "CODE"
.org $6529
map_control_0c6529:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $CEE6
map_control_0ecee6:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count

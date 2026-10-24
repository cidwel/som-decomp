.setcpu "65816"
.segment "CODE"
.org $9839
map_control_0e9839:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count

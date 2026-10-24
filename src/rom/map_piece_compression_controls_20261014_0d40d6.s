.setcpu "65816"
.segment "CODE"
.org $40D6
map_control_0d40d6:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $CF06
map_control_0ecf06:
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count

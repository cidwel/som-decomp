.setcpu "65816"
.segment "CODE"
.org $51CE
map_control_0c51ce:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count

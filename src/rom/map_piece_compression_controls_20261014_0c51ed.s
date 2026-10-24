.setcpu "65816"
.segment "CODE"
.org $51ED
map_control_0c51ed:
    .byte $E9 ; backreference distance high bits
    .byte $89 ; distance low bit/count

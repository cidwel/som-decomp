.setcpu "65816"
.segment "CODE"
.org $BEC2
map_control_0ebec2:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

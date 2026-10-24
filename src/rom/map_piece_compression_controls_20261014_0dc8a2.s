.setcpu "65816"
.segment "CODE"
.org $C8A2
map_control_0dc8a2:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count

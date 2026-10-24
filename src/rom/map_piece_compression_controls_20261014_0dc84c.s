.setcpu "65816"
.segment "CODE"
.org $C84C
map_control_0dc84c:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count

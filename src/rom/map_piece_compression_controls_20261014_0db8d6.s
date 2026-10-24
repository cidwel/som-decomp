.setcpu "65816"
.segment "CODE"
.org $B8D6
map_control_0db8d6:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

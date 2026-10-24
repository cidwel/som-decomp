.setcpu "65816"
.segment "CODE"
.org $B8C4
map_control_0db8c4:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

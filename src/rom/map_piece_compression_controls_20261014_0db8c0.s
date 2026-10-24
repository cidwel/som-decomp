.setcpu "65816"
.segment "CODE"
.org $B8C0
map_control_0db8c0:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

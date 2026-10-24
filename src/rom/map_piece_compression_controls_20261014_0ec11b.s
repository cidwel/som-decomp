.setcpu "65816"
.segment "CODE"
.org $C11B
map_control_0ec11b:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

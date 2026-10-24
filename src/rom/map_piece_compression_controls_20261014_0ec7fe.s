.setcpu "65816"
.segment "CODE"
.org $C7FE
map_control_0ec7fe:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

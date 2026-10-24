.setcpu "65816"
.segment "CODE"
.org $C012
map_control_0ec012:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count

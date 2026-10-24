.setcpu "65816"
.segment "CODE"
.org $C9AC
map_control_0ec9ac:
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count

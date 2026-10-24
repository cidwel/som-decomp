.setcpu "65816"
.segment "CODE"
.org $A78D
map_control_0da78d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

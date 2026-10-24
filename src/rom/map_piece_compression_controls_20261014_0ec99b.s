.setcpu "65816"
.segment "CODE"
.org $C99B
map_control_0ec99b:
    .byte $E8 ; backreference distance high bits
    .byte $A6 ; distance low bit/count

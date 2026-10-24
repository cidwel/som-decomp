.setcpu "65816"
.segment "CODE"
.org $4851
map_control_0d4851:
    .byte $E8 ; backreference distance high bits
    .byte $A1 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $A3C9
map_control_0ea3c9:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count

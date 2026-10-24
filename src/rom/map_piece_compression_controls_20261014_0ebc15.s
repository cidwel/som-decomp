.setcpu "65816"
.segment "CODE"
.org $BC15
map_control_0ebc15:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count

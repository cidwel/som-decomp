.setcpu "65816"
.segment "CODE"
.org $BC20
map_control_0ebc20:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $BC2B
map_control_0ebc2b:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $A3 ; distance low bit/count

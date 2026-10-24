.setcpu "65816"
.segment "CODE"
.org $A7EC
map_control_0fa7ec:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count

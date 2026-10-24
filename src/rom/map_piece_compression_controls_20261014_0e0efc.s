.setcpu "65816"
.segment "CODE"
.org $0EFC
map_control_0e0efc:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count

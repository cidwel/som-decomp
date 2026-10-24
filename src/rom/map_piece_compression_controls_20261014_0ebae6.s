.setcpu "65816"
.segment "CODE"
.org $BAE6
map_control_0ebae6:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $93 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

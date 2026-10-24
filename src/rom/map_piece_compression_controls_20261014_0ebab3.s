.setcpu "65816"
.segment "CODE"
.org $BAB3
map_control_0ebab3:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

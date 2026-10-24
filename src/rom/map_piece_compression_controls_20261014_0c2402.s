.setcpu "65816"
.segment "CODE"
.org $2402
map_control_0c2402:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $51 ; distance low bit/count

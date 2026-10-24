.setcpu "65816"
.segment "CODE"
.org $20F2
map_control_0d20f2:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

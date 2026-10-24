.setcpu "65816"
.segment "CODE"
.org $4D10
map_control_0d4d10:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count

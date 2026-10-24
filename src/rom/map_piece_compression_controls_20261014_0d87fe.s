.setcpu "65816"
.segment "CODE"
.org $87FE
map_control_0d87fe:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $45 ; distance low bit/count

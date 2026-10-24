.setcpu "65816"
.segment "CODE"
.org $5D69
map_control_0e5d69:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $77 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $10DD
map_control_0e10dd:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $BB70
map_control_0dbb70:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

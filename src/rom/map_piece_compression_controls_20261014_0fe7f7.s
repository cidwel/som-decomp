.setcpu "65816"
.segment "CODE"
.org $E7F7
map_control_0fe7f7:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count

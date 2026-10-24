.setcpu "65816"
.segment "CODE"
.org $325B
map_control_0c325b:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

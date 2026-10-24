.setcpu "65816"
.segment "CODE"
.org $23F4
map_control_0c23f4:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count

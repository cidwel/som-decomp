.setcpu "65816"
.segment "CODE"
.org $F616
map_control_0ef616:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4C ; distance low bit/count

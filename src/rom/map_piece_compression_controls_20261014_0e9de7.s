.setcpu "65816"
.segment "CODE"
.org $9DE7
map_control_0e9de7:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count

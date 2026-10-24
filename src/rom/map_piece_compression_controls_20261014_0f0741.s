.setcpu "65816"
.segment "CODE"
.org $0741
map_control_0f0741:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $92 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $4BA7
map_control_0f4ba7:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1F ; distance low bit/count

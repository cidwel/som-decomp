.setcpu "65816"
.segment "CODE"
.org $81EE
map_control_0f81ee:
    .byte $ED ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count

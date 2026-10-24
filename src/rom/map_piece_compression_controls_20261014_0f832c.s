.setcpu "65816"
.segment "CODE"
.org $832C
map_control_0f832c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count

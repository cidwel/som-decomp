.setcpu "65816"
.segment "CODE"
.org $F70D
map_control_0df70d:
    .byte $E9 ; backreference distance high bits
    .byte $86 ; distance low bit/count

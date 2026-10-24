.setcpu "65816"
.segment "CODE"
.org $20AE
map_control_0d20ae:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

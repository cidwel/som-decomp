.setcpu "65816"
.segment "CODE"
.org $209A
map_control_0d209a:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

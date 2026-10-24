.setcpu "65816"
.segment "CODE"
.org $C0CF
map_control_0ec0cf:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

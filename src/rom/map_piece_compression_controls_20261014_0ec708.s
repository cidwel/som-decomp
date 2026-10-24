.setcpu "65816"
.segment "CODE"
.org $C708
map_control_0ec708:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $C19B
map_control_0ec19b:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

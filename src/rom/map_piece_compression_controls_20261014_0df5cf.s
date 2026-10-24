.setcpu "65816"
.segment "CODE"
.org $F5CF
map_control_0df5cf:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

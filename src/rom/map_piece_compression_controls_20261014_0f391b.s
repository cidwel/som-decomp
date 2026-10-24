.setcpu "65816"
.segment "CODE"
.org $391B
map_control_0f391b:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

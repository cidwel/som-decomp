.setcpu "65816"
.segment "CODE"
.org $41CB
map_control_0d41cb:
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count

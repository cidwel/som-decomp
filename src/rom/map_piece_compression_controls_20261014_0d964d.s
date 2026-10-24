.setcpu "65816"
.segment "CODE"
.org $964D
map_control_0d964d:
    .byte $E8 ; backreference distance high bits
    .byte $11 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $11A0
map_control_0d11a0:
    .byte $E8 ; backreference distance high bits
    .byte $99 ; distance low bit/count

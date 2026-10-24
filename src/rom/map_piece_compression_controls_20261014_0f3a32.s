.setcpu "65816"
.segment "CODE"
.org $3A32
map_control_0f3a32:
    .byte $E8 ; backreference distance high bits
    .byte $94 ; distance low bit/count

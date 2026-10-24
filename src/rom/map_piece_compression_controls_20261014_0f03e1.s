.setcpu "65816"
.segment "CODE"
.org $03E1
map_control_0f03e1:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

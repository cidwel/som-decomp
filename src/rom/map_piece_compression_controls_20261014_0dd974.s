.setcpu "65816"
.segment "CODE"
.org $D974
map_control_0dd974:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count

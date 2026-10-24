.setcpu "65816"
.segment "CODE"
.org $B6BA
map_control_0eb6ba:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

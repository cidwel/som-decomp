.setcpu "65816"
.segment "CODE"
.org $B6AF
map_control_0eb6af:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

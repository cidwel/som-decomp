.setcpu "65816"
.segment "CODE"
.org $EB5D
map_control_0deb5d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

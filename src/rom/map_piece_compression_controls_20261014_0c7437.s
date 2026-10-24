.setcpu "65816"
.segment "CODE"
.org $7437
map_control_0c7437:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $C906
map_control_0ec906:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count

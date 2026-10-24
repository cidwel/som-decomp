.setcpu "65816"
.segment "CODE"
.org $92A9
map_control_0f92a9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $92BA
map_control_0f92ba:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

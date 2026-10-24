.setcpu "65816"
.segment "CODE"
.org $6D37
map_control_0d6d37:
    .byte $E8 ; backreference distance high bits
    .byte $87 ; distance low bit/count

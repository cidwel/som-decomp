.setcpu "65816"
.segment "CODE"
.org $6263
map_control_0e6263:
    .byte $E8 ; backreference distance high bits
    .byte $44 ; distance low bit/count

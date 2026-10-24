.setcpu "65816"
.segment "CODE"
.org $F4D4
map_control_0df4d4:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count

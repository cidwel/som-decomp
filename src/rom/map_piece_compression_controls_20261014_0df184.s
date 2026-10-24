.setcpu "65816"
.segment "CODE"
.org $F184
map_control_0df184:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

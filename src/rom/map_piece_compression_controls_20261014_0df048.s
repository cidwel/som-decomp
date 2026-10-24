.setcpu "65816"
.segment "CODE"
.org $F048
map_control_0df048:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count

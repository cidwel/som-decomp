.setcpu "65816"
.segment "CODE"
.org $398A
map_control_0d398a:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

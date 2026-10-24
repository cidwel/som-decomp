.setcpu "65816"
.segment "CODE"
.org $E39A
map_control_0de39a:
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count

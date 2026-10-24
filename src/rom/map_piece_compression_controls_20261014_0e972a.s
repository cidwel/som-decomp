.setcpu "65816"
.segment "CODE"
.org $972A
map_control_0e972a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $F97A
map_control_0ef97a:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

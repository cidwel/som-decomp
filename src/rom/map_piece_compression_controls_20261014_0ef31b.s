.setcpu "65816"
.segment "CODE"
.org $F31B
map_control_0ef31b:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count

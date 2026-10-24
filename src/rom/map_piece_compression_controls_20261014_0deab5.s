.setcpu "65816"
.segment "CODE"
.org $EAB5
map_control_0deab5:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count

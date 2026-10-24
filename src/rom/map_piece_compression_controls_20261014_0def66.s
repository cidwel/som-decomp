.setcpu "65816"
.segment "CODE"
.org $EF66
map_control_0def66:
    .byte $E8 ; backreference distance high bits
    .byte $0E ; distance low bit/count

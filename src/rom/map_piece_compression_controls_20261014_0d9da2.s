.setcpu "65816"
.segment "CODE"
.org $9DA2
map_control_0d9da2:
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count

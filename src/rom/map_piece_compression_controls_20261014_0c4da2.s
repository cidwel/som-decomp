.setcpu "65816"
.segment "CODE"
.org $4DA2
map_control_0c4da2:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count

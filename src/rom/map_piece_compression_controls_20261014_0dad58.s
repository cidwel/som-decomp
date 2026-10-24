.setcpu "65816"
.segment "CODE"
.org $AD58
map_control_0dad58:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count

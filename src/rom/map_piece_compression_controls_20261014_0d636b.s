.setcpu "65816"
.segment "CODE"
.org $636B
map_control_0d636b:
    .byte $E8 ; backreference distance high bits
    .byte $14 ; distance low bit/count

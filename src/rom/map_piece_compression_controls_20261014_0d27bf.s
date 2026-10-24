.setcpu "65816"
.segment "CODE"
.org $27BF
map_control_0d27bf:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count

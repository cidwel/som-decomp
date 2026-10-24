.setcpu "65816"
.segment "CODE"
.org $E970
map_control_0fe970:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

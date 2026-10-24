.setcpu "65816"
.segment "CODE"
.org $DF29
map_control_0ddf29:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $DF4F
map_control_0ddf4f:
    .byte $E8 ; backreference distance high bits
    .byte $62 ; distance low bit/count

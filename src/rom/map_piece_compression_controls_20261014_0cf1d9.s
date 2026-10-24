.setcpu "65816"
.segment "CODE"
.org $F1D9
map_control_0cf1d9:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $AE08
map_control_0dae08:
    .byte $E8 ; backreference distance high bits
    .byte $38 ; distance low bit/count

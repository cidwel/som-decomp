.setcpu "65816"
.segment "CODE"
.org $7DCF
map_control_0d7dcf:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count

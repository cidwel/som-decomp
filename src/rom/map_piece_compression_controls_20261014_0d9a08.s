.setcpu "65816"
.segment "CODE"
.org $9A08
map_control_0d9a08:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count

.setcpu "65816"
.segment "CODE"
.org $9A39
map_control_0d9a39:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
